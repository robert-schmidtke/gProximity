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
 
#ifndef __CUDA_INTERSECT_TREE_H_
#define __CUDA_INTERSECT_TREE_H_

#include "cuda_prefix.h"
#include "cuda_defs.h"
#include "cuda_intersect_nodes.h"
#include "cuda_intersect_tritri.h"

template <int nTotalProcessors>
static __device__ __inline__ void callAbort(unsigned int *workQueueCounter, const int threadID)
{
	if(threadID == 0)
		atomicInc(workQueueCounter, nTotalProcessors);
}


// nWorkQueueInitItems should be smaller than workQueueCapacity, e.g. 1/2 workQueueCapacity
// CollisionTag: set the tag for collision. (for milestone 0, for ccd -1)
template <class TreeNode, class BV, int workQueueCapacity, int nWorkQueueInitItems, int nThreads>
__global__ void traverseTree(const TreeNode* tree_object1, const GPUVertex* vertex_object1, const uint3* tri_object1,
							 const TreeNode* tree_object2, const GPUVertex* vertex_object2, const uint3* tri_object2,
							 int2* workQueues, unsigned int* workQueueCounts, unsigned int* idleCount, const unsigned int globalWorkQueueCapacity,
							 int2* outputList, unsigned int* outputListIdx)
{
	__shared__ int workQueueIdx;
	__shared__ int globalWorkQueueIdx;
	__shared__ int2 localWorkQueue[workQueueCapacity];
	__shared__ unsigned int wantToAbort;

	const int blockOffset = gridDim.x * blockIdx.y + blockIdx.x;
	const int threadOffset = threadIdx.x;

	// read local counter
	if(threadOffset == 0)
	{
		globalWorkQueueIdx = workQueueCounts[blockOffset];
		workQueueIdx = min(nWorkQueueInitItems, globalWorkQueueIdx);
		globalWorkQueueIdx -= workQueueIdx;
	}

	__syncthreads();

	if(workQueueIdx == 0)
	{
		callAbort<workQueueCapacity>(idleCount, threadOffset);
		return;
	}


	{
		int2* globalQueue = &workQueues[blockOffset * globalWorkQueueCapacity + globalWorkQueueIdx];
		int queueOffset = threadOffset;
		while(queueOffset < workQueueIdx * 3)
		{
			((int*)localWorkQueue)[queueOffset] = ((int*)globalQueue)[queueOffset];
			queueOffset += nThreads;
		}
	}

	__syncthreads();

	while(workQueueIdx > 0)
	{
		int2 work_item;
		int nActive = min(nThreads, workQueueIdx);

		work_item.x = -1;
		if(threadOffset < workQueueIdx)
		{
			work_item = localWorkQueue[workQueueIdx - nActive + threadOffset];
		}
		__syncthreads();

		if(threadOffset == 0)
		{
			workQueueIdx -= nActive;
		}
		__syncthreads();

		if(work_item.x >= 0)
		{
			TreeNode node1 = tree_object1[work_item.x];
			TreeNode node2 = tree_object2[work_item.y];

			if(intersect<BV>(node1.bbox, node2.bbox))
			{
				if(node1.isLeaf() && node2.isLeaf())    // both leaf
				{
					int tri1 = node1.getTriID();
					int tri2 = node2.getTriID();

					int globalOutputIndex = atomicInc(outputListIdx, COLLISION_PAIR_CAPACITY - 1);
					outputList[globalOutputIndex] = make_int2(tri1, tri2);
				}
				else if(node2.isLeaf() || (!node1.isLeaf() && (node1.bbox.getSize() > node2.bbox.getSize())))
				{
					int left1 = node1.getLeftChild() + work_item.x;
					int right1 = left1 + 1;

					int localPtr = atomicAdd(&workQueueIdx, 2);

					if(localPtr < workQueueCapacity)
					{
						localWorkQueue[localPtr].x = left1;
						localWorkQueue[localPtr].y = work_item.y;
						localPtr++;

						if(localPtr < workQueueCapacity)
						{
							localWorkQueue[localPtr].x = right1;
							localWorkQueue[localPtr].y = work_item.y;
						}
						else
						{
							int globalPtr = atomicAdd(&globalWorkQueueIdx, 1);
							int2* globalQueue = &workQueues[blockOffset * globalWorkQueueCapacity + globalPtr];

							globalQueue[0].x = right1;
							globalQueue[0].y = work_item.y;
						}
					}
					else
					{
						int globalPtr = atomicAdd(&globalWorkQueueIdx, 2);
						int2* globalQueue = &workQueues[blockOffset * globalWorkQueueCapacity + globalPtr];

						globalQueue[0].x = left1;
						globalQueue[0].y = work_item.y;

						globalQueue[1].x = right1;
						globalQueue[1].y = work_item.y;
					}
				}
				else
				{
					int left2 = node2.getLeftChild() + work_item.y;
					int right2 = left2 + 1;

					int localPtr = atomicAdd(&workQueueIdx, 2);

					if(localPtr < workQueueCapacity)
					{
						localWorkQueue[localPtr].x = work_item.x;
						localWorkQueue[localPtr].y = left2;
						localPtr++;

						if(localPtr < workQueueCapacity)
						{
							localWorkQueue[localPtr].x = work_item.x;
							localWorkQueue[localPtr].y = right2;
						}
						else
						{
							int globalPtr = atomicAdd(&globalWorkQueueIdx, 1);
							int2* globalQueue = &workQueues[blockOffset * globalWorkQueueCapacity + globalPtr];

							globalQueue[0].x = work_item.x;
							globalQueue[0].y = right2;
						}
					}
					else
					{
						int globalPtr = atomicAdd(&globalWorkQueueIdx, 2);
						int2* globalQueue = &workQueues[blockOffset * globalWorkQueueCapacity + globalPtr];

						globalQueue[0].x = work_item.x;
						globalQueue[0].y = left2;

						globalQueue[1].x = work_item.x;
						globalQueue[1].y = right2;
					}
				}
			}
		}

		__syncthreads();

		if((workQueueIdx >= workQueueCapacity - nThreads) || (globalWorkQueueIdx >= QUEUE_SIZE_PER_TASK_GLOBAL - nThreads * 2 - workQueueCapacity) || (workQueueIdx == 0))
		{
			callAbort<workQueueCapacity>(idleCount, threadOffset);
			break;
		}

		if(threadOffset == 0)
		{
			wantToAbort = *idleCount;
		}

		__syncthreads();

		if(wantToAbort > QUEUE_IDLETASKS_FOR_ABORT)
		{
			callAbort<workQueueCapacity>(idleCount, threadOffset);
			break;
		}
	}

	if(threadOffset == 0)
	{
		workQueueIdx = min(workQueueIdx, workQueueCapacity);
		workQueueCounts[blockOffset] = workQueueIdx + globalWorkQueueIdx;
	}
	__syncthreads();

	{
		int queueOffset = threadOffset;
		int2* globalQueue = &workQueues[blockOffset * globalWorkQueueCapacity + globalWorkQueueIdx];
		while(queueOffset < workQueueIdx * 2)
		{
			((int*)globalQueue)[queueOffset] = ((int*)localWorkQueue)[queueOffset];
			queueOffset += nThreads;
		}
	}
	__syncthreads();
}


