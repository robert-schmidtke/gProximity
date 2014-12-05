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
 
#include "cuda_bvh_constru.h"
#include "cuda_defs.h"
#include "radixsort.h"
#include "cuda_timer.h"
#include "cuda_make_grid.h"
#include "split_compaction.h"
#include "split_sort.h"



#include <cuda_gl_interop.h>
#include <texture_types.h>
#include <stdio.h>

#include "bvh_kernels.h"

#define STORE_NODES(threadOffset,treeOffset, tree, buffer) do { if (threadOffset < 16) ((float *)&tree[treeOffset])[threadOffset] = ((float *)buffer)[threadOffset]; } while(0);

#define POP_QUEUE(outItem, queue, queuePtr, threadOffset) do { if (threadOffset < 10) ((int *)&outItem)[threadOffset] = ((int *)&queue[queuePtr])[threadOffset]; queuePtr--; } while(0);


texture<float2, 1, cudaReadModeElementType> g_tex_AABBs;
__constant__ int g_tex_AABBs_offset;

#define MAX_CONSTRUCTION_LEVELS 400
static ConstructionLevelStats stats[MAX_CONSTRUCTION_LEVELS];

template <int nSplitThreads>
__global__ void makeSplit(BVHConstructionState BVH, const int nActiveSplits, const int nTrisAtLeafs)
{
	__shared__ int sharedArray[6*nSplitThreads];
	
	__shared__ float splitPoint;
	__shared__ AABB nodeBB;
	
	__shared__ int bestAxis;
	__shared__ AABBSplit inSplit;
	__shared__ AABBNode outBuffer[2];
	
	const int myOffset = gridDim.x * blockIdx.y + blockIdx.x;
	if(myOffset >= nActiveSplits)
		return;
		
	int threadOffset = threadIdx.y * blockDim.x + threadIdx.x;
	
	if(threadOffset == 0)
	{
		inSplit = BVH.inputSplits[BVH.splitIndexTable[myOffset]];
	}
	CONDOREMU_SYNC(nSplitThreads > WARP_SIZE);
	
	int tsz = inSplit.right - inSplit.left + 1;	// total number of triangles
	
	//
	// Initialization: (primary thread only)
	// Reads in split information and writes it to parent node,
	// sets up the SAH sampling information.
	//
	
	if(threadOffset == 0)
	{
	
		nodeBB = BVH.tree[inSplit.myIndex].bbox;
		
		// find biggest axis
		nodeBB.bb_max.x -= nodeBB.bb_min.x;
		nodeBB.bb_max.y -= nodeBB.bb_min.y;
		nodeBB.bb_max.z -= nodeBB.bb_min.z;
		
		bestAxis = (nodeBB.bb_max.x > nodeBB.bb_max.y) ? 0 : 1;
		bestAxis = (nodeBB.bb_max.z > max(nodeBB.bb_max.x, nodeBB.bb_max.y)) ? 2 : bestAxis;
		
		// set splitpoint = object median
		if(bestAxis == 0)
			splitPoint = nodeBB.bb_min.x + 0.5f * nodeBB.bb_max.x;
		else if(bestAxis == 1)
			splitPoint = nodeBB.bb_min.y + 0.5f * nodeBB.bb_max.y;
		else
			splitPoint = nodeBB.bb_min.z + 0.5f * nodeBB.bb_max.z;
			
			
			
		// new child pointer (relative address in bytes):
		BVH.tree[inSplit.myIndex].lChild = ((inSplit.nextIndex - inSplit.myIndex) << 5) | bestAxis;
	}
	
	
	
	//
	// PART 1: sort triangle into left and right half according to
	// split axis and coordinate.
	//
	
	int numLeft = 0;						// number of primitives on left side
	
	
	int nScanTrisLeft = tsz,				// number of primitives still to process
	    inputOffsetLeft = inSplit.left,		// start offset in output triID[] to process
	    inputOffsetRight = inSplit.right;	// end offset in output triID[] to process
	    
	// make pointers to arrays we need in shared memory
	int *shared_localTriIDs = &sharedArray[0];
	int *shared_left = &sharedArray[2*nSplitThreads];
	
	while(nScanTrisLeft > 0)
	{
		splitSort_Warp<nSplitThreads>(shared_localTriIDs, shared_left, BVH.triIDs, bestAxis, splitPoint, threadOffset, nScanTrisLeft, inputOffsetLeft, inputOffsetRight, numLeft);
	}
	
	
	//
	// PART 2: (primary thread only)
	// Store results in BVH nodes and write out resulting splits
	//
	
	__syncthreads();
	
	// special case: subdivision did not work out, just go half/half
	if(numLeft == 0 || numLeft == tsz)
	{
		numLeft = tsz / 2;
	}
	
	// local shared memory for storing boxes
	float *localBoxes = (float *)sharedArray;
	
	// LEFT child: calculate BB
	int nBoxesToProcess = numLeft;
	int boxOffset = inSplit.left;
	
#include "bvh_parallelupdate.cu"
	
	storeSplit<nSplitThreads, 0>(threadOffset, myOffset, numLeft, inSplit, localBoxes, BVH.outputSplits, BVH.outputSplitMask, BVH.tree, BVH.triIDs, outBuffer, nTrisAtLeafs);
	__syncthreads();
	
	// RIGHT child: calculate BB
	nBoxesToProcess = tsz - numLeft;
	boxOffset = inSplit.left + numLeft;
	
#include "bvh_parallelupdate.cu"
	
	storeSplit<nSplitThreads, 1>(threadOffset, myOffset, numLeft, inSplit, localBoxes, BVH.outputSplits, BVH.outputSplitMask, BVH.tree, BVH.triIDs, outBuffer, nTrisAtLeafs);
	__syncthreads();
	
	STORE_NODES(threadOffset, inSplit.nextIndex, BVH.tree, outBuffer);
}


