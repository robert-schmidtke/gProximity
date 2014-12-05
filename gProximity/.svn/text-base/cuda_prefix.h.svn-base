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
 
#ifndef __CUDA_PREFIX_H_
#define __CUDA_PREFIX_H_

/**
 * Prefix-sum implementation.
 */

#include "cuda_defs.h"


// Warp-size prefix sum on array ptr in shared memory, based on Timo Aila's code
template <int maxlevel>
__device__ int scanwarp(int* ptr, const int idx)
{
	int val = ptr[idx];
	int oval = val;
	
	if(2 <= maxlevel)
	{
		if(idx & 1)	val += ptr[(idx | (1-1))  ^ 1], ptr[idx] = val;
	}
	if(4 <= maxlevel)
	{
		if(idx & 2)	val += ptr[(idx | (2-1))  ^ 2], ptr[idx] = val;
	}
	if(8 <= maxlevel)
	{
		if(idx & 4)	val += ptr[(idx | (4-1))  ^ 4], ptr[idx] = val;
	}
	if(16 <= maxlevel)
	{
		if(idx & 8)	val += ptr[(idx | (8-1))  ^ 8], ptr[idx] = val;
	}
	if(32 <= maxlevel)
	{
		if(idx & 16)	val += ptr[(idx | (16-1)) ^16], ptr[idx] = val;
	}
	
	return val - oval;	// inclusive -> exclusive
}

template <int maxThreads>
static __device__ __inline__ int prefixSum(int *sharedPtr, int idx, const int oval)
{
	// val = prefix sum of local warp block
	
	int val = scanwarp<WARP_SIZE>(sharedPtr, idx);
	
	// write all max. elements into first WARP_SIZE elements
	// (only works it nThreads/WARP_SIZE <= WARP_SIZE!)
	if((idx & (WARP_SIZE - 1)) == (WARP_SIZE - 1))
		sharedPtr[idx >> WARP_SIZE_LOG2] = val + oval;
		
	__syncthreads();
	
	// do prefix sum of max. element of all blocks
	if(idx < WARP_SIZE)
		sharedPtr[idx] = scanwarp< (maxThreads >> WARP_SIZE_LOG2) > (sharedPtr, idx);
		
	__syncthreads();
	
	// add the offset for this warp on all elements
	val += sharedPtr[idx >> WARP_SIZE_LOG2];
	
	return val;
}

// reduction in shared memory
#define REDUCE(shared,idx,nThreads,op) do { for (int r = nThreads/2; r != 0; r /= 2) {\
												if (idx < r) shared[idx] = shared[idx] op shared[idx + r];\
												__syncthreads(); } } while (0);

#define REDUCE_FCN(shared,idx,nThreads,FCN) do { for (int r = nThreads/2; r != 0; r /= 2) {\
												if (idx < r) shared[idx] = FCN (shared[idx],shared[idx + r]);\
												__syncthreads(); } } while (0);

// this is a cleaner solution to reduction, but in practice is slower than the macro above!
template <int nThreads, typename T>
static __device__ __inline__ void sharedReduce_Add(T *shared, const unsigned int idx)
{
	if(nThreads >= 512)
	{
		if(idx < 256) shared[idx] = shared[idx] + shared[idx + 256];
		__syncthreads();
	}
	if(nThreads >= 256)
	{
		if(idx < 128) shared[idx] = shared[idx] + shared[idx + 128];
		__syncthreads();
	}
	if(nThreads >= 128)
	{
		if(idx < 64) shared[idx] = shared[idx] + shared[idx + 64];
		__syncthreads();
	}
	if(nThreads >= 64)
	{
		if(idx < 32) shared[idx] = shared[idx] + shared[idx + 32];
		__syncthreads();
	}
	
	// from now on we're on a per-warp basis and don't need to __syncthreads() all the time
	if(nThreads >= 32)
		if(idx < 16) shared[idx] = shared[idx] + shared[idx + 16];
	if(nThreads >= 16)
		if(idx < 8) shared[idx] = shared[idx] + shared[idx + 8];
	if(nThreads >= 8)
		if(idx < 4) shared[idx] = shared[idx] + shared[idx + 4];
	if(nThreads >= 4)
		if(idx < 2) shared[idx] = shared[idx] + shared[idx + 2];
	if(nThreads >= 2)
		if(idx < 1) shared[idx] = shared[idx] + shared[idx + 1];
		
	if(nThreads > 32) __syncthreads();
}


#endif
