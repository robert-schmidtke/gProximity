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
 
#ifndef SPLITLIST_COMPACTION_H
#define SPLITLIST_COMPACTION_H

#include "cuda_defs.h"
#include "cuda_prefix.h"
#include "cuda_aabbsplit.h"

/************************************************************************/
/* Split list compaction functions										*/
/* Version 1 uses the bank conflict reduced prefix sum by Mark Harris	*/
/* Version 2 uses the warp-wise XOR prefix sum by Timo Aila				*/
/************************************************************************/

// take a list of splits which may or may not be terminated yet
// and write all those that are still active into the output list
template <int nThreads> __global__
void compactSplitList1(const AABBSplit *inputSplits, AABBSplit *outputSplits, int *activeSplitMask, SplitListStats *splitStats, const unsigned int nInputSplits)
{
	// Statically allocated shared memory for scan kernels
	__shared__ int temp[2*nThreads + (2*nThreads)/SCAN_NUM_BANKS];
	__shared__ int shared_splitsizes[nThreads];
	
	const int thid = threadIdx.x;
	const int twotimesthid = 2 * thid;
	const int ai = thid;
	const int bi = thid + nThreads;
	const int bankOffsetA = SCAN_CONFLICT_FREE_OFFSET(ai);
	const int bankOffsetB = SCAN_CONFLICT_FREE_OFFSET(bi);
	int splitsizes = 0;
	
	// offset into the output split list, increased after each run
	int outputOffset = 0;
	int inputOffset	 = 0;
	
	// we need to run the threadsize-scan as many times as the inputsplit array is long
	// divided by the number of threads we have for each scan. this may result in some
	// leftover entries, which we handle afterwards.
	unsigned int nSplitsLeft = nInputSplits;
	
	while(nSplitsLeft >= 2 * nThreads)
	{
		int firstActive  = activeSplitMask[inputOffset + ai];
		int secondActive = activeSplitMask[inputOffset + bi];
		
		// Cache the computational window in shared memory
		temp[ai + bankOffsetA] = firstActive;
		temp[bi + bankOffsetB] = secondActive;
		
		int offset = 1;
		
		for(int d = nThreads; d > 0; d >>= 1, offset *= 2)    // build sum in place up the tree
		{
			CONDOREMU_SYNC(nThreads > WARP_SIZE);
			if(thid < d)
			{
				int ai = offset * (twotimesthid + 1) - 1;
				int bi = offset * (twotimesthid + 2) - 1;
				ai += SCAN_CONFLICT_FREE_OFFSET(ai);
				bi += SCAN_CONFLICT_FREE_OFFSET(bi);
				temp[bi] += temp[ai];
			}
		}
		
		CONDOREMU_SYNC(nThreads > WARP_SIZE);
		int tempActiveSplits = temp[2*nThreads-1 + SCAN_CONFLICT_FREE_OFFSET(2*nThreads-1)];
		CONDOREMU_SYNC(nThreads > WARP_SIZE);
		if(thid == 0)  // clear the last element
			temp[2*nThreads-1 + SCAN_CONFLICT_FREE_OFFSET(2*nThreads-1)] = 0;
			
		for(int d = 1; d < 2 * nThreads; d *= 2) // traverse down tree & build scan
		{
			offset /= 2;
			CONDOREMU_SYNC(nThreads > WARP_SIZE);
			if(thid < d)
			{
				int ai = offset * (twotimesthid + 1) - 1;
				int bi = offset * (twotimesthid + 2) - 1;
				ai += SCAN_CONFLICT_FREE_OFFSET(ai);
				bi += SCAN_CONFLICT_FREE_OFFSET(bi);
				int t = temp[ai];
				temp[ai] = temp[bi];
				temp[bi] += t;
			}
		}
		
		CONDOREMU_SYNC(nThreads > WARP_SIZE);
		
		if(firstActive)
		{
			AABBSplit split = inputSplits[inputOffset + ai];
			splitsizes += split.right - split.left + 1;
			outputSplits[outputOffset + temp[ai + bankOffsetA]] = split;
		}
		
		if(secondActive)
		{
			AABBSplit split = inputSplits[inputOffset + bi];
			splitsizes += split.right - split.left + 1;
			outputSplits[outputOffset + temp[bi + bankOffsetB]] = split;
		}
		
		// modify the offsets
		outputOffset += tempActiveSplits;
		nSplitsLeft -= 2 * nThreads;
		inputOffset += 2 * nThreads;
	}
	
	// handle rest of compaction in the same manner, but with elements out of bound set to zero
	if(nSplitsLeft > 0)
	{
	
		int firstActive  = (ai < nSplitsLeft) ? activeSplitMask[inputOffset + ai] : 0;
		int secondActive = (bi < nSplitsLeft) ? activeSplitMask[inputOffset + bi] : 0;
		
		// Cache the computational window in shared memory
		temp[ai + bankOffsetA] = firstActive;
		temp[bi + bankOffsetB] = secondActive;
		
		int offset = 1;
		
		for(int d = nThreads; d > 0; d >>= 1, offset *= 2)    // build sum in place up the tree
		{
			CONDOREMU_SYNC(nThreads > WARP_SIZE);
			if(thid < d)
			{
				int ai = offset * (twotimesthid + 1) - 1;
				int bi = offset * (twotimesthid + 2) - 1;
				ai += SCAN_CONFLICT_FREE_OFFSET(ai);
				bi += SCAN_CONFLICT_FREE_OFFSET(bi);
				temp[bi] += temp[ai];
			}
		}
		
		CONDOREMU_SYNC(nThreads > WARP_SIZE);
		int tempActiveSplits = temp[2*nThreads-1 + SCAN_CONFLICT_FREE_OFFSET(2*nThreads-1)];
		CONDOREMU_SYNC(nThreads > WARP_SIZE);
		if(thid == 0)  // clear the last element
			temp[2*nThreads-1 + SCAN_CONFLICT_FREE_OFFSET(2*nThreads-1)] = 0;
			
		for(int d = 1; d < 2 * nThreads; d *= 2) // traverse down tree & build scan
		{
			offset /= 2;
			CONDOREMU_SYNC(nThreads > WARP_SIZE);
			if(thid < d)
			{
				int ai = offset * (twotimesthid + 1) - 1;
				int bi = offset * (twotimesthid + 2) - 1;
				ai += SCAN_CONFLICT_FREE_OFFSET(ai);
				bi += SCAN_CONFLICT_FREE_OFFSET(bi);
				int t = temp[ai];
				temp[ai] = temp[bi];
				temp[bi] += t;
			}
		}
		
		CONDOREMU_SYNC(nThreads > WARP_SIZE);
		
		
		if(firstActive)
		{
			AABBSplit split = inputSplits[inputOffset + ai];
			splitsizes += split.right - split.left + 1;
			outputSplits[outputOffset + temp[ai + bankOffsetA]] = split;
		}
		
		if(secondActive)
		{
			AABBSplit split = inputSplits[inputOffset + bi];
			splitsizes += split.right - split.left + 1;
			outputSplits[outputOffset + temp[bi + bankOffsetB]] = split;
		}
		
		outputOffset += tempActiveSplits;
	}
	
	// write total of split sizes to memory
	shared_splitsizes[ai] = splitsizes;
	CONDOREMU_SYNC(nThreads > WARP_SIZE);
	
	if(thid == 0)
	{
		splitStats->nActiveSplits = outputOffset;
		
		// compute avg. split size
		int tempSum = splitsizes;
		for(int i = 1; i < nThreads; i++)
			tempSum += shared_splitsizes[i];
			
		splitStats->avgSplitSize = tempSum / (float)outputOffset;
	}
}