template <int nSplitThreads, int nMaxTris>
__global__ void makeSplitLocal(BVHConstructionState BVH, const unsigned int nActiveSplits, const int nTrisAtLeafs)
{
	__shared__ int sharedArray[6*nSplitThreads];
	
	__shared__ float splitPoint;
	__shared__ WorkQueueItem workItem;
	__shared__ int bestAxis;
	__shared__ AABBNode outBuffer[2];
	__shared__ int globalLeft, globalRight;
	
	// cached data from global memory:
	__shared__ float localBoundingBoxes[nMaxTris*6];
	__shared__ int localTriIDs[nMaxTris];
	__shared__ int localToGlobalTriIDs[nMaxTris];
	
	// work queue data
	__shared__ WorkQueueItem workQueue[nMaxTris];
	__shared__ int workQueueIdx;
	
	const int myOffset = gridDim.x * blockIdx.y + blockIdx.x;
	
	if(myOffset >= nActiveSplits)
		return;
		
	int threadOffset = threadIdx.y * blockDim.x + threadIdx.x;
	
	//
	// set up work queue
	//
	
	// read in initial split information
	if(threadOffset == 0)
	{
		workQueueIdx = 0;
		const AABBSplit tempSplit = BVH.smallSplits[myOffset];
		globalLeft = tempSplit.left;
		globalRight = tempSplit.right;
		
		workQueue[0].split.left = 0;
		workQueue[0].split.right = tempSplit.right - tempSplit.left;
		workQueue[0].split.myIndex = tempSplit.myIndex;
		workQueue[0].split.nextIndex = tempSplit.nextIndex;
	}
	
	// read parent node BB
	if(threadOffset < 6)
		((float *)&workQueue[0].nodeBB)[threadOffset] = ((float *) & BVH.tree[workQueue[0].split.myIndex].bbox)[threadOffset];
		
	__syncthreads();
	
	//
	// read in complete geometry information from global memory:
	//
	int startOffset = globalLeft + threadOffset;
	if(startOffset <= globalRight)
	{
		// read triangle ID
		localTriIDs[threadOffset] = threadOffset;
		const int triID = BVH.triIDs[startOffset];
		localToGlobalTriIDs[threadOffset] = triID;
		
		// read bounding box
		
		// X
		float2 box = AABB_GET_AXIS(triID, 0);
		localBoundingBoxes[0*nMaxTris + threadOffset] = box.x;
		localBoundingBoxes[3*nMaxTris + threadOffset] = box.y;
		
		// Y
		box = AABB_GET_AXIS(triID, 1);
		localBoundingBoxes[1*nMaxTris + threadOffset] = box.x;
		localBoundingBoxes[4*nMaxTris + threadOffset] = box.y;
		
		// Z
		box = AABB_GET_AXIS(triID, 2);
		localBoundingBoxes[2*nMaxTris + threadOffset] = box.x;
		localBoundingBoxes[5*nMaxTris + threadOffset] = box.y;
	}
	
	//
	// while items in local work queue:
	//
	while(workQueueIdx >= 0)
	{
	
		// pop last element from work queue
		POP_QUEUE(workItem, workQueue, workQueueIdx, threadOffset);
		
		int tsz = workItem.split.right - workItem.split.left + 1;	// total number of triangles
		
		if(tsz > 2)
		{
		
			if(threadOffset < 3)  // workItem.nodeBB.bb_max -= workItem.nodeBB.bb_min
				((float *)&workItem.nodeBB)[threadOffset + 3] -= ((float *) & workItem.nodeBB)[threadOffset];
			__syncthreads();
			
			if(threadOffset == 0)
			{
			
				//printf("[%d] Split(%d, %d):[%.2f %.2f %.2f]-[%.2f %.2f %.2f]\n", myOffset, inSplit.left, inSplit.right, nodeBB.bb_min.x, nodeBB.bb_min.y, nodeBB.bb_min.z, nodeBB.bb_max.x, nodeBB.bb_max.y, nodeBB.bb_max.z);
				bestAxis = (workItem.nodeBB.bb_max.x > workItem.nodeBB.bb_max.y) ? 0 : 1;
				bestAxis = (workItem.nodeBB.bb_max.z > max(workItem.nodeBB.bb_max.x, workItem.nodeBB.bb_max.y)) ? 2 : bestAxis;
				
				
				// set split point = box median
				if(bestAxis == 0)
					splitPoint = workItem.nodeBB.bb_min.x + 0.5f * workItem.nodeBB.bb_max.x;
				else if(bestAxis == 1)
					splitPoint = workItem.nodeBB.bb_min.y + 0.5f * workItem.nodeBB.bb_max.y;
				else
					splitPoint = workItem.nodeBB.bb_min.z + 0.5f * workItem.nodeBB.bb_max.z;
					
				// new child pointer (relative address in bytes):
				BVH.tree[workItem.split.myIndex].lChild = ((workItem.split.nextIndex - workItem.split.myIndex) << 5) | bestAxis;
			}
			__syncthreads();
			
			
			//
			// PART 1: sort triangle into left and right half according to
			// split axis and coordinate.
			//
			
			int numLeft = splitSortShared_Local(sharedArray, &localTriIDs[workItem.split.left], localBoundingBoxes, nMaxTris, bestAxis, splitPoint, threadOffset, tsz);
			
			//
			// PART 2: (primary thread only)
			// Store results in BVH nodes and write out resulting splits
			//
			
			
			if(numLeft == 0 || numLeft == tsz)
				numLeft = tsz / 2;
				
			__syncthreads();
			
			// local shared memory for storing boxes
			float *localBoxes = (float *)sharedArray;
			
			// LEFT child: calculate BB
			int nBoxesToProcess = numLeft;
			int boxOffset = workItem.split.left;
#include "bvh_parallelupdate_local.cu"
			storeSplitLocal<nSplitThreads, 0>(threadOffset, myOffset, numLeft, workItem.split, localBoxes, workQueue, workQueueIdx, localTriIDs, localToGlobalTriIDs, outBuffer[0], nTrisAtLeafs);
			
			// RIGHT child: calculate BB
			nBoxesToProcess = tsz - numLeft;
			boxOffset += numLeft;
#include "bvh_parallelupdate_local.cu"
			storeSplitLocal<nSplitThreads, 1>(threadOffset, myOffset, numLeft, workItem.split, localBoxes, workQueue, workQueueIdx, localTriIDs, localToGlobalTriIDs, outBuffer[1], nTrisAtLeafs);
			
			// save the two nodes off to global tree
			STORE_NODES(threadOffset, workItem.split.nextIndex, BVH.tree, outBuffer);
		}
		else
		{
			if(threadOffset < 2)
			{
				//
				// only two primitives in this split:
				// do not even run the full routine for finding a split, just sort them right here
				// and make them leaves right away. run for both children in parallel on two threads.
				//
				
				// new child pointer (relative address in bytes):
				if(threadOffset == 0)
					BVH.tree[workItem.split.myIndex].lChild = ((workItem.split.nextIndex - workItem.split.myIndex) << 5);
					
				const int index = workItem.split.left + threadOffset;
				const int triID = localTriIDs[index];
				
				// get bounds for this triangle
				outBuffer[threadOffset].bbox.bb_min.x = localBoundingBoxes[triID];
				outBuffer[threadOffset].bbox.bb_min.y = localBoundingBoxes[triID +   nMaxTris];
				outBuffer[threadOffset].bbox.bb_min.z = localBoundingBoxes[triID + 2*nMaxTris];
				outBuffer[threadOffset].bbox.bb_max.x = localBoundingBoxes[triID + 3*nMaxTris];
				outBuffer[threadOffset].bbox.bb_max.y = localBoundingBoxes[triID + 4*nMaxTris];
				outBuffer[threadOffset].bbox.bb_max.z = localBoundingBoxes[triID + 5*nMaxTris];
				
				// make leaf:
				if(nTrisAtLeafs == 0)    // one tri/leaf: store triID
				{
					outBuffer[threadOffset].leafTriID = (localToGlobalTriIDs[triID] << 2) | 3;
				}
				else   // version w/ multiple primitives per leaf: store index range
				{
					outBuffer[threadOffset].leafTriID = ((globalLeft + index) << 2) | 3;
					outBuffer[threadOffset].right = (globalLeft + index);
				}
			}
			__syncthreads();
			
			// save the two nodes off to global tree
			STORE_NODES(threadOffset, workItem.split.nextIndex, BVH.tree, outBuffer);
		}
		
		// end of work queue loop, sync for loop condition test
		__syncthreads();
	}
	
	//
	// done with construction, write back modified index list
	//
	
	if(nTrisAtLeafs > 0)
	{
		int startOffset = globalLeft + threadOffset;
		int endOffset = globalRight;
		int localOffset = threadOffset;
		
		while(startOffset <= endOffset)
		{
			BVH.triIDs[startOffset] = localToGlobalTriIDs[localTriIDs[localOffset]];
			
			localOffset += nSplitThreads;
			startOffset += nSplitThreads;
		}
	}
}


