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
 
#include "lbvh.h"
#include "radixsort.h"
#include <stdio.h>

void check_cuda_error(const char *msg)
{
	cudaError_t err = cudaGetLastError();
	if (err != cudaSuccess)
	{
		fprintf(stderr, "CUDA Error: %s in %s\n", cudaGetErrorString(err), msg);
		exit(EXIT_FAILURE);
	}
}


// Input: level - an array of "levels" one per overlapping adjacent pair of
//                faces. This is the octet at which Z codes of two neighboring
//                faces differ.
// Input: split_pos - an array of indices. This is the index of the left
//                    triangle of each overlapping pair which created the split
// Input: spaces - array of offsets one per item in the levels array. This is
//                 final position in the splits array each level:split_pos
//                 pair (split) will go to. The other intermediate positions
//                 will be filled by this position.
// Output: split_lvl - The final array of levels - one per split
// Output: split_lvl_pos - The final array of positions at a level where the split occurs
__global__ void generate_missing_splits(size_t N, unsigned int *level,
                                        unsigned int *split_pos, unsigned int *spaces,
                                        unsigned int *split_lvl, unsigned int *split_lvl_pos
                                       )
{
	// My index
	unsigned int tid = (blockIdx.x * blockDim.x) + threadIdx.x;
	
	// We may spawn more threads than we need so that all blocks
	// of the same size - so check if we are within valid range
	if (tid < N)
	{
		// Generate splits not already there in the given level and split_pos
		// array. For a given split l:s we need to generate l:s, l+1:s all
		// the way up to maxDepthToCheck:s
		for (unsigned int i = 0; i < (maxDepthToCheck - level[tid]); ++i)
		{
			split_lvl[spaces[tid] + i] = level[tid] + i;
			split_lvl_pos[spaces[tid] + i] = split_pos[tid];
		}
	}
	__syncthreads();
}



void gpu_generate_missing_splits(unsigned int N, unsigned int *level,
                                 unsigned int *split_pos, unsigned int *spaces,
                                 unsigned int *split_lvl, unsigned int *split_lvl_pos
                                )
{
	generate_missing_splits <<< BLOCKING(N, 256) >>> (N, level, split_pos,
	        spaces, split_lvl, split_lvl_pos
	                                                 );
	                                                 
	cudaThreadSynchronize();
	check_cuda_error("diff_generate_missing_splits");
}


