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
 
#include <GL/glew.h>
#include <GL/glut.h>

#include <cuda_runtime.h>
#include <cutil_inline.h>
#include <cutil_gl_inline.h>
#include <cuda_gl_interop.h>

#include "cuda_bvhexports.h"
#include "cuda_bvh_constru.h"
#include "cuda_rss_constru.h"
#include "cuda_obb.h"

#include "scene.h"
#include "transform.h"
#include "cuda_vertex.h"
#include "cpu_bvh_constru.h"

#include <iostream>
#include <fstream>

Scene::Scene(std::string const& scene_file_name)
{
	std::ifstream input(scene_file_name.c_str(), std::ios::in);

	if(!input.good())
	{
		std::cout << "Could not open the scene file: " << scene_file_name << std::endl;
		return;
	}

	while(!input.eof())
	{
		std::string name;
		float x,y,z, a, b, c, s;
		input >> name >> x >> y >> z >> a >> b >> c >> s;
		//std::cout << x << y << z << a << b << c << s << std::endl;
		//std::cout << name << std::endl;
		Transform t = VecToSE3(x, y, z, a, b, c);
		ModelInstance* model = new ModelInstance;
		model->load(name.c_str(), s, t);
		m_models.push_back(model);
	}

	m_setting.use_texture_buffer = false;
	m_setting.use_gpu_bvh = false;
}



Scene::~Scene()
{
	for(std::list<ModelInstance*>::iterator it = m_models.begin(); it != m_models.end(); ++it)
		delete *it;
	m_models.clear();
}

void Scene::setup_GL_instance()
{
	int maxV, maxI;
	glGetIntegerv(GL_MAX_ELEMENTS_VERTICES, &maxV);
	glGetIntegerv(GL_MAX_ELEMENTS_INDICES, &maxI);

	std::cout << "OpenGL VBO max vertices " << maxV << " " << "max indices " << maxI << std::endl;

	for(std::list<ModelInstance*>::iterator it = m_models.begin(); it != m_models.end(); ++it)
	{
		ModelInstance* object = *it;

		VBOVertex* modelVertices = new VBOVertex[object->nVerts];
		unsigned int* modelIndices = new unsigned int[object->nTris * 3];

		for(unsigned int t = 0; t < object->nVerts; ++t)
		{
			modelVertices[t].v = object->verlist[t];
		}

		for(unsigned int t = 0; t < object->nTris; ++t)
		{
			const Triangle& tri = object->trilist[t];
			modelIndices[3 * t] = tri.p[0];
			modelIndices[3 * t + 1] = tri.p[1];
			modelIndices[3 * t + 2] = tri.p[2];
		}

		glGenBuffers(1, &object->vbo_Vertex);
		glBindBuffer(GL_ARRAY_BUFFER, object->vbo_Vertex);
		glBufferData(GL_ARRAY_BUFFER, object->nVerts * sizeof(VBOVertex), modelVertices, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		switch(glGetError())
		{
		case GL_OUT_OF_MEMORY:
			printf("out of memory\n");
		default:
			;
		}

		glGenBuffers(1, &object->vbo_TriIndex);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, object->vbo_TriIndex);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, object->nTris * 3 * sizeof(unsigned int), modelIndices, GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		delete [] modelIndices;
		modelIndices = NULL;
		delete [] modelVertices;
		modelVertices = NULL;
	}
}

bool Scene::BVHPreProcessing()
{
	bool res;
	if(m_setting.use_gpu_bvh)
		res = BVHPreProcessing_GPU();
	else
		res = BVHPreProcessing_CPU();

	return res;
}

bool Scene::BVHPostProcessing()
{
	bool res;
	if(m_setting.use_gpu_bvh)
		res = BVHPostProcessing_GPU();
	else
		res = BVHPostProcessing_CPU();
	
	return res;
}



