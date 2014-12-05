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
 
#ifndef __CUDA_INTERSECT_NODES_H_
#define __CUDA_INTERSECT_NODES_H_

#include "cuda_obb.h"
#include "cuda_aabb.h"
#include <vector_functions.h>

#define OBB_ROTATION_MATRIX_EPSILON 0.000001f

template <class BV>
__device__ __inline__ bool intersect(const BV &node1, const BV &node2)
{
	return true;
}

// specialization: AABB - AABB intersect
template <>
__device__ __inline__ bool intersect<AABB>(const AABB &node1, const AABB &node2)
{
	if((node1.bb_min.x > node2.bb_max.x || node1.bb_min.y > node2.bb_max.y || node1.bb_min.z > node2.bb_max.z)
	        || (node1.bb_max.x < node2.bb_min.x || node1.bb_max.y < node2.bb_min.y || node1.bb_max.z < node2.bb_min.z))
		return false;
	else
		return true;
}


template <>
__device__ __inline__ bool intersect<OBB>(const OBB &node1, const OBB &node2)
{

	//translation, in parent frame
	float3 v = f3v_sub(node1.center, node2.center);
	
	//translation, in A's frame
	float3 T = make_float3(f3v_dot(v, node1.axis1), f3v_dot(v, node1.axis2), f3v_dot(v, node1.axis3));
	
	
	//calculate rotation matrix (B's basis with respect to A', R1)
	float3 R1;
	R1.x = f3v_dot(node1.axis1, node2.axis1);
	R1.y = f3v_dot(node1.axis1, node2.axis2);
	R1.z = f3v_dot(node1.axis1, node2.axis3);
	
	/*
	ALGORITHM: Use the separating axis test for all 15 potential
	separating axes. If a separating axis could not be found, the two
	boxes overlap.
	*/
	
	// Axes: A's basis vectors
	{
		float rb;
		rb = node2.extents.x * fabs(R1.x) + node2.extents.y * fabs(R1.y) + node2.extents.z * fabs(R1.z) + OBB_ROTATION_MATRIX_EPSILON * (node2.extents.x + node2.extents.y + node2.extents.z);
		if(fabs(T.x) > (node1.extents.x + rb))
			return false;
	}
	
	//calculate rotation matrix (B's basis with respect to A', R2)
	float3 R2;
	R2.x = f3v_dot(node1.axis2, node2.axis1);
	R2.y = f3v_dot(node1.axis2, node2.axis2);
	R2.z = f3v_dot(node1.axis2, node2.axis3);
	
	{
		float rb;
		rb = node2.extents.x * fabs(R2.x) + node2.extents.y * fabs(R2.y) + node2.extents.z * fabs(R2.z) + OBB_ROTATION_MATRIX_EPSILON * (node2.extents.x + node2.extents.y + node2.extents.z);
		if(fabs(T.y) > (node1.extents.y + rb))
			return false;
	}
	
	//calculate rotation matrix (B's basis with respect to A', R3)
	float3 R3;
	R3.x = f3v_dot(node1.axis3, node2.axis1);
	R3.y = f3v_dot(node1.axis3, node2.axis2);
	R3.z = f3v_dot(node1.axis3, node2.axis3);
	
	{
		float rb;
		rb = node2.extents.x * fabs(R3.x) + node2.extents.y * fabs(R3.y) + node2.extents.z * fabs(R3.z) + OBB_ROTATION_MATRIX_EPSILON * (node2.extents.x + node2.extents.y + node2.extents.z);;
		if(fabs(T.z) > (node1.extents.z + rb))
			return false;
	}
	
	// Axes: B's basis vectors
	{
		float rb, t;
		rb = node1.extents.x * fabs(R1.x) + node1.extents.y * fabs(R2.x) + node1.extents.z * fabs(R3.x) + OBB_ROTATION_MATRIX_EPSILON * (node1.extents.x + node1.extents.y + node1.extents.z);;
		t = fabs(T.x * R1.x + T.y * R2.x + T.z * R3.x);
		if(t > (node2.extents.x + rb))
			return false;
			
		rb = node1.extents.x * fabs(R1.y) + node1.extents.y * fabs(R2.y) + node1.extents.z * fabs(R3.y) + OBB_ROTATION_MATRIX_EPSILON * (node1.extents.x + node1.extents.y + node1.extents.z);;;
		t = fabs(T.x * R1.y + T.y * R2.y + T.z * R3.y);
		if(t > (node2.extents.y + rb))
			return false;
			
		rb = node1.extents.x * fabs(R1.z) + node1.extents.y * fabs(R2.z) + node1.extents.z * fabs(R3.z) + OBB_ROTATION_MATRIX_EPSILON * (node1.extents.x + node1.extents.y + node1.extents.z);;;
		t = fabs(T.x * R1.z + T.y * R2.z + T.z * R3.z);
		if(t > (node2.extents.z + rb))
			return false;
	}
	
	// Axes: 9 cross products
	
	//L = A0 x B0
	{
		float ra, rb, t;
		ra = node1.extents.y * fabs(R3.x) + node1.extents.z * fabs(R2.x) + OBB_ROTATION_MATRIX_EPSILON * (node1.extents.y + node1.extents.z);
		rb = node2.extents.y * fabs(R1.z) + node2.extents.z * fabs(R1.y) + OBB_ROTATION_MATRIX_EPSILON * (node2.extents.y + node2.extents.z);
		t = fabs(T.z * R2.x - T.y * R3.x);
		
		if(t > ra + rb)
			return false;
	}
	
	//L = A0 x B1
	{
		float ra, rb, t;
		ra = node1.extents.y * fabs(R3.y) + node1.extents.z * fabs(R2.y) + OBB_ROTATION_MATRIX_EPSILON * (node1.extents.y + node1.extents.z);
		rb = node2.extents.x * fabs(R1.z) + node2.extents.z * fabs(R1.x) + OBB_ROTATION_MATRIX_EPSILON * (node2.extents.x + node2.extents.z);
		t = fabs(T.z * R2.y - T.y * R3.y);
		
		if(t > ra + rb)
			return false;
	}
	
	//L = A0 x B2
	{
		float ra, rb, t;
		ra = node1.extents.y * fabs(R3.z) + node1.extents.z * fabs(R2.z) + OBB_ROTATION_MATRIX_EPSILON * (node1.extents.y + node1.extents.z);
		rb = node2.extents.x * fabs(R1.y) + node2.extents.y * fabs(R1.x) + OBB_ROTATION_MATRIX_EPSILON * (node2.extents.x + node2.extents.y);
		t = fabs(T.z * R2.z - T.y * R3.z);
		
		if(t > ra + rb)
			return false;
	}
	
	//L = A1 x B0
	{
		float ra, rb, t;
		ra = node1.extents.x * fabs(R3.x) + node1.extents.z * fabs(R1.x) + OBB_ROTATION_MATRIX_EPSILON * (node1.extents.x + node1.extents.z);
		rb = node2.extents.y * fabs(R2.z) + node2.extents.z * fabs(R2.y) + OBB_ROTATION_MATRIX_EPSILON * (node2.extents.y + node2.extents.z);
		t = fabs(T.x * R3.x - T.z * R1.x);
		
		if(t > ra + rb)
			return false;
	}
	
	//L = A1 x B1
	{
		float ra, rb, t;
		ra = node1.extents.x * fabs(R3.y) + node1.extents.z * fabs(R1.y) + OBB_ROTATION_MATRIX_EPSILON * (node1.extents.x + node1.extents.z);
		rb = node2.extents.x * fabs(R2.z) + node2.extents.z * fabs(R2.x) + OBB_ROTATION_MATRIX_EPSILON * (node2.extents.y + node2.extents.z);
		t = fabs(T.x * R3.y - T.z * R1.y);
		
		if(t > ra + rb)
			return false;
	}
	
	//L = A1 x B2
	{
		float ra, rb, t;
		ra = node1.extents.x * fabs(R3.z) + node1.extents.z * fabs(R1.z) + OBB_ROTATION_MATRIX_EPSILON * (node1.extents.x + node1.extents.z);
		rb = node2.extents.x * fabs(R2.y) + node2.extents.y * fabs(R2.x) + OBB_ROTATION_MATRIX_EPSILON * (node2.extents.x + node2.extents.y);
		t = fabs(T.x * R3.z - T.z * R1.z);
		
		if(t > ra + rb)
			return false;
	}
	
	//L = A2 x B0
	{
		float ra, rb, t;
		ra = node1.extents.x * fabs(R2.x) + node1.extents.y * fabs(R1.x) + OBB_ROTATION_MATRIX_EPSILON * (node1.extents.x + node1.extents.y);
		rb = node2.extents.y * fabs(R3.z) + node2.extents.z * fabs(R3.y) + OBB_ROTATION_MATRIX_EPSILON * (node2.extents.y + node2.extents.z);
		t = fabs(T.y * R1.x - T.x * R2.x);
		
		if(t > ra + rb)
			return false;
	}
	
	//L = A2 x B1
	{
		float ra, rb, t;
		ra = node1.extents.x * fabs(R2.y) + node1.extents.y * fabs(R1.y) + OBB_ROTATION_MATRIX_EPSILON * (node1.extents.x + node1.extents.y);
		rb = node2.extents.x * fabs(R3.z) + node2.extents.z * fabs(R3.x) + OBB_ROTATION_MATRIX_EPSILON * (node2.extents.x + node2.extents.z);
		t = fabs(T.y * R1.y - T.x * R2.y);
		
		if(t > ra + rb)
			return false;
	}
	
	//L = A2 x B2
	{
		float ra, rb, t;
		ra = node1.extents.x * fabs(R2.z) + node1.extents.y * fabs(R1.z) + OBB_ROTATION_MATRIX_EPSILON * (node1.extents.x + node1.extents.y);
		rb = node2.extents.x * fabs(R3.y) + node2.extents.y * fabs(R3.x) + OBB_ROTATION_MATRIX_EPSILON * (node2.extents.x + node2.extents.y);
		t = fabs(T.y * R1.z - T.x * R2.z);
		
		if(t > ra + rb)
			return false;
	}
	
	// no separating axis found:
	// the two boxes overlap
	
	return true;
}

#endif