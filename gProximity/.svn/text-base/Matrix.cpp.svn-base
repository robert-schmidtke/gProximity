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
 
#include "Matrix.h"
#include <iomanip>

using namespace std;

Matrix::Matrix(float * Q)
{
	this->x[0][0] = Q[0];
	this->x[0][1] = Q[1];
	this->x[0][2] = Q[2];
	this->x[0][3] = Q[3];
	this->x[1][0] = Q[4];
	this->x[1][1] = Q[5];
	this->x[1][2] = Q[6];
	this->x[1][3] = Q[7];
	this->x[2][0] = Q[8];
	this->x[2][1] = Q[9];
	this->x[2][2] = Q[10];
	this->x[2][3] = Q[11];
	this->x[3][0] = Q[12];
	this->x[3][1] = Q[13];
	this->x[3][2] = Q[14];
	this->x[3][3] = Q[15];
}

Matrix::Matrix(const Matrix & right_op)
{
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			x[i][j] = right_op.x[i][j];
}

Matrix& Matrix::operator+= (const Matrix & right_op)
{
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			x[i][j] += right_op.x[i][j];
	return *this;
}

Matrix& Matrix::operator-= (const Matrix & right_op)
{
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			x[i][j] -= right_op.x[i][j];
	return *this;
}

Matrix& Matrix::operator*= (float right_op)
{
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			x[i][j] *= right_op;
	return *this;
}

Matrix& Matrix::operator*= (const Matrix & right_op)
{
	Matrix ret = *this;

	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
		{
			float sum = 0;
			for(int k = 0; k < 4; k++)
				sum += ret.x[i][k] * right_op.x[k][j];
			x[i][j] = sum;
		}
		return *this;
}

void Matrix::invert()
{
	float det = determinant();
	Matrix inverse;
	inverse.x[0][0]  = det3(x[1][1], x[1][2], x[1][3],
		x[2][1], x[2][2], x[2][3],
		x[3][1], x[3][2], x[3][3]) / det;
	inverse.x[0][1] = -det3(x[0][1], x[0][2], x[0][3],
		x[2][1], x[2][2], x[2][3],
		x[3][1], x[3][2], x[3][3]) / det;
	inverse.x[0][2]  = det3(x[0][1], x[0][2], x[0][3],
		x[1][1], x[1][2], x[1][3],
		x[3][1], x[3][2], x[3][3]) / det;
	inverse.x[0][3] = -det3(x[0][1], x[0][2], x[0][3],
		x[1][1], x[1][2], x[1][3],
		x[2][1], x[2][2], x[2][3]) / det;

	inverse.x[1][0] = -det3(x[1][0], x[1][2], x[1][3],
		x[2][0], x[2][2], x[2][3],
		x[3][0], x[3][2], x[3][3]) / det;
	inverse.x[1][1]  = det3(x[0][0], x[0][2], x[0][3],
		x[2][0], x[2][2], x[2][3],
		x[3][0], x[3][2], x[3][3]) / det;
	inverse.x[1][2] = -det3(x[0][0], x[0][2], x[0][3],
		x[1][0], x[1][2], x[1][3],
		x[3][0], x[3][2], x[3][3]) / det;
	inverse.x[1][3]  = det3(x[0][0], x[0][2], x[0][3],
		x[1][0], x[1][2], x[1][3],
		x[2][0], x[2][2], x[2][3]) / det;

	inverse.x[2][0]  = det3(x[1][0], x[1][1], x[1][3],
		x[2][0], x[2][1], x[2][3],
		x[3][0], x[3][1], x[3][3]) / det;
	inverse.x[2][1] = -det3(x[0][0], x[0][1], x[0][3],
		x[2][0], x[2][1], x[2][3],
		x[3][0], x[3][1], x[3][3]) / det;
	inverse.x[2][2]  = det3(x[0][0], x[0][1], x[0][3],
		x[1][0], x[1][1], x[1][3],
		x[3][0], x[3][1], x[3][3]) / det;
	inverse.x[2][3] = -det3(x[0][0], x[0][1], x[0][3],
		x[1][0], x[1][1], x[1][3],
		x[2][0], x[2][1], x[2][3]) / det;


	inverse.x[3][0] = -det3(x[1][0], x[1][1], x[1][2],
		x[2][0], x[2][1], x[2][2],
		x[3][0], x[3][1], x[3][2]) / det;
	inverse.x[3][1] =  det3(x[0][0], x[0][1], x[0][2],
		x[2][0], x[2][1], x[2][2],
		x[3][0], x[3][1], x[3][2]) / det;
	inverse.x[3][2] = -det3(x[0][0], x[0][1], x[0][2],
		x[1][0], x[1][1], x[1][2],
		x[3][0], x[3][1], x[3][2]) / det;
	inverse.x[3][3] =  det3(x[0][0], x[0][1], x[0][2],
		x[1][0], x[1][1], x[1][2],
		x[2][0], x[2][1], x[2][2]) / det;

	*this = inverse;
}

Matrix Matrix::getInverse()const
{
	Matrix ret = *this;
	ret.invert();
	return ret;
}

