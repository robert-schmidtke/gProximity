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
 
#ifndef __MATRIX_H_
#define __MATRIX_H_

#include "Vector3.h"
#include <iostream>
#include <iomanip>
#include <math.h>

class Matrix
{
public:
	Matrix() {}
	Matrix(float * mat);
	Matrix(const Matrix & orig);

	void invert();
	void transpose();
	Matrix getInverse()const;
	Matrix getTranspose()const;

	Matrix & operator+= (const Matrix& right_op);
	Matrix & operator-= (const Matrix& right_op);
	Matrix & operator*= (const Matrix& right_op);
	Matrix & operator*= (float right_op);

	friend Matrix operator- (const Matrix& left_op, const Matrix& right_op);
	friend Matrix operator+ (const Matrix& left_op, const Matrix& right_op);
	friend Matrix operator*(const Matrix& left_op, const Matrix& right_op);

	// matrix mult. performed left to right
	friend Vector3 operator*(const Matrix& left_op, const Vector3& right_op);
	// Transform vector by a matrix
	friend Matrix operator*(const Matrix & left_op, float right_op);

	friend Vector3 TransformLoc(const Matrix& left_op, const Vector3& right_op);
	friend Vector3 TransformVec(const Matrix& left_op, const Vector3& right_op);

	void fromAngleAxis(Vector3 angle, float rot);

	friend Matrix zeroMatrix();
	friend Matrix identityMatrix();
	friend Matrix translate(float _x, float _y, float _z);
	friend Matrix scale(float _x, float _y, float _z);
	friend Matrix rotate(const Vector3 & axis, float angle);
	friend Matrix rotateX(float angle);    //
	friend Matrix rotateY(float angle);    // More efficient than arbitrary axis
	friend Matrix rotateZ(float angle);    //
	friend Matrix viewMatrix(const Vector3& eye, const Vector3 & gaze,
		const Vector3& up);
	friend std::ostream & operator<< (std::ostream& out, const Matrix& right_op);

	float determinant();
	float x[4][4];
};

// 3x3 matrix determinant -- helper function
inline float det3(float a, float b, float c,
				  float d, float e, float f,
				  float g, float h, float i)
{
	return a * e * i + d * h * c + g * b * f - g * e * c - d * b * i - a * h * f;
}

#endif