__host__ void BVHConstructionState::registerGeometryBuffers()
{
	// register shared GL triangle data for CUDA use
	CUDA_SAFE_CALL(cudaGLRegisterBufferObject(bufferVertices));
	CUDA_SAFE_CALL(cudaGLRegisterBufferObject(bufferTriIndices));
}

__host__ void BVHConstructionState::releaseGeometryBuffers()
{
	// unregister shared GL triangle data for CUDA use
	CUDA_SAFE_CALL(cudaGLUnregisterBufferObject(bufferVertices));
	CUDA_SAFE_CALL(cudaGLUnregisterBufferObject(bufferTriIndices));
}

__host__ void BVHConstructionState::allocate(int nTris, int nVerts, int nTrisAtLeaf)
{
	nElements = nTris;
	nVertices = nVerts;
	
	// allocate memory for triangle IDs
	GPUMALLOC((void**) &triIDs, sizeof(int) * nElements);
	GPUMALLOC((void**) &outTriIDs, sizeof(int) * nElements);
	
	// try some less conservative memory allocation if we allow more than 1 primitive per leaf
	int nMemoryElements = nElements;
#ifdef GPLANNER_DEBUG
	printf("allocating %i nodes in tree\n", (2 * nMemoryElements - 1));
#endif
	
	GPUMALLOC((void**) &tree, sizeof(AABBNode) *(2 * nMemoryElements - 1)); // this is very conservative
	
	// for construction
	GPUMALLOC((void**) &inputSplits,     sizeof(AABBSplit) * nMemoryElements);
	GPUMALLOC((void**) &outputSplits,    sizeof(AABBSplit) * nMemoryElements);
	GPUMALLOC((void**) &outputSplitMask, nMemoryElements * sizeof(int));
	GPUMALLOC((void**) &splitIndexTable, nMemoryElements * sizeof(int));
	
	GPUMALLOC((void**) &smallSplits,  sizeof(AABBSplit) * nMemoryElements);
	GPUMALLOC((void**) &nSmallSplits,  sizeof(unsigned int));
	
	// for stats from compaction (active splits, avg. split size)
	GPUMALLOC((void**) &splitStats, sizeof(SplitListStats));
	GPUMEMSET(splitStats, 0, sizeof(SplitListStats));
	
	// AABBs
	GPUMALLOC((void **)&d_AABBTexData, nElements * 3 * sizeof(float2));
	
	zCodes = NULL;
	
	levelOffsetList = NULL;
	nLevels = 0;
	vertexPointer = NULL;
	triIdxPointer = NULL;
}


