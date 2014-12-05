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
 
#ifndef __CUDA_AABBNODE_H__
#define __CUDA_AABBNODE_H__

#include "cuda_aabb.h"

/** CUDA axis-aligned bounding box class
 */
struct AABBNode
{
public:
	AABB bbox;	///< actual bounding box
	
	/**
	 * Compact representation of several members:
	 *  - lower 2 bits:
	 *     0-2: split axis (x,y,z)
	 *       3: node is leaf
	 *  - upper 27 bits:
	 *     - for inner node: address to first child
	 *       (second child is in consecutive location)
	 *  - upper 30 bits
	 *     - for leaf node: triangle index
	 **/
	union
	{
		unsigned int lChild;
		unsigned int leafTriID;
		unsigned int left;
	};
	
	unsigned int right;
	
	__device__ __inline__ bool isLeaf() const
	{
		return (left & 3) == 3;
	}
	
	__device__ __inline__ int getLeftChild() const
	{
		return left >> 5;
	}
	//__device__ __inline__ int getRightChild() const
	//{
	//	return (left >> 5) + 1;
	//}
	__device__ __inline__ int getTriID() const
	{
		return left >> 2;
	}
	//__device__ __inline__ int getAxis() const
	//{
	//	return left & 3;
	//}
	//__device__ __inline__ int getParent() const
	//{
	//	return right;
	//}
};


/// macros for common operations on the AABB node
#define AABB_ISLEAF(node) (((node).lChild & 3) == 3)

#endif
