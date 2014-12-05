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

#include "Transform.h"
#include "mathdef.h"
#include <math.h>
#include "Matrix.h"
#include <assert.h>

void Transform::set_identity()
{
	m_R[0][0] = m_R[1][1] = m_R[2][2]  = 1;
	m_R[0][1] = m_R[0][2] = m_R[1][0] = m_R[1][2] = m_R[2][0] =  m_R[2][1] = 0;
	m_T[0] = 0;
	m_T[1] = 0;
	m_T[2] = 0;
}

bool Transform::is_identity() const
{
	return FLOAT_EQ(m_R[0][0], 1.0f) && FLOAT_EQ(m_R[0][1], 0.0f) && FLOAT_EQ(m_R[0][2], 0.0f)
		&& FLOAT_EQ(m_R[1][0], 0.0f) && FLOAT_EQ(m_R[1][1], 1.0f) && FLOAT_EQ(m_R[1][2], 0.0f)
		&& FLOAT_EQ(m_R[2][0], 0.0f) && FLOAT_EQ(m_R[2][1], 0.0f) && FLOAT_EQ(m_R[2][2], 1.0f)
		&& FLOAT_EQ(m_T[0], 0.0f) && FLOAT_EQ(m_T[1], 0.0f) && FLOAT_EQ(m_T[2], 0.0f);
}

bool Transform::is_transl_zero()
{
	return FLOAT_EQ(m_T[0], 0.0f) && FLOAT_EQ(m_T[1], 0.0f) && FLOAT_EQ(m_T[2], 0.0f);
}

bool Transform::is_rotate_zero()
{
	return FLOAT_EQ(m_R[1][0], 0.0f) && FLOAT_EQ(m_R[1][1], 1.0f) && FLOAT_EQ(m_R[1][2], 0.0f)
		&& FLOAT_EQ(m_R[2][0], 0.0f) && FLOAT_EQ(m_R[2][1], 0.0f) && FLOAT_EQ(m_R[2][2], 1.0f)
		&& FLOAT_EQ(m_T[0], 0.0f) && FLOAT_EQ(m_T[1], 0.0f) && FLOAT_EQ(m_T[2], 0.0f);
}

void Transform::set_product(Transform const& X, Transform const& Y)
{
	if(X.is_identity())
	{
		m_T[0] = Y.m_T[0], m_T[1] = Y.m_T[1], m_T[2] = Y.m_T[2];
		m_R[0][0] = Y.m_R[0][0], m_R[0][1] = Y.m_R[0][1], m_R[0][2] = Y.m_R[0][2];
		m_R[1][0] = Y.m_R[1][0], m_R[1][1] = Y.m_R[1][1], m_R[1][2] = Y.m_R[1][2];
		m_R[2][0] = Y.m_R[2][0], m_R[2][1] = Y.m_R[2][1], m_R[2][2] = Y.m_R[2][2];
	}
	else if(Y.is_identity())
	{
		m_T[0] = X.m_T[0], m_T[1] = X.m_T[1], m_T[2] = X.m_T[2];
		m_R[0][0] = X.m_R[0][0], m_R[0][1] = X.m_R[0][1], m_R[0][2] = X.m_R[0][2];
		m_R[1][0] = X.m_R[1][0], m_R[1][1] = X.m_R[1][1], m_R[1][2] = X.m_R[1][2];
		m_R[2][0] = X.m_R[2][0], m_R[2][1] = X.m_R[2][1], m_R[2][2] = X.m_R[2][2];
	}
	else
	{
		m_T[0] = X.m_T[0] + X.m_R[0][0] * Y.m_T[0] + X.m_R[0][1] * Y.m_T[1] + X.m_R[0][2] * Y.m_T[2];
		m_T[1] = X.m_T[1] + X.m_R[1][0] * Y.m_T[0] + X.m_R[1][1] * Y.m_T[1] + X.m_R[1][2] * Y.m_T[2];
		m_T[2] = X.m_T[2] + X.m_R[2][0] * Y.m_T[0] + X.m_R[2][1] * Y.m_T[1] + X.m_R[2][2] * Y.m_T[2];

		m_R[0][0] = X.m_R[0][0] * Y.m_R[0][0] + X.m_R[0][1] * Y.m_R[1][0] + X.m_R[0][2] * Y.m_R[2][0];
		m_R[0][1] = X.m_R[0][0] * Y.m_R[0][1] + X.m_R[0][1] * Y.m_R[1][1] + X.m_R[0][2] * Y.m_R[2][1];
		m_R[0][2] = X.m_R[0][0] * Y.m_R[0][2] + X.m_R[0][1] * Y.m_R[1][2] + X.m_R[0][2] * Y.m_R[2][2];

		m_R[1][0] = X.m_R[1][0] * Y.m_R[0][0] + X.m_R[1][1] * Y.m_R[1][0] + X.m_R[1][2] * Y.m_R[2][0];
		m_R[1][1] = X.m_R[1][0] * Y.m_R[0][1] + X.m_R[1][1] * Y.m_R[1][1] + X.m_R[1][2] * Y.m_R[2][1];
		m_R[1][2] = X.m_R[1][0] * Y.m_R[0][2] + X.m_R[1][1] * Y.m_R[1][2] + X.m_R[1][2] * Y.m_R[2][2];

		m_R[2][0] = X.m_R[2][0] * Y.m_R[0][0] + X.m_R[2][1] * Y.m_R[1][0] + X.m_R[2][2] * Y.m_R[2][0];
		m_R[2][1] = X.m_R[2][0] * Y.m_R[0][1] + X.m_R[2][1] * Y.m_R[1][1] + X.m_R[2][2] * Y.m_R[2][1];
		m_R[2][2] = X.m_R[2][0] * Y.m_R[0][2] + X.m_R[2][1] * Y.m_R[1][2] + X.m_R[2][2] * Y.m_R[2][2];
	}
}

