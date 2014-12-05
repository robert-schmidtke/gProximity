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
 
#ifndef __CUDA_OBB_H_
#define __CUDA_OBB_H_

#include "cuda_vectors.h"
#include "cuda_defs.h"


/** Oriented bounding box (60 bytes)
 */
class OBB
{
public:
	__device__ __inline__ void calcExtentsForOBB(OBB &bv, float3 &minExtent, float3 &maxExtent)
	{
		// generate all 8 points of OBB
		bv.axis1 = f3v_mul1(bv.axis1, bv.extents.x);
		bv.axis2 = f3v_mul1(bv.axis2, bv.extents.y);
		bv.axis3 = f3v_mul1(bv.axis3, bv.extents.z);
		
		float3 point, temp;
		float dist;
		
		// 1
		temp = f3v_add(bv.axis1, bv.axis2);
		point = f3v_add(temp, bv.axis3);
		dist = f3v_dot(point, axis1);
		minExtent.x = min(minExtent.x, dist);
		maxExtent.x = max(maxExtent.x, dist);
		dist = f3v_dot(point, axis2);
		minExtent.y = min(minExtent.y, dist);
		maxExtent.y = max(maxExtent.y, dist);
		dist = f3v_dot(point, axis3);
		minExtent.z = min(minExtent.z, dist);
		maxExtent.z = max(maxExtent.z, dist);
		
		// 2
		point = f3v_sub(temp, bv.axis3);
		dist = f3v_dot(point, axis1);
		minExtent.x = min(minExtent.x, dist);
		maxExtent.x = max(maxExtent.x, dist);
		dist = f3v_dot(point, axis2);
		minExtent.y = min(minExtent.y, dist);
		maxExtent.y = max(maxExtent.y, dist);
		dist = f3v_dot(point, axis3);
		minExtent.z = min(minExtent.z, dist);
		maxExtent.z = max(maxExtent.z, dist);
		
		// 3
		temp = f3v_sub(bv.axis1, bv.axis2);
		point = f3v_add(temp, bv.axis3);
		dist = f3v_dot(point, axis1);
		minExtent.x = min(minExtent.x, dist);
		maxExtent.x = max(maxExtent.x, dist);
		dist = f3v_dot(point, axis2);
		minExtent.y = min(minExtent.y, dist);
		maxExtent.y = max(maxExtent.y, dist);
		dist = f3v_dot(point, axis3);
		minExtent.z = min(minExtent.z, dist);
		maxExtent.z = max(maxExtent.z, dist);
		
		// 4
		point = f3v_sub(temp, bv.axis3);
		dist = f3v_dot(point, axis1);
		minExtent.x = min(minExtent.x, dist);
		maxExtent.x = max(maxExtent.x, dist);
		dist = f3v_dot(point, axis2);
		minExtent.y = min(minExtent.y, dist);
		maxExtent.y = max(maxExtent.y, dist);
		dist = f3v_dot(point, axis3);
		minExtent.z = min(minExtent.z, dist);
		maxExtent.z = max(maxExtent.z, dist);
		
		// 5
		bv.axis1.x = -bv.axis1.x;
		bv.axis1.y = -bv.axis1.y;
		bv.axis1.z = -bv.axis1.z;
		
		temp = f3v_add(bv.axis1, bv.axis2);
		point = f3v_add(temp, bv.axis3);
		dist = f3v_dot(point, axis1);
		minExtent.x = min(minExtent.x, dist);
		maxExtent.x = max(maxExtent.x, dist);
		dist = f3v_dot(point, axis2);
		minExtent.y = min(minExtent.y, dist);
		maxExtent.y = max(maxExtent.y, dist);
		dist = f3v_dot(point, axis3);
		minExtent.z = min(minExtent.z, dist);
		maxExtent.z = max(maxExtent.z, dist);
		
		// 6
		point = f3v_sub(temp, bv.axis3);
		dist = f3v_dot(point, axis1);
		minExtent.x = min(minExtent.x, dist);
		maxExtent.x = max(maxExtent.x, dist);
		dist = f3v_dot(point, axis2);
		minExtent.y = min(minExtent.y, dist);
		maxExtent.y = max(maxExtent.y, dist);
		dist = f3v_dot(point, axis3);
		minExtent.z = min(minExtent.z, dist);
		maxExtent.z = max(maxExtent.z, dist);
		
		// 7
		temp = f3v_sub(bv.axis1, bv.axis2);
		point = f3v_add(temp, bv.axis3);
		dist = f3v_dot(point, axis1);
		minExtent.x = min(minExtent.x, dist);
		maxExtent.x = max(maxExtent.x, dist);
		dist = f3v_dot(point, axis2);
		minExtent.y = min(minExtent.y, dist);
		maxExtent.y = max(maxExtent.y, dist);
		dist = f3v_dot(point, axis3);
		minExtent.z = min(minExtent.z, dist);
		maxExtent.z = max(maxExtent.z, dist);
		
		// 8
		point = f3v_sub(temp, bv.axis3);
		dist = f3v_dot(point, axis1);
		minExtent.x = min(minExtent.x, dist);
		maxExtent.x = max(maxExtent.x, dist);
		dist = f3v_dot(point, axis2);
		minExtent.y = min(minExtent.y, dist);
		maxExtent.y = max(maxExtent.y, dist);
		dist = f3v_dot(point, axis3);
		minExtent.z = min(minExtent.z, dist);
		maxExtent.z = max(maxExtent.z, dist);
	}
	
