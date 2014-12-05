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
 
#ifndef __LBVH_H_
#define __LBVH_H_

typedef unsigned int IndexCode;

#define LOG_NBRANCH 1


void check_cuda_error(const char *msg);

// We have a 8-way tree so log of that is 3. maxDepthToCheck is one less
// than the number of octets in a word which is 32 bits right now.
//static const unsigned int maxDepthToCheck = ((sizeof(unsigned int) * 8)/3) - 1;
//static const unsigned int maxDepthToCheck = 30;
// changed for binary build -- CL

//static const unsigned int maxDepthToCheck = (sizeof(unsigned int) * 8) % LOG_NBRANCH == 0 ?
//(((sizeof(unsigned int) * 8) / LOG_NBRANCH) - 2) :
//(((sizeof(unsigned int) * 8) / LOG_NBRANCH) - 1);
static const unsigned int maxDepthToCheck = ((sizeof(unsigned int) * 8)/3) - 1;

#define BLOCKING(size, width) ((size)+(width)-1)/(width), width



struct Interval
{
	unsigned int begin, end;
};

struct BVNode
{
	unsigned int level;
	Interval faces;
	Interval children;
	unsigned int parent;
};

struct LBVH
{
	unsigned int *level;
	unsigned int *splitPos;
	BVNode *Nodes;
	unsigned int numSplits;
	unsigned int numNodes;
};

/** Structure used in BVH construction process
 */
typedef struct
{
	double timeSplitMs,    ///< time for split
	       timeCompactMs,  ///< time for compact
	       timeBucketMs;   ///< time bucket
	int nActiveSplits;     ///< number of active splits
} ConstructionLevelStats;


// Input: codes - the Z code
// Output: level - an array of "levels" one per overlapping adjacent pair of
//                 faces. This is the octet at which Z codes of two neighboring
//                 faces differ. In essence this level represents two nodes -
//                 the split separates the rightmost face in the subtree under
//                 the left node from the leftmost face in the subtree under
//                 the right node.
// Output: split_pos - an array of indices. This is the index of the left
//                     triangle of each overlapping pair which created the split
// Output: spaces - an auxiliary array. A split which occurs at level l also
//                  also occurs at level l+1, all the way down to the leaf.
//                  However we do not generate this information in this kernel.
//                  We generate these implicit splits in another pass. But for
//                  each split generated in this kernel we need to know how many
//                  more splits we need to generate in the lower levels in the
//                  tree. This is the array which keeps track of this information
template<unsigned int logB>
__global__ void diff_bits_w_nbr_kernel(
									   unsigned int *codes,
									   size_t N,
									   unsigned int *level,
									   unsigned int *split_pos,
									   unsigned int *spaces)
{
	// My index
	unsigned int tid = (blockIdx.x * blockDim.x) + threadIdx.x;

	// My right neighbors index
	unsigned int tid_r = tid + 1;

	// This is the mask 0011 1000 0000 0000 0000 0000 0000 0000
	// Used to pick the first 3 bits and then so on and so forth
	// This actually assumes that logB is 3 - needs to be fixed
	//unsigned int mask = 0x38000000;
	//unsigned int mask = 1 << 29; /// changed for binary -- CL
	unsigned int mask = ((1 << logB) - 1) << (30 - logB);

	// We may spawn more threads than we need so that all blocks
	// of the same size - so check if we are within valid range
	if (tid < N)
	{
		unsigned int differPos = 0;

		// Go over every "octet" (octet only if branching factor
		// is 8 - in the general case this would be
		// log_2 (branching factor) set of bits) and see at
		// which octet do the Z codes of two neighboring triangles
		// differ. One important thing to note that in the specific
		// case of 30 bit Z values and 3 bit octets - there are 10
		// octets in the Z value. However I am only going over 9
		// (that is the value of maxDepthToCheck in this case) octets
		// This is because each leaf in Bvh should have all those faces
		// whose Z codes match in the first 9 octets. This will
		// hold in general.
		for (unsigned int i = 0; i < maxDepthToCheck; ++i)
		{
			// My Z code
			IndexCode p = codes[tid];

			// My neighbors Z code
			IndexCode p_r = codes[tid_r];

			// Bits in my i-th octet
			unsigned int l_bits = p & mask;

			// Bits in my neighbors i-th octet
			unsigned int r_bits = p_r & mask;

			// If they differ then we have found the octet in which
			// me and my neighbor differ.
			// Else increment the octet number and shift the mask
			// so that I select the next octet in the next iteration
			if (l_bits != r_bits)
			{
				break;
			}
			else
			{
				differPos++;
				mask = mask >> logB;
			}
		}

		// This is the octet at which Z codes of two neighboring
		// faces differ.
		level[tid] = differPos;

		// Position of the split in the array. This is the index
		// of the left face in each pair
		split_pos[tid] = tid;

		// For each split how many more splits do we have to
		// generate in the lower levels of the tree
		spaces[tid] = (maxDepthToCheck - differPos);
	}
	__syncthreads();
}


__global__ void generate_missing_splits(size_t N, unsigned int *level,
										unsigned int *split_pos, unsigned int *spaces,
										unsigned int *split_lvl, unsigned int *split_lvl_pos
										);


template <typename ConstructionState>
void gpu_diff_bits_w_nbr(const ConstructionState *on_device, unsigned int *level,
						 unsigned int *split_pos, unsigned int *spaces)
{
	/// CL
	diff_bits_w_nbr_kernel<LOG_NBRANCH> <<< BLOCKING(on_device->nElements - 1, 256) >>>
		(on_device->zCodes, on_device->nElements - 1, level, split_pos, spaces);

	cudaThreadSynchronize();
	check_cuda_error("diff_bits_w_nbr_kernel");

}

void gpu_generate_missing_splits(unsigned int N, unsigned int *level,
								 unsigned int *split_pos, unsigned int *spaces,
								 unsigned int *split_lvl, unsigned int *split_lvl_pos
								 );

__global__ void generate_nodes_from_splits(
	const unsigned int* split_lvl,
	const unsigned int* split_lvl_pos,
	BVNode *nodes, const unsigned int *node_offset,
	unsigned int N, unsigned int numPrimitives
	);

__global__ void generate_offsets_for_nodes(unsigned int *node_offset,
										   const unsigned int* split_lvl,
										   unsigned int N);

__global__ void generate_faceendandidx_from_nodes(
	unsigned int* faceEndIdx,
	unsigned int* nodeIdx,
	BVNode* nodes, unsigned int N
	);

__global__ void generate_levelstart_idx(unsigned int *node_start,
										BVNode *nodes, unsigned int N);

__global__ void    generate_child_links_first_phase(BVNode *nodes,
													const unsigned int *faceEndIdx,
													const unsigned int *nodeIdx,
													unsigned int N);

__global__ void    generate_child_links_second_phase(BVNode *nodes,
													 const unsigned int *nodeIdx,
													 unsigned int *node_start,
													 unsigned int leafLevel,
													 unsigned int N);

__global__ void    generate_parent_info(BVNode *nodes, unsigned int N);

__global__ void contract_skinny_branches(BVNode *nodes, unsigned int N);


#endif