// concatenate X to the right to the Transform
void Transform::append(const Transform& X)
{
	if(is_identity())
	{
		m_T[0] = X.m_T[0], m_T[1] = X.m_T[1], m_T[2] = X.m_T[2];
		m_R[0][0] = X.m_R[0][0], m_R[0][1] = X.m_R[0][1], m_R[0][2] = X.m_R[0][2];
		m_R[1][0] = X.m_R[1][0], m_R[1][1] = X.m_R[1][1], m_R[1][2] = X.m_R[1][2];
		m_R[2][0] = X.m_R[2][0], m_R[2][1] = X.m_R[2][1], m_R[2][2] = X.m_R[2][2];
	}
	else if(!X.is_identity())
	{
		m_T[0] = m_T[0] + m_R[0][0] * X.m_T[0] +  m_R[0][1] * X.m_T[1] + m_R[0][2] * X.m_T[2];
		m_T[1] = m_T[1] + m_R[1][0] * X.m_T[0] +  m_R[1][1] * X.m_T[1] + m_R[1][2] * X.m_T[2];
		m_T[2] = m_T[2] + m_R[2][0] * X.m_T[0] +  m_R[2][1] * X.m_T[1] + m_R[2][2] * X.m_T[2];

		float tmpR0[3] = {m_R[0][0], m_R[0][1], m_R[0][2]};

		m_R[0][0] = tmpR0[0] * X.m_R[0][0] + tmpR0[1] * X.m_R[1][0] + tmpR0[2] * X.m_R[2][0];
		m_R[0][1] = tmpR0[0] * X.m_R[0][1] + tmpR0[1] * X.m_R[1][1] + tmpR0[2] * X.m_R[2][1];
		m_R[0][2] = tmpR0[0] * X.m_R[0][2] + tmpR0[1] * X.m_R[1][2] + tmpR0[2] * X.m_R[2][2];

		float tmpR1[3] = {m_R[1][0], m_R[1][1], m_R[1][2]};

		m_R[1][0] = tmpR1[0] * X.m_R[0][0] + tmpR1[1] * X.m_R[1][0] + tmpR1[2] * X.m_R[2][0];
		m_R[1][1] = tmpR1[0] * X.m_R[0][1] + tmpR1[1] * X.m_R[1][1] + tmpR1[2] * X.m_R[2][1];
		m_R[1][2] = tmpR1[0] * X.m_R[0][2] + tmpR1[1] * X.m_R[1][2] + tmpR1[2] * X.m_R[2][2];

		float tmpR2[3] = {m_R[2][0], m_R[2][1], m_R[2][2]};

		m_R[2][0] = tmpR2[0] * X.m_R[0][0] + tmpR2[1] * X.m_R[1][0] + tmpR2[2] * X.m_R[2][0];
		m_R[2][1] = tmpR2[0] * X.m_R[0][1] + tmpR2[1] * X.m_R[1][1] + tmpR2[2] * X.m_R[2][1];
		m_R[2][2] = tmpR2[0] * X.m_R[0][2] + tmpR2[1] * X.m_R[1][2] + tmpR2[2] * X.m_R[2][2];
	}
}


