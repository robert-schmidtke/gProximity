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
 
#ifndef __CPU_BVH_CONSTRU_H_
#define __CPU_BVH_CONSTRU_H_

#include "geometry.h"
#include <vector_types.h>

/**
 * OBB structure on CPU
 */
struct OBB_host
{
	float3 center;		///< center point of OBB
	float3 axis1,		///< major axes specifying the OBB
	       axis2,
	       axis3;
	float3 extents;		///< half extensions along each axis
};

/**
 * OBB Node structure on CPU
 */
class OBBNode_host
{
public:
	OBB_host bbox;				///< bounding box (OBB)
	unsigned int left,			///< pointers to left/right children (right is hardly used)
	         right;
};

/** Create OBB hierarchy from PQP and transform it into GPU OBB hierarchy
  * @param model Geometry model for one obstacle or one robot component
  * @return Pointer to root OBBNode_host of the BVH hierarchy that is consistent with GPU's OBBNode mode (i.e. using world-frame)
  */
OBBNode_host* PQP_createOBBTree(ModelInstance* model);


/** Create OBB hierarchy in PQP's mode
 * @param model Geometry model for one obstacle or one robot component
 * @param parent_relative Whether to transform each node's axis to parent node's frame (default true for PQP, but in GPU OBB we use world-frame)
 * @return Pointer to root OBBNode_host of the BVH hierarchy on CPU
 */
void* createPQPModel(ModelInstance* model, bool parent_relative = true);



#endif