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
 
{
#ifndef UPDATE_TRIARRAY
#define UPDATE_TRIARRAY BVH.triIDs
#endif

	//
	// Updates a bounding box on multiple threads in parallel.
	// Output is stored in the first index of localBoxes, which is assumed to
	// be a shared memory array of 6*nThreads floats.
	//
	
	// NB: localBoxes is arranged as an struct of arrays instead of array of structs,
	// i.e. all the min[0] values are stored first, then all min[1] etc.
	// This ensures shared memory accesses are conflict free.
	
	// if the number of boxes is pretty low (compared to #threads), then
	// the hierarchical reduction should only be run on as many threads
	// as are necessary, so we compute the next largest power of two for
	// the number of boxes here to detect this.
	int nextPowerTwo = nBoxesToProcess;
	{
		nextPowerTwo--;
		nextPowerTwo |= nextPowerTwo >> 1;
		nextPowerTwo |= nextPowerTwo >> 2;
		nextPowerTwo |= nextPowerTwo >> 4;
		nextPowerTwo |= nextPowerTwo >> 8;
		nextPowerTwo |= nextPowerTwo >> 16;
		nextPowerTwo++;
		nextPowerTwo = min(nextPowerTwo, nSplitThreads);
	}
	
	// go through the list of boxes in chunks, each thread reading one of the boxes and
	// building the bounding box locally
	{
#ifndef UPDATE_EXTBBOX
		AABB localBox; // AABB in registers, to be updated by each thread
		AABB_INIT(localBox);
#define UPDATE_EXTBOX localBox
#endif
		while(nBoxesToProcess > 0)
		{
			if(threadOffset < nBoxesToProcess)
			{
				const int triID = UPDATE_TRIARRAY[boxOffset + threadOffset];
				float2 box;
				
				// X
				box = tex1Dfetch(g_tex_AABBs, triID);
				UPDATE_EXTBOX.bb_min.x = min(UPDATE_EXTBOX.bb_min.x, box.x);
				UPDATE_EXTBOX.bb_max.x = max(UPDATE_EXTBOX.bb_max.x, box.y);
				// Y
				box = tex1Dfetch(g_tex_AABBs, triID + g_tex_AABBs_offset);
				UPDATE_EXTBOX.bb_min.y = min(UPDATE_EXTBOX.bb_min.y, box.x);
				UPDATE_EXTBOX.bb_max.y = max(UPDATE_EXTBOX.bb_max.y, box.y);
				// Z
				box = tex1Dfetch(g_tex_AABBs, triID + 2 * g_tex_AABBs_offset);
				UPDATE_EXTBOX.bb_min.z = min(UPDATE_EXTBOX.bb_min.z, box.x);
				UPDATE_EXTBOX.bb_max.z = max(UPDATE_EXTBOX.bb_max.z, box.y);
			}
			
			boxOffset += nSplitThreads;
			nBoxesToProcess -= nSplitThreads;
		}
		
		if(threadOffset < nextPowerTwo)
		{
			// save accumulated bounding boxes to shared memory
			localBoxes[threadOffset]				   = UPDATE_EXTBOX.bb_min.x;
			localBoxes[threadOffset + nSplitThreads]   = UPDATE_EXTBOX.bb_min.y;
			localBoxes[threadOffset + 2*nSplitThreads] = UPDATE_EXTBOX.bb_min.z;
			localBoxes[threadOffset + 3*nSplitThreads] = UPDATE_EXTBOX.bb_max.x;
			localBoxes[threadOffset + 4*nSplitThreads] = UPDATE_EXTBOX.bb_max.y;
			localBoxes[threadOffset + 5*nSplitThreads] = UPDATE_EXTBOX.bb_max.z;
		}
		__syncthreads();
	}
	
	// merge bounding boxes by parallel reduce:
	for(int r = nextPowerTwo / 2; r != 0; r /= 2)
	{
		if(threadOffset < r)
		{
			int other = threadOffset + r;
			
			// min[0]..min[2]
			localBoxes[threadOffset                  ] = min(localBoxes[threadOffset                  ], localBoxes[other                  ]);
			localBoxes[threadOffset + nSplitThreads  ] = min(localBoxes[threadOffset + nSplitThreads  ], localBoxes[other + nSplitThreads  ]);
			localBoxes[threadOffset + 2*nSplitThreads] = min(localBoxes[threadOffset + 2*nSplitThreads], localBoxes[other + 2*nSplitThreads]);
			
			// max[0]..max[2]
			localBoxes[threadOffset + 3*nSplitThreads] = max(localBoxes[threadOffset + 3*nSplitThreads], localBoxes[other + 3*nSplitThreads]);
			localBoxes[threadOffset + 4*nSplitThreads] = max(localBoxes[threadOffset + 4*nSplitThreads], localBoxes[other + 4*nSplitThreads]);
			localBoxes[threadOffset + 5*nSplitThreads] = max(localBoxes[threadOffset + 5*nSplitThreads], localBoxes[other + 5*nSplitThreads]);
		}
		
		__syncthreads();
	}
	
#undef UPDATE_TRIARRAY
#undef UPDATE_EXTBBOX
}