void Transform::append_left(const Transform& X)
{
	if(is_identity())
	{
		m_T[0] = X.m_T[0], m_T[1] = X.m_T[1], m_T[2] = X.m_T[2];
		m_R[0][0] = X.m_R[0][0], m_R[0][1] = X.m_R[0][1], m_R[0][2] = X.m_R[0][2];
		m_R[1][0] = X.m_R[1][0], m_R[1][1] = X.m_R[1][1], m_R[1][2] = X.m_R[1][2];
		m_R[2][0] = X.m_R[2][0], m_R[2][1] = X.m_R[2][1], m_R[2][2] = X.m_R[2][2];
	}
	else if(!X.is_identity())
	{
		Transform tmp = X;
		tmp.append(*this);
		*this = tmp;
	}
}

void Transform::apply(float out[3], const float in[3]) const
{
	if(is_identity())
	{
		out[0] = in[0], out[1] = in[1], out[2] = in[2];
	}
	else
	{
		out[0] = m_R[0][0] * in[0] + m_R[0][1] * in[1] + m_R[0][2] * in[2] + m_T[0];
		out[1] = m_R[1][0] * in[0] + m_R[1][1] * in[1] + m_R[1][2] * in[2] + m_T[1];
		out[2] = m_R[2][0] * in[0] + m_R[2][1] * in[1] + m_R[2][2] * in[2] + m_T[2];
	}
}

void Transform::apply_inv(float out[3], const float in[3]) const
{
	if(is_identity())
	{
		out[0] = in[0], out[1] = in[1], out[2] = in[2];
	}
	else
	{
		float tmp[3] = {in[0] - m_T[0], in[1] - m_T[1], in[2] - m_T[2]};
		out[0] = m_R[0][0] * tmp[0] + m_R[1][0] * tmp[1] + m_R[2][0] * tmp[2];
		out[1] = m_R[0][1] * tmp[0] + m_R[1][1] * tmp[1] + m_R[2][1] * tmp[2];
		out[2] = m_R[0][2] * tmp[0] + m_R[1][2] * tmp[1] + m_R[2][2] * tmp[2];
	}
}

void Transform::extract_axis_angle(float axis[3], float& angle)
{
	float trace = m_R[0][0] + m_R[1][1] + m_R[2][2];
	float cs = 0.5f * (trace - 1.0f);
	angle = acosf(cs);

	if(angle > 0)
	{
		if(angle < MATH_PI)
		{
			axis[0] = m_R[2][1] - m_R[1][2];
			axis[1] = m_R[0][2] - m_R[2][0];
			axis[2] = m_R[1][0] - m_R[0][1];
			float t = sqrtf(axis[0] * axis[0] + axis[1] * axis[1] + axis[2] * axis[2]);
			if(t > 0)
			{
				axis[0] = axis[0] / t;
				axis[1] = axis[1] / t;
				axis[2] = axis[2] / t;
			}
		}
		else
		{
			float halfinverse;
			if(m_R[0][0] >= m_R[1][1])
			{
				if(m_R[0][0] >= m_R[2][2])
				{
					axis[0] = 0.5f * sqrtf(1.0f + m_R[0][0] - m_R[1][1] - m_R[2][2]);
					halfinverse = 0.5f / axis[0];
					axis[1] = halfinverse * m_R[0][1];
					axis[2] = halfinverse * m_R[0][2];
				}
				else
				{
					axis[2] = 0.5f * sqrtf(1.0f + m_R[2][2] - m_R[0][0] - m_R[1][1]);
					halfinverse = 0.5f / axis[2];
					axis[0] = halfinverse * m_R[0][2];
					axis[1] = halfinverse * m_R[1][2];
				}
			}
			else
			{
				if(m_R[1][1] >= m_R[2][2])
				{
					axis[1] = 0.5f * sqrtf(1.0f + m_R[1][1] - m_R[0][0] - m_R[2][2]);
					halfinverse = 0.5f / axis[1];
					axis[0] = halfinverse * m_R[0][1];
					axis[2] = halfinverse * m_R[1][2];
				}
				else
				{
					axis[2] = 0.5f * sqrtf(1.0f + m_R[2][2] - m_R[0][0] - m_R[1][1]);
					halfinverse = 0.5f / axis[2];
					axis[0] = halfinverse * m_R[0][2];
					axis[1] = halfinverse * m_R[1][2];
				}
			}
		}
	}
	else
	{
		axis[0] = 1;
		axis[1] = 0;
		axis[2] = 0;
	}
}