// free everything that's not needed for rendering -- for one-time build
__host__ void BVHConstructionState::freeNonEssential()
{
	if(outTriIDs)
	{
		GPUFREE(outTriIDs);
	}
	
	if(inputSplits)
	{
		GPUFREE(inputSplits);
	}
	
	if(outputSplits)
	{
		GPUFREE(outputSplits);
	}
	
	if(outputSplitMask)
	{
		GPUFREE(outputSplitMask);
	}
	
	if(splitIndexTable)
	{
		GPUFREE(splitIndexTable);
	}
	
	if(smallSplits)
	{
		GPUFREE(smallSplits);
	}
	
	if(nSmallSplits)
	{
		GPUFREE(nSmallSplits);
	}
	
	if(splitStats)
	{
		GPUFREE(splitStats);
	}
	
	if(d_AABBTexData)
	{
		CUDA_SAFE_CALL(cudaUnbindTexture(g_tex_AABBs));
		GPUFREE(d_AABBTexData);
	}
}


__host__ void BVHConstructionState::updateGeometry_wobb(float3 &bb_min, float3 &bb_max)
{
	static int triIndexListInitialized = 0;
	
	if(!triIndexListInitialized)
	{
		triIndexListInitialized = 1;
	}
	
	// map VBOs to CUDA addresses
	GPUVertex *d_GL_vertices = NULL;
	uint3 *d_GL_triIndices = NULL;
	
	CUDA_SAFE_CALL(cudaGLMapBufferObject((void**)&d_GL_vertices, bufferVertices));
	CUDA_SAFE_CALL(cudaGLMapBufferObject((void**)&d_GL_triIndices, bufferTriIndices));
	
	
	float* v = NULL;
	GPUMALLOC((void**)&v, sizeof(float) * nVertices);
	int nBlocks = (int)ceilf(nVertices / (float)AABB_BOUNDINGBOX_THREADS);
	dim3 grid(nBlocks, 1, 1);
	dim3 threads(AABB_BOUNDINGBOX_THREADS, 1, 1);
	
	float tmp;
	nvRadixSort::RadixSort radixSort(nVertices, true);
	
	copyGPUVertex <<< grid, threads>>>(d_GL_vertices, v, nVertices, nVertices, true, 0);
	radixSort.sort(v, NULL, nVertices, 32, true);
	FROMGPU(&tmp, v, sizeof(float));
	bb_min.x = tmp;
	FROMGPU(&tmp, v + nVertices - 1, sizeof(float));
	bb_max.x = tmp;
	
	copyGPUVertex <<< grid, threads>>>(d_GL_vertices, v, nVertices, nVertices, true, 1);
	radixSort.sort(v, NULL, nVertices, 32, true);
	FROMGPU(&tmp, v, sizeof(float));
	bb_min.y = tmp;
	FROMGPU(&tmp, v + nVertices - 1, sizeof(float));
	bb_max.y = tmp;
	
	copyGPUVertex <<< grid, threads>>>(d_GL_vertices, v, nVertices, nVertices, true, 2);
	radixSort.sort(v, NULL, nVertices, 32, true);
	FROMGPU(&tmp, v, sizeof(float));
	bb_min.z = tmp;
	FROMGPU(&tmp, v + nVertices - 1, sizeof(float));
	bb_max.z = tmp;
	
	
	GPUFREE(v);
	
	
	// construct AABBs from triangles and store in texture
	constructAABBsIndexed(d_GL_vertices, d_GL_triIndices, bb_min, bb_max);
	
	CUDA_SAFE_CALL(cudaGLUnmapBufferObject(bufferVertices));
	CUDA_SAFE_CALL(cudaGLUnmapBufferObject(bufferTriIndices));
	
	initSplitLists(bb_min, bb_max);
}