template <int nThreads> __global__
void compactSplitList2(const AABBSplit *inputSplits, AABBSplit *outputSplits, int *activeSplitMask, SplitListStats *splitStats, const unsigned int nInputSplits)
{
	// Statically allocated shared memory for scan kernels
	__shared__ int ptr[nThreads];
	__shared__ int shared_splitsizes[nThreads];
	__shared__ int numLocalActive;
	
	const int idx = threadIdx.x;
	
	// offset into the output split list, increased after each run
	int splitsizes = 0;
	int outputOffset = 0;
	int inputOffset	 = 0;
	
	// we need to run the threadsize-scan as many times as the inputsplit array is long
	// divided by the number of threads we have for each scan.
	int nSplitsLeft = nInputSplits;
	
	while(nSplitsLeft > 0)
	{
		// load data from global memory
		int isActive = (idx < nSplitsLeft) ? activeSplitMask[inputOffset + idx] : 0;
		ptr[idx] = isActive;
		
		__syncthreads();
		
		// val = prefix sum of local warp block
		int val = scanwarp<32>(ptr, idx);
		
		// write all max. elements into first WARP_SIZE elements
		// (only works it nThreads/WARP_SIZE <= WARP_SIZE!)
		if((idx & (WARP_SIZE - 1)) == (WARP_SIZE - 1))
			ptr[idx >> WARP_SIZE_LOG2] = val + isActive;
			
		__syncthreads();
		
		// do prefix sum of max. element of all blocks
		
		if(idx < WARP_SIZE)
			ptr[idx] = scanwarp< (nThreads >> WARP_SIZE_LOG2) > (ptr, idx);
			
			
		__syncthreads();
		
		// add the offset for this warp on all elements
		val += ptr[idx >> WARP_SIZE_LOG2];
		
		__syncthreads();
		
		// write out value to split list with modified offset
		if(isActive)
		{
			AABBSplit split = inputSplits[inputOffset + idx];
			splitsizes += split.right - split.left + 1;
			outputSplits[outputOffset + val] = split;
		}
		
		if(idx == (nThreads - 1))
			numLocalActive = val + isActive;
			
		__syncthreads();
		
		// modify the offsets
		outputOffset += numLocalActive;
		nSplitsLeft -= nThreads;
		inputOffset += nThreads;
	}
	
	// write total of split sizes to memory
	shared_splitsizes[idx] = splitsizes;
	
	__syncthreads();
	
	// parallel reduce on split sizes
	for(int r = nThreads / 2; r != 0; r /= 2)
	{
		if(idx < r)
		{
			shared_splitsizes[idx] += shared_splitsizes[idx + r];
		}
		__syncthreads();
	}
	
	// write out global information about the splits found
	if(idx == 0)
	{
		splitStats->nActiveSplits = outputOffset;
		splitStats->avgSplitSize = shared_splitsizes[0] / (float)outputOffset;
	}
}