// Input: split_lvl - an array of levels - one per split
// Input: split_lvl_pos - an array of position in each level where the split occurs
// Input: node_offset - an array of offsets, one per split where each
//                      split will start writing its corresponding nodes
// Input: numPrimitives - Total number of faces
// Output: nodes - array of nodes created by the splits
__global__ void generate_nodes_from_splits(
    const unsigned int* split_lvl,
    const unsigned int* split_lvl_pos,
    BVNode *nodes, const unsigned int *node_offset,
    unsigned int N, unsigned int numPrimitives
)
{
	// My index
	unsigned int tid = threadIdx.x + blockIdx.x * blockDim.x;
	
	// We need to do some special processing if a split is the first or the
	// last split in a level
	// If a split is the first split in a level it would generate two nodes
	// If a split is the last split in a level it would generate one node
	// but the upper bound on its range of faces would be the total number of
	// faces in the scene
	// If neither of these two cases happen then one split generats one node
	// and the its range of faces is
	// [split's value + 1, right neighboring split's value + 1]
	bool firstSplitInLevel = false;
	bool lastSplitInLevel = false;
	
	// We may spawn more threads than we need so that all blocks
	// of the same size - so check if we are within valid range
	if (tid < N)
	{
		// Where should I write my node
		unsigned int writeOffset = node_offset[tid];
		
		// The faces interval
		Interval I;
		
		// Check if a split is the first in its level. Special
		// case to generate the root node.
		if (tid == 0)
		{
			// If this is the first split then it is also going to be
			// the first split in this level (we sorted the splits and
			// the sort is stable)
			firstSplitInLevel = true;
			
			// The first thread actually writes three nodes - the root node
			// and the first two nodes in the next level
			
			// We write the root node - the other two nodes are written later
			// since all other splits which are the first in their level
			// also have two write two nodes.
			I.begin = 0;
			I.end = numPrimitives;
			nodes[writeOffset].faces = I;
			nodes[writeOffset].level = 0;
			writeOffset++;
		}
		else
		{
			// A split is the first in its level if its level is different from
			// its left neighbors
			unsigned int lvl = split_lvl[tid];
			unsigned int lvl_l = split_lvl[tid-1];
			
			if (lvl != lvl_l)
				firstSplitInLevel = true;
		}
		
		// Check if a split is the last split in a level. Special case for the
		// last split which is a boundary condition
		if (tid == N - 1)
			lastSplitInLevel = true;
		else
		{
			// A split is the last in its level if its level is different from
			// its right neighbors
			unsigned int lvl = split_lvl[tid];
			unsigned int lvl_r = split_lvl[tid+1];
			if (lvl != lvl_r)
				lastSplitInLevel = true;
		}
		
		// If this is the first split in a level - generate that extra node
		if (firstSplitInLevel)
		{
			I.begin = 0;
			I.end = split_lvl_pos[tid] + 1;
			nodes[writeOffset].faces = I;
			
			// A split which is at level 0 is actually a node at level 1 and
			// so on and so forth. If the Z codes of two faces differ in the
			// first octet then their level is 0. But that split will generate
			// two nodes at level 1 (Level 0 is the root node which does not
			// correspond to any split)
			nodes[writeOffset].level = split_lvl[tid] + 1;
			
			// Increment offset so that the next node can be written
			writeOffset++;
		}
		
		// If this is the last node in a split then the upper bound on the faces
		// interval is the total number of faces. Otherwise if follows the usual
		// calculation
		if (lastSplitInLevel)
		{
			I.begin = split_lvl_pos[tid] + 1;
			I.end = numPrimitives;
		}
		else
		{
			I.begin = split_lvl_pos[tid] + 1;
			I.end = split_lvl_pos[tid+1] + 1;
		}
		
		// Write the faces interval and the level of this particular node
		nodes[writeOffset].faces = I;
		nodes[writeOffset].level = split_lvl[tid] + 1;
	}
}


// Input: split_lvl - an array of levels - one per split
// Output: node_offset - an array of nodes per split. For every
//                       split in in the splits array generate
//                       the number of nodes it will create
__global__ void generate_offsets_for_nodes(unsigned int *node_offset,
        const unsigned int* split_lvl,
        unsigned int N)
{
	// My index
	unsigned int tid = threadIdx.x + blockIdx.x * blockDim.x;
	
	// We may spawn more threads than we need so that all blocks
	// of the same size - so check if we are within valid range
	if (tid < N)
	{
		if (tid == 0)
		{
			// This is 3 because we need to write 3 nodes
			// 1. the root node
			// 2. the "extra node" since we are the first split
			//      at this level
			// 3. the node itself
			node_offset[tid] = 3;
		}
		else
		{
			unsigned int lvl = split_lvl[tid];
			unsigned int lvl_l = split_lvl[tid-1];
			
			// If my level is different from my left neighbor's then
			// I am the first split in this level - hence I will
			// create two nodes
			if (lvl != lvl_l)
				node_offset[tid] = 2;
			else
				node_offset[tid] = 1;
		}
	}
}


// Input: nodes - an array of nodes
// Output: faceEndIdx - an array of indices of the face which is the upper bound of the
//                      faces interval
// Output: nodeIdx - an array of node indices which is just the thread id
__global__ void generate_faceendandidx_from_nodes(
    unsigned int* faceEndIdx,
    unsigned int* nodeIdx,
    BVNode* nodes, unsigned int N
)
{
	// My index
	unsigned int tid = threadIdx.x + (blockIdx.x * blockDim.x);
	
	// We may spawn more threads than we need so that all blocks
	// of the same size - so check if we are within valid range
	if (tid < N)
	{
		faceEndIdx[tid] = nodes[tid].faces.end;
		nodeIdx[tid] = tid;
	}
}