__host__ void BVHConstructionState::updateGeometry(const float3 &bb_min, const float3 &bb_max)
{
	static int triIndexListInitialized = 0;
	
	if(!triIndexListInitialized)
	{
		triIndexListInitialized = 1;
	}
	
	// map VBOs to CUDA addresses
	GPUVertex *d_GL_vertices = NULL;
	uint3 *d_GL_triIndices = NULL;
	
	CUDA_SAFE_CALL(cudaGLMapBufferObject((void**)&d_GL_vertices, bufferVertices));
	CUDA_SAFE_CALL(cudaGLMapBufferObject((void**)&d_GL_triIndices, bufferTriIndices));
	
	// construct AABBs from triangles and store in texture
	constructAABBsIndexed(d_GL_vertices, d_GL_triIndices, bb_min, bb_max);
	
	CUDA_SAFE_CALL(cudaGLUnmapBufferObject(bufferVertices));
	CUDA_SAFE_CALL(cudaGLUnmapBufferObject(bufferTriIndices));
	
	initSplitLists(bb_min, bb_max);
}

__host__ void BVHConstructionState::constructAABBsIndexed(const GPUVertex *d_Vertices, uint3 *d_TriIndices, const float3 &bb_min, const float3 &bb_max)
{
	int nBlocks = (int)ceilf(nElements / (float)AABB_BLOCK_SIZE);
	
	// calculate dimensions for storing all AABBs in a single 2-D texture
	int tex_width = nElements * 3;
	int tex_offset = nElements;
	
	CUDA_SAFE_CALL(cudaMemcpyToSymbol(g_tex_AABBs_offset, &tex_offset, sizeof(int)));
	
	dim3 grid(nBlocks, 1, 1);
	dim3 threads(AABB_BLOCK_SIZE, 1, 1);
	
	// execute kernel for generating the AABBs from triangles
	generateAABBsIndexed <<< nBlocks, AABB_BLOCK_SIZE  >>>(d_AABBTexData, triIDs, d_Vertices, d_TriIndices, zCodes, nElements, tex_offset, bb_min, bb_max);
	
	cudaThreadSynchronize();
	
	
	// check if kernel execution generated an error
	CUT_CHECK_ERROR("AABB generation kernel execution failed");
	
	// allocate CUDA array for storing AABBs
	cudaChannelFormatDesc channelDesc = cudaCreateChannelDesc(32, 32, 0, 0, cudaChannelFormatKindFloat);
	
	// set up texture
	g_tex_AABBs.filterMode = cudaFilterModePoint;
	g_tex_AABBs.normalized = false;
	g_tex_AABBs.channelDesc = channelDesc;
	CUDA_SAFE_CALL(cudaBindTexture(NULL, &g_tex_AABBs, d_AABBTexData, &channelDesc, tex_width * sizeof(float2)));
}



