/*
 *  gProximity Library.
 *  
 *  
 *  Copyright (C) 2010 University of North Carolina at Chapel Hill.
 *  All rights reserved.
 *  
 *  Permission to use, copy, modify, and distribute this software and its
 *  documentation for educational, research, and non-profit purposes, without
 *  fee, and without a written agreement is hereby granted, provided that the
 *  above copyright notice, this paragraph, and the following four paragraphs
 *  appear in all copies.
 *  
 *  Permission to incorporate this software into commercial products may be
 *  obtained by contacting the University of North Carolina at Chapel Hill.
 *  
 *  This software program and documentation are copyrighted by the University of
 *  North Carolina at Chapel Hill. The software program and documentation are
 *  supplied "as is", without any accompanying services from the University of
 *  North Carolina at Chapel Hill or the authors. The University of North
 *  Carolina at Chapel Hill and the authors do not warrant that the operation of
 *  the program will be uninterrupted or error-free. The end-user understands
 *  that the program was developed for research purposes and is advised not to
 *  rely exclusively on the program for any reason.
 *  
 *  IN NO EVENT SHALL THE UNIVERSITY OF NORTH CAROLINA AT CHAPEL HILL OR ITS
 *  EMPLOYEES OR THE AUTHORS BE LIABLE TO ANY PARTY FOR DIRECT, INDIRECT,
 *  SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES, INCLUDING LOST PROFITS,
 *  ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF THE
 *  UNIVERSITY OF NORTH CAROLINA AT CHAPEL HILL OR THE AUTHORS HAVE BEEN ADVISED
 *  OF THE POSSIBILITY OF SUCH DAMAGE.
 *  
 *  THE UNIVERSITY OF NORTH CAROLINA AT CHAPEL HILL AND THE AUTHORS SPECIFICALLY
 *  DISCLAIM ANY WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 *  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE AND ANY
 *  STATUTORY WARRANTY OF NON-INFRINGEMENT. THE SOFTWARE PROVIDED HEREUNDER IS
 *  ON AN "AS IS" BASIS, AND THE UNIVERSITY OF NORTH CAROLINA AT CHAPEL HILL AND
 *  THE AUTHORS HAVE NO OBLIGATIONS TO PROVIDE MAINTENANCE, SUPPORT, UPDATES,
 *  ENHANCEMENTS, OR MODIFICATIONS.
 *  
 *  Please send all BUG REPORTS to:
 *  
 *  geom@cs.unc.edu
 *  
 *  The authors may be contacted via:
 *  
 *  Christian Lauterbach, Qi Mo, Jia Pan and Dinesh Manocha
 *  Dept. of Computer Science
 *  Frederick P. Brooks Jr. Computer Science Bldg.
 *  3175 University of N.C.
 *  Chapel Hill, N.C. 27599-3175
 *  United States of America
 *  
 *  http://gamma.cs.unc.edu/GPUCOL/
 *  
 */
 
#include <Inventor/SoDB.h>
#include <Inventor/SoInput.h>
#include <Inventor/actions/SoCallbackAction.h>
#include <Inventor/SoPrimitiveVertex.h>
#include <Inventor/nodes/SoCoordinate3.h>
#include <Inventor/nodes/SoIndexedFaceSet.h>
#include <Inventor/nodes/SoSeparator.h>
#include <Inventor/nodes/SoShape.h>
#include <Inventor/nodes/SoSphere.h>
#include <Inventor/nodes/SoTranslation.h>
#include <cybergarage/x3d/SceneGraph.h>
#include "ply.h"
#include "importer_utility.h"

#include <GL/glew.h>
#include "Vector3.h"
#include "Matrix.h"
#include "Triangle.h"
#include "Utility.h"
#include <string>
#include <float.h>

#include "geometry.h"
#include "transform.h"
#include <cuda_runtime.h>
#include <cutil.h>

SoCoordinate3* ModelInstance::coord3 = NULL;
SoIndexedFaceSet* ModelInstance::ifs = NULL;
int ModelInstance::coord3idx = 0;

ModelInstance::ModelInstance()
{
	isInstanced = false;
	trilist = NULL;
	verlist = NULL;
	nVerts = 0;
	nTris = 0;
	bb[0] = Vector3(-FLT_MAX, -FLT_MAX, -FLT_MAX);
	bb[1] = Vector3(FLT_MAX, FLT_MAX, FLT_MAX);
	vbo_Vertex = 0;
	vbo_TriIndex = 0;
	boundingBoxGenerated = false;
	obbTree = NULL;
	vertexPointer = NULL;
	triIdxPointer = NULL;
	bvh_constru = NULL;
	rss_constru = NULL;
}

ModelInstance::~ModelInstance()
{
	destroy();
}

void ModelInstance::destroy()
{
	if(!isInstanced)
	{
		if(verlist)
			_aligned_free(verlist);
		verlist = NULL;

		if(trilist)
			delete [] trilist;
		trilist = NULL;

		if(vbo_TriIndex)
		{
			glDeleteBuffersARB(1, &vbo_TriIndex);
			vbo_TriIndex = 0;
		}

		if(vbo_Vertex)
		{
			glDeleteBuffersARB(1, &vbo_Vertex);
			vbo_Vertex = 0;
		}
		//
		if(obbTree)
		{
			CUDA_SAFE_CALL(cudaFree(obbTree));
			obbTree = NULL;
		}
	}
}

void ModelInstance::calculateAABoundingBox()
{
	if(!boundingBoxGenerated && nTris > 0)
	{
		bb[0] = Vector3(FLT_MAX, FLT_MAX, FLT_MAX);
		bb[1] = Vector3(-FLT_MAX, -FLT_MAX, -FLT_MAX);

		for(unsigned int i = 0; i < nTris; ++i)
		{
			const Triangle& t = trilist[i];
			for(unsigned int j = 0; j < 3; ++j)
			{
				int vid = t.p[j];
				const Vector3& v = verlist[vid];
				for(unsigned int k = 0; k < 3; ++k)
				{
					if(v[k] < bb[0][k])
						bb[0][k] = v[k];
					if(v[k] > bb[1][k])
						bb[1][k] = v[k];
				}
			}
		}
	}
}

