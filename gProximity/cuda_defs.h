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
 
#ifndef __CUDA_DEFS_H_
#define __CUDA_DEFS_H_

#include <float.h>
#include <cuda.h>

#ifndef max
#define max(a,b) (((a) > (b)) ? (a) : (b))
#endif
#ifndef min
#define min(a,b) (((a) < (b)) ? (a) : (b))
#endif


//#define USETEXTUREBUFFER // undef if hope to use global memory instead of texture buffer for storing vertex and triangle

#define QUEUE_NTASKS 128
#define LOG_QUEUE_NTASKS 7
#define QUEUE_SIZE_PER_TASK 600
#define QUEUE_SIZE_PER_TASK_GLOBAL 50000
#define QUEUE_IDLETASKS_FOR_ABORT QUEUE_NTASKS*2/3
#define TRAVERSAL_THREADS 64
#define BALANCE_THREADS 512 //256
#define QUEUE_SIZE_PER_TASK_INIT TRAVERSAL_THREADS*3
#define QUEUE_NTASKS_PER_CIRCLE 50000
#define QUEUE_REFILL_THRESHOLD QUEUE_NTASKS_PER_CIRCLE*1.5
#define COLLISION_PAIR_CAPACITY 16000000

#define COLLISIONFREE_RES 1
#define COLLISION_RES 0
#define COLLISIONFREE_TAG (make_ushort2(-1, -1))

#define COLLISION_THREADS 32
#define COLLISION_STACK_SIZE 32
//#define COLLISION_THREADS 8
//#define COLLISION_STACK_SIZE 128
#define GENERAL_THREADS 256

#define BVH_PACKET_BLOCK_WIDTH 32
#define BVH_PACKET_BLOCK_HEIGHT 9
//#define BVH_PACKET_STACK_SIZE 32
#define BVH_PACKET_STACK_SIZE 97
#define BVH_PACKET_OVERLAP_SUM_SIZE 32

#define CCD_MAX_INTERPOLATION 16
#define LOG_CCD_MAX_INTERPOLATION 4

#define WARP_SIZE 32
#define HALF_WARP_SIZE 16
#define TWO_WARP_SIZE 64
#define WARP_SIZE_LOG2 5

#define LBVH_GRID_LEVELS 10
#define AABB_BLOCK_SIZE 256
#define SMALLSPLIT_THRESHOLD WARP_SIZE
#define AABB_BOUNDINGBOX_THREADS 256

#define SCAN_NUM_BANKS 16
#define SCAN_LOG_NUM_BANKS 4

#define SEPARATE_MODE 0
#define ALLINONE_MODE 1
//#define COLLISION_MODE SEPARATE_MODE
#define COLLISION_MODE ALLINONE_MODE

// how many triangles to have at the leaves of the tree (can be less,
// but not more)
#define SCENE_SPLIT_LEAFTRIS 0

#define NSPLIT_CANDIDATES (2*WARP_SIZE)
#define NSPLIT_AXES 1
#define SCAN_THREADS (NSPLIT_CANDIDATES * NSPLIT_AXES)
#define SPLIT_THREADS NSPLIT_CANDIDATES

// Threads used for main work queue compaction kernel
#define SPLITLIST_COMPACTION_THREADS 32

#define CONDOREMU_SYNC(cond) if (cond) __syncthreads()


#define SCAN_CONFLICT_FREE_OFFSET(index) ((index) >> SCAN_LOG_NUM_BANKS)

#define GPUMALLOC(D_POINTER, SIZE) CUDA_SAFE_CALL(cudaMalloc(D_POINTER, SIZE))
#define CPUMALLOC(H_POINTER, SIZE) CUDA_SAFE_CALL(cudaMallocHost(H_POINTER, SIZE))

//#define CPUFREE(H_POINTER)  if(H_POINTER) CUDA_SAFE_CALL(cudaFreeHost(H_POINTER))

#define CPUFREE(H_POINTER) \
	do { \
	if(H_POINTER) CUDA_SAFE_CALL(cudaFreeHost(H_POINTER)); \
	H_POINTER = NULL; \
	} while(0)

#define GPUFREE(D_POINTER) \
	do { \
	if(D_POINTER) CUDA_SAFE_CALL(cudaFree(D_POINTER)); \
	D_POINTER = NULL; \
	} while(0)

#define TOGPU(D_POINTER, H_POINTER, SIZE) CUDA_SAFE_CALL(cudaMemcpy(D_POINTER, H_POINTER, SIZE, cudaMemcpyHostToDevice))
#define FROMGPU(H_POINTER, D_POINTER, SIZE) CUDA_SAFE_CALL(cudaMemcpy(H_POINTER, D_POINTER, SIZE, cudaMemcpyDeviceToHost))
#define GPUTOGPU(D_TO, D_FROM, SIZE) CUDA_SAFE_CALL(cudaMemcpy(D_TO, D_FROM, SIZE, cudaMemcpyDeviceToDevice))

#define TOGPU_CONSTANT(D_POINTER, H_POINTER, SIZE, OFFSET) CUDA_SAFE_CALL(cudaMemcpyToSymbol(D_POINTER, H_POINTER, SIZE, OFFSET, cudaMemcpyHostToDevice))
#define GPUTOGPU_CONSTANT(D_TO, D_FROM, SIZE, OFFSET) CUDA_SAFE_CALL(cudaMemcpyToSymbol(D_TO, D_FORM, SIZE, OFFSET, cudaMemcpyDeviceToDevice))

#define GPUMEMSET(D_POINTER, INTVALUE, SIZE) CUDA_SAFE_CALL(cudaMemset(D_POINTER, INTVALUE, SIZE))

#ifdef __DEVICE_EMULATION__
#define EMULATION_ONLY_SYNC() __syncthreads()
#define CONDOREMU_SYNC(cond) __syncthreads()
#else
#define EMULATION_ONLY_SYNC()
#define CONDOREMU_SYNC(cond) if (cond) __syncthreads()
#endif

#define CUDA_UPPERROUND4(size) (ceilf(size/4.0f) * 4)


#ifndef CUDART_NORM_HUGE_F
#define CUDART_NORM_HUGE_F FLT_MAX
#endif

#define MAX_BLOCKS_PER_DIMENSION 65535

#endif