template <int nThreads> __global__
void compactSplitList3(int *splitIndexTable, int *activeSplitMask, SplitListStats *splitStats, const unsigned int nInputSplits)
{
	// Statically allocated shared memory for scan kernels
	__shared__ int ptr[nThreads];
	__shared__ int shared_splitsizes[nThreads];
	__shared__ int numLocalActive;
	
	const int idx = threadIdx.x;
	
	// offset into the output split list, increased after each run
	int outputOffset = 0;
	int inputOffset	 = 0;
	int splitsizes = 0;
	
	// we need to run the threadsize-scan as many times as the inputsplit array is long
	// divided by the number of threads we have for each scan.
	int nSplitsLeft = nInputSplits;
	
	while(nSplitsLeft > 0)
	{
		// load data from global memory
		int nActive  = (idx < nSplitsLeft) ? activeSplitMask[inputOffset + idx] : 0;
		int isActive = (nActive > 0) ? 1 : 0;
		splitsizes  += nActive;
		ptr[idx] = isActive;
		
		__syncthreads();
		
		int val = prefixSum<nThreads>(ptr, idx, isActive);
		
		// write out value to split list with modified offset
		if(isActive)
			splitIndexTable[outputOffset + val] = inputOffset + idx;
			
		if(idx == (nThreads - 1))
			numLocalActive = val + isActive;
			
		__syncthreads();
		
		// modify the offsets
		outputOffset += numLocalActive;
		nSplitsLeft -= nThreads;
		inputOffset += nThreads;
	}
	
	// write total of split sizes to memory
	shared_splitsizes[idx] = splitsizes;
	
	__syncthreads();
	
	// parallel reduce on split sizes
	for(int r = nThreads / 2; r != 0; r /= 2)
	{
		if(idx < r)
		{
			shared_splitsizes[idx] += shared_splitsizes[idx + r];
		}
		__syncthreads();
	}
	
	// write out global information about the splits found
	if(idx == 0)
	{
		splitStats->nActiveSplits = outputOffset;
		splitStats->avgSplitSize = shared_splitsizes[0] / (float)outputOffset;
	}
}

