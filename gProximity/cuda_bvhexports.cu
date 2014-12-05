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
 
#include "cuda_bvhexports.h"
#include "cuda_defs.h"
#include "cuda_bvh_constru.h"
#include "cuda_rss_constru.h"
#include "cuda_timer.h"

void buildBVHTree2(void *bvh, float *bb_min, float *bb_max)
{
	BVHConstructionState *BVH = (BVHConstructionState *)bvh;
	
	float3 bb_min_, bb_max_;
	
	BVH->updateGeometry_wobb(bb_min_, bb_max_);
	
	bb_min[0] = bb_min_.x;
	bb_min[1] = bb_min_.y;
	bb_min[2] = bb_min_.z;
	bb_max[0] = bb_max_.x;
	bb_max[1] = bb_max_.y;
	bb_max[2] = bb_max_.z;
	
	
	BVH->build(bb_min_,bb_max_, SCENE_SPLIT_LEAFTRIS,
	                                 true,   // dump stats
	                                 true);  // free temporaries
}


void buildBVHTree(void *bvh, float *bb_min, float *bb_max)
{
	BVHConstructionState *BVH = (BVHConstructionState *)bvh;
	
	BVH->updateGeometry(make_float3(bb_min[0], bb_min[1], bb_min[2]),
	                    make_float3(bb_max[0], bb_max[1], bb_max[2]));
	                    
	BVH->build(make_float3(bb_min[0], bb_min[1], bb_min[2]),
	                                 make_float3(bb_max[0], bb_max[1], bb_max[2]), SCENE_SPLIT_LEAFTRIS,
	                                 true,   // dump stats
	                                 true);  // free temporaries
}


void* createBVHObject(GLuint bufferVertices, GLuint bufferTriIndices, unsigned int nTris, unsigned int nVerts)
{
	// set up BVH object
	BVHConstructionState *BVH = new BVHConstructionState;
	memset(BVH, 0, sizeof(BVHConstructionState));
	BVH->bufferVertices = bufferVertices;
	BVH->bufferTriIndices = bufferTriIndices;
	
	// register OpenGL buffers so they can be used
	BVH->registerGeometryBuffers();
	
	// allocate all needed buffers in device memory
	BVH->allocate(nTris, nVerts);
	
	return BVH;
}


void deleteBVHObject(void *bvh)
{
	BVHConstructionState *BVH = (BVHConstructionState *)bvh;
	BVH->free();				   // free all device memory
	BVH->releaseGeometryBuffers(); // unregister all OpenGL buffers
	
	delete bvh;
	bvh = NULL;
}


void buildRSSTree2(void *rss, float *bb_min, float *bb_max)
{
	RSSConstructionState *Rss = (RSSConstructionState *)rss;
	
	float3 bb_min_, bb_max_;
	
	Rss->updateGeometry_wobb(bb_min_, bb_max_);
	
	bb_min[0] = bb_min_.x;
	bb_min[1] = bb_min_.y;
	bb_min[2] = bb_min_.z;
	bb_max[0] = bb_max_.x;
	bb_max[1] = bb_max_.y;
	bb_max[2] = bb_max_.z;
	
	
	Rss->build(false, false, true);
}


void buildRSSTree(void *rss, float *bb_min, float *bb_max)
{
	RSSConstructionState *Rss = (RSSConstructionState *)rss;
	
	Rss->updateGeometry(make_float3(bb_min[0], bb_min[1], bb_min[2]),
	                    make_float3(bb_max[0], bb_max[1], bb_max[2]));
	                    
	Rss->build(false, false, true);
}


void* createRSSObject(GLuint bufferVertices, GLuint bufferTriIndices, unsigned int nTris, unsigned int nVerts)
{
	RSSConstructionState* rss = new RSSConstructionState;
	memset(rss, 0, sizeof(RSSConstructionState));
	rss->bufferVertices = bufferVertices;
	rss->bufferTriIndices = bufferTriIndices;

	rss->registerGeometryBuffers();

	rss->allocate(nTris, nVerts);

	return rss;
}

void deleteRSSObject(void* Rss)
{
	RSSConstructionState* rss = (RSSConstructionState*)Rss;
	rss->free();
	rss->releaseGeometryBuffers();

	delete rss;
	rss = NULL;
}