bool Scene::BVHPreProcessing_CPU()
{
	printf("num of models: %d\n", m_models.size());

	for(std::list<ModelInstance*>::iterator it = m_models.begin(); it != m_models.end(); ++it)
	{
		ModelInstance* model = *it;
		GPUVertex* vertexPointer = NULL;
		uint3* triIdxPointer = NULL;
		CUDA_SAFE_CALL(cudaGLRegisterBufferObject(model->vbo_Vertex));
		CUDA_SAFE_CALL(cudaGLRegisterBufferObject(model->vbo_TriIndex));
		CUDA_SAFE_CALL(cudaGLMapBufferObject((void**)&vertexPointer, model->vbo_Vertex));
		CUDA_SAFE_CALL(cudaGLMapBufferObject((void**)&triIdxPointer, model->vbo_TriIndex));

		if(m_setting.use_texture_buffer)
		{
			model->vertexPointer = vertexPointer;
			model->triIdxPointer = triIdxPointer;
		}
		else
		{
			GPUVertex* global_vertexPointer = NULL;
			uint3* global_triIdxPointer = NULL;
			GPUMALLOC((void**)&global_vertexPointer, sizeof(GPUVertex) * model->nVerts);
			GPUMALLOC((void**)&global_triIdxPointer, sizeof(uint3) * model->nTris);
			GPUTOGPU(global_vertexPointer, vertexPointer, sizeof(GPUVertex) * model->nVerts);
			GPUTOGPU(global_triIdxPointer, triIdxPointer, sizeof(uint3) * model->nTris);
			model->vertexPointer = global_vertexPointer;
			model->triIdxPointer = global_triIdxPointer;

			CUDA_SAFE_CALL(cudaGLUnmapBufferObject(model->vbo_Vertex));
			CUDA_SAFE_CALL(cudaGLUnmapBufferObject(model->vbo_TriIndex));
			CUDA_SAFE_CALL(cudaGLUnregisterBufferObject(model->vbo_Vertex));
			CUDA_SAFE_CALL(cudaGLUnregisterBufferObject(model->vbo_TriIndex));
		}

		OBBNode_host* object = PQP_createOBBTree(model);
		OBBNode* d_obbTree = NULL;
		GPUMALLOC((void**)&d_obbTree, sizeof(OBBNode) * (2 * model->nTris - 1));
		OBBNode* h_obbTree = new OBBNode[2 * model->nTris - 1];
		for(int j = 0; j < 2 * model->nTris - 1; ++j)
		{
			h_obbTree[j].bbox.axis1 = object[j].bbox.axis1;
			h_obbTree[j].bbox.axis2 = object[j].bbox.axis2;
			h_obbTree[j].bbox.axis3 = object[j].bbox.axis3;
			h_obbTree[j].bbox.center = object[j].bbox.center;
			h_obbTree[j].bbox.extents = object[j].bbox.extents;
			h_obbTree[j].left = object[j].left;
			h_obbTree[j].right = object[j].right;
		}

		TOGPU(d_obbTree, h_obbTree, sizeof(OBBNode) * (2 * model->nTris - 1));
		model->obbTree = d_obbTree;

		delete [] object;
		delete [] h_obbTree;
	}

	return true;
}

bool Scene::BVHPostProcessing_CPU()
{

	for(std::list<ModelInstance*>::iterator it = m_models.begin(); it != m_models.end(); ++it)
	{
		ModelInstance* model = *it;
		if(m_setting.use_texture_buffer)
		{
			CUDA_SAFE_CALL(cudaGLUnmapBufferObject(model->vbo_Vertex));
			CUDA_SAFE_CALL(cudaGLUnmapBufferObject(model->vbo_TriIndex));
			CUDA_SAFE_CALL(cudaGLUnregisterBufferObject(model->vbo_Vertex));
			CUDA_SAFE_CALL(cudaGLUnregisterBufferObject(model->vbo_TriIndex));
		}
		else
		{
			GPUFREE(model->vertexPointer);
			GPUFREE(model->triIdxPointer);
		}
		GPUFREE(model->obbTree);
	}

	return true;
}

