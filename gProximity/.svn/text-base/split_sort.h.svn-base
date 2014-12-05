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
 
#ifndef __SPLIT_SORT_H_
#define __SPLIT_SORT_H_

#include "cuda_prefix.h"

#define AABB_GET_AXIS(ID, axis) tex1Dfetch(g_tex_AABBs, ID + axis*g_tex_AABBs_offset)

/**
 * Performs a split of the triangle indices into left and right side based on the
 * split position and axis given by the parameters.
 * This version works on a per-warp basis.
 */
template <int nThreads>
__device__ __inline__ void splitSort_Warp(int localTriIDs[nThreads], int left[nThreads], int *triIDs, const int bestAxis, const float splitPoint, const int ai,
        int &nScanTrisLeft, int &inputOffsetLeft, int &inputOffsetRight, int &numLeft)
{
	int isLeft, isRight;
	
	if(ai < nScanTrisLeft)
	{
		// read in triangle indices
		localTriIDs[ai] = triIDs[inputOffsetLeft + ai];
		
		// calculate center of bounding box for triangle 1
		float2 box = AABB_GET_AXIS(localTriIDs[ai], bestAxis);
		float centroid = (box.x + box.y) * 0.5f;
		
		// is primitive left or right of split point?
		isLeft  = (centroid <= splitPoint) ? 1 : 0;
		isRight = isLeft ^ 1;
		left[ai]  = isLeft;
	}
	else
	{
		localTriIDs[ai] = 0;
		isLeft  = 0;
		isRight = 0;
		left[ai]  = 0;
	}
	
	__syncthreads();
	
	// val = prefix sum of local warp block
	int val = scanwarp<32>(left, ai);
	
	if(nThreads > WARP_SIZE)
	{
		// write all max. elements into first WARP_SIZE elements
		// (only works it nThreads/WARP_SIZE <= WARP_SIZE!)
		if((ai & (WARP_SIZE - 1)) == (WARP_SIZE - 1))
			left[ai >> WARP_SIZE_LOG2] = val + isLeft;
			
		__syncthreads();
		
		// do prefix sum of max. element of all blocks
		if(ai < WARP_SIZE)
			left[ai] = scanwarp< (nThreads >> WARP_SIZE_LOG2) > (left, ai);
			
		__syncthreads();
		
		// add the offset for this warp on all elements
		val += left[ai >> WARP_SIZE_LOG2];
		
		__syncthreads();
	}
	
	// save out the highest value of this block
	if(ai == nThreads - 1)
		left[ai] = val + isLeft;
		
	__syncthreads();
	
	// will be the number of elements on the left for this whole iteration
	int numLeftLocal = left[nThreads - 1];
	
	// if all are on the left anyway, no need to write to memory
	if(numLeftLocal == nThreads)
	{
		numLeft += nThreads;
		inputOffsetLeft += nThreads;
		nScanTrisLeft -= nThreads;
		return;
	}
	
	// optimization to save memory BW: if the prefix sum in left[] at the
	// thread position is the same as the thread position, then the element
	// at that ID is not going to change, i.e. writing it would be a waste of
	// bandwidth, ergo skip it.
	isLeft = (val < ai) ? isLeft : 0;
	
	// store back triIDs on the left side
	if(isLeft)
		triIDs[inputOffsetLeft + val] = localTriIDs[ai];
		
	inputOffsetLeft += numLeftLocal;
	nScanTrisLeft -= nThreads;
	
	// Swap right elements with the elements at the very end of the array
	//
	// Note: the sync() call is necessary because the end of the array and the
	// read window we're looking at may overlap, so we have to save off first
	// before we can overwrite from shared memory.
	const int globalIdx = inputOffsetRight - (ai - val);
	if(isRight)
		triIDs[inputOffsetLeft + ai - val] = triIDs[globalIdx];
	__syncthreads();
	if(isRight)
		triIDs[globalIdx] = localTriIDs[ai];
		
	// get next set of triIDs
	numLeft += numLeftLocal;
	inputOffsetRight -= nThreads - numLeftLocal;
}