int ModelInstance::load(const char* fileName, float scalarFactor)
{
	char* extension = _strdup(strrchr(fileName, '.'));
	strtolower(extension);

	int retCode;

	if(strcmp(extension, ".obj") == 0)
	{
		retCode = loadOBJ(fileName, scalarFactor);
	}
	else if(strcmp(extension, ".ply") == 0)
	{
		retCode = loadPLY(fileName, scalarFactor);
	}
	else if(strcmp(extension, ".tri") == 0)
	{
		retCode = loadTRI(fileName, scalarFactor);
	}
	else if(strcmp(extension, ".tr2") == 0)
	{
		retCode = loadTRI2(fileName, scalarFactor);
	}
	else if(strcmp(extension, ".wrl") == 0)
	{
		retCode = loadVRML(fileName, scalarFactor);
	}
	else if(strcmp(extension, ".iv") == 0)
	{
		retCode = loadIV(fileName, scalarFactor);
	}

	free(extension);

	return retCode;
}

int ModelInstance::load(const char* fileName, float scalarFactor, Transform const& t)
{
	int retCode = load(fileName, scalarFactor);

	for(int i = 0; i < nVerts; ++i)
	{
		float in[3];
		float out[3];
		in[0] = verlist[i].e[0];
		in[1] = verlist[i].e[1];
		in[2] = verlist[i].e[2];
		t.apply(out, in);
		verlist[i].e[0] = out[0];
		verlist[i].e[1] = out[1];
		verlist[i].e[2] = out[2];
	}

	return retCode;
}

int ModelInstance::loadOBJ(const char* fileName, float scalarFactor)
{
	FILE* objFileStream = fopen(fileName, "rb");
	if(!objFileStream) return -1;

	unsigned int curVert = 0;

#define OBJ_COORD_X 0
#define OBJ_COORD_Y 1
#define OBJ_COORD_Z 2

	char lineBuffer[2000];
	bool has_vertexNormals = false;
	bool has_textureCoords = false;

	std::vector<SSEVertex> tempVertexList;
	std::vector<Triangle> tempTriangleList;
	std::vector<Vector2> tempTexCoords;
	std::vector<SSEVertex> tempVertexNormals;

	while(fgets(lineBuffer, 2000, objFileStream))
	{
		char *firstToken = strtok(lineBuffer, "\r\n\t ");

		if(!firstToken || firstToken[0] == '#' || firstToken[0] == 0)
			continue;

		strtolower(firstToken);

		switch(firstToken[0])
		{
		case 'v': // new vertex
			if(firstToken[1] == 'n')
			{
				// vertex normal
				SSEVertex newVert;
				newVert.e[OBJ_COORD_X] = (float)atof(strtok(NULL, "\t "));
				newVert.e[OBJ_COORD_Y] = (float)atof(strtok(NULL, "\t "));
				newVert.e[OBJ_COORD_Z] = (float)atof(strtok(NULL, "\t "));
				tempVertexNormals.push_back(newVert);
				has_vertexNormals = true;
			}
			else if(firstToken[1] == 't')
			{
				// texture coordinate
				Vector2 newVert;
				newVert.e[0] = (float)atof(strtok(NULL, "\t "));
				newVert.e[1] = 1.0f - (float)atof(strtok(NULL, "\t "));
				tempTexCoords.push_back(newVert);
				has_textureCoords = true;
			}
			else
			{
				SSEVertex newVert;
				newVert.e[OBJ_COORD_X] = (float)atof(strtok(NULL, "\t "));
				newVert.e[OBJ_COORD_Y] = (float)atof(strtok(NULL, "\t "));
				newVert.e[OBJ_COORD_Z] = (float)atof(strtok(NULL, "\t "));
				newVert *= scalarFactor;
				tempVertexList.push_back(newVert);
			}
			break;
		case 'f': // new face
			{
				Triangle tri;
#define OBJ_MAXVERTSPERFACE 30
				char *vertData[OBJ_MAXVERTSPERFACE];
				int nFaceVerts = 0;

				while((vertData[nFaceVerts] = strtok(NULL, "\t \r\n")) != NULL)
					if(strlen(vertData[nFaceVerts]))
						nFaceVerts++;

				for(int t = 0; t < (nFaceVerts - 2); t++)
				{
					if(has_textureCoords == false && has_vertexNormals == false)
					{
						// vertex indices
						tri.p[0] = atoi(vertData[0]) - 1;
						tri.p[1] = atoi(vertData[t + 1]) - 1;
						tri.p[2] = atoi(vertData[t + 2]) - 1;
					}
					else
					{
						// in vID/vtID/vnID format
						const char *v1;

						for(int i = 0; i < 3; i++)
						{
							// vertex ID
							if(i == 0)
								v1 = vertData[0];
							else
								v1 = vertData[t + i];

							tri.p[i] = atoi(v1) - 1;

							// texture coordinate
							const char *v2 = strchr(v1 + 1, '/');

							if(v2)
							{
#ifdef _USE_TEXTURING
								if(has_textureCoords)
									tri.uv[i] = tempTexCoords[atoi(v2 + 1) -1];
#endif

								// vertex normal
								const char *v3 = strchr(v2 + 1, '/');
							}
						}
					}

					tri.updateFromVerticesNoReorder(tempVertexList[tri.p[0]],
						tempVertexList[tri.p[1]],
						tempVertexList[tri.p[2]]);
					tri.n = -tri.n;

#ifdef _USE_TEXTURING
					if(has_textureCoords)
					{
						tri.uv[1] = tri.uv[1] - tri.uv[0];
						tri.uv[2] = tri.uv[2] - tri.uv[0];
					}
					else
					{
						tri.uv[0] = tri.uv[2] = tri.uv[1] = Vector2(0, 0);
					}
#endif


					tempTriangleList.push_back(tri);
				}
			}
			break;
		case 'u': // use material
		case 's': // no idea
		case 'o': // new object
		case 'm': // material library
		case 'g': // scene name
			// do nothing
			break;
		default: // unknown tag:
			std::cout << "Warning: Unknown OBJ tag " << firstToken << " skipping." << std::endl;
		}
	}

	std::cout << "OBJ file "  << fileName << " loaded, " << tempTriangleList.size() << "faces, " << tempVertexList.size() << " vertices" << std::endl;

	// copy over temporary vertex list:
	modelFileName = std::string(fileName);
	nVerts = (unsigned int)tempVertexList.size();
	verlist = (SSEVertex *)_aligned_malloc(sizeof(SSEVertex) * nVerts, 16);
	for(unsigned int i = 0; i < nVerts; i++)
		verlist[i] = tempVertexList[i];
	tempVertexList.clear();

	// copy over temporary triangle list:
	nTris = (unsigned int)tempTriangleList.size();
	trilist = new Triangle[nTris];
	for(unsigned int i = 0; i < nTris; i++)
		trilist[i] = tempTriangleList[i];
	tempTriangleList.clear();

	return 1;
}