__host__ void BVHConstructionState::initSplitLists(const float3 &bb_min, const float3 &bb_max)
{
	// initialize first split:
	AABBSplit h_intervalBuffer;
	h_intervalBuffer.left = 0;
	h_intervalBuffer.right = nElements - 1;
	h_intervalBuffer.myIndex = 0;
	h_intervalBuffer.nextIndex = 1;
	
	// copy initial interval list to device
	CUDA_SAFE_CALL(cudaMemcpy(inputSplits, &h_intervalBuffer, sizeof(AABBSplit), cudaMemcpyHostToDevice));
	GPUMEMSET(splitIndexTable, 0, 4);
	
	// initialize root BVH node
	AABBNode root;
	root.left = 0;
	root.right = nElements;
	root.bbox.bb_min = bb_min;
	root.bbox.bb_max = bb_max;
	
	// copy root node to device
	CUDA_SAFE_CALL(cudaMemcpy(tree, &root, sizeof(AABBNode), cudaMemcpyHostToDevice));
}

__host__ void BVHConstructionState::switchSplitLists()
{
	AABBSplit *temp = outputSplits;
	outputSplits = inputSplits;
	inputSplits = temp;
}

__host__ void BVHConstructionState::free()
{
	freeNonEssential();
	if(tree)
	{
		GPUFREE(tree);
	}
	if(triIDs)
	{
		GPUFREE(triIDs);
	}
	if(levelOffsetList)
	{
		::free(levelOffsetList);
		levelOffsetList = 0;
	}
}

__host__ double BVHConstructionState::build(const float3 &bb_min, const float3 &bb_max,
		int nTrisPerLeaf,
        bool dumpStats,
        bool freeConstructionState)
{
	SplitListStats splitStats;
	splitStats.nActiveSplits = 1;
	splitStats.avgSplitSize = (float)nElements;
	splitStats.nSmallSplits = 0;
	
	CUDA_SAFE_CALL(cudaMemcpy(this->splitStats, &splitStats, sizeof(SplitListStats), cudaMemcpyHostToDevice)); // copy over new number of active splits
	
	TimerValue timerConstruction, timerSplit, timerCompact;
	timerConstruction.start();
	int nRuns = 0;
	
	// do splits:
	// run the construction level-by-level
	while(splitStats.nActiveSplits > 0)
	{
		// run one block for every active split
		dim3 grid = makeGrid(splitStats.nActiveSplits);
		// call the split kernel on this:
		dim3 threads(SPLIT_THREADS, NSPLIT_AXES, 1);
		
		timerSplit.start();
		makeSplit<SPLIT_THREADS> <<< grid, threads >>>(*this, splitStats.nActiveSplits, nTrisPerLeaf);
		timerSplit.stop();
		
		stats[nRuns].timeBucketMs = 0.0f;
		stats[nRuns].nActiveSplits = splitStats.nActiveSplits;
		stats[nRuns].timeSplitMs = (float)timerSplit.getElapsedMs();
		
#ifdef GPLANNER_DEBUG
		checkBVHSanity(triIDs, nElements, false);
#endif
		
		// run compaction step:
		dim3 gridCompact(1, 1, 1);
		dim3 gridThreads(SPLITLIST_COMPACTION_THREADS, 1, 1);
		timerCompact.start();
		
		compactSplitList_Small<SPLITLIST_COMPACTION_THREADS> <<< gridCompact, gridThreads >>>(this->splitIndexTable, this->outputSplits, this->smallSplits, this->outputSplitMask, this->splitStats, splitStats.nActiveSplits * 2);
		
		CUDA_SAFE_CALL(cudaMemcpy(&splitStats, this->splitStats, sizeof(SplitListStats), cudaMemcpyDeviceToHost)); // copy over new number of active splits
		timerCompact.stop();
		stats[nRuns].timeCompactMs = (float)timerCompact.getElapsedMs();
		
		switchSplitLists();	// make output split list the input split list
		nRuns++;
	}
	
	
	// now construct all the small splits with the special kernel:
	if(splitStats.nSmallSplits)
	{
		// run one block for every active split
		dim3 grid = makeGrid(splitStats.nSmallSplits);
		
		// call the split kernel on this:
		dim3 threads(WARP_SIZE, 1, 1);
		
		timerSplit.start();
		makeSplitLocal<WARP_SIZE, 32> <<< grid, threads >>>(*this, splitStats.nSmallSplits, nTrisPerLeaf);
		timerSplit.stop();
		
#ifdef GPLANNER_DEBUG
		checkBVHSanity(triIDs, nElements, false);
#endif
		
		stats[nRuns].nActiveSplits = splitStats.nSmallSplits;
		stats[nRuns].timeSplitMs = (float)timerSplit.getElapsedMs();
		stats[nRuns].timeCompactMs = 0;
		nRuns++;
	}
	
	
	timerConstruction.stop();
	
	if(dumpStats)    // dump stats to CSV file?
	{
		int sumActiveSplits = 0, maxActiveSplits = 0;
		double allTimeCompact = 0.0f, allTimeSplit = 0.0f;
		for(int i = 0; i < nRuns; i++)
		{
			sumActiveSplits += stats[i].nActiveSplits;
			maxActiveSplits = max(maxActiveSplits, stats[i].nActiveSplits);
			allTimeCompact += stats[i].timeCompactMs;
			allTimeSplit   += stats[i].timeSplitMs;
		}
		
		// print out debug construction stats:
#ifdef GPLANNER_DEBUG
		printf("Construction stats (tris/leaf: %d):\n", nTrisPerLeaf);
		printf(" - %d total splits over %d runs (%.2f avg.)\n", sumActiveSplits, nRuns, sumActiveSplits / (float)nRuns);
		printf(" - %d max. active splits in run\n", maxActiveSplits);
		
		printf(" - Time in split:      %.2f ms\n", allTimeSplit);
		printf(" - Time in compaction: %.2f ms\n", allTimeCompact);
		printf(" - Time overall:       %.2f ms\n", timerConstruction.getElapsedMs());
#endif
		
		FILE *statsFile = fopen("construction_stats.csv", "w");
		if(statsFile)
		{
			for(int i = 0; i < nRuns; i++)
			{
				fprintf(statsFile, "%f;%f;%d;%f\r\n", stats[i].timeSplitMs, stats[i].timeCompactMs, stats[i].nActiveSplits, stats[i].timeBucketMs);
			}
			fclose(statsFile);
		}
	}
	
	if(freeConstructionState)
		freeNonEssential();
		
	return timerConstruction.getElapsed();
}

