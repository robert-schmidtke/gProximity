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
 
#ifndef __MATH_DEFINES_H_
#define __MATH_DEFINES_H_

// Useful constants
//
#define MATH_PI		3.141592f	// Pi
#define MATH_PI2		6.283185f	// Pi^2
#define MATH_HALF_PI	1.570796f	// Pi/2
#define E		2.718282f	// Euler's Number
#define DTOR	0.017452f	// Degree -> Radian
#define RTOD	57.29578f	// Radian -> Degree
#define EPSILON 0.00001f	// useful for float comparisons

// Useful macros
//
#define SQR(a)			((a)*(a))
#define SWAP(a,b)		{ a^=b; b^=a; a^=b; }
#define LERP(a,l,r)		((l) + (((r) - (l))*(a)))
#define CLAMP(v,l,r)	((v)<(l)?(l) : (v)>(r)?(r):v)

// get sign from float without branching, returns -1 or 1
//#define FLOATSIGN(f) ( +1 | ((*(int *)&f) >> (sizeof(float) * 8 - 1)) )

// get sign from float without branching, returns -1, 0 or 1
#define FLOATSIGN(f) ( ((f) > 0.0) - ((f) < 0.0) )

// Floating point comparisons with epsilon factored
// in, so that small fp instabilities won't matter
// (e.g. coordinate comparisons)

// a <= b
#define FLOAT_LE(a,b) (((a)-(b))<EPSILON)
// a < b
#define FLOAT_LT(a,b) (((a)-(b))<-EPSILON)
// a >= b
#define FLOAT_GE(a,b) (((b)-(a))<EPSILON)
// a > b
#define FLOAT_GT(a,b) (((b)-(a))<-EPSILON)
// a == b
#define FLOAT_EQ(a,b) ((((a)-(b))<EPSILON) && (((a)-(b))>-EPSILON))


#endif