int ModelInstance::loadPLY(const char* fileName, float scalarFactor)
{
	// PLY object:
	PlyFile *ply;

	// PLY properties:
	char **elist;
	int nelems, num_elems;
	int file_type;
	float version;
	float plyScale = scalarFactor;

	// open a stream of the file given to us
	FILE *plyFileStream = fopen(fileName, "rb");

	if(!plyFileStream)
		return -1;

	// hand over the stream to the ply functions:
	ply = ply_read(plyFileStream, &nelems, &elist);

	if(ply == NULL)
	{
		printf("Error while parsing the PLY file!\n");
		return -1;
	}

	ply_get_info(ply, &version, &file_type);

	std::cout << "PLY file " << fileName << " loaded, version " << version << ", " << nelems << " elements" << std::endl;

	// buffer to store vertices in while parsing:
	unsigned int curVert = 0;

	typedef struct PLYVertex
	{
		float coords[3];
		unsigned char color[3];
		void *other_props;
	} PLYVertex;

	typedef struct PLYFace
	{
		unsigned char nverts;
		int *verts;
		void *other_props;
	} PLYFace;

	PlyProperty vert_props[] =
	{
		/* list of property information for a vertex */
		{"x", PLY_FLOAT, PLY_FLOAT, 0, 0, 0, 0, 0},
		{"y", PLY_FLOAT, PLY_FLOAT, 4, 0, 0, 0, 0},
		{"z", PLY_FLOAT, PLY_FLOAT, 8, 0, 0, 0, 0},
		{"red", PLY_UCHAR, PLY_UCHAR, (int)offsetof(PLYVertex, color[0]), 0, 0, 0, 0},
		{"green", PLY_UCHAR, PLY_UCHAR, (int)offsetof(PLYVertex, color[1]), 0, 0, 0, 0},
		{"blue", PLY_UCHAR, PLY_UCHAR, (int)offsetof(PLYVertex, color[2]), 0, 0, 0, 0},
	};

	PlyProperty face_props[] =
	{
		/* list of property information for a vertex */
		{"vertex_indices", PLY_INT, PLY_INT, offsetof(PLYFace, verts), 1, PLY_UCHAR, PLY_UCHAR, offsetof(PLYFace, nverts)},
	};

	// needed for parsing elements:
	char *elem_name;
	PlyProperty **plist;
	PlyOtherProp *vert_other = NULL, *face_other = NULL;
	PlyOtherElems *other_elements = NULL;
	bool has_vertex_indices = false;
	bool has_vertex_x = false, has_vertex_y = false, has_vertex_z = false, has_colors = false;

	unsigned char color_components = 0;
	unsigned char *colorBuffer;

	modelFileName = std::string(fileName);

	int nprops;
	for(int i = 0; i < nelems; i++)
	{
		// get the description of the first element (i.e. type)
		elem_name = elist[i];

		std::cout << "Element: " << i << " : " << elem_name << std::endl;

		plist = ply_get_element_description(ply, elem_name, &num_elems, &nprops);

		// this is a vertex:
		if(equal_strings("vertex", elem_name))
		{
			int j;
			for(j = 0; j < nprops; j++)
			{
				if(equal_strings("x", plist[j]->name))
				{
					ply_get_property(ply, elem_name, &vert_props[0]);   /* x */
					has_vertex_x = true;
				}
				else if(equal_strings("y", plist[j]->name))
				{
					ply_get_property(ply, elem_name, &vert_props[1]);   /* y */
					has_vertex_y = true;
				}
				else if(equal_strings("z", plist[j]->name))
				{
					ply_get_property(ply, elem_name, &vert_props[2]);   /* z */
					has_vertex_z = true;
				}
				else if(equal_strings("red", plist[j]->name))
				{
					ply_get_property(ply, elem_name, &vert_props[3]);   /* z */
					color_components++;
				}
				else if(equal_strings("green", plist[j]->name))
				{
					ply_get_property(ply, elem_name, &vert_props[4]);   /* z */
					color_components++;
				}
				else if(equal_strings("blue", plist[j]->name))
				{
					ply_get_property(ply, elem_name, &vert_props[5]);   /* z */
					color_components++;
				}
			}

			has_colors = color_components == 3;

			// test for necessary properties
			if((!has_vertex_x) || (!has_vertex_y) || (!has_vertex_z))
			{
				std::cout << "Warning: Vertex with less than 3 coordinated detected. Output will most likely be corrupt!" << std::endl;
				continue;
			}

			// grab all the vertex elements
			PLYVertex plyNewVertex;
			std::cout << "Allocating " << (num_elems * sizeof(SSEVertex)) << " bytes of storage." << std::endl;
			verlist = (SSEVertex *)_aligned_malloc(sizeof(SSEVertex) * (num_elems + 1), 16);
			nVerts = num_elems;

			// do we have vertex colors?
			if(has_colors)
			{
				colorBuffer = new unsigned char[num_elems*3];
				std::cout << "Allocating " << (num_elems * 3) << " bytes of storage for vertex colors." << std::endl;
			}

			for(j = 0; j < num_elems; j++)
			{
				ply_get_element(ply, (void *)&plyNewVertex);

				if(has_colors)
				{
					colorBuffer[curVert*3] = plyNewVertex.color[0];
					colorBuffer[curVert*3 + 1] = plyNewVertex.color[1];
					colorBuffer[curVert*3 + 2] = plyNewVertex.color[2];
				}

				verlist[curVert++] = (plyScale * Vector3(plyNewVertex.coords));

				if(j != 0 && j % 1000000 == 0)
				{
					std::cout << " - " << j << " of " << num_elems << " loaded." << std::endl;
				}
			}
		}
		// this is a face (and, hopefully, a triangle):
		else if(equal_strings("face", elem_name))
		{
			int j;
			for(j = 0; j < nprops; j++)
			{
				if(equal_strings("vertex_indices", plist[j]->name))
				{
					ply_get_property(ply, elem_name, &face_props[0]);   /* vertex_indices */
					has_vertex_indices = true;
				}
			}

			/* test for necessary properties */
			if(!has_vertex_indices)
			{
				std::cout << "Warning: Face without vertex indices detected in PLY file. Output will most likely be corrupt!" << std::endl;
				continue;
			}

			/* grab all the face elements */
			Triangle tri;
			PLYFace plyFace;
			plyFace.other_props = NULL;

			std::cout << "Allocating " << (num_elems * sizeof(Triangle)) << " bytes of storage." << std::endl;
			trilist = new Triangle[num_elems];

			for(j = 0; j < num_elems; j++)
			{
				ply_get_element(ply, (void *)&plyFace);
				if(plyFace.nverts != 3)
				{
					std::cout << "Warning: Face with more than 3 vertices detected. The importer will only read triangles, skipping..." << std::endl;
					continue;
				}

				//
				// make a triangle in our format from PLY face + vertices
				//


				// copy vertex indices
				tri.p[0] = plyFace.verts[0];
				tri.p[1] = plyFace.verts[1];
				tri.p[2] = plyFace.verts[2];

				tri.updateFromVerticesNoReorder(verlist[tri.p[0]],
					verlist[tri.p[1]],
					verlist[tri.p[2]]);

				// insert triangle into list
				trilist[nTris++] = tri;

				if(j != 0 && j % 500000 == 0)
				{
					std::cout << " - " << j << " of " << num_elems << " loaded." << std::endl;
				}
			}

		}
		else // otherwise: skip all further
			other_elements = ply_get_other_element(ply, elem_name, num_elems);
	}

	// PLY parsing ended, clean up vertex buffer and close the file
	ply_close(ply);
	fclose(plyFileStream);

	return 1;
}

