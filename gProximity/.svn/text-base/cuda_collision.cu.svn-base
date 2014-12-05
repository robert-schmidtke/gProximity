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
 
#include "cuda_collision.h"
#include "cuda_bvh_constru.h"
#include "cuda_intersect_tree.h"
#include "cuda_timer.h"
#include "cuda_defs.h"
#include "cuda_make_grid.h"
#include <cutil.h>

unsigned int CUDA_trianglePairCollide(GPUVertex* d_vertices1, uint3* d_triIndices1, GPUVertex* d_vertices2, uint3* d_triIndices2, int2* collisionPairs, unsigned int nPairs, int2** collisionList)
{
	dim3 grids = makeGrid((int)ceilf(nPairs / (float)COLLISION_THREADS));
	dim3 threads(COLLISION_THREADS, 1, 1);
	triangleCollision <<< grids, threads >>> (d_vertices1, d_triIndices1, d_vertices2, d_triIndices2, collisionPairs, nPairs);

	unsigned int nCollisions = 0;

	if(collisionList)
	{
		*collisionList = new int2[nPairs];
		FROMGPU(*collisionList, collisionPairs, sizeof(int2) * nPairs);
		for(int i = 0; i < nPairs; ++i)
		{
			if ((*collisionList)[i].x <= 0 && (*collisionList)[i].y <= 0)
				nCollisions++;
		}
	}
	else
	{
		int2* collisionList_tmp = new int2[nPairs];
		FROMGPU(collisionList_tmp, collisionPairs, sizeof(int2) * nPairs);
		for(int i = 0; i < nPairs; ++i)
		{
			if ((*collisionList)[i].x <= 0 && (*collisionList)[i].y <= 0)
				nCollisions++;
		}

		delete [] collisionList_tmp;
	}

	return nCollisions;
}

int CUDA_BVHCollide(ModelInstance* model1, ModelInstance* model2, int** collisionList)
{
	OBBNode* obbTree1 = (OBBNode*)model1->obbTree;
	OBBNode* obbTree2 = (OBBNode*)model2->obbTree;
	GPUVertex* d_vertices1 = (GPUVertex*)model1->vertexPointer;
	GPUVertex* d_vertices2 = (GPUVertex*)model2->vertexPointer;
	uint3* d_triIndices1 = (uint3*)model1->triIdxPointer;
	uint3* d_triIndices2 = (uint3*)model2->triIdxPointer;

	unsigned int* d_collisionPairIndex = NULL;
	unsigned int* d_collisionSync = NULL;
	unsigned int* d_nWorkQueueElements = NULL;
	int2* d_collisionPairs = NULL;
	int2* d_workQueues = NULL, *d_workQueues2 = NULL;
	unsigned int* d_workQueueCounts = NULL;
	int* d_balanceSignal = NULL;

	// allocate collision list (try to be conservative)
	unsigned int collisionPairCapacity = COLLISION_PAIR_CAPACITY;
	GPUMALLOC((void**)&d_collisionPairs, sizeof(int2) * collisionPairCapacity);

	GPUMALLOC((void **)&d_collisionPairIndex, sizeof(int));
	GPUMALLOC((void **)&d_nWorkQueueElements, sizeof(int));
	GPUMALLOC((void **)&d_collisionSync, sizeof(int));
	
	// allocate work queues
	GPUMALLOC((void **)&d_workQueues, sizeof(int2)*QUEUE_NTASKS*QUEUE_SIZE_PER_TASK_GLOBAL);
	GPUMALLOC((void **)&d_workQueues2, sizeof(int2)*QUEUE_NTASKS*QUEUE_SIZE_PER_TASK_GLOBAL);
	GPUMALLOC((void **)&d_workQueueCounts, sizeof(int)*QUEUE_NTASKS);
	GPUMALLOC((void**)&d_balanceSignal, sizeof(int));

	// init first work element:
	GPUMEMSET(d_workQueues, 0, sizeof(int2));
	GPUMEMSET(d_workQueueCounts, 0, sizeof(int) * QUEUE_NTASKS);
	GPUMEMSET(d_collisionPairIndex, 0, sizeof(int));
	

	unsigned int firstCount = 1;
	TOGPU(d_workQueueCounts, &firstCount, sizeof(unsigned int));

	unsigned int nPairs = 0;
	int nActiveSplits = 1;
	int nRuns = 0;
	int bNeedBalance = 0;

	TimerValue balanceTimer, traverseTimer;
	double elapsedBalance = 0, elapsedTraverse = 0;

	bool bstop = false;

	while(nActiveSplits)
	{	
		GPUMEMSET(d_collisionSync, 0, sizeof(int));
		traverseTree<OBBNode, OBB, QUEUE_SIZE_PER_TASK, QUEUE_SIZE_PER_TASK_INIT, TRAVERSAL_THREADS> <<< QUEUE_NTASKS, TRAVERSAL_THREADS>>>(obbTree1, d_vertices1, d_triIndices1,
		        obbTree2, d_vertices2, d_triIndices2,
		        d_workQueues, d_workQueueCounts, d_collisionSync, QUEUE_SIZE_PER_TASK_GLOBAL, d_collisionPairs, d_collisionPairIndex);
		cudaThreadSynchronize();

		unsigned int* workQueueCounts = new unsigned int[QUEUE_NTASKS];
		FROMGPU(workQueueCounts, d_workQueueCounts, sizeof(unsigned int) * QUEUE_NTASKS);
		
		for(int i = 0; i < QUEUE_NTASKS; ++i)
		{
			if(workQueueCounts[i] >= QUEUE_SIZE_PER_TASK_GLOBAL)
			{
				bstop = true;
				printf("the %d-th global queue is overflow! %d\n", i, workQueueCounts[i]);
				break;
			}
		}

		delete [] workQueueCounts;

		if(bstop)
			break;

		balanceWorkList<BALANCE_THREADS, QUEUE_NTASKS, int2> <<< 1, BALANCE_THREADS>>>(d_workQueues, d_workQueues2, d_workQueueCounts, QUEUE_SIZE_PER_TASK_GLOBAL, d_nWorkQueueElements, d_balanceSignal);
		
		FROMGPU(&nActiveSplits, d_nWorkQueueElements, sizeof(unsigned int));
		FROMGPU(&bNeedBalance, d_balanceSignal, sizeof(unsigned int));
		
		printf("active splits num: %d\n", nActiveSplits);
		
		if(bNeedBalance == 1)
		{
			int2* t = d_workQueues;
			d_workQueues = d_workQueues2;
			d_workQueues2 = t;
		}

		nRuns++;
	}

	FROMGPU(&nPairs, d_collisionPairIndex, sizeof(int));

	//run actual collision tests of primitives
	unsigned int nCollision = CUDA_trianglePairCollide(d_vertices1, d_triIndices1, d_vertices2, d_triIndices2, d_collisionPairs, nPairs, (int2 **)collisionList);


	GPUFREE(d_workQueueCounts);
	GPUFREE(d_workQueues);
	GPUFREE(d_workQueues2);
	GPUFREE(d_collisionPairs);
	GPUFREE(d_collisionPairIndex);
	GPUFREE(d_nWorkQueueElements);
	GPUFREE(d_collisionSync);
	GPUFREE(d_balanceSignal);

	return nPairs;

}