	__device__ __inline__ void init(OBB &bv1, OBB &bv2)
	{
		// somewhat based on code from Dave Eberly / geometrictools.com
		
		// guess at center by taking middle
		center = f3v_add(bv1.center, bv2.center);
		center = f3v_mul1(center, 0.5f);
		
		// ASSUME: axis = axis of BV1
		axis1 = bv1.axis1;
		axis2 = bv1.axis2;
		axis3 = bv1.axis3;
		
		// extents as calculated from all 16 points and 3 axes
		float3 minExtent = make_float3(CUDART_NORM_HUGE_F, CUDART_NORM_HUGE_F, CUDART_NORM_HUGE_F),
		       maxExtent = make_float3(-CUDART_NORM_HUGE_F, -CUDART_NORM_HUGE_F, -CUDART_NORM_HUGE_F);
		       
		calcExtentsForOBB(bv1, minExtent, maxExtent);
		calcExtentsForOBB(bv2, minExtent, maxExtent);
		
		// [minExtent,maxExtent] is the axis-aligned box in the coordinate system of the
		// merged box axes.  Update the current box center to be the center of
		// the new box.  Compute the extents based on the new center.
		
		float factorX = 0.5f * (maxExtent.x + minExtent.x);
		float3 correctorX = f3v_mul1(axis1, factorX);
		center = f3v_add(correctorX, center);
		extents.x = 0.5f * (maxExtent.x - minExtent.x);
		
		float factorY = 0.5f * (maxExtent.y + minExtent.y);
		float3 correctorY = f3v_mul1(axis2, factorY);
		center = f3v_add(correctorY, center);
		extents.y = 0.5f * (maxExtent.y - minExtent.y);
		
		float factorZ = 0.5f * (maxExtent.z + minExtent.z);
		float3 correctorZ = f3v_mul1(axis3, factorZ);
		center = f3v_add(correctorZ, center);
		extents.z = 0.5f * (maxExtent.z - minExtent.z);
		
		/*for (j = 0; j < 3; j++)
		{
			kBox.Center += (((Real)0.5)*(kMax[j]+kMin[j]))*kBox.Axis[j];
			kBox.Extent[j] = ((Real)0.5)*(kMax[j]-kMin[j]);
		}*/
	}
	