__host__ void BVHConstructionState::mapGeometryBuffers()
{
	if(vertexPointer == NULL)
	{
		CUDA_SAFE_CALL(cudaGLMapBufferObject((void**)&vertexPointer, bufferVertices));
	}
	if(triIdxPointer == NULL)
	{
		CUDA_SAFE_CALL(cudaGLMapBufferObject((void**)&triIdxPointer, bufferTriIndices));
	}
}

__host__ void BVHConstructionState::unmapGeometryBuffers()
{
	if(vertexPointer)
	{
		CUDA_SAFE_CALL(cudaGLUnmapBufferObject(bufferVertices));
		vertexPointer = NULL;
	}
	if(triIdxPointer)
	{
		CUDA_SAFE_CALL(cudaGLUnmapBufferObject(bufferTriIndices));
		triIdxPointer = NULL;
	}
}



__host__ void BVHConstructionState::reorderByLevel()
{
	// temporary list of offsets (new offset for each level--each node's offset can be computed
	// according to its position within the level)
	unsigned int offsetList[200];
	AABBNode *treeIn, *treeOut;
	
	// allocate trees
#ifdef GPLANNER_DEBUG
	printf("Reordering tree by level...\n");
#endif
	treeIn = (AABBNode *)malloc(sizeof(AABBNode) * (2 * nElements - 1));
	treeOut = (AABBNode *)malloc(sizeof(AABBNode) * (2 * nElements - 1));
	
	// read back tree from GPU
	cudaMemcpy(treeIn, tree, sizeof(AABBNode)*(2 * nElements - 1), cudaMemcpyDeviceToHost);
	
	uint2 *nodeList[2];
	unsigned int listSize[2];
	
	// in nodelist and out nodelist interchange after one iteration:
	// in each iteration, the children of nodes in in nodelist are added in out nodelist
	nodeList[0] = (uint2 *)malloc(sizeof(uint2) * nElements);
	nodeList[1] = (uint2 *)malloc(sizeof(uint2) * nElements);
	nodeList[0][0] = make_uint2(0, 0); // init with root node
	listSize[0] = 1;
	nLevels = 0;
	
	// reorder nodes: the new nodes will be arranged from top to down, from left to right
	unsigned int listIn = 0, listOut = 1;
	unsigned int curOffset = 0;
	offsetList[0] = 0;
	while(listSize[listIn])
	{
		nLevels++;
		unsigned int childOffset = curOffset + listSize[listIn];
		offsetList[nLevels] = childOffset;			              // new offset for each level (the children of previous level)
		listSize[listOut] = 0;
		
		// for each node in this level
		for(unsigned int i = 0; i < listSize[listIn]; i++)
		{
			int offset = nodeList[listIn][i].x;					// offset in the old order
			AABBNode node = treeIn[offset];						// get node
			
			node.right = nodeList[listIn][i].y;					// parent
			
			if(!AABB_ISLEAF(node))
			{
				// push back children for next level (the offset and parent are both in old order, because we
				// need to fetch in the old list)
				nodeList[listOut][listSize[listOut]++] = make_uint2(offset + (node.left >> 5), offset);
				nodeList[listOut][listSize[listOut]++] = make_uint2(offset + (node.left >> 5) + 1, offset);
				
				// modify child pointer (children pointer in new order)
				node.left = (childOffset - curOffset) << 5;
				childOffset += 2; // each node has two children
			}
			treeOut[curOffset++] = node; // write node to new tree
		}
		
		listIn = 1 - listIn;
		listOut = 1 - listOut;
	}
	
	// copy offset list to GPU
	if(levelOffsetList == 0)
		levelOffsetList = (unsigned int *)malloc((nLevels + 1) * sizeof(unsigned int));
	memcpy(levelOffsetList, offsetList, (nLevels + 1)*sizeof(unsigned int));
	
	// copy new tree to GPU
	cudaMemcpy(tree, treeOut, sizeof(AABBNode)*(2 * nElements - 1), cudaMemcpyHostToDevice);
	
#ifdef GPLANNER_DEBUG
	printf("Done. %d levels in tree.\n", nLevels);
#endif
	
	::free(treeIn);
	::free(treeOut);
	::free(nodeList[0]);
	::free(nodeList[1]);
}

