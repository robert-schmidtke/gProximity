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
 
#ifndef __CUDA_BVH_CONSTRU_H_
#define __CUDA_BVH_CONSTRU_H_

#include <GL/glew.h>
#include "cuda_aabbsplit.h"
#include "cuda_aabbnode.h"
#include "cuda_obb.h"
#include "cuda_vertex.h"
#include "lbvh.h"
#include "cuda_defs.h"

/** Check the validness of BVH constructed
 * @param indexlist Index list for BVH
 * @param g_nTris Number of triangles (leaf nodes) in BVH
 * @param printList Switch for printing
 */
void checkBVHSanity(int *indexlist, int g_nTris, bool printList);

/** struct for construction of GPU AABB and OBB
 */
typedef struct
{
	/// work queue stuff: compaction based
	int* splitIndexTable;		///< offset map from blockID -> offset in input split table
	AABBSplit* inputSplits;		///< input split array
	AABBSplit* outputSplits;	///< output array for new splits
	int* outputSplitMask;		///< active/inactive array for new splits
	
	AABBSplit* smallSplits;		///< output array for small splits
	unsigned int* nSmallSplits; ///< internal counter for small splits
	
	
	/// geometry information
	int* triIDs;					///< current read buffer for tri indices
	int* outTriIDs;					///< current write buffer for tri indices
	AABBNode* tree;					///< output tree structure
	float2* d_AABBTexData;			///< AABB data
	unsigned int* levelOffsetList;	///< offsets for first node for each level of the tree
	unsigned int nLevels;			///< number of levels
	
	/// construction stats and info
	unsigned int nElements;		///< number of total geometry elements
	SplitListStats* splitStats; ///< temporary split information
	unsigned int nVertices;
	
	/// for z-code grid build:
	unsigned int* zCodes;       ///< Z-code
	
	GLuint bufferVertices, bufferTriIndices;	///< OpenGL buffers for geometric objects
	
	GPUVertex* vertexPointer;					///< pointer to geometry vertices
	uint3* triIdxPointer;						///< pointer to triangle indices
	
	__host__ void switchSplitLists();
	
	__host__ void updateGeometry_wobb(float3 &bb_min, float3 &bb_max);
	__host__ void updateGeometry(const float3 &bb_min, const float3 &bb_max);
	
	/** allocate memory for build
	 * @param nTris Number of triangles in the geometry
	 * @param nTrisAtLeaf Number of triangles in the left node
	 */
	__host__ void allocate(int nTris, int nVerts, int nTrisAtLeaf = 0);
	
	/// free everything that's not needed for rendering -- for one-time build
	__host__ void freeNonEssential();
	
	/// free everything (including built hierarchy)
	__host__ void free();
	
	/// construct AABB for each triangle
	__host__ void constructAABBsIndexed(const GPUVertex* vertices, uint3* triangles, const float3 &bb_min, const float3 &bb_max);
	
	__host__ void initSplitLists(const float3 &bb_min, const float3 &bb_max);
	
	
	/** build BVH tree
	 * @param bb_min Bounding box lower bound
	 * @param bb_max Bounding box upper bound
	 * @param dumpStats Dump status to file afterwards?
	 * @param freeConstructionState Free construction state afterwards? (if one-time build)
	 */
	__host__ double build(const float3 &bb_min, const float3 &bb_max,
						  int nTrisPerLeaf,
	                      bool dumpStats,
	                      bool freeConstructionState);
	                      
	/** reorder AABB tree to the top-down, left-right order
	 */
	__host__ void reorderByLevel();
	
	
	/** create OBB from AABB
	 * @param outTree OBB tree
	 * @param nVerts Number of vertices
	 */
	__host__ double createOBBTree(OBBNode **outTree, int nVerts);
	
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
	
} BVHConstructionState;



#endif