// Input: nodes - an array of nodes
// Output: node_start - an array indices one per level, each of which
//                      is the index of the first node in that level
//                      in the nodes array
__global__ void generate_levelstart_idx(unsigned int *node_start,
                                        BVNode *nodes, unsigned int N)
{
	// My index
	unsigned int tid = threadIdx.x + (blockIdx.x * blockDim.x);
	
	// We may spawn more threads than we need so that all blocks
	// of the same size - so check if we are within valid range
	if (tid < N)
	{
		// The first node is always the first node in that level
		// Else look to your left and if your left neighbor has
		// a different level than you then you are the first
		// node in that level. Write your index to the
		// appropriate location in the node_start array
		if (tid == 0)
		{
			unsigned int lvl = nodes[tid].level;
			node_start[lvl] = tid;
		}
		else
		{
			unsigned int lvl = nodes[tid].level;
			unsigned int lvl_l = nodes[tid-1].level;
			
			if (lvl != lvl_l)
				node_start[lvl] = tid;
		}
	}
}


// Input: faceEndIdx - an array of indices of the face which is the upper bound of the
//                     faces interval
// Input: nodeIdx - an array of node indices corresponding to the upper bound of the faces interval
// Output: nodes - an array of nodes whose children intervals get updated
// Note: This is the first phase of the node updation. In this phase only
//       the leaves have the correct children intervals. The information
//       generated in this step is used by the second phase to generate
//       correct children intervals for all nodes.
__global__ void    generate_child_links_first_phase(BVNode *nodes,
        const unsigned int *faceEndIdx,
        const unsigned int *nodeIdx,
        unsigned int N)
{
	// My index
	unsigned int tid = threadIdx.x + (blockIdx.x * blockDim.x);
	
	// We may spawn more threads than we need so that all blocks
	// of the same size - so check if we are within valid range
	if (tid < N)
	{
		Interval I;
		
		// Me and my right neighbors key
		unsigned int key_r = faceEndIdx[tid+1];
		unsigned int key = faceEndIdx[tid];
		
		// Me and my right neighbors value
		unsigned int value = nodeIdx[tid];
		unsigned int value_r = nodeIdx[tid+1];
		
		// The last node has to be a child - this is done
		// separately since the last node has no right
		// neighbor
		if (tid == N - 1)
		{
			I.begin = 0;
			I.end = 0;
		}
		else
		{
			// This is a bit subtle - when you arrange the
			// nodes by the face-id of the upper bound of the
			// face in their faces interval (all faces under
			// that node) - then you can pick out the leaf
			// nodes by looking at the face-id's of two neighboring
			// nodes. If they differ it is a leaf. Drawing
			// a tree and thinking about it helps to visualize
			// this. If they are equal then one is the rightmost
			// child of the other. Remember value is the index
			// to that node (rightmost child). Hence we set
			// I.end to value_r+1
			if (key != key_r)
			{
				I.begin = 0;
				I.end = 0;
			}
			else
			{
				I.end = value_r + 1;
			}
		}
		
		// Set the children interval. The begin will be wrong for
		// non-leaf nodes - but that will be fixed in the second
		// phase.
		nodes[value].children.begin = I.begin;
		nodes[value].children.end = I.end;
	}
}


// Input: nodeIdx - an array of node indices corresponding to the upper bound of the faces interval
// Input: node_start - array of indices of nodes in the nodes array, which are the
//                     first nodes in their level
// Input: leafLevel - level of leaves
// Output: nodes - an array of nodes whose children intervals get updated
// Note: This is the second phase of the node updation. Genrates the correct
//       lower bound for child intervals for non-leaf nodes
__global__ void    generate_child_links_second_phase(BVNode *nodes,
        const unsigned int *nodeIdx,
        unsigned int *node_start,
        unsigned int leafLevel,
        unsigned int N)
{
	// My index
	unsigned int tid = threadIdx.x + (blockIdx.x * blockDim.x);
	
	// We may spawn more threads than we need so that all blocks
	// of the same size - so check if we are within valid range
	if (tid < N)
	{
		bool leftNbrDiffKey = false;
		
		// What is the node corresponding to this entry in
		// faceEndAndIdx
		unsigned int nodeIndex = nodeIdx[tid];
		
		// Leaves have their children already updated so no need
		// to update
		if (nodes[nodeIndex].level != leafLevel)
		{
			// What we are trying to do here is figure which
			// nodes are the first nodes in their level. The first
			// node is of course the first node. For the rest
			// we look at their left neighbor and if their
			// levels differ then we set leftNbrDiffKey flag to
			// true
			if (nodeIndex == 0)
				leftNbrDiffKey = true;
			else
			{
				unsigned int lvl = nodes[nodeIndex].level;
				unsigned int lvl_l = nodes[nodeIndex-1].level;
				
				if (lvl != lvl_l)
					leftNbrDiffKey = true;
			}
			
			unsigned int begin;
			
			// If this node is first node in this level then
			// its left child (lower bound of the child interval)
			// is the first node in the subsequent level. This is
			// where the node_start array comes handy since for
			// each level it keeps the index of the first node
			// in that level. If a node is not the first
			// node in that level then its leftmost child is
			// one to the right of its left neighbor's righmost
			// child which is the upper bound of its left
			// neighbor's children interval. This is why we
			// had to calculate the upper bounds in a separate
			// pass. A causality of the absence of a global sync
			if (leftNbrDiffKey)
			{
				unsigned int lvl = nodes[nodeIndex].level;
				begin = node_start[lvl+1];
			}
			else
				begin = nodes[nodeIndex-1].children.end;
				
			// Set the correct lower bound of the children interval
			nodes[nodeIndex].children.begin = begin;
		}
	}
}