int ModelInstance::loadTRI(const char* fileName, float scalarFactor)
{
	FILE *triFileStream = fopen(fileName, "rb");
	if(!triFileStream)
		return -1;

	char buffer[20];
	fscanf(triFileStream, "%s", buffer);
	assert(strcmp(buffer, "TRI") == 0);

	fscanf(triFileStream, "%d", &nVerts);
	fscanf(triFileStream, "%d", &nTris);

	float* vertices = new float[3 * nVerts];
	int* triIndex = new int[3 * nTris];

	for(unsigned int i = 0; i < 3 * nVerts; ++i)
	{
		float tmp;
		fscanf(triFileStream, "%f", &tmp);
		vertices[i] = tmp;
	}

	for(unsigned int i = 0; i < 3 * nTris; ++i)
	{
		int tmp;
		fscanf(triFileStream, "%d", &tmp);
		triIndex[i] = tmp;
	}

	modelFileName = std::string(fileName);



	verlist = (SSEVertex *)_aligned_malloc(sizeof(SSEVertex) * nVerts, 16);
	for(unsigned int i = 0; i < nVerts; i++)
	{
		verlist[i] = SSEVertex(vertices[3 * i], vertices[3 * i + 1], vertices[3 * i + 2]);
		verlist[i] *= scalarFactor;
	}

	trilist = new Triangle[nTris];
	for(unsigned int i = 0; i < nTris; i++)
	{
		Triangle tmp;
		tmp.p[0] = triIndex[3 * i];
		tmp.p[1] = triIndex[3 * i + 1];
		tmp.p[2] = triIndex[3 * i + 2];
		trilist[i] = tmp;
	}


	delete [] vertices;
	vertices = NULL;
	delete [] triIndex;
	triIndex = NULL;

	fclose(triFileStream);

	return 1;
}

int ModelInstance::loadTRI2(const char* fileName, float scalarFactor)
{
	FILE *tri2FileStream = fopen(fileName, "rb");
	if(!tri2FileStream)
		return -1;

	fscanf(tri2FileStream, "%d", &nTris);
	nVerts = 3 * nTris;

	float* vertices = new float[3 * nVerts];
	int* triIndex = new int[3 * nTris];


	for(unsigned int i = 0; i < 3 * nVerts; ++i)
	{
		float tmp;
		fscanf(tri2FileStream, "%f", &tmp);
		vertices[i] = tmp;
	}

	for(unsigned int i = 0; i < 3 * nTris; ++i)
	{
		triIndex[i] = i;
	}

	modelFileName = std::string(fileName);

	verlist = (SSEVertex *)_aligned_malloc(sizeof(SSEVertex) * nVerts, 16);
	for(unsigned int i = 0; i < nVerts; i++)
	{
		verlist[i] = SSEVertex(vertices[3 * i], vertices[3 * i + 1], vertices[3 * i + 2]);
		verlist[i] *= scalarFactor;
	}

	// copy over temporary triangle list:
	trilist = new Triangle[nTris];
	for(unsigned int i = 0; i < nTris; i++)
	{
		Triangle tmp;
		tmp.p[0] = triIndex[3 * i];
		tmp.p[1] = triIndex[3 * i + 1];
		tmp.p[2] = triIndex[3 * i + 2];
		trilist[i] = tmp;
	}

	delete [] vertices;
	vertices = NULL;
	delete [] triIndex;
	triIndex = NULL;

	fclose(tri2FileStream);

	return 1;
}

