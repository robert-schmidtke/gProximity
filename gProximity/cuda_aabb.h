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
 
#ifndef __CUDA_AABB_H_
#define __CUDA_AABB_H_

#include "cuda_defs.h"

/** Basic axis-aligned bounding box
 */
class AABB
{
public:
	/** init AABB given 6 3D points
	 */
	__device__ __inline__ void init(const float3 &v1, const float3 &v2, const float3 &v3,
	                                const float3 &u1, const float3 &u2, const float3 &u3)
	{
		bb_min.x = min(v1.x, min(v2.x, v3.x));
		bb_max.x = max(v1.x, max(v2.x, v3.x));
		
		bb_min.y = min(v1.y, min(v2.y, v3.y));
		bb_max.y = max(v1.y, max(v2.y, v3.y));
		
		bb_min.z = min(v1.z, min(v2.z, v3.z));
		bb_max.z = max(v1.z, max(v2.z, v3.z));
		
		bb_min.x = min(u1.x, min(u2.x, u3.x));
		bb_max.x = max(u1.x, max(u2.x, u3.x));
		
		bb_min.y = min(u1.y, min(u2.y, u3.y));
		bb_max.y = max(u1.y, max(u2.y, u3.y));
		
		bb_min.z = min(u1.z, min(u2.z, u3.z));
		bb_max.z = max(u1.z, max(u2.z, u3.z));
	}
	
	/** init AABB given a triangle
	 */
	__device__ __inline__ void init(const float3 &v1, const float3 &v2, const float3 &v3)
	{
		bb_min.x = min(v1.x, min(v2.x, v3.x));
		bb_max.x = max(v1.x, max(v2.x, v3.x));
		
		bb_min.y = min(v1.y, min(v2.y, v3.y));
		bb_max.y = max(v1.y, max(v2.y, v3.y));
		
		bb_min.z = min(v1.z, min(v2.z, v3.z));
		bb_max.z = max(v1.z, max(v2.z, v3.z));
	}
	
	/** init AABB covered two given AABBs
	 */
	__device__ __inline__ void init(const AABB &box1, const AABB &box2)
	{
		bb_min.x = min(box1.bb_min.x, box2.bb_min.x);
		bb_max.x = max(box1.bb_max.x, box2.bb_max.x);
		
		bb_min.y = min(box1.bb_min.y, box2.bb_min.y);
		bb_max.y = max(box1.bb_max.y, box2.bb_max.y);
		
		bb_min.z = min(box1.bb_min.z, box2.bb_min.z);
		bb_max.z = max(box1.bb_max.z, box2.bb_max.z);
	}
	
	/** extend AABB to cover a new point
	 */
	__device__ __inline__ void update(const float3 &v)
	{
		bb_min.x = min(bb_min.x, v.x);
		bb_max.x = max(bb_max.x, v.x);
		
		bb_min.y = min(bb_min.y, v.y);
		bb_max.y = max(bb_max.y, v.y);
		
		bb_min.z = min(bb_min.z, v.z);
		bb_max.z = max(bb_max.z, v.z);
	}
	
	/** init AABB by the default maximum AABB
	 */
	__device__ __inline__ void init()
	{
		bb_min.z = bb_min.y = bb_min.x = CUDART_NORM_HUGE_F;
		bb_max.z = bb_max.y = bb_max.x = -CUDART_NORM_HUGE_F;
	}
	
	__device__ __inline__ float getSize() const
	{
		return (bb_min.x - bb_max.x) * (bb_min.x - bb_max.x) +
		       (bb_min.y - bb_max.y) * (bb_min.y - bb_max.y) +
		       (bb_min.z - bb_max.z) * (bb_min.z - bb_max.z);
	}
	
	float3 bb_min,   ///< AABB's min bound
	       bb_max;   ///< AABB's max bound
};

/// init a default AABB
#define AABB_INIT(box) do { (box).bb_min.z = (box).bb_min.y = (box).bb_min.x =  CUDART_NORM_HUGE_F; \
						    (box).bb_max.z = (box).bb_max.y = (box).bb_max.x = -CUDART_NORM_HUGE_F; } while(0);


/// extend AABB to cover a new point
#define AABB_UPDATE(box, f3vec) do { (box).bb_min.x = min((box).bb_min.x, f3vec.x); \
								     (box).bb_min.y = min((box).bb_min.y, f3vec.y); \
								     (box).bb_min.z = min((box).bb_min.z, f3vec.z); \
								     (box).bb_max.x = max((box).bb_max.x, f3vec.x); \
								     (box).bb_max.y = max((box).bb_max.y, f3vec.y); \
								     (box).bb_max.z = max((box).bb_max.z, f3vec.z); } while(0);

/// extend AABB to cover a new AABB
#define AABB_UPDATE_FROM_AABB(box, box2) do {  (box).bb_min.x = min((box).bb_min.x, (box2).bb_min.x); \
											   (box).bb_min.y = min((box).bb_min.y, (box2).bb_min.y); \
											   (box).bb_min.z = min((box).bb_min.z, (box2).bb_min.z); \
											   (box).bb_max.x = max((box).bb_max.x, (box2).bb_max.x); \
											   (box).bb_max.y = max((box).bb_max.y, (box2).bb_max.y); \
											   (box).bb_max.z = max((box).bb_max.z, (box2).bb_max.z); } while(0);

/// extend AABB's min bound to cover a new point
#define AABB_UPDATEMIN(box, f3vec) do { (box).bb_min.x = min((box).bb_min.x, f3vec.x); \
									    (box).bb_min.y = min((box).bb_min.y, f3vec.y); \
									    (box).bb_min.z = min((box).bb_min.z, f3vec.z); } while(0);

/// extend AABB's max bound to cover a new point
#define AABB_UPDATEMAX(box, f3vec) do { (box).bb_max.x = max((box).bb_max.x, f3vec.x); \
									    (box).bb_max.y = max((box).bb_max.y, f3vec.y); \
									    (box).bb_max.z = max((box).bb_max.z, f3vec.z); } while(0);


/// half area of AABB box
#define AABB_SURFACEAREA(area, box) do { float3 dim = f3v_sub((box).bb_max, (box).bb_min); \
									     area = dim.x*dim.y + dim.x*dim.z + dim.y*dim.z; } while(0);

/// half area of AABB box (but box is OVERWRITTEN)
#define AABB_SURFACEAREA_NOTEMP(area, box) do {(box).bb_max = f3v_sub((box).bb_max, (box).bb_min); \
											   area = (box).bb_max.x*(box).bb_max.y + (box).bb_max.x*(box).bb_max.z + (box).bb_max.y*(box).bb_max.z; } while(0);

/// whether two AABB intersect
#define AABB_INTERSECTS(box1, box2) ( ((box1).bb_min.x < (box2).bb_max.x && (box1).bb_min.y < (box2).bb_max.y && (box1).bb_min.z < (box2).bb_max.z) || ((box1).bb_max.x > (box2).bb_min.x && (box1).bb_max.y > (box2).bb_min.y && (box1).bb_max.z > (box2).bb_min.z) )


#endif