/**
 * Performs a split of the triangle indices into left and right side based on the
 * split position and axis given by the parameters.
 * This version works on a per-warp basis.
 */
__device__ __inline__
int splitSortShared_Local(int *left, int *triIDs, const float *boxes, const int nMaxTris, const int bestAxis, const float splitPoint, const int ai, const int nScanTrisLeft)
{
	int isLeft, localTriID;
	if(ai < nScanTrisLeft)
	{
		// read in triangle indices
		localTriID = triIDs[ai];
		
		// calculate center of bounding box for triangle 1
		float box_min = boxes[localTriID + bestAxis*nMaxTris];
		float box_max = boxes[localTriID + (bestAxis + 3)*nMaxTris];
		float centroid = (box_min + box_max) * 0.5f;
		
		// is primitive left or right of split point?
		isLeft   = (centroid <= splitPoint) ? 1 : 0;
		left[ai] = isLeft;
	}
	else
	{
		isLeft   = 0;
		left[ai] = 0;
		localTriID = 0;
	}
	
	__syncthreads();
	
	// val = prefix sum of local warp block
	int val = scanwarp<32>(left, ai);
	
	// save out the highest value of this block
	if(ai == WARP_SIZE - 1)
		left[ai] = val + isLeft;
		
	// this is the number of elements on the left
	int numLeft = left[WARP_SIZE - 1];
	
	// store back triIDs on the left side
	if(isLeft)
		triIDs[val] = localTriID;
	else if(ai < nScanTrisLeft)  // or right side
		triIDs[nScanTrisLeft - 1 - (ai - val)] = localTriID;
		
	return numLeft;
}



/**
* Performs a split of the triangle indices into left and right side based on the
* split position and axis given by the parameters.
* This version works on a per-warp basis.
*/
template <int nThreads> __device__ __inline__
int splitSortShared(int *localTriIDs, int *resortedTriIDs, int *left, int *triIDs, const int bestAxis, const float splitPoint, const int ai, const int nScanTrisLeft, const int inputOffsetLeft)
{
	int isLeft;
	if(ai < nScanTrisLeft)
	{
		// read in triangle indices
		localTriIDs[ai] = triIDs[inputOffsetLeft + ai];
		
		// calculate center of bounding box for triangle 1
		float2 box = AABB_GET_AXIS(localTriIDs[ai], bestAxis);
		float centroid = (box.x + box.y) * 0.5f;
		
		// is primitive left or right of split point?
		isLeft   = (centroid <= splitPoint) ? 1 : 0;
		left[ai] = isLeft;
	}
	else
	{
		localTriIDs[ai] = 0;
		isLeft   = 0;
		left[ai] = 0;
	}
	
	__syncthreads();
	
	// val = prefix sum of local warp block
	int val = scanwarp<32>(left, ai);
	
	if(nThreads > WARP_SIZE)
	{
		// write all max. elements into first WARP_SIZE elements
		// (only works it nThreads/WARP_SIZE <= WARP_SIZE!)
		if((ai & (WARP_SIZE - 1)) == (WARP_SIZE - 1))
			left[ai >> WARP_SIZE_LOG2] = val + isLeft;
			
		__syncthreads();
		
		// do prefix sum of max. element of all blocks
		if(ai < WARP_SIZE)
			left[ai] = scanwarp< (nThreads >> WARP_SIZE_LOG2) > (left, ai);
			
		__syncthreads();
		
		// add the offset for this warp on all elements
		val += left[ai >> WARP_SIZE_LOG2];
		
		__syncthreads();
	}
	
	// save out the highest value of this block
	if(ai == nThreads - 1)
		left[ai] = val + isLeft;
		
	__syncthreads();
	
	// this is the number of elements on the left
	int numLeft = left[nThreads - 1];
	
	// store back triIDs on the left side
	if(isLeft)
		resortedTriIDs[val] = localTriIDs[ai];
	else if(ai < nScanTrisLeft)  // or right side
		resortedTriIDs[nScanTrisLeft - (ai - val)] = localTriIDs[ai];
		
	// if all are on the left or right anyway, no need to write to memory
	//if (numLeft != nScanTrisLeft && numLeft != 0) {
	// now do coalesced writes back to global memory:
	if(ai < nScanTrisLeft)
		triIDs[inputOffsetLeft + ai] = resortedTriIDs[ai];
	//}
	
	return numLeft;
}