int ModelInstance::loadVRML(const char *fileName, float scalarFactor)
{
	CyberX3D::SceneGraph *sceneGraph;
	int retCode = 1;

	std::cout << "Loading VRML file " << fileName << "." << std::endl;

	// load VRML file
	char *vrmlFileName = _strdup(fileName);
	sceneGraph = new CyberX3D::SceneGraph();

	// loaded without errors ?
	if(sceneGraph->load(vrmlFileName))    // yes, get information from scene graph:
	{
		free(vrmlFileName);
		sceneGraph->initialize();
		std::cout << "parsing VRML scene graph..." << std::endl;
		traverseVRMLSceneGraph(sceneGraph, sceneGraph->getNodes(), 0);

		for(unsigned int i = 0; i < nVerts; i++)
		{
			verlist[i] *= scalarFactor;
		}
	}
	else   // no, error reading VRML file !
	{
		free(vrmlFileName);
		std::cout << "Error reading VRML file (line " << sceneGraph->getParserErrorLineNumber() << ") : " << sceneGraph->getParserErrorLineString() << std::endl;
		return -1;
	}

	return retCode;
}

void ModelInstance::traverseVRMLSceneGraph(CyberX3D::SceneGraph *sceneGraph, CyberX3D::Node *firstNode, unsigned int level)
{
	static TriangleList *tempTriList = NULL;
	static Vector3List *tempVectorList = NULL;

	if(!firstNode)
		return;

	if(tempTriList == NULL)
		tempTriList = new TriangleList;
	if(tempVectorList == NULL)
		tempVectorList = new Vector3List;

	CyberX3D::Node *node;

	// Traverse all nodes:
	for(node = firstNode; node; node = node->next())
	{
		if(node->isShapeNode())    // geometry node, read triangle information
		{

			CyberX3D::ShapeNode* shape = (CyberX3D::ShapeNode*)node;
			CyberX3D::GeometryNode* gnode = shape->getGeometry3D();
			CyberX3D::AppearanceNode* appearance = shape->getAppearanceNodes();
			float point[3];
			Triangle tri;
			Vector3 n;
			Vector3 normals[3];
			Vector2 uv[3];
			Matrix m, mRot;;

			// Transformation matrix of the following shape.
			// All coordinates (vertices and normals) need to
			// be Transformed with this so we get the proper
			// values
			shape->getTransformMatrix(m.x);
			m.transpose();

			// Generate copy of matrix without translation
			// for Transforming the normal vectors
			mRot = m;
			mRot.x[0][3] = 0;
			mRot.x[1][3] = 0;
			mRot.x[2][3] = 0;

			// Handle geometry types:
			if(gnode->isIndexedFaceSetNode())
			{
				CyberX3D::IndexedFaceSetNode *idxFaceSet = (CyberX3D::IndexedFaceSetNode *)gnode;
				int pointCount = 0;
				int coordIndex;

#define MAX_POLYGON_POINTS 12
				SSEVertex triPoints[MAX_POLYGON_POINTS];

				// Triangle coordinates
				CyberX3D::CoordinateNode *coordinateNode = idxFaceSet->getCoordinateNodes();
				if(!coordinateNode)
					continue;

				// Texture coordinates, if existing
				CyberX3D::TextureCoordinateNode *texCoordNode	= idxFaceSet->getTextureCoordinateNodes();

				// Vertex normals, if existing
				CyberX3D::NormalNode	*normalNode	= idxFaceSet->getNormalNodes();

				int nNormalIndexes = idxFaceSet->getNNormalIndexes();
				int nCoordIndexes = idxFaceSet->getNCoordIndexes();
				int nTexCoordIndexes = idxFaceSet->getNTexCoordIndexes();

				for(int nCoordIndex = 0; nCoordIndex < nCoordIndexes; nCoordIndex++)
				{
					coordIndex = idxFaceSet->getCoordIndex(nCoordIndex);

					// If index set ended *and* we have 3 points, finish off triangle
					if(coordIndex == -1)
					{
						//cout << "Creating tris from " << pointCount << " vertices." << endl;
						for(int triN = 0; triN < (pointCount - 2); triN++)  // triangulate polygon
						{
							// Finished with coordinates.

							// Calculate unit normal vector (check winding so it will
							// point the right way !)
							if(idxFaceSet->getCCW())
								n = cross(triPoints[triN + 1] - triPoints[triN + 0], triPoints[triN + 2] - triPoints[triN + 0]);
							else
								n = cross(triPoints[triN + 2] - triPoints[triN + 0], triPoints[triN + 1] - triPoints[triN + 0]);

							// Degenerate triangle, points must be collinear/identical:
							// skip this triangle
							if(n.squaredLength() == 0.0)
							{
								std::cout << "Degenerate triangle (collinear points?) detected!" << std::endl;
								pointCount = 0;
								continue;
							}

							n.makeUnitVector();

							// get triangle indices from best index combination:
							int v_offset = nVerts - 3 - ((pointCount - 3) - triN);
							tri.p[0] = v_offset;
							tri.p[1] = v_offset + 1;
							tri.p[2] = v_offset + 2;

							// insert triangle into list
							tempTriList->push_back(tri);
						}

						pointCount = 0;
					}
					else
					{
						coordinateNode->getPoint(coordIndex, point);

						if(pointCount >= MAX_POLYGON_POINTS)    // if we've got more than 3 points, ignore this
						{
							std::cout << "Surface with too many vertices detected, ignoring..." << std::endl;
							pointCount = 0;
						}

						// save point in triangle (Transformed by matrix)
						triPoints[pointCount] = SSEVertex(m * Vector3(point));
						tempVectorList->push_back(triPoints[pointCount]);
						nVerts++;

						pointCount++;
					}
				}
			}


		}
		else
			traverseVRMLSceneGraph(sceneGraph, node->getChildNodes(), level + 1);
	}

	// Traversal ended if this is the first level.
	// Now copy dynamically allocated lists to static arrays:
	//
	if(level == 0)
	{
		unsigned int i;

		// Allocate memory for tris:
		std::cout << tempVectorList->size() << " Vertices," << std::endl;
		std::cout << "Allocating " << (tempVectorList->size() * sizeof(Vector3)) << " Bytes." << std::endl;
		verlist = (SSEVertex *)_aligned_malloc(sizeof(SSEVertex) * tempVectorList->size(), 16);

		// Allocate memory for tris:
		std::cout << tempTriList->size() << " Triangles," << std::endl;
		std::cout << "Allocating " << (tempTriList->size() * sizeof(Triangle)) << " Bytes." << std::endl;
		trilist = new Triangle[tempTriList->size()];

		//
		// Copy vertices from list to static array:
		//

		for(i = 0; i < tempVectorList->size(); i++)
			verlist[i] = tempVectorList->at(i);

		//
		// Copy triangles from list to static array:
		//

		for(i = 0; i < tempTriList->size(); i++)
		{
			trilist[nTris] = tempTriList->at(i);
			nTris++;
		}

		if(NULL != tempTriList)
		{
			delete tempTriList;
			tempTriList = NULL;
		}

		if(NULL != tempVectorList)
		{
			delete tempVectorList;
			tempVectorList = NULL;
		}
	}
}