	// init OBB from triangle
	__device__ __inline__ void init(const float3 &v1, const float3 &v2, const float3 &v3)
	{
		// center is average of all 3 points (first guess, not final position)
		center = f3v_add(v1, v2);
		center = f3v_add(center, v3);
		center = f3v_mul1(center, 1.0f / 3.0f);
		
		// first axis: longest edge of triangle
		
		// edges of triangle: find longest
		float3 e1 = f3v_sub(v2, v1);
		float3 e2 = f3v_sub(v3, v1);
		float3 e3 = f3v_sub(v3, v2);
		
		// first axis: normal vector of triangle
		axis1 = f3v_cross(e1, e2); // normal vector
		
		float l1 = f3v_dot(e1, e1);
		float l2 = f3v_dot(e2, e2);
		float l3 = f3v_dot(e3, e3);
		
		// second axis: longest edge
		if(l1 > l2 && l1 > l2)
			axis2 = e1;
		else if(l2 > l3 && l2 > l1)
			axis2 = e2;
		else
			axis2 = e3;
			
		// 3rd axis: arbitrary orthogonal vector
		axis3 = f3v_cross(axis1, axis2);
		
		// normalize axes
		float invlen = 1.0f / sqrt(f3v_dot(axis1, axis1));
		axis1 = f3v_mul1(axis1, invlen);
		float invlen2 = 1.0f / sqrt(f3v_dot(axis2, axis2));
		axis2 = f3v_mul1(axis2, invlen2);
		float invlen3 = 1.0f / sqrt(f3v_dot(axis3, axis3));
		axis3 = f3v_mul1(axis3, invlen3);
		
		extents.x = 0; // no extent along normal since triangle flat
		
		// now compute extents along 2nd and 3rd axis
		float3 vv1 = f3v_sub(v1, center);
		float3 vv2 = f3v_sub(v2, center);
		float3 vv3 = f3v_sub(v3, center);
		//extents.y = max(max(fabs(f3v_dot(v1,axis2)), fabs(f3v_dot(v2,axis2))), fabs(f3v_dot(v3,axis2)));
		//extents.z = max(max(fabs(f3v_dot(v1,axis3)), fabs(f3v_dot(v2,axis3))), fabs(f3v_dot(v3,axis3)));
		
		// axis 1
		float2 bbY;
		float3 dotAxis = make_float3(f3v_dot(vv1, axis2), f3v_dot(vv2, axis2), f3v_dot(vv3, axis2));
		bbY.x = min(min(dotAxis.x, dotAxis.y), dotAxis.z);
		bbY.y = max(max(dotAxis.x, dotAxis.y), dotAxis.z);
		
		float factor2 = 0.5f * (bbY.y + bbY.x);
		float3 corrector2 = f3v_mul1(axis2, factor2);
		center = f3v_add(center, corrector2);
		extents.y = 0.5f * (bbY.y - bbY.x);
		
		// axis 2
		float2 bbZ;
		dotAxis = make_float3(f3v_dot(vv1, axis3), f3v_dot(vv2, axis3), f3v_dot(vv3, axis3));
		bbZ.x = min(min(dotAxis.x, dotAxis.y), dotAxis.z);
		bbZ.y = max(max(dotAxis.x, dotAxis.y), dotAxis.z);
		
		float factor3 = 0.5f * (bbZ.y + bbZ.x);
		float3 corrector3 = f3v_mul1(axis3, factor3);
		center = f3v_add(center, corrector3);
		extents.z = 0.5f * (bbZ.y - bbZ.x);
	}
	
	
	__device__ __inline__ void init(const float3 &v1, const float3 &v2, const float3 &v3, const float3 &u1, const float3 &u2, const float3 &u3)
	{
		// center is average of all 3 points (first guess, not final position)
		center = f3v_add(v1, v2);
		center = f3v_add(center, v3);
		center = f3v_add(center, u1);
		center = f3v_add(center, u2);
		center = f3v_add(center, u3);
		center = f3v_mul1(center, 1.0f / 6.0f);
		
		// edges of triangle: find longest
		float3 e1 = f3v_sub(v2, v1);
		float3 e2 = f3v_sub(v3, v1);
		float3 e3 = f3v_sub(v3, v2);
		
		// first axis: normal vector of triangle
		axis1 = f3v_cross(e1, e2); // normal vector
		
		float l1 = f3v_dot(e1, e1);
		float l2 = f3v_dot(e2, e2);
		float l3 = f3v_dot(e3, e3);
		
		// second axis: longest edge
		if(l1 > l2 && l1 > l2)
			axis2 = e1;
		else if(l2 > l3 && l2 > l1)
			axis2 = e2;
		else
			axis2 = e3;
			
		// 3rd axis: arbitrary orthogonal vector
		axis3 = f3v_cross(axis1, axis2);
		
		// normalize axes
		float invlen = 1.0f / sqrt(f3v_dot(axis1, axis1));
		axis1 = f3v_mul1(axis1, invlen);
		float invlen2 = 1.0f / sqrt(f3v_dot(axis2, axis2));
		axis2 = f3v_mul1(axis2, invlen2);
		float invlen3 = 1.0f / sqrt(f3v_dot(axis3, axis3));
		axis3 = f3v_mul1(axis3, invlen3);
		
		// now compute extents along axes
		
		float3 minExtent, maxExtent;
		
		float3 point = f3v_sub(v1, center);
		float dist = f3v_dot(point, axis1);
		minExtent.x = dist;
		maxExtent.x = dist;
		dist = f3v_dot(point, axis2);
		minExtent.y = dist;
		maxExtent.y = dist;
		dist = f3v_dot(point, axis3);
		minExtent.z = dist;
		maxExtent.z = dist;
		
		point = f3v_sub(v2, center);
		dist = f3v_dot(point, axis1);
		minExtent.x = min(minExtent.x, dist);
		maxExtent.x = max(maxExtent.x, dist);
		dist = f3v_dot(point, axis2);
		minExtent.y = min(minExtent.y, dist);
		maxExtent.y = max(maxExtent.y, dist);
		dist = f3v_dot(point, axis3);
		minExtent.z = min(minExtent.z, dist);
		maxExtent.z = max(maxExtent.z, dist);
		
		point = f3v_sub(v3, center);
		dist = f3v_dot(point, axis1);
		minExtent.x = min(minExtent.x, dist);
		maxExtent.x = max(maxExtent.x, dist);
		dist = f3v_dot(point, axis2);
		minExtent.y = min(minExtent.y, dist);
		maxExtent.y = max(maxExtent.y, dist);
		dist = f3v_dot(point, axis3);
		minExtent.z = min(minExtent.z, dist);
		maxExtent.z = max(maxExtent.z, dist);
		
		point = f3v_sub(u1, center);
		dist = f3v_dot(point, axis1);
		minExtent.x = min(minExtent.x, dist);
		maxExtent.x = max(maxExtent.x, dist);
		dist = f3v_dot(point, axis2);
		minExtent.y = min(minExtent.y, dist);
		maxExtent.y = max(maxExtent.y, dist);
		dist = f3v_dot(point, axis3);
		minExtent.z = min(minExtent.z, dist);
		maxExtent.z = max(maxExtent.z, dist);
		
		point = f3v_sub(u2, center);
		dist = f3v_dot(point, axis1);
		minExtent.x = min(minExtent.x, dist);
		maxExtent.x = max(maxExtent.x, dist);
		dist = f3v_dot(point, axis2);
		minExtent.y = min(minExtent.y, dist);
		maxExtent.y = max(maxExtent.y, dist);
		dist = f3v_dot(point, axis3);
		minExtent.z = min(minExtent.z, dist);
		maxExtent.z = max(maxExtent.z, dist);
		
		point = f3v_sub(u3, center);
		dist = f3v_dot(point, axis1);
		minExtent.x = min(minExtent.x, dist);
		maxExtent.x = max(maxExtent.x, dist);
		dist = f3v_dot(point, axis2);
		minExtent.y = min(minExtent.y, dist);
		maxExtent.y = max(maxExtent.y, dist);
		dist = f3v_dot(point, axis3);
		minExtent.z = min(minExtent.z, dist);
		maxExtent.z = max(maxExtent.z, dist);
		
		// [minExtent,maxExtent] is the axis-aligned box in the coordinate system of the
		// merged box axes.  Update the current box center to be the center of
		// the new box.  Compute the extents based on the new center.
		
		float factorX = 0.5f * (maxExtent.x + minExtent.x);
		float3 correctorX = f3v_mul1(axis1, factorX);
		center = f3v_add(correctorX, center);
		extents.x = 0.5f * (maxExtent.x - minExtent.x);
		
		float factorY = 0.5f * (maxExtent.y + minExtent.y);
		float3 correctorY = f3v_mul1(axis2, factorY);
		center = f3v_add(correctorY, center);
		extents.y = 0.5f * (maxExtent.y - minExtent.y);
		
		float factorZ = 0.5f * (maxExtent.z + minExtent.z);
		float3 correctorZ = f3v_mul1(axis3, factorZ);
		center = f3v_add(correctorZ, center);
		extents.z = 0.5f * (maxExtent.z - minExtent.z);
	}
	
	__device__ __inline__ float getSize() const
	{
		return extents.x * extents.x + extents.y * extents.y + extents.z * extents.z;
	}
	
	float3 center;		// center point of OBB
	float3 axis1,		// major axes specifying the OBB
	       axis2,
	       axis3;
	float3 extents;		// extents to boundary from center point,
	// along each axis
};



// OBBTree node (68 bytes)
class OBBNode
{
public:
	OBB bbox;					// bounding box for node
	unsigned int left,			// pointers to left/right children
	         right;
	         
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
};

#endif