/**
 * Computes prefix sum of all the values in arrays left and right
 * and sets numLeft to the number of active values in the left array
 * (i.e. number of elements on the left).
 */
template <int nSplitThreads> __device__ __inline__ void indexPrefixSum(int *left, int *right, int *numLeft, const int thid)
{

	const int twotimesthid = 2 * thid;
	int offset = 1;
	
	for(int d = nSplitThreads; d > 0; d >>= 1, offset *= 2)    // build sum in place up the tree
	{
		CONDOREMU_SYNC(nSplitThreads > WARP_SIZE);
		if(thid < d)
		{
			int ai = offset * (twotimesthid + 1) - 1;
			int bi = offset * (twotimesthid + 2) - 1;
			ai += SCAN_CONFLICT_FREE_OFFSET(ai);
			bi += SCAN_CONFLICT_FREE_OFFSET(bi);
			left[bi] += left[ai];
			right[bi] += right[ai];
		}
	}
	
	CONDOREMU_SYNC(nSplitThreads > WARP_SIZE);
	*numLeft = left[2*nSplitThreads-1 + SCAN_CONFLICT_FREE_OFFSET(2*nSplitThreads-1)];
	CONDOREMU_SYNC(nSplitThreads > WARP_SIZE);
	if(thid == 0)    // clear the last element
	{
		left[2*nSplitThreads-1  + SCAN_CONFLICT_FREE_OFFSET(2*nSplitThreads-1)] = 0;
		right[2*nSplitThreads-1 + SCAN_CONFLICT_FREE_OFFSET(2*nSplitThreads-1)] = 0;
	}
	
	for(int d = 1; d < 2 * nSplitThreads; d *= 2) // traverse down tree & build scan
	{
		offset /= 2;
		CONDOREMU_SYNC(nSplitThreads > WARP_SIZE);
		if(thid < d)
		{
			int ai = offset * (twotimesthid + 1) - 1;
			int bi = offset * (twotimesthid + 2) - 1;
			ai += SCAN_CONFLICT_FREE_OFFSET(ai);
			bi += SCAN_CONFLICT_FREE_OFFSET(bi);
			int t = left[ai];
			left[ai] = left[bi];
			left[bi] += t;
			t = right[ai];
			right[ai] = right[bi];
			right[bi] += t;
		}
	}
	
	CONDOREMU_SYNC(nSplitThreads > WARP_SIZE);
}

