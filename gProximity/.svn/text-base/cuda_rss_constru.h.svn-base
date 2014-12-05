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
 
#ifndef __CUDA_RSS_CONSTRU_H_
#define __CUDA_RSS_CONSTRU_H_


#include <GL/glew.h>
#include "cuda_rss.h"
#include "cuda_vertex.h"
#include "lbvh.h"


typedef struct  
{
	int* triIDs;
	BVNode* lbvh_tree;

	unsigned int nElements;
	unsigned int nVertices;
	unsigned int* zCodes;
	float2* d_AABBTexData;

	unsigned int* levelOffsetList;
	unsigned int nLevels;

	GLuint bufferVertices, bufferTriIndices;
	GPUVertex* vertexPointer;
	uint3* triIdxPointer;

	__host__ void allocate(int nTris, int nVerts);

	/// free everything that's not needed for rendering -- for one-time build
	__host__ void freeNonEssential();

	/// free everything (including built hierarchy)
	__host__ void free();

	__host__ void updateGeometry_wobb(float3 &bb_min, float3 &bb_max);
	__host__ void updateGeometry(const float3& bb_min, const float3& bb_max);

	__host__ void constructAABBsIndexed(const GPUVertex *d_Vertices, uint3 *d_TriIndices, const float3 &bb_min, const float3 &bb_max);
	
	__host__ void reorderByLevel(LBVH& lbvh);

	__host__ double build(bool trisStoredAsEdges = false, 
						  bool dumpStats = false,
						  bool freeConstructionState = true);

	/** unregister shared GL triangle data for CUDA use
	 */
	__host__ void releaseGeometryBuffers();
	
	/** register shared GL triangle data for CUDA use
	 */
	__host__ void registerGeometryBuffers();
	
	/** map shared GL triangle data to texture buffer
	 */
	__host__ void mapGeometryBuffers();
	
	/** unmap shared GL triangle data to texture buffer
	 */
	__host__ void unmapGeometryBuffers();
} RSSConstructionState;

#endif