int ModelInstance::loadIV(const char* fileName, float scalarFactor)
{
	SoDB::init();
	SoInput in;

	coord3 = NULL;
	ifs = NULL;
	int coord3idx = 0;
	if(in.openFile(fileName))
	{
		SoSeparator* root = SoDB::readAll(&in);
		if(!root)
			return -1;

		coord3 = new SoCoordinate3;
		coord3->point.setNum(0);
		ifs = new SoIndexedFaceSet;
		ifs->coordIndex.setNum(0);

		SoCallbackAction triAction;
		triAction.addTriangleCallback(SoShape::getClassTypeId(), ModelInstance::triang_CB, NULL);
		triAction.apply(root);

		nTris = ifs->coordIndex.getNum() / 3;
		nVerts = coord3->point.getNum();

		verlist = (SSEVertex *)_aligned_malloc(sizeof(SSEVertex) * nVerts, 16);
		for(unsigned int i = 0; i < nVerts; i++)
		{
			verlist[i] = SSEVertex(coord3->point[i][0], coord3->point[i][1], coord3->point[i][2]);
			verlist[i] *= scalarFactor;
		}


		trilist = new Triangle[nTris];
		for(unsigned int i = 0; i < nTris; i++)
		{
			Triangle tmp;
			tmp.p[0] = ifs->coordIndex[3 * i];
			tmp.p[1] = ifs->coordIndex[3 * i + 1];
			tmp.p[2] = ifs->coordIndex[3 * i + 2];
			trilist[i] = tmp;
		}

		return 1;
	}
	return -1;
}

void ModelInstance::triang_CB(void *data,
							  SoCallbackAction *action,
							  const SoPrimitiveVertex *vertex1,
							  const SoPrimitiveVertex *vertex2,
							  const SoPrimitiveVertex *vertex3)
{
	const SbVec3f vtx[] = {vertex1->getPoint(), vertex2->getPoint(), vertex3->getPoint()};
	const SbMatrix mm = action->getModelMatrix();

	SbVec3f vx[3];
	for(int i = 0; i < 3; ++i)
		mm.multVecMatrix(vtx[i], vx[i]);

	coord3->point.setNum(coord3->point.getNum() + 3);
	coord3->point.setValues(coord3idx, 3, vx);

	int32_t indices[] = {coord3idx, coord3idx + 1, coord3idx + 2};
	coord3idx += 3;

	int oldsize = ifs->coordIndex.getNum();
	ifs->coordIndex.setNum(oldsize + 3);
	ifs->coordIndex.setValues(oldsize, 3, indices);

}



int ModelInstance::loadSTLA(const char* fileName, float scalarFactor)
{
	FILE* stlFileStream = fopen(fileName, "rb");
	if(!stlFileStream) return -1;

	modelFileName = std::string(fileName);

	char input[256];
	char token[256];
	int tex_num = 0;
	char* next;
	float r1, r2, r3, r4;
	int face_num = 0;
	int ivert;
	int count;
	float temp[3];
	float cor3[3][COR3_MAX];
	int face[10][COR3_MAX];
	int face_order[COR3_MAX];
	int cor3_num = 0;
	int icor3;
	int i;
	int dump_num = 0;
	int width;

	while(fgets(input, 256, stlFileStream))
	{
		tex_num += 1;

		for(next = input; *next != '\0' && isspace(*next); next++)
		{}

		if(*next == '\0' || *next == '#' || *next == '!' || *next == '$')
		{
			continue;
		}

		sscanf(next, "%s%n", token, &width);

		next = next + width;

		if(importer_equal_strings(token, "facet"))
		{
			// face normal, ignore
			sscanf(next, "%*s %e %e %e", &r1, &r2, &r3);

			fgets(input, 256, stlFileStream);
			tex_num += 1;

			ivert = 0;

			for(;;)
			{
				fgets(input, 256, stlFileStream);
				tex_num += 1;

				count = sscanf(input, "%*s %e %e %e", &r1, &r2, &r3);

				if(count != 3) break;

				temp[0] = r1;
				temp[1] = r2;
				temp[2] = r3;

				if(cor3_num < 1000)
				{
					icor3 = importer_rcol_find(cor3, 3, cor3_num, temp);
				}
				else
					icor3 = -1;

				if(icor3 == -1)
				{
					icor3 = cor3_num;

					if(cor3_num < COR3_MAX)
					{
						for(i = 0; i < 3; ++i)
						{
							cor3[i][cor3_num] = temp[i];
						}
					}
					cor3_num += 1;
				}
				else
				{
					dump_num += 1;
				}

				if(ivert < 10 && face_num < COR3_MAX)
				{
					face[ivert][face_num] = icor3;
				}

				ivert += 1;
			}

			fgets(input, 256, stlFileStream);
			tex_num += 1;

			if(ivert > 3)
			{
				printf("Error: triangle mesh required!\n");
				return -1;
			}


			if(face_num < COR3_MAX)
			{
				face_order[face_num] = ivert;
			}

			face_num = face_num + 1;
		}
		else if(importer_equal_strings(token, "color"))
		{
			sscanf(next, "%*s %f %f %f %f", &r1, &r2, &r3, &r4);
		}
		else if(importer_equal_strings(token, "endsolid"))
		{
		}
		else
		{
			printf("\n");
			printf("Error:not supported in stl ascii read!\n");
			return -1;
		}
	}

	nVerts = cor3_num;
	nTris = face_num;


	verlist = (SSEVertex *)_aligned_malloc(sizeof(SSEVertex) * nVerts, 16);
	for(unsigned int i = 0; i < nVerts; i++)
	{
		verlist[i] = SSEVertex(cor3[0][i], cor3[1][i], cor3[2][i]);
		verlist[i] *= scalarFactor;
	}

	// copy over temporary triangle list:
	trilist = new Triangle[nTris];
	for(unsigned int i = 0; i < nTris; i++)
	{
		Triangle tmp;
		tmp.p[0] = face[0][i];
		tmp.p[1] = face[1][i];
		tmp.p[2] = face[2][i];
		trilist[i] = tmp;
	}

	fclose(stlFileStream);

	return 1;
}