void rotate(float axis[3], float angle, float R_[3][3])
{
	float co = cos(angle);
	float si = sin(angle);
	float co1 = 1 - co;

	R_[0][0] = axis[0] * axis[0] * co1 + co;
	R_[0][1] = axis[0] * axis[1] * co1 - axis[2] * si;
	R_[0][2] = axis[0] * axis[2] * co1 + axis[1] * si;

	R_[1][0] = axis[0] * axis[1] * co1 + axis[2] * si;
	R_[1][1] = axis[1] * axis[1] * co1 + co;
	R_[1][2] = axis[2] * axis[1] * co1 - axis[0] * si;

	R_[2][0] = axis[2] * axis[0] * co1 - axis[1] * si;
	R_[2][1] = axis[2] * axis[1] * co1 + axis[0] * si;
	R_[2][2] = axis[2] * axis[2] * co1 + co;
}

void apply(float out[3], const float R_[3][3], const float T_[3], const float in[3])
{
	out[0] = R_[0][0] * in[0] + R_[0][1] * in[1] + R_[0][2] * in[2] + T_[0];
	out[1] = R_[1][0] * in[0] + R_[1][1] * in[1] + R_[1][2] * in[2] + T_[1];
	out[2] = R_[2][0] * in[0] + R_[2][1] * in[1] + R_[2][2] * in[2] + T_[2];
}

Transform make_transl_transform(float tx, float ty, float tz)
{
	Transform t;
	t.set_identity();
	t.m_T[0] = tx;
	t.m_T[1] = ty;
	t.m_T[2] = tz;
	return t;
}

Transform make_rotate_transform(float ax0, float ax1, float ax2, float angle)
{
	Transform t;
	float co = cos(angle);
	float si = sin(angle);
	float co1 = 1 - co;

	float len = sqrt(ax0 * ax0 + ax1 * ax1 + ax2 * ax2);
	assert(len > 0);
	ax0 /= len;
	ax1 /= len;
	ax2 /= len;

	t.m_R[0][0] = ax0 * ax0 * co1 + co;
	t.m_R[0][1] = ax0 * ax1 * co1 - ax2 * si;
	t.m_R[0][2] = ax0 * ax2 * co1 + ax1 * si;

	t.m_R[1][0] = ax0 * ax1 * co1 + ax2 * si;
	t.m_R[1][1] = ax1 * ax1 * co1 + co;
	t.m_R[1][2] = ax2 * ax1 * co1 - ax0 * si;

	t.m_R[2][0] = ax2 * ax0 * co1 - ax1 * si;
	t.m_R[2][1] = ax2 * ax1 * co1 + ax0 * si;
	t.m_R[2][2] = ax2 * ax2 * co1 + co;

	t.m_T[0] = t.m_T[1] = t.m_T[2] = 0;

	return t;
}

Transform VecToSE3(float q[6])
{
	Transform X;
	X.m_T[0] = q[0];
	X.m_T[1] = q[1];
	X.m_T[2] = q[2];

	Matrix rot, alpha, beta, gamma;
	alpha = rotateX(q[3]);
	beta = rotateY(q[4]);
	gamma = rotateZ(q[5]);

	rot = (gamma * beta) * alpha;

	for(int i = 0; i < 3; ++i)
	{
		for(int j = 0; j < 3; ++j)
			X.m_R[i][j] = rot.x[i][j];
	}

	return X;
}


Transform VecToSE3(float t1, float t2, float t3, float r1, float r2, float r3)
{
	Transform X;
	X.m_T[0] = t1;
	X.m_T[1] = t2;
	X.m_T[2] = t3;

	Matrix rot, alpha, beta, gamma;
	alpha = rotateX(r1);
	beta = rotateY(r2);
	gamma = rotateZ(r3);

	rot = (gamma * beta) * alpha;

	for(int i = 0; i < 3; ++i)
	{
		for(int j = 0; j < 3; ++j)
			X.m_R[i][j] = rot.x[i][j];
	}

	return X;
}