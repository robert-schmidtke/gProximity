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

#ifndef __VECTOR2_H_
#define __VECTOR2_H_

#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>

class Vector2
{
public:

	Vector2()
	{
		e[0] = 0;
		e[1] = 0;
	}
	Vector2(float e0, float e1)
	{
		e[0] = e0;
		e[1] = e1;
	}
	float x() const
	{
		return e[0];
	}
	float y() const
	{
		return e[1];
	}
	void setX(float a)
	{
		e[0] = a;
	}
	void setY(float a)
	{
		e[1] = a;
	}

	Vector2(const Vector2 &v)
	{
		e[0] = v.e[0];
		e[1] = v.e[1];
	}

	const Vector2& operator+() const
	{
		return *this;
	}
	Vector2 operator-() const
	{
		return Vector2(-e[0], -e[1]);
	}
	float& operator[](int i)
	{
		assert(i >= 0 && i < 2);
		return e[i];
	}
	float operator[](int i) const
	{
		assert(i >= 0 && i < 2);
		return e[i];
	}

	Vector2& operator+=(const Vector2 &v2);
	Vector2& operator-=(const Vector2 &v2);
	Vector2& operator*=(const float t);
	Vector2& operator/=(const float t);
	void scramble();


	float length() const
	{
		return sqrt(e[0] * e[0] + e[1] * e[1]);
	}
	float squaredLength() const
	{
		return e[0] * e[0] + e[1] * e[1] ;
	}

	void makeUnitVector();

	float e[2];
};

inline void Vector2::scramble()
{
	float _x;
	float _y = e[0];

	_x =  e[1] * 1234.12345054321f;
	e[0] = _x - (int)_x;
	_y = _y * 7654.54321012345f;
	e[1] = _y - (int)_y;
}

inline bool operator==(const Vector2 &t1, const Vector2 &t2)
{
	return ((t1[0] == t2[0]) && (t1[1] == t2[1]));
}

inline bool operator!=(const Vector2 &t1, const Vector2 &t2)
{
	return ((t1[0] != t2[0]) || (t1[1] != t2[1]));
}

inline std::istream &operator>>(std::istream &is, Vector2 &t)
{
	is >> t[0] >> t[1];
	return is;
}

inline std::ostream &operator<<(std::ostream &os, const Vector2 &t)
{
	os << t[0] << " " << t[1] ;
	return os;
}

inline Vector2 unitVector(const Vector2& v)
{
	float k = 1.0f / sqrt(v.e[0] * v.e[0] + v.e[1] * v.e[1]);
	return Vector2(v.e[0] * k, v.e[1] * k);
}

inline void Vector2::makeUnitVector()
{
	float k = 1.0f / sqrt(e[0] * e[0] + e[1] * e[1]);
	e[0] *= k;
	e[1] *= k;
}

inline Vector2 operator+(const Vector2 &v1, const Vector2 &v2)
{
	return Vector2(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1]);
}

inline Vector2 operator-(const Vector2 &v1, const Vector2 &v2)
{
	return Vector2(v1.e[0] - v2.e[0], v1.e[1] - v2.e[1]);
}

inline Vector2 operator*(float t, const Vector2 &v)
{
	return Vector2(t * v.e[0], t * v.e[1]);
}

inline Vector2 operator*(const Vector2 &v, float t)
{
	return Vector2(t * v.e[0], t * v.e[1]);
}

inline Vector2 operator/(const Vector2 &v, float t)
{
	return Vector2(v.e[0] / t, v.e[1] / t);
}


inline float dot(const Vector2 &v1, const Vector2 &v2)
{
	return v1.e[0] * v2.e[0] + v1.e[1] * v2.e[1];
}



inline Vector2& Vector2::operator+=(const Vector2 &v)
{
	e[0]  += v.e[0];
	e[1]  += v.e[1];
	return *this;
}

inline Vector2& Vector2::operator-=(const Vector2& v)
{
	e[0]  -= v.e[0];
	e[1]  -= v.e[1];
	return *this;
}

inline Vector2& Vector2::operator*=(const float t)
{
	e[0]  *= t;
	e[1]  *= t;
	return *this;
}

inline Vector2& Vector2::operator/=(const float t)
{
	e[0]  /= t;
	e[1]  /= t;
	return *this;
}


#endif