int ModelInstance::loadSTLB(const char* fileName, float scalarFactor)
{
	FILE* stlFileStream = fopen(fileName, "rb");
	if(!stlFileStream)
	{
		return -1;
	}

	modelFileName = std::string(fileName);

	short attribute = 0;
	char c;
	float cvec[3];
	int icor3;
	int i;
	int iface;
	int ivert;
	int bytes_num = 0;
	int face_num;
	float cor3[3][COR3_MAX];
	int face[3][COR3_MAX];
	int face_order[COR3_MAX];
	int cor3_num = 0;
	int dup_num = 0;

	for(i = 0; i < 80; ++i)
	{
		c = (char)fgetc(stlFileStream);
		bytes_num += 1;
	}

	face_num = importer_long_int_read(stlFileStream);
	bytes_num += 4;

	for(iface = 0; iface < face_num; ++iface)
	{
		face_order[iface] = 3;


		for(i = 0; i < 3; ++i)
		{
			importer_float_read(stlFileStream);
			bytes_num += 4;
		}

		for(ivert = 0; ivert < face_order[iface]; ivert++)
		{
			for(i = 0; i < 3; ++i)
			{
				cvec[i] = importer_float_read(stlFileStream);
				bytes_num += 4;
			}

			if(cor3_num < 1000)
			{
				icor3 = importer_rcol_find(cor3, 3, cor3_num, cvec);
			}
			else
				icor3 = -1;

			if(icor3 == -1)
			{
				icor3 = cor3_num;
				if(cor3_num < COR3_MAX)
				{
					cor3[0][cor3_num] = cvec[0];
					cor3[1][cor3_num] = cvec[1];
					cor3[2][cor3_num] = cvec[2];
				}
				cor3_num += 1;
			}
			else
				dup_num += 1;

			face[ivert][iface] = icor3;
		}

		attribute = importer_short_int_read(stlFileStream);
		bytes_num += 2;
	}


	nVerts = cor3_num;
	nTris = face_num;

	verlist = (SSEVertex *)_aligned_malloc(sizeof(SSEVertex) * nVerts, 16);
	for(unsigned int i = 0; i < nVerts; i++)
	{
		verlist[i] = SSEVertex(cor3[0][i], cor3[1][i], cor3[2][i]);
		verlist[i] *= scalarFactor;
	}

	// copy over temporary triangle list:
	trilist = new Triangle[nTris];
	for(unsigned int i = 0; i < nTris; i++)
	{
		Triangle tmp;
		tmp.p[0] = face[0][i];
		tmp.p[1] = face[1][i];
		tmp.p[2] = face[2][i];
		trilist[i] = tmp;
	}

	fclose(stlFileStream);

	return 1;
}

int ModelInstance::makeBox(float a, float b, float c)
{
	nVerts = 8;
	nTris = 12;

	if(verlist) _aligned_free(verlist);
	if(trilist) delete [] trilist;

	verlist = (SSEVertex *)_aligned_malloc(sizeof(SSEVertex) * nVerts, 16);
	trilist = new Triangle[nTris];

	verlist[0] = SSEVertex(0.5f * a, -0.5f * b, 0.5f * c);
	verlist[1] = SSEVertex(0.5f * a, 0.5f * b, 0.5f * c);
	verlist[2] = SSEVertex(-0.5f * a, 0.5f * b, 0.5f * c);
	verlist[3] = SSEVertex(-0.5f * a, -0.5f * b, 0.5f * c);
	verlist[4] = SSEVertex(0.5f * a, -0.5f * b, -0.5f * c);
	verlist[5] = SSEVertex(0.5f * a, 0.5f * b, -0.5f * c);
	verlist[6] = SSEVertex(-0.5f * a, 0.5f * b, -0.5f * c);
	verlist[7] = SSEVertex(-0.5f * a, -0.5f * b, -0.5f * c);

	trilist[0].p[0] = 0;
	trilist[0].p[1] = 4;
	trilist[0].p[2] = 1;
	trilist[1].p[0] = 1;
	trilist[1].p[1] = 4;
	trilist[1].p[2] = 5;
	trilist[2].p[0] = 2;
	trilist[2].p[1] = 6;
	trilist[2].p[2] = 3;
	trilist[3].p[0] = 3;
	trilist[3].p[1] = 6;
	trilist[3].p[2] = 7;
	trilist[4].p[0] = 3;
	trilist[4].p[1] = 0;
	trilist[4].p[2] = 2;
	trilist[5].p[0] = 2;
	trilist[5].p[1] = 0;
	trilist[5].p[2] = 1;
	trilist[6].p[0] = 6;
	trilist[6].p[1] = 5;
	trilist[6].p[2] = 7;
	trilist[7].p[0] = 7;
	trilist[7].p[1] = 5;
	trilist[7].p[2] = 4;
	trilist[8].p[0] = 1;
	trilist[8].p[1] = 5;
	trilist[8].p[2] = 2;
	trilist[9].p[0] = 2;
	trilist[9].p[1] = 5;
	trilist[9].p[2] = 6;
	trilist[10].p[0] = 3;
	trilist[10].p[1] = 7;
	trilist[10].p[2] = 0;
	trilist[11].p[0] = 0;
	trilist[11].p[1] = 7;
	trilist[11].p[2] = 4;

	return 1;

}