bool Scene::BVHPreProcessing_GPU()
{
	printf("num of models: %d\n", m_models.size());

	for(std::list<ModelInstance*>::iterator it = m_models.begin(); it != m_models.end(); ++it)
	{
		ModelInstance* model = *it;
		void* object = createBVHObject(model->vbo_Vertex, model->vbo_TriIndex, model->nTris, model->nVerts);
		buildBVHTree2(object, model->bb[0].e, model->bb[1].e);
		OBBNode* obbtree = NULL;
		double time = ((BVHConstructionState*)object)->createOBBTree(&obbtree, 0);
		printf("AABB->OBB conversion: %f ms\n", time * 1000.0f);

		((BVHConstructionState*)object)->mapGeometryBuffers();
		model->bvh_constru = object;
		model->obbTree = obbtree;

		if(m_setting.use_texture_buffer)
		{
			model->vertexPointer = ((BVHConstructionState*)object)->vertexPointer;
			model->triIdxPointer = ((BVHConstructionState*)object)->triIdxPointer;
		}
		else
		{
			GPUVertex* global_vertexPointer = NULL;
			uint3* global_triIdxPointer = NULL;
			GPUMALLOC((void**)&global_vertexPointer, sizeof(GPUVertex) * model->nVerts);
			GPUMALLOC((void**)&global_triIdxPointer, sizeof(uint3) * model->nTris);
			GPUTOGPU(global_vertexPointer, ((BVHConstructionState*)object)->vertexPointer, sizeof(GPUVertex) * model->nVerts);
			GPUTOGPU(global_triIdxPointer, ((BVHConstructionState*)object)->triIdxPointer, sizeof(uint3) * model->nTris);
			model->vertexPointer = global_vertexPointer;
			model->triIdxPointer = global_triIdxPointer;
		}
		
	}
	return true;
}

bool Scene::BVHPostProcessing_GPU()
{
	for(std::list<ModelInstance*>::iterator it = m_models.begin(); it != m_models.end(); ++it)
	{
		ModelInstance* model = *it;
		GPUFREE(model->obbTree);
		((BVHConstructionState*)model->bvh_constru)->unmapGeometryBuffers();
		deleteBVHObject(model->bvh_constru);
	}
	return true;
}

bool Scene::RSSPreProcessing()
{
	for(std::list<ModelInstance*>::iterator it  = m_models.begin(); it != m_models.end(); ++it)
	{
		ModelInstance* model = *it;
		void* object = createRSSObject(model->vbo_Vertex, model->vbo_TriIndex, model->nTris, model->nVerts);
		buildRSSTree2(object, model->bb[0].e, model->bb[1].e);
		
		((RSSConstructionState*)object)->mapGeometryBuffers();
		model->rss_constru = object;

		if(m_setting.use_texture_buffer)
		{
			model->vertexPointer = ((RSSConstructionState*)object)->vertexPointer;
			model->triIdxPointer = ((RSSConstructionState*)object)->triIdxPointer;
		}
		else
		{
			GPUVertex* global_vertexPointer = NULL;
			uint3* global_triIdxPointer = NULL;
			GPUMALLOC((void**)&global_vertexPointer, sizeof(GPUVertex) * model->nVerts);
			GPUMALLOC((void**)&global_triIdxPointer, sizeof(uint3) * model->nTris);
			GPUTOGPU(global_vertexPointer, ((RSSConstructionState*)object)->vertexPointer, sizeof(GPUVertex) * model->nVerts);
			GPUTOGPU(global_triIdxPointer, ((RSSConstructionState*)object)->triIdxPointer, sizeof(uint3) * model->nTris);
			model->vertexPointer = global_vertexPointer;
			model->triIdxPointer = global_triIdxPointer;
		}
	}
	return true;
}

bool Scene::RSSPostProcessing()
{
	for(std::list<ModelInstance*>::iterator it = m_models.begin(); it != m_models.end(); ++it)
	{
		ModelInstance* model = *it;
		((RSSConstructionState*)model->rss_constru)->unmapGeometryBuffers();
		deleteRSSObject(model->rss_constru);
	}
	return true;
}