template <int nSplitThreads, bool isPartial>
__device__ __inline__ void splitSort(int *localTriIDs, int *left, int *right,
                                     int *triIDs, const int bestAxis, const float splitPoint, const int ai,
                                     int *nScanTrisLeft, int *inputOffsetLeft, int *inputOffsetRight, int *numLeft)
{
	// offsets for bank-conflict free scan
	const int bi = ai + nSplitThreads;
	const int ai_offset = ai + SCAN_CONFLICT_FREE_OFFSET(ai);
	const int bi_offset = bi + SCAN_CONFLICT_FREE_OFFSET(bi);
	
	// block read triangle indices into local shared memory
	if(isPartial)
	{
		bool isActive1 = ai < *nScanTrisLeft;
		bool isActive2 = bi < *nScanTrisLeft;
		int isLeft1, isLeft2, isRight1, isRight2;
		
		if(isActive1)
		{
			// read in 2 triangle indices
			localTriIDs[ai] = triIDs[*inputOffsetLeft + ai];
			
			// calculate center of bounding box for triangle 1
			float2 box = AABB_GET_AXIS(localTriIDs[ai], bestAxis);
			float centroid = (box.x + box.y) * 0.5f;
			//C_DEBUG(printf("Testing triangle1 at %d+%d: %d, axis %d: centroid %f, split %f\n", *inputOffsetLeft, ai, localTriIDs[ai], bestAxis, centroid, splitPoint));
			
			// is primitive left or right of splitpoint?
			isLeft1 = (centroid <= splitPoint) ? 1 : 0;
			isRight1 = isLeft1 ^ 1;
			left[ai_offset]  = isLeft1;
			right[ai_offset] = isLeft1 ^ 1;
		}
		else
		{
			localTriIDs[ai] = -1;
			isLeft1 = 0;
			isRight1 = 0;
			left[ai_offset]  = 0;
			right[ai_offset] = 0;
		}
		
		if(isActive2)
		{
			localTriIDs[bi] = triIDs[*inputOffsetLeft + bi];
			
			// calculate center of bounding box for triangle 2
			float2 box = AABB_GET_AXIS(localTriIDs[bi], bestAxis);
			float centroid = (box.x + box.y) * 0.5f;
			//C_DEBUG(printf("Testing triangle2 %d+%d %d, axis %d: centroid %f, split %f\n", *inputOffsetLeft, ai, localTriIDs[bi], bestAxis, centroid, splitPoint));
			
			// is primitive left or right of splitpoint?
			isLeft2 = (centroid <= splitPoint) ? 1 : 0;
			isRight2 = isLeft2 ^ 1;
			left[bi_offset]  = isLeft2;
			right[bi_offset] = isLeft2 ^ 1;
		}
		else
		{
			localTriIDs[bi] = -1;
			isLeft2 = 0;
			isRight2 = 0;
			left[bi_offset]  = 0;
			right[bi_offset] = 0;
		}
		
		
		// will be the number of elements on the left for this iteration
		int numLeftLocal = 0;
		
		// do prefix sum on isLeft and isRight
		indexPrefixSum<nSplitThreads>(left, right, &numLeftLocal, ai);
		
		// early exit: if all primitives are on the left, we don't need to
		// write any data
		if(numLeftLocal == *nScanTrisLeft)
		{
			*numLeft += numLeftLocal;
			*inputOffsetLeft += numLeftLocal;
			CONDOREMU_SYNC(nSplitThreads > WARP_SIZE);
			return;
		}
		
		// optimization to save memory BW: if the prefix sum in left[] at the
		// thread position is the same as the thread position, then the element
		// at that ID is not going to change, i.e. writing it would be a waste of
		// bandwidth, ergo skip it.
		isLeft1 = (left[ai_offset] < ai) ? isLeft1 : 0;
		isLeft2 = (left[bi_offset] < bi) ? isLeft2 : 0;
		
		// store back triIDs on the left side
		if(isLeft1)
			triIDs[*inputOffsetLeft + left[ai_offset]] = localTriIDs[ai];
		if(isLeft2)
			triIDs[*inputOffsetLeft + left[bi_offset]] = localTriIDs[bi];
			
		*inputOffsetLeft += numLeftLocal;
		
		if(isRight1)
			triIDs[*inputOffsetLeft  + right[ai_offset]] = localTriIDs[ai];
		if(isRight2)
			triIDs[*inputOffsetLeft  + right[bi_offset]] = localTriIDs[bi];
			
		*numLeft += numLeftLocal;
	}
	else
	{
		float centroid;
		int isLeft1, isLeft2, isRight1, isRight2;
		
		// read in 2 triangle indices
		localTriIDs[ai] = triIDs[*inputOffsetLeft + ai];
		localTriIDs[bi] = triIDs[*inputOffsetLeft + bi];
		
		// calculate center of bounding box for triangle 1
		float2 box = AABB_GET_AXIS(localTriIDs[ai], bestAxis);
		centroid = (box.x + box.y) * 0.5f;
		//C_DEBUG(printf("Testing triangle1 at %d+%d: %d, axis %d: centroid %f, split %f\n", *inputOffsetLeft, ai,localTriIDs[ai], bestAxis, centroid, splitPoint));
		
		// is primitive left or right of splitpoint?
		isLeft1 = (centroid <= splitPoint) ? 1 : 0;
		isRight1 = isLeft1 ^ 1;
		left[ai_offset]  = isLeft1;
		right[ai_offset] = isRight1;
		
		// calculate center of bounding box for triangle 2
		box = AABB_GET_AXIS(localTriIDs[bi], bestAxis);
		centroid = (box.x + box.y) * 0.5f;
		//C_DEBUG(printf("Testing triangle2 at %d+%d: %d, axis %d: centroid %f, split %f\n", *inputOffsetLeft, ai,localTriIDs[bi], bestAxis, centroid, splitPoint));
		
		// is primitive left or right of splitpoint?
		isLeft2 = (centroid <= splitPoint) ? 1 : 0;
		isRight2 = isLeft2 ^ 1;
		left[bi_offset]  = isLeft2;
		right[bi_offset] = isRight2;
		
		// will be the number of elements on the left for this iteration
		int numLeftLocal = 0;
		
		// do prefix sum on isLeft and isRight
		indexPrefixSum<nSplitThreads>(left, right, &numLeftLocal, ai);
		
		// if all are on the left anyway, no need to write to memory
		if(numLeftLocal == 2 * nSplitThreads)
		{
			*numLeft += 2 * nSplitThreads;
			*inputOffsetLeft += 2 * nSplitThreads;
			*nScanTrisLeft -= 2 * nSplitThreads;
			
			CONDOREMU_SYNC(nSplitThreads > WARP_SIZE);
			return;
		}
		
		// optimization to save memory BW: if the prefix sum in left[] at the
		// thread position is the same as the thread position, then the element
		// at that ID is not going to change, i.e. writing it would be a waste of
		// bandwidth, ergo skip it.
		isLeft1 = (left[ai_offset] < ai) ? isLeft1 : 0;
		isLeft2 = (left[bi_offset] < bi) ? isLeft2 : 0;
		
		// store back triIDs on the left side
		if(isLeft1)
			triIDs[*inputOffsetLeft + left[ai_offset]] = localTriIDs[ai];
		if(isLeft2)
			triIDs[*inputOffsetLeft + left[bi_offset]] = localTriIDs[bi];
		*inputOffsetLeft += numLeftLocal;
		
		*nScanTrisLeft -= 2 * nSplitThreads;
		const int numRightLocal = 2 * nSplitThreads - numLeftLocal;
		
		// if we don't have enough elements on right side to swap...
		if(*nScanTrisLeft < numRightLocal)
		{
		
			int ra = right[ai_offset];
			int rb = right[bi_offset];
			
			// write the old element to the position is should be swapped with, may be overwritten later
			if(isRight1)
				triIDs[*inputOffsetLeft + ra] = triIDs[*inputOffsetRight - ra];
			if(isRight2)
				triIDs[*inputOffsetLeft + rb] = triIDs[*inputOffsetRight - rb];
				
			// barrier to ensure that all writes are done
			CONDOREMU_SYNC(nSplitThreads > WARP_SIZE);
			
			// write the new element into the swapped position. for ra or rb > nScanTrisLeft, this will overwrite
			// the previous value written in the step above, to make it correct
			if(isRight1)
				triIDs[*inputOffsetRight - ra] = localTriIDs[ai];
			if(isRight2)
				triIDs[*inputOffsetRight - rb] = localTriIDs[bi];
		}
		else
		{
			// now read in all the elements on the right side of triIDs that we need
			// to swap with elements on the right side of this chunk
			if(isRight1)
			{
				// this is essentially a swap operation
				int globalIdx = *inputOffsetRight - right[ai_offset];
				triIDs[*inputOffsetLeft + right[ai_offset]] = triIDs[globalIdx];
				triIDs[globalIdx] = localTriIDs[ai];
			}
			
			if(isRight2)
			{
				// this is essentially a swap operation
				int globalIdx = *inputOffsetRight - right[bi_offset];
				triIDs[*inputOffsetLeft + right[bi_offset]] = triIDs[globalIdx];
				triIDs[globalIdx] = localTriIDs[bi];
			}
		}
		
		// get next set of triIDs
		*numLeft += numLeftLocal;
		*inputOffsetRight -= numRightLocal;
	}
	
	CONDOREMU_SYNC(nSplitThreads > WARP_SIZE);
}

#endif