void Matrix::transpose()
{
	for(int i = 0; i < 4; i++)
		for(int j = i + 1; j < 4; j++)
		{
			float temp = x[i][j];
			x[i][j] = x[j][i];
			x[j][i] = temp;
		}
}

Matrix Matrix::getTranspose()const
{
	Matrix ret = *this;
	ret.transpose();

	return ret;
}

Vector3 TransformLoc(const Matrix& left_op, const Vector3& right_op)
{
	return left_op * right_op;
}

Vector3 TransformVec(const Matrix& left_op, const Vector3& right_op)
{
	Vector3 ret;

	ret[0] = right_op[0] * left_op.x[0][0] + right_op[1] * left_op.x[0][1] +
		right_op[2] * left_op.x[0][2];
	ret[1] = right_op[0] * left_op.x[1][0] + right_op[1] * left_op.x[1][1] +
		right_op[2] * left_op.x[1][2];
	ret[2] = right_op[0] * left_op.x[2][0] + right_op[1] * left_op.x[2][1] +
		right_op[2] * left_op.x[2][2];

	return ret;

}

Matrix zeroMatrix()
{
	Matrix ret;
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			ret.x[i][j] = 0.0;
	return ret;
}

Matrix identityMatrix()
{
	Matrix ret;
	ret.x[0][0] = 1.0;
	ret.x[0][1] = 0.0;
	ret.x[0][2] = 0.0;
	ret.x[0][3] = 0.0;
	ret.x[1][0] = 0.0;
	ret.x[1][1] = 1.0;
	ret.x[1][2] = 0.0;
	ret.x[1][3] = 0.0;
	ret.x[2][0] = 0.0;
	ret.x[2][1] = 0.0;
	ret.x[2][2] = 1.0;
	ret.x[2][3] = 0.0;
	ret.x[3][0] = 0.0;
	ret.x[3][1] = 0.0;
	ret.x[3][2] = 0.0;
	ret.x[3][3] = 1.0;
	return ret;
}

Matrix translate(float _x, float _y, float _z)
{
	Matrix ret = identityMatrix();

	ret.x[0][3] = _x;
	ret.x[1][3] = _y;
	ret.x[2][3] = _z;

	return ret;
}

// angle is in radians
Matrix rotateX(float angle)
{
	Matrix ret = identityMatrix();

	float cosine = cos(angle);
	float sine   = sin(angle);

	ret.x[1][1] = cosine;
	ret.x[1][2] =  -sine;
	ret.x[2][1] =   sine;
	ret.x[2][2] = cosine;

	return ret;
}

// angle is in radians
Matrix rotateY(float angle)
{
	Matrix ret = identityMatrix();

	float cosine = cos(angle);
	float sine   = sin(angle);

	ret.x[0][0] = cosine;
	ret.x[0][2] =   sine;
	ret.x[2][0] =  -sine;
	ret.x[2][2] = cosine;

	return ret;
}

// angle is in radians
Matrix rotateZ(float angle)
{
	Matrix ret = identityMatrix();

	float cosine = cos(angle);
	float sine   = sin(angle);

	ret.x[0][0] = cosine;
	ret.x[0][1] =  -sine;
	ret.x[1][0] =   sine;
	ret.x[1][1] = cosine;

	return ret;
}

// rotation is in radians about an arbitrary axis
Matrix
rotate(const Vector3 & axis, float angle)
{
	Vector3 _axis = unitVector(axis);
	Matrix ret;
	float x = _axis.x();
	float y = _axis.y();
	float z = _axis.z();
	float cosine = cos(angle);
	float sine = sin(angle);
	float t   = 1 - cosine;

	ret.x[0][0] = t * x * x + cosine;
	ret.x[0][1] = t * x * y - sine * z;
	ret.x[0][2] = t * x * z + sine * y;
	ret.x[0][3] = 0.0;

	ret.x[1][0] = t * x * y + sine * z;
	ret.x[1][1] = t * y * y + cosine;
	ret.x[1][2] = t * y * z - sine * x;
	ret.x[1][3] = 0.0;

	ret.x[2][0] = t * x * z - sine * y;
	ret.x[2][1] = t * y * z + sine * x;
	ret.x[2][2] = t * z * z + cosine;
	ret.x[2][3] = 0.0;

	ret.x[3][0] = 0.0;
	ret.x[3][1] = 0.0;
	ret.x[3][2] = 0.0;
	ret.x[3][3] = 1.0;

	return ret;
}

Matrix scale(float _x, float _y, float _z)
{
	Matrix ret = zeroMatrix();

	ret.x[0][0] = _x;
	ret.x[1][1] = _y;
	ret.x[2][2] = _z;
	ret.x[3][3] = 1.0;

	return ret;
}