/**
 * Like compactSplitList3, but sorts splits under a certain size (SMALLSPLIT_THRESHOLD)
 * into a second split list for small splits.
 */
template <int nThreads> __global__
void compactSplitList_Small(int *splitIndexTable, AABBSplit *splitList, AABBSplit *smallSplitList, int *activeSplitMask, SplitListStats *splitStats, const unsigned int nInputSplits)
{
	// Statically allocated shared memory for scan kernels
	__shared__ int ptr[nThreads];
	__shared__ int shared_splitsizes[nThreads];
	__shared__ int numLocalActive, numLocalSmall;
	
	const int idx = threadIdx.x;
	
	// offset into the output split list, increased after each run
	int outputOffset = 0;
	// offset into the small split list, accumulated
	int outputOffsetSmall = splitStats->nSmallSplits;
	int inputOffset	 = 0;
	int splitsizes = 0;
	
	// we need to run the threadsize-scan as many times as the inputsplit array is long
	// divided by the number of threads we have for each scan.
	int nSplitsLeft = nInputSplits;
	
	while(nSplitsLeft > 0)
	{
		// load data from global memory
		int nActive  = (idx < nSplitsLeft) ? activeSplitMask[inputOffset + idx] : 0;
		int isActive = (nActive > SMALLSPLIT_THRESHOLD) ? 1 : 0;
		int isSmall  = (nActive > 0) ? (1 - isActive) : 0;
		splitsizes  += nActive;
		
		ptr[idx] = isActive;
		__syncthreads();
		int val  = prefixSum<nThreads>(ptr, idx, isActive);
		if(isActive)
			splitIndexTable[outputOffset + val] = inputOffset + idx;
			
		__syncthreads();
		ptr[idx] = isSmall;
		__syncthreads();
		int val2 = prefixSum<nThreads>(ptr, idx, isSmall);
		if(isSmall)
			smallSplitList[outputOffsetSmall + val2] = splitList[inputOffset + idx];
			
		if(idx == (nThreads - 1))
		{
			numLocalActive = val + isActive;
			numLocalSmall  = val2 + isSmall;
		}
		
		__syncthreads();
		
		// modify the offsets
		outputOffset += numLocalActive;
		outputOffsetSmall += numLocalSmall;
		nSplitsLeft -= nThreads;
		inputOffset += nThreads;
	}
	
	// write total of split sizes to memory
	shared_splitsizes[idx] = splitsizes;
	
	__syncthreads();
	
	// parallel reduce on split sizes
	for(int r = nThreads / 2; r != 0; r /= 2)
	{
		if(idx < r)
		{
			shared_splitsizes[idx] += shared_splitsizes[idx + r];
		}
		__syncthreads();
	}
	
	// write out global information about the splits found
	if(idx == 0)
	{
		splitStats->nActiveSplits = outputOffset;
		splitStats->nSmallSplits = outputOffsetSmall;
		splitStats->avgSplitSize = shared_splitsizes[0] / (float)outputOffset;
	}
}