// Input: nodes - an array of nodes
// Output: nodes - an array of nodes
// Note: Input and output are the same since for every node we are writing
//       the index of its parent
__global__ void    generate_parent_info(BVNode *nodes, unsigned int N)
{
	// My index
	unsigned int tid = threadIdx.x + (blockIdx.x * blockDim.x);
	
	// We may spawn more threads than we need so that all blocks
	// of the same size - so check if we are within valid range
	if (tid < N)
	{
		// For every node - go over its list of children and set
		// their parent pointer to this node
		for (unsigned int i = nodes[tid].children.begin;
		        i < nodes[tid].children.end; ++i)
		{
			nodes[i].parent = tid;
		}
	}
}


// Input: nodes - an array of nodes
// Output: nodes - an array of nodes
// Note: Input and output are the same since we are contracting the tree.
//       By contracting I mean that if a node has one child then it should
//       inherit all its grandchildren and remove its single chidl
__global__ void contract_skinny_branches(BVNode *nodes, unsigned int N)
{
	// My index
	unsigned int tid = threadIdx.x + (blockIdx.x * blockDim.x);
	
	// We may spawn more threads than we need so that all blocks
	// of the same size - so check if we are within valid range
	if (tid < N)
	{
		// The high level algorithm -
		// 1. For every leaf look at its parent
		//    1a. If the parent has only one child then the parent
		//        inherits all its grandchildren
		// 2. If this is the leftmost child then go up the tree
		//    to its parent and repeat from 1 until you hit root
		// Note: Since only the thread corresponding to the leftmost
		//       child climbs up there is no contention
		
		// Check if this is a leaf - leaves have no (0,0) children
		// interval
		bool isLeaf =
		    ((nodes[tid].children.end - nodes[tid].children.begin) == 0);
		    
		if (isLeaf)
		{
			// Index of the parent in the nodes array
			unsigned int parent = nodes[tid].parent;
			
			// Index of the child in the nodes array
			unsigned int child = tid;
			
			// Repeat until you hit root
			while (nodes[parent].level != 0)
			{
				// TODO:
				// Update bounding box here - unfortuately this has to be
				// different for leaves and internal nodes. For leaves the bounding box
				// calculation happens over the vertices - while for internal
				// nodes the bounding box calculation just needs to look up
				// internal nodes (children)
				/*
				if ((nodes[child].children.end - nodes[child].children.begin) == 0)
				{
				for (unsigned int i = nodes[child].faces.begin;
				i < nodes[child].faces.end; ++i)
				{
				}
				}
				else
				{
				for (unsigned int i = nodes[child].children.begin;
				i < nodes[child].children.end; ++i)
				{
				}
				}
				*/
				
				// If the parent has only one child then it inherits its children's
				// faces and children interval.
				// Else choose the thread corresponding to the leftmost child and only
				// let it climb up
				if ((nodes[parent].children.end - nodes[parent].children.begin) == 1)
				{
					unsigned int childIdx = nodes[parent].children.begin;
					nodes[parent].children = nodes[childIdx].children;
					nodes[parent].faces = nodes[childIdx].faces;
				}
				else
				{
					bool isLeftMostChild = (child == nodes[parent].children.begin);
					if (!isLeftMostChild)
					{
						break;
					}
				}
				
				// Leftmost child climbs up
				child = parent;
				parent = nodes[parent].parent;
			}
		}
	}
}