// oldest balancing (gproximity's)
// 1. no pump
// 2. copy from inqueue to outqueue with only a few threads (large overhead)
template <int nThreads, int nQueues, class WorkElement>
__global__ void balanceWorkList(WorkElement *workQueueIn, WorkElement* workQueueOut, unsigned int* workQueueCount, const unsigned int maxQueueSize, unsigned int *totalEntries, int* balanceSignal)
{
	__shared__ int shared_sum[nThreads];
	__shared__ int shared_queuesizes[nQueues];
	__shared__ int shared_ifbalance;
	const int idx = threadIdx.x;

	// sum on workQueueCount to find total number of entries
	int nSplitsLeft = nQueues, inputOffset = idx;
	shared_sum[idx] = 0;

	if(idx == 0)
	{
		shared_ifbalance = 0;
	}
	__syncthreads();

	while(idx < nSplitsLeft)
	{
		int nQueueElements = workQueueCount[inputOffset];
		shared_queuesizes[inputOffset] = nQueueElements;
		if((nQueueElements < QUEUE_SIZE_PER_TASK_INIT) && (shared_ifbalance == 0)) atomicExch(&shared_ifbalance, 1);
		else if((nQueueElements >=  QUEUE_SIZE_PER_TASK_GLOBAL - TRAVERSAL_THREADS * 4 - QUEUE_SIZE_PER_TASK) && (shared_ifbalance == 0)) atomicExch(&shared_ifbalance, 1);
		shared_sum[idx] += nQueueElements;
		inputOffset += nThreads;
		nSplitsLeft -= nThreads;
	}
	__syncthreads();

	REDUCE(shared_sum, idx, nThreads, +);

	nSplitsLeft = shared_sum[0];

	if(idx == 0)
	{
		*totalEntries = nSplitsLeft;
		*balanceSignal = shared_ifbalance;
	}
	__syncthreads();

	if(shared_ifbalance > 0)
	{
		int nSplitsPerQueue, nWithPlus1;
		nSplitsPerQueue = nSplitsLeft / nQueues;
		nWithPlus1 = nSplitsLeft - nSplitsPerQueue * nQueues;

		inputOffset = 0;
		int outputOffset = 0, inputQueue = -1, inputQueueCount = 0;

		for(int q = 0; q < nQueues; ++q)
		{
			int nSplitsLocal;
			if(q < nWithPlus1)
				nSplitsLocal = nSplitsPerQueue + 1;
			else
				nSplitsLocal = nSplitsPerQueue;

			outputOffset = maxQueueSize * q + idx;

			if(idx == 0)
				workQueueCount[q] = nSplitsLocal;

			while(nSplitsLocal > 0)
			{
				if(inputQueueCount <= 0)
				{
					inputQueue++;
					inputOffset = idx;
					inputQueueCount = shared_queuesizes[inputQueue];
				}
				else
				{
					int splitsToWrite = min(nSplitsLocal, inputQueueCount);
					splitsToWrite = min(splitsToWrite, nThreads);

					if(idx < splitsToWrite)
						workQueueOut[outputOffset] = workQueueIn[inputQueue * maxQueueSize + inputOffset];
					nSplitsLocal -= splitsToWrite;
					inputOffset += splitsToWrite;
					outputOffset += splitsToWrite;
					inputQueueCount -= splitsToWrite;
					nSplitsLeft -= splitsToWrite;
				}
				__syncthreads();
			}
		}
	}
}

__global__ void triangleCollision(GPUVertex* vertices1, uint3* triIndices1, GPUVertex* vertices2, uint3* triIndices2, int2* pairs, const int nPairs)
{
	unsigned int threadId = (blockIdx.y * gridDim.x + blockIdx.x) * blockDim.x + threadIdx.x;

	if(threadId < nPairs)
	{
		float3 u1, u2, u3, v1, v2, v3;
		int2 pair = pairs[threadId];

		uint3 idx = triIndices1[pair.x];
		uint3 idx2 = triIndices2[pair.y];

		u1 = vertices1[idx.x].v;
		u2 = vertices1[idx.y].v;
		u3 = vertices1[idx.z].v;

		v1 = vertices2[idx2.x].v;
		v2 = vertices2[idx2.y].v;
		v3 = vertices2[idx2.z].v;

		if(triangleIntersection(u1, u2, u3, v1, v2, v3))
		{
			pairs[threadId] = make_int2(-pair.x, -pair.y);
		}
	}
}


#endif