// creates viewing Matrix that so the ey is at xyz origin looking down the -z axis
Matrix
viewMatrix(const Vector3 & eye, const Vector3 & gaze, const Vector3 & up)
{
	Matrix ret = identityMatrix();

	// create an orthoganal basis from parameters
	Vector3 w = -(unitVector(gaze));
	Vector3 u = unitVector(cross(up, w));
	Vector3 v = cross(w, u);

	// rotate orthoganal basis to xyz basis
	ret.x[0][0] = u.x();
	ret.x[0][1] = u.y();
	ret.x[0][2] = u.z();
	ret.x[1][0] = v.x();
	ret.x[1][1] = v.y();
	ret.x[1][2] = v.z();
	ret.x[2][0] = w.x();
	ret.x[2][1] = w.y();
	ret.x[2][2] = w.z();

	// translare eye to xyz origin
	Matrix move = identityMatrix();
	move.x[0][3] = -(eye.x());
	move.x[1][3] = -(eye.y());
	move.x[2][3] = -(eye.z());

	ret = ret * move;
	return ret;
}

Matrix operator+ (const Matrix & left_op, const Matrix & right_op)
{
	Matrix ret;

	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			ret.x[i][j] = left_op.x[i][j] + right_op.x[i][j];

	return ret;
}

Matrix operator- (const Matrix & left_op, const Matrix & right_op)
{
	Matrix ret;

	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			ret.x[i][j] = left_op.x[i][j] - right_op.x[i][j];

	return ret;
}

Matrix operator*(const Matrix & left_op, float right_op)
{
	Matrix ret;

	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			ret.x[i][j] = left_op.x[i][j] * right_op;

	return ret;
}

Matrix operator*(const Matrix & left_op, const Matrix & right_op)
{
	Matrix ret;

	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
		{
			float subt = 0.0;
			for(int k = 0; k < 4; k++)
				subt += left_op.x[i][k] * right_op.x[k][j];
			ret.x[i][j] = subt;
		}

		return ret;
}

// Transform a vector by matrix
Vector3 operator*(const Matrix & left_op, const Vector3 & right_op)
{
	Vector3 ret;
	float temp;

	ret[0] = right_op[0] * left_op.x[0][0] + right_op[1] * left_op.x[0][1] +
		right_op[2] * left_op.x[0][2] +               left_op.x[0][3];
	ret[1] = right_op[0] * left_op.x[1][0] + right_op[1] * left_op.x[1][1] +
		right_op[2] * left_op.x[1][2] +               left_op.x[1][3];
	ret[2] = right_op[0] * left_op.x[2][0] + right_op[1] * left_op.x[2][1] +
		right_op[2] * left_op.x[2][2] +               left_op.x[2][3];
	temp   = right_op[0] * left_op.x[3][0] + right_op[1] * left_op.x[3][1] +
		right_op[2] * left_op.x[3][2] +               left_op.x[3][3];

	ret /= temp;
	return ret;
}

std::ostream & operator<< (std::ostream & out, const Matrix & right_op)
{
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
			out << setprecision(3) << setw(10) << right_op.x[i][j];
		out << endl;
	}
	return out;
}

float Matrix::determinant()
{
	float det;
	det  = x[0][0] * det3(x[1][1], x[1][2], x[1][3],
		x[2][1], x[2][2], x[2][3],
		x[3][1], x[3][2], x[3][3]);
	det -= x[0][1] * det3(x[1][0], x[1][2], x[1][3],
		x[2][0], x[2][2], x[2][3],
		x[3][0], x[3][2], x[3][3]);
	det += x[0][2] * det3(x[1][0], x[1][1], x[1][3],
		x[2][0], x[2][1], x[2][3],
		x[3][0], x[3][1], x[3][3]);
	det -= x[0][3] * det3(x[1][0], x[1][1], x[1][2],
		x[2][0], x[2][1], x[2][2],
		x[3][0], x[3][1], x[3][2]);
	return det;
}

void Matrix::fromAngleAxis(Vector3 angle, float rot)
{

	float fCos = cos(rot);
	float fSin = sin(rot);
	float fOneMinusCos = ((float)1.0) - fCos;
	float fX2 = angle[0] * angle[0];
	float fY2 = angle[1] * angle[1];
	float fZ2 = angle[2] * angle[2];
	float fXYM = angle[0] * angle[1] * fOneMinusCos;
	float fXZM = angle[0] * angle[2] * fOneMinusCos;
	float fYZM = angle[1] * angle[2] * fOneMinusCos;
	float fXSin = angle[0] * fSin;
	float fYSin = angle[1] * fSin;
	float fZSin = angle[2] * fSin;

	x[0][0] = fX2 * fOneMinusCos + fCos;
	x[0][1] = fXYM - fZSin;
	x[0][2] = fXZM + fYSin;
	x[0][3] = 0;

	x[1][0] = fXYM + fZSin;
	x[1][1] = fY2 * fOneMinusCos + fCos;
	x[1][2] = fYZM - fXSin;
	x[1][3] = 0;

	x[2][0] = fXZM - fYSin;
	x[2][1] = fYZM + fXSin;
	x[2][2] = fZ2 * fOneMinusCos + fCos;
	x[2][3] = 0;

	x[3][0] = 0;
	x[3][1] = 0;
	x[3][2] = 0;
	x[3][3] = 1;
}