int ModelInstance::makeCylinder(float r, float h, int tot)
{
	float phi, phid;
	phid = MATH_PI * 2.0f / tot;
	phi = 0.0f;

	nVerts = tot * 2 + 2;
	nTris = tot * 4;

	if(verlist) _aligned_free(verlist);
	if(trilist) delete [] trilist;

	verlist = (SSEVertex *)_aligned_malloc(sizeof(SSEVertex) * nVerts, 16);
	trilist = new Triangle[nTris];

	for(int i = 0; i < tot; ++i)
	{
		verlist[i] = SSEVertex(r * cos(phi + phid * i), r * sin(phi + phid * i), h / 2.0f);
		verlist[i + tot] = SSEVertex(r * cos(phi + phid * i), r * sin(phi + phid * i), - h / 2.0f);
	}
	verlist[tot * 2] = SSEVertex(0, 0, h / 2.0f);
	verlist[tot * 2 + 1] = SSEVertex(0, 0, -h / 2.0f);

	int triid = 0;
	for(int i = 0; i < tot; ++i)
	{
		Triangle tmp;
		tmp.p[0] = tot * 2;
		tmp.p[1] = i;
		tmp.p[2] = (i == tot - 1) ? 0 : (i + 1);
		trilist[triid] = tmp;
		triid++;
	}

	for(int i = 0; i < tot; ++i)
	{
		Triangle tmp;
		tmp.p[0] = tot * 2 + 1;
		tmp.p[1] = (i == tot - 1) ? tot : (i + 1 + tot);
		tmp.p[2] = i + tot;
		trilist[triid] = tmp;
		triid++;
	}

	for(int i = 0; i < tot; ++i)
	{
		Triangle tmp;
		int a, b, c, d;
		a = i;
		b = (i == tot - 1) ? 0 : (i + 1);
		c = i + tot;
		d = (i == tot - 1) ? tot : (i + 1 + tot);

		tmp.p[0] = b;
		tmp.p[1] = a;
		tmp.p[2] = c;
		trilist[triid] = tmp;
		triid++;
		tmp.p[0] = b;
		tmp.p[1] = c;
		tmp.p[2] = d;
		trilist[triid] = tmp;
		triid++;
	}

	return 1;
}

int ModelInstance::makeSphere(float r, int seg, int ring)
{
	nVerts = 2 + ring * seg;
	nTris = seg * 2 + (ring - 1) * seg * 2;

	if(verlist) _aligned_free(verlist);
	if(trilist) delete [] trilist;

	verlist = (SSEVertex *)_aligned_malloc(sizeof(SSEVertex) * nVerts, 16);
	trilist = new Triangle[nTris];

	float phi, phid;
	phid = MATH_PI * 2.0f / seg;
	phi = 0.0f;

	float theta, thetad;
	thetad = MATH_PI * 1.0f / (ring + 1);
	theta = 0;

	for(int i = 0; i < ring; ++i)
	{
		float theta_ = theta + thetad * (i + 1);
		for(int j = 0; j < seg; ++j)
		{
			verlist[i * seg + j] = SSEVertex(r * sin(theta_) * cos(phi + j * phid), r * sin(theta_) * sin(phi + j * phid), r * cos(theta_));
		}
	}

	verlist[ring * seg] = SSEVertex(0, 0, r);
	verlist[ring * seg + 1] = SSEVertex(0, 0, -r);

	int triid = 0;
	for(int i = 0; i < ring - 1; ++i)
	{
		for(int j = 0; j < seg; ++j)
		{
			Triangle tmp;
			int a, b, c, d;
			a = i * seg + j;
			b = (j == seg - 1) ? (i * seg) : (i * seg + j + 1);
			c = (i + 1) * seg + j;
			d = (j == seg - 1) ? ((i + 1) * seg) : ((i + 1) * seg + j + 1);
			tmp.p[0] = a;
			tmp.p[1] = c;
			tmp.p[2] = b;
			trilist[triid] = tmp;
			triid++;
			tmp.p[0] = b;
			tmp.p[1] = c;
			tmp.p[2] = d;
			trilist[triid] = tmp;
			triid++;
		}
	}

	for(int j = 0; j < seg; ++j)
	{
		int a, b;
		a = j;
		b = (j == seg - 1) ? 0 : (j + 1);
		Triangle tmp;
		tmp.p[0] = ring * seg;
		tmp.p[1] = a;
		tmp.p[2] = b;
		trilist[triid] = tmp;
		triid++;

		a = (ring - 1) * seg + j;
		b = (j == seg - 1) ? (ring - 1) * seg : ((ring - 1) * seg + j + 1);
		tmp.p[0] = a;
		tmp.p[1] = ring * seg + 1;
		tmp.p[2] = b;
		trilist[triid] = tmp;
		triid++;
	}

	return 1;
}

void ModelInstance::saveOBJ(const char* fileName)
{
	FILE* objFileStream = fopen(fileName, "w");
	if(!objFileStream)
	{
		return;
	}

	for(unsigned int i = 0; i < nVerts; ++i)
	{
		fprintf(objFileStream, "v %f %f %f\n", verlist[i].x(), verlist[i].y(), verlist[i].z());
	}

	for(unsigned int i = 0; i < nTris; ++i)
	{
		fprintf(objFileStream, "f %d %d %d\n", trilist[i].p[0] + 1, trilist[i].p[1] + 1, trilist[i].p[2] + 1);
	}

	fclose(objFileStream);
}