template <int nThreads, int nQueues, class WorkElement> __global__
void balanceWorkList(WorkElement *workQueueIn, WorkElement *workQueueOut, unsigned int *workQueueCount, const unsigned int maxQueueSize, unsigned int *totalEntries)
{
	__shared__ int shared_sum[nThreads];
	__shared__ int shared_queuesizes[nQueues];
	const int idx = threadIdx.x;
	
	// sum on workQueueCount to find total number of entries
	int nSplitsLeft = nQueues, inputOffset = idx;
	shared_sum[idx] = 0;
	while(idx < nSplitsLeft)
	{
		int nQueueElements = workQueueCount[inputOffset];
		shared_queuesizes[inputOffset] = nQueueElements;
		shared_sum[idx] += nQueueElements;
		inputOffset += nThreads;
		nSplitsLeft -= nThreads;
	}
	__syncthreads();
	
	// sum up shared values
	REDUCE(shared_sum, idx, nThreads, +);
	
	// compute how many splits to put in each queue
	nSplitsLeft = shared_sum[0];
	int nSplitsPerQueue = (int)ceilf(nSplitsLeft / (float)nQueues);
	
	// write total number back to global mem
	if(idx == 0)
		*totalEntries = nSplitsLeft;
		
	// for each queue
	inputOffset = 0;
	int outputOffset = 0, inputQueue = -1, inputQueueCount = 0;
	for(int q = 0; q < nQueues; q++)
	{
		// how many splits to put in this queue (can be less for last queue)
		int nSplitsLocal = min(nSplitsLeft, nSplitsPerQueue);
		outputOffset = maxQueueSize * q + idx;
		
		if(idx == 0)
			workQueueCount[q] = nSplitsLocal;
			
		while(nSplitsLocal > 0)
		{
			// still splits left in current input queue?
			if(inputQueueCount <= 0)    // no, go to next one
			{
				inputQueue++;
				inputOffset = idx;
				inputQueueCount = shared_queuesizes[inputQueue];
				continue;
			}
			
			// ok, got a queue with entries left to distribute
			int splitsToWrite = min(nSplitsLocal, inputQueueCount);
			splitsToWrite = min(splitsToWrite, nThreads);
			
			// each thread writes one entry
			if(idx < splitsToWrite)
				workQueueOut[outputOffset] = workQueueIn[inputQueue*maxQueueSize + inputOffset];
			nSplitsLocal -= splitsToWrite;
			inputOffset  += splitsToWrite;
			outputOffset += splitsToWrite;
			inputQueueCount -= splitsToWrite;
			nSplitsLeft -= splitsToWrite;
			
			__syncthreads();
		}
	}
}


template <int nThreads, int nQueues, class WorkElement> __global__
void balanceFrontList(WorkElement *workQueueIn, WorkElement *workQueueOut, unsigned int *workQueueCount, const unsigned int maxQueueSize, unsigned int *totalEntries)
{
	const int idx = threadIdx.x;
	
	// compute how many splits to put in each queue
	unsigned int nSplitsLeft = *totalEntries;
	int nSplitsPerQueue = (int)ceilf(nSplitsLeft / (float)nQueues);
	
	// for each queue
	int inputOffset = idx;
	int outputOffset = 0;
	for(int q = 0; q < nQueues; q++)
	{
		// how many splits to put in this queue (can be less for last queue)
		int nSplitsLocal = min(nSplitsLeft, nSplitsPerQueue);
		outputOffset = maxQueueSize * q + idx;
		
		if(idx == 0)
			workQueueCount[q] = nSplitsLocal;
			
		while(nSplitsLocal > 0)
		{
			// ok, got a queue with entries left to distribute
			int splitsToWrite = min(nSplitsLocal, nThreads);
			
			// each thread writes one entry
			if(idx < splitsToWrite)
				workQueueOut[outputOffset] = workQueueIn[inputOffset];
			inputOffset  += splitsToWrite;
			outputOffset += splitsToWrite;
			nSplitsLeft -= splitsToWrite;
			nSplitsLocal -= splitsToWrite;
			
			__syncthreads();
		}
	}
}

#endif