__host__ double BVHConstructionState::createOBBTree(OBBNode **outTree, int nVerts)
{
	if(nLevels == 0)
		reorderByLevel();
		
	// allocate memory for OBB tree
	if(*outTree)
		cudaFree(*outTree);
	cudaMalloc((void **)outTree, sizeof(OBBNode)*(nElements * 2 - 1));
	
	mapGeometryBuffers();
	
	// work all levels bottom up
	TimerValue updateTime;
	updateTime.start();
	for(int l = nLevels - 1; l >= 0; l--)
	{
		// number of nodes to process in this level
		int nNodesThisLevel = levelOffsetList[l+1] - levelOffsetList[l];
		
#define CONVERT_THREADS 64
		int nBlocks = (int)ceil(nNodesThisLevel / (float)CONVERT_THREADS);
		
		// call update kernel
		AABBtoOBBbyLevel <<< nBlocks, CONVERT_THREADS >>>(tree, *outTree, levelOffsetList[l], nNodesThisLevel, vertexPointer, triIdxPointer, nVerts);
		CUT_CHECK_ERROR("AABBtoOBBbyLevel");
	}
	
	updateTime.stop();
	
	unmapGeometryBuffers();
	
	return updateTime.getElapsed();
}


void checkBVHSanity(int *indexlist, int g_nTris, bool printList)
{
	printf("######### SANITY CHECK ###############\n");
	bool hasError = false;
	
	int *ids = (int *)malloc(sizeof(int) * g_nTris);
	int *id_hist = (int *)malloc(sizeof(int) * g_nTris);
	
	memset(id_hist, 0, sizeof(int)*g_nTris);
	
	CUDA_SAFE_CALL(cudaMemcpy(ids, indexlist, g_nTris * sizeof(int), cudaMemcpyDeviceToHost));
	
	if(printList)
		printf("[ ");
		
	for(int i = 0; i < g_nTris; i++)
	{
		if(printList)
			printf("%d ", ids[i]);
		if(ids[i] < 0 || ids[i] >= g_nTris)
		{
			printf("Error: invalid ID %d referenced at idx %d!\n", ids[i], i);
			hasError = true;
		}
		else
			id_hist[ids[i]]++;
	}
	
	if(printList)
		printf("]\n");
		
	for(int i = 0; i < g_nTris; i++)
	{
		if(id_hist[i] == 0)
		{
			printf("Error: ID %d not referenced!\n", i);
			hasError = true;
		}
		else if(id_hist[i] > 1)
		{
			printf("Error: ID %d referenced %d times!\n", i, id_hist[i]);
			hasError = true;
		}
	}
	
	free(ids);
	free(id_hist);
	if(hasError)
		getchar();
}



