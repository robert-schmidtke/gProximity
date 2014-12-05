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
 
#ifndef __CUDA_RSS_H_
#define __CUDA_RSS_H_

typedef struct
{
	float3 center;
	float3 axis1,
		axis2,
		axis3;
	float2 extents;
	float  radius;
} RSS;

class RSSNode
{
public:
	RSS ssphere;	// actual swept sphere
	
	/**
	 * Compact representation of several members:
	 *  - lower 2 bits:
	 *     TODO: do not need split axis any more, remove this or make other use of the bits
	 *       0-2: split axis (x,y,z)
	 *       3: node is leaf
	 *  - upper 30 bits:
	 *     - for inner node: address to first child
	 *       (second child is in consecutive location)
	 *     - for leaf node: triangle index (shifted left by two bits)
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
	__device__ __inline__ bool isNoLeaf() const
	{
		return (left & 3) != 3;
	}
	__device__ __inline__ int getLeftChild() const
	{
		return left >> 5;
	}
	__device__ __inline__ int getRightChild() const
	{
		return (left >> 5) + 1;
	}
	__device__ __inline__ int getTriID() const
	{
		return left >> 2;
	}
	__device__ __inline__ int getAxis() const
	{
		return left & 3;
	}
	__device__ __inline__ int getParent() const
	{
		return right;
	}
};

//
// macros for common operations on the AABB node
//

#define RSS_TRIID(node) ((node).leafTriID)
//#define RSS_AXIS(node) ((node).lChild & 3)
#define RSS_ISLEAF(node) (((node).lChild & 3) == 3)

// get children (as byte offset in array of nodes!)
#define RSS_LEFTCHILD(node) (((node).lChild & ~3))
#define RSS_RIGHTCHILD(node) (((node).lChild & ~3) + 32)


#endif 