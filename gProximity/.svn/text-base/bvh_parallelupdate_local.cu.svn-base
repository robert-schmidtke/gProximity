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
	//
	// Updates a bounding box on multiple threads in parallel.
	// Output is stored in the first index of localBoxes, which is assumed to
	// be a shared memory array of 6*nThreads floats.
	//
	
	// NB: localBoxes is arranged as an struct of arrays instead of array of structs,
	// i.e. all the min[0] values are stored first, then all min[1] etc.
	// This ensures shared memory accesses are conflict free.
	
	
	if(threadOffset < nBoxesToProcess)
	{
		const int triID = localTriIDs[boxOffset + threadOffset];
		
		localBoxes[threadOffset]				   = localBoundingBoxes[triID];
		localBoxes[threadOffset +   nSplitThreads] = localBoundingBoxes[triID +   nMaxTris];
		localBoxes[threadOffset + 2*nSplitThreads] = localBoundingBoxes[triID + 2*nMaxTris];
		localBoxes[threadOffset + 3*nSplitThreads] = localBoundingBoxes[triID + 3*nMaxTris];
		localBoxes[threadOffset + 4*nSplitThreads] = localBoundingBoxes[triID + 4*nMaxTris];
		localBoxes[threadOffset + 5*nSplitThreads] = localBoundingBoxes[triID + 5*nMaxTris];
	}
	
	__syncthreads();
	
#define MERGE_NAIVE_THRESHOLD 4
	if(nBoxesToProcess <= MERGE_NAIVE_THRESHOLD)
	{
		if(threadOffset < 3)
		{
			int myOffset1 = threadOffset * nSplitThreads;
			int myOffset2 = (threadOffset + 3) * nSplitThreads;
			float myVal1 = localBoxes[myOffset1];
			float myVal2 = localBoxes[myOffset2];
			for(int i = 1; i < nBoxesToProcess; i++)
			{
				myVal1 = min(myVal1, localBoxes[myOffset1 + i]);
				myVal2 = max(myVal2, localBoxes[myOffset2 + i]);
			}
			localBoxes[threadOffset] = myVal1;
			localBoxes[threadOffset + 3] = myVal2;
		}
		__syncthreads();
	}
	else   // merge bounding boxes by parallel reduce:
	{
		for(int r = nSplitThreads / 2; r != 0; r /= 2)
		{
			int other = threadOffset + r;
			
			if(threadOffset < r && other < nBoxesToProcess)
			{
			
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
		
		if(threadOffset < 6)
			localBoxes[threadOffset] = localBoxes[threadOffset*nSplitThreads];
		__syncthreads();
	}
}
