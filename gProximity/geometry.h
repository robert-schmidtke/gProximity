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
 
#ifndef __GEOMETRY_H_
#define __GEOMETRY_H_

#include "Vector3.h"
#include "Triangle.h"

typedef Triangle* SceneTriangleList;
typedef SSEVertex* SceneVertexList;
typedef Vector3* VertexNormalList;

namespace CyberX3D
{
	class SceneGraph;
	class Node;
}

class SoCallbackAction;
class SoPrimitiveVertex;
class SoCoordinate3;
class SoIndexedFaceSet;
class Transform;

class ModelInstance
{
public:
	SceneTriangleList trilist;
	SceneVertexList verlist;

	unsigned int nVerts;
	unsigned int nTris;

	Vector3 bb[2]; // axis-aligned bounding box

	bool isInstanced;
	bool boundingBoxGenerated;
	std::string modelFileName;

	void* bvh_constru;
	void* rss_constru;
	void* obbTree; // pointer to obbtree (on device)
	void* vertexPointer;
	void* triIdxPointer;

	unsigned int vbo_Vertex, vbo_TriIndex; // for OPENGL interoperability

	ModelInstance();

	~ModelInstance();

	void destroy();

	void calculateAABoundingBox();

	int load(const char* fileName, float scalarFactor);

	int load(const char* fileName, float scalarFactor, Transform const& t);

	int loadOBJ(const char* fileName, float scalarFactor);

	int loadPLY(const char* fileName, float scalarFactor);

	int loadTRI(const char* fileName, float scalarFactor);

	int loadTRI2(const char* fileName, float scalarFactor);

	int loadVRML(const char *fileName, float scalarFactor);

	int loadIV(const char* fileName, float scalarFactor);

	int loadSTLA(const char* fileName, float scalarFactor);

	int loadSTLB(const char* fileName, float scalarFactor);

	int makeBox(float a, float b, float c);
	int makeCylinder(float r, float h, int tot = 32);
	int makeSphere(float r, int seg = 32, int ring = 32);

	void saveOBJ(const char* fileName);

private:
	static void triang_CB(void* data,
		SoCallbackAction* action,
		const SoPrimitiveVertex* vertex1,
		const SoPrimitiveVertex* vertex2,
		const SoPrimitiveVertex* vertex3);

	void traverseVRMLSceneGraph(CyberX3D::SceneGraph *sceneGraph, CyberX3D::Node *firstNode, unsigned int level);

	static SoCoordinate3* coord3;
	static SoIndexedFaceSet* ifs;
	static int coord3idx;
};


#endif