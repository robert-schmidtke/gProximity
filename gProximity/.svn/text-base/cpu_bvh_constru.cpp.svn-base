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
 
#include "cpu_bvh_constru.h"

#include <vector_functions.h>
#include "PQP.h"

void* createPQPModel(ModelInstance* model, bool parent_relative)
{
	PQP_Model* pTree = new PQP_Model;
	pTree->BeginModel(model->nTris);
	float p1[3], p2[3], p3[3];
	
	for(unsigned int i = 0; i < model->nTris; ++i)
	{
		int id = model->trilist[i].p[0];
		p1[0] = model->verlist[id].x();
		p1[1] = model->verlist[id].y();
		p1[2] = model->verlist[id].z();
		id = model->trilist[i].p[1];
		p2[0] = model->verlist[id].x();
		p2[1] = model->verlist[id].y();
		p2[2] = model->verlist[id].z();
		id = model->trilist[i].p[2];
		p3[0] = model->verlist[id].x();
		p3[1] = model->verlist[id].y();
		p3[2] = model->verlist[id].z();
		
		pTree->AddTri(p1, p2, p3, i);
	}
	pTree->EndModel(parent_relative);
	
	return pTree;
}


OBBNode_host* PQP_createOBBTree(ModelInstance* model)
{
	PQP_Model* pTree = (PQP_Model*)createPQPModel(model, false); ///< false means using world coordinate instead of parent-relative coordinate
	
	OBBNode_host* hTree = new OBBNode_host[pTree->num_bvs];
	
	for(int i = 0; i < pTree->num_bvs; ++i)
	{
		OBBNode_host node;
		int isLeaf = pTree->child(i)->Leaf();
		if(isLeaf)
		{
			int triId = (- pTree->child(i)->first_child - 1);
			triId = pTree->tris[triId].id; ///< triangles' id will change in EndModel(), i.e. triId != id
			node.left = ((triId << 2) | 3);
			node.right = 0;
			node.bbox.axis1 = make_float3((float)(pTree->b[i].R[0][0]), (float)(pTree->b[i].R[1][0]), (float)(pTree->b[i].R[2][0]));
			node.bbox.axis2 = make_float3((float)(pTree->b[i].R[0][1]), (float)(pTree->b[i].R[1][1]), (float)(pTree->b[i].R[2][1]));
			node.bbox.axis3 = make_float3((float)(pTree->b[i].R[0][2]), (float)(pTree->b[i].R[1][2]), (float)(pTree->b[i].R[2][2]));
			node.bbox.center = make_float3((float)(pTree->b[i].To[0]), (float)(pTree->b[i].To[1]), (float)(pTree->b[i].To[2]));
			node.bbox.extents = make_float3((float)(pTree->b[i].d[0]), (float)(pTree->b[i].d[1]), (float)(pTree->b[i].d[2]));
		}
		else
		{
			node.left = ((pTree->b[i].first_child - i) << 5);
			node.right = 0;
			node.bbox.axis1 = make_float3((float)(pTree->b[i].R[0][0]), (float)(pTree->b[i].R[1][0]), (float)(pTree->b[i].R[2][0]));
			node.bbox.axis2 = make_float3((float)(pTree->b[i].R[0][1]), (float)(pTree->b[i].R[1][1]), (float)(pTree->b[i].R[2][1]));
			node.bbox.axis3 = make_float3((float)(pTree->b[i].R[0][2]), (float)(pTree->b[i].R[1][2]), (float)(pTree->b[i].R[2][2]));
			node.bbox.center = make_float3((float)(pTree->b[i].To[0]), (float)(pTree->b[i].To[1]), (float)(pTree->b[i].To[2]));
			node.bbox.extents = make_float3((float)(pTree->b[i].d[0]), (float)(pTree->b[i].d[1]), (float)(pTree->b[i].d[2]));
		}
		hTree[i] = node;
	}
	
	delete pTree;
	return hTree;
}