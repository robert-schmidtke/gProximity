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

#ifndef COMMON_VECTOR3_H
#define COMMON_VECTOR3_H

#include <math.h>
#include <limits.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <iomanip>
#include <vector>

#include "mathdef.h"

class Vector3;

class SSEVertex
{
public:

	SSEVertex() { }
	SSEVertex(const float e0, const float e1, const float e2)
	{
		e[0] = e0;
		e[1] = e1;
		e[2] = e2;
	}
	SSEVertex(const float enew[3])
	{
		e[0] = enew[0];
		e[1] = enew[1];
		e[2] = enew[2];
	}
	SSEVertex(const Vector3 &v);
	SSEVertex(const SSEVertex &v)
	{
		t = v.t;
		e[0] = v.e[0];
		e[1] = v.e[1];
		e[2] = v.e[2];
	}

	SSEVertex& operator=(const SSEVertex& v)
	{
		t = v.t;
		e[0] = v.e[0];
		e[1] = v.e[1];
		e[2] = v.e[2];
		return *this;
	}
	SSEVertex& operator=(const Vector3& v);
	SSEVertex& operator=(const float* v)
	{
		e[0] = v[0];
		e[1] = v[1];
		e[2] = v[2];
		return *this;
	}

	const SSEVertex& operator+() const
	{
		return *this;
	}
	SSEVertex operator-() const
	{
		return SSEVertex(-e[0], -e[1], -e[2]);
	}
	float& operator[](int i)
	{
		return e[i];
	}
	float operator[](int i) const
	{
		return e[i];
	}

	float x() const
	{
		return e[0];
	}
	float y() const
	{
		return e[1];
	}
	float z() const
	{
		return e[2];
	}
	void setX(const float a)
	{
		e[0] = a;
	}
	void setY(const float a)
	{
		e[1] = a;
	}
	void setZ(const float a)
	{
		e[2] = a;
	}
	void set(const float *enew)
	{
		e[0] = enew[0];
		e[1] = enew[1];
		e[2] = enew[2];
	}

	SSEVertex& operator+=(const SSEVertex &v2);
	SSEVertex& operator-=(const SSEVertex &v2);
	SSEVertex& operator*=(const float t);
	SSEVertex& operator/=(const float t);

	float length() const
	{
		return sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
	}
	float squaredLength() const
	{
		return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
	}

	void makeUnitVector();

	float minComponent() const
	{
		return e[indexOfMinComponent()];
	}
	float maxComponent() const
	{
		return e[indexOfMaxComponent()];
	}
	float maxAbsComponent() const
	{
		return e[indexOfMaxAbsComponent()];
	}
	float minAbsComponent() const
	{
		return e[indexOfMinAbsComponent()];
	}
	int indexOfMinComponent() const
	{
		return (e[0] < e[1] && e[0] < e[2]) ? 0 : (e[1] < e[2] ? 1 : 2);
	}

	int indexOfMinAbsComponent() const
	{
		if(fabs(e[0]) < fabs(e[1]) && fabs(e[0]) < fabs(e[2]))
			return 0;
		else if(fabs(e[1]) < fabs(e[2]))
			return 1;
		else
			return 2;
	}

	int indexOfMaxComponent() const
	{
		return (e[0] > e[1] && e[0] > e[2]) ? 0 : (e[1] > e[2] ? 1 : 2);
	}

	int indexOfMaxAbsComponent() const
	{
		if(fabs(e[0]) > fabs(e[1]) && fabs(e[0]) > fabs(e[2]))
			return 0;
		else if(fabs(e[1]) > fabs(e[2]))
			return 1;
		else
			return 2;
	}

	int t;
	float e[3];
};


class Vector3
{
public:

	Vector3() { }
	Vector3(const float e0, const float e1, const float e2)
	{
		e[0] = e0;
		e[1] = e1;
		e[2] = e2;
	}
	Vector3(const float enew[3])
	{
		e[0] = enew[0];
		e[1] = enew[1];
		e[2] = enew[2];
	}
	Vector3(const SSEVertex &enew)
	{
		e[0] = enew[0];
		e[1] = enew[1];
		e[2] = enew[2];
	}

	inline Vector3(const Vector3 &v)
	{
		e[0] = v.e[0];
		e[1] = v.e[1];
		e[2] = v.e[2];
	}

	Vector3& operator=(const SSEVertex& v)
	{
		e[0] = v.e[0];
		e[1] = v.e[1];
		e[2] = v.e[2];
		return *this;
	}
	Vector3& operator=(const float* v)
	{
		e[0] = v[0];
		e[1] = v[1];
		e[2] = v[2];
		return *this;
	}

	const Vector3& operator+() const
	{
		return *this;
	}
	Vector3 operator-() const
	{
		return Vector3(-e[0], -e[1], -e[2]);
	}
	float& operator[](int i)
	{
		return e[i];
	}
	float operator[](int i) const
	{
		return e[i];
	}

	float x() const
	{
		return e[0];
	}
	float y() const
	{
		return e[1];
	}
	float z() const
	{
		return e[2];
	}
	void setX(const float a)
	{
		e[0] = a;
	}
	void setY(const float a)
	{
		e[1] = a;
	}
	void setZ(const float a)
	{
		e[2] = a;
	}
	void set(const float *enew)
	{
		e[0] = enew[0];
		e[1] = enew[1];
		e[2] = enew[2];
	}

	Vector3& operator+=(const Vector3 &v2);
	Vector3& operator-=(const Vector3 &v2);
	Vector3& operator*=(const float t);
	Vector3& operator/=(const float t);

	float length() const
	{
		return sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
	}
	float squaredLength() const
	{
		return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
	}

	void makeUnitVector();

	float minComponent() const
	{
		return e[indexOfMinComponent()];
	}
	float maxComponent() const
	{
		return e[indexOfMaxComponent()];
	}
	float maxAbsComponent() const
	{
		return e[indexOfMaxAbsComponent()];
	}
	float minAbsComponent() const
	{
		return e[indexOfMinAbsComponent()];
	}
	int indexOfMinComponent() const
	{
		return (e[0] < e[1] && e[0] < e[2]) ? 0 : (e[1] < e[2] ? 1 : 2);
	}

	int indexOfMinAbsComponent() const
	{
		if(fabs(e[0]) < fabs(e[1]) && fabs(e[0]) < fabs(e[2]))
			return 0;
		else if(fabs(e[1]) < fabs(e[2]))
			return 1;
		else
			return 2;
	}

	int indexOfMaxComponent() const
	{
		return (e[0] > e[1] && e[0] > e[2]) ? 0 : (e[1] > e[2] ? 1 : 2);
	}

	int indexOfMaxAbsComponent() const
	{
		if(fabs(e[0]) > fabs(e[1]) && fabs(e[0]) > fabs(e[2]))
			return 0;
		else if(fabs(e[1]) > fabs(e[2]))
			return 1;
		else
			return 2;
	}

	float e[3];
};

inline SSEVertex::SSEVertex(const Vector3 &v)
{
	e[0] = v.e[0];
	e[1] = v.e[1];
	e[2] = v.e[2];
}
inline SSEVertex& SSEVertex::operator=(const Vector3& v)
{
	e[0] = v.e[0];
	e[1] = v.e[1];
	e[2] = v.e[2];
	return *this;
}

inline bool operator==(const Vector3 &t1, const Vector3 &t2)
{
	return ((t1[0] == t2[0]) && (t1[1] == t2[1]) && (t1[2] == t2[2]));
}

inline bool operator!=(const Vector3 &t1, const Vector3 &t2)
{
	return ((t1[0] != t2[0]) || (t1[1] != t2[1]) || (t1[2] != t2[2]));
}

inline std::istream &operator>>(std::istream &is, Vector3 &t)
{
	is >> t[0] >> t[1] >> t[2];
	return is;
}

inline std::ostream &operator<<(std::ostream &os, const Vector3 &t)
{
	os << t[0] << " " << t[1] << " " << t[2];
	return os;
}

inline Vector3 unitVector(const Vector3& v)
{
	float k = 1.0f / sqrt(v.e[0] * v.e[0] + v.e[1] * v.e[1] + v.e[2] * v.e[2]);
	return Vector3(v.e[0] * k, v.e[1] * k, v.e[2] * k);
}

inline void Vector3::makeUnitVector()
{
	float k = 1.0f / sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
	e[0] *= k;
	e[1] *= k;
	e[2] *= k;
}

inline Vector3 operator+(const Vector3 &v1, const Vector3 &v2)
{
	return Vector3(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]);
}

inline Vector3 operator-(const Vector3 &v1, const Vector3 &v2)
{
	return Vector3(v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]);
}

inline Vector3 operator*(float t, const Vector3 &v)
{
	return Vector3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

inline Vector3 operator*(const Vector3 &v, float t)
{
	return Vector3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

inline Vector3 operator/(const Vector3 &v, float t)
{
	return Vector3(v.e[0] / t, v.e[1] / t, v.e[2] / t);
}


inline float dot(const Vector3 &v1, const Vector3 &v2)
{
	return v1.e[0] * v2.e[0] + v1.e[1] * v2.e[1]  + v1.e[2] * v2.e[2];
}

inline float dot(const Vector3 &v1, const float *v2)
{
	return v1.e[0] * v2[0] + v1.e[1] * v2[1]  + v1.e[2] * v2[2];
}

inline float dot(const float *v1, const float *v2)
{
	return v1[0] * v2[0] + v1[1] * v2[1]  + v1[2] * v2[2];
}

inline Vector3 cross(const Vector3 &v1, const Vector3 &v2)
{
	return Vector3((v1.e[1] * v2.e[2] - v1.e[2] * v2.e[1]),
		(v1.e[2] * v2.e[0] - v1.e[0] * v2.e[2]),
		(v1.e[0] * v2.e[1] - v1.e[1] * v2.e[0]));
}

inline bool operator<(const Vector3 &v1, const Vector3 &v2)
{
	return (FLOAT_LT(v1.e[0], v2.e[0]) && FLOAT_LT(v1.e[1], v2.e[1]) && FLOAT_LT(v1.e[2], v2.e[2]));
}

inline bool operator<=(const Vector3 &v1, const Vector3 &v2)
{
	return (FLOAT_LE(v1.e[0], v2.e[0]) && FLOAT_LE(v1.e[1], v2.e[1]) && FLOAT_LE(v1.e[2], v2.e[2]));
}

inline bool operator>(const Vector3 &v1, const Vector3 &v2)
{
	return (FLOAT_GT(v1.e[0], v2.e[0]) && FLOAT_GT(v1.e[1], v2.e[1]) && FLOAT_GT(v1.e[2], v2.e[2]));
}

inline bool operator>=(const Vector3 &v1, const Vector3 &v2)
{
	return (FLOAT_GE(v1.e[0], v2.e[0]) && FLOAT_GE(v1.e[1], v2.e[1]) && FLOAT_GE(v1.e[2], v2.e[2]));
}

inline Vector3& Vector3::operator+=(const Vector3 &v)
{
	e[0]  += v.e[0];
	e[1]  += v.e[1];
	e[2]  += v.e[2];
	return *this;
}

inline Vector3& Vector3::operator-=(const Vector3& v)
{
	e[0]  -= v.e[0];
	e[1]  -= v.e[1];
	e[2]  -= v.e[2];
	return *this;
}

inline Vector3& Vector3::operator*=(const float t)
{
	e[0]  *= t;
	e[1]  *= t;
	e[2]  *= t;
	return *this;
}

inline Vector3& Vector3::operator/=(const float t)
{
	e[0]  /= t;
	e[1]  /= t;
	e[2]  /= t;
	return *this;
}

inline
Vector3 reflect(const Vector3& in, const Vector3& normal)
{
	// assumes unit length normal
	return in - normal * (2 * dot(in, normal));
}

// Area of a triangle:
inline float triangleArea(Vector3 v1, Vector3 v2, Vector3 v3)
{
	return (cross(v1, v2) + cross(v2, v3) + cross(v3, v1)).length() * 0.5f;
}

inline Vector3 vmul(const Vector3 &v1, const Vector3 &v2)
{
	return Vector3(v1.e[0] * v2.e[0], v1.e[1] * v2.e[1], v1.e[2] * v2.e[2]);
}

#define CONVERT_V3_to_V4(s, d) {d.e[0]=s.e[0]; d.e[1]=s.e[1]; d.e[2]=s.e[2];}
#define CONVERT_V4_to_V3(s, d) {d.e[0]=s.e[0]; d.e[1]=s.e[1]; d.e[2]=s.e[2];}

inline bool operator==(const SSEVertex &t1, const SSEVertex &t2)
{
	return ((t1[0] == t2[0]) && (t1[1] == t2[1]) && (t1[2] == t2[2]));
}

inline bool operator!=(const SSEVertex &t1, const SSEVertex &t2)
{
	return ((t1[0] != t2[0]) || (t1[1] != t2[1]) || (t1[2] != t2[2]));
}

inline std::istream &operator>>(std::istream &is, SSEVertex &t)
{
	is >> t[0] >> t[1] >> t[2];
	return is;
}

inline std::ostream &operator<<(std::ostream &os, const SSEVertex &t)
{
	os << t[0] << " " << t[1] << " " << t[2];
	return os;
}

inline SSEVertex unitVector(const SSEVertex& v)
{
	float k = 1.0f / sqrt(v.e[0] * v.e[0] + v.e[1] * v.e[1] + v.e[2] * v.e[2]);
	return SSEVertex(v.e[0] * k, v.e[1] * k, v.e[2] * k);
}

inline void SSEVertex::makeUnitVector()
{
	float k = 1.0f / sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
	e[0] *= k;
	e[1] *= k;
	e[2] *= k;
}

inline SSEVertex operator+(const SSEVertex &v1, const SSEVertex &v2)
{
	return SSEVertex(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]);
}

inline SSEVertex operator-(const SSEVertex &v1, const SSEVertex &v2)
{
	return SSEVertex(v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]);
}

inline SSEVertex operator-(const SSEVertex &v1, const Vector3 &v2)
{
	return SSEVertex(v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]);
}

inline SSEVertex operator-(const Vector3 &v1, const SSEVertex &v2)
{
	return SSEVertex(v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]);
}

inline Vector3 operator-(const Vector3 &v1, const float v2[3])
{
	return Vector3(v1[0] - v2[0], v1[1] - v2[1], v1[2] - v2[2]);
}

inline Vector3 operator-(const float v1[3], const Vector3 &v2)
{
	return Vector3(v1[0] - v2[0], v1[1] - v2[1], v1[2] - v2[2]);
}


inline SSEVertex operator*(float t, const SSEVertex &v)
{
	return SSEVertex(t * v.e[0], t * v.e[1], t * v.e[2]);
}

inline SSEVertex operator*(const SSEVertex &v, float t)
{
	return SSEVertex(t * v.e[0], t * v.e[1], t * v.e[2]);
}

inline SSEVertex operator/(const SSEVertex &v, float t)
{
	return SSEVertex(v.e[0] / t, v.e[1] / t, v.e[2] / t);
}


inline float dot(const SSEVertex &v1, const SSEVertex &v2)
{
	return v1.e[0] * v2.e[0] + v1.e[1] * v2.e[1]  + v1.e[2] * v2.e[2];
}

inline float dot(const SSEVertex &v1, const Vector3 &v2)
{
	return v1.e[0] * v2.e[0] + v1.e[1] * v2.e[1]  + v1.e[2] * v2.e[2];
}

inline float dot(const Vector3 &v1, const SSEVertex &v2)
{
	return v1.e[0] * v2.e[0] + v1.e[1] * v2.e[1]  + v1.e[2] * v2.e[2];
}

inline float dot(const SSEVertex &v1, const float *v2)
{
	return v1.e[0] * v2[0] + v1.e[1] * v2[1]  + v1.e[2] * v2[2];
}


inline SSEVertex cross(const SSEVertex &v1, const SSEVertex &v2)
{
	return SSEVertex((v1.e[1] * v2.e[2] - v1.e[2] * v2.e[1]),
		(v1.e[2] * v2.e[0] - v1.e[0] * v2.e[2]),
		(v1.e[0] * v2.e[1] - v1.e[1] * v2.e[0]));
}

inline bool operator<(const SSEVertex &v1, const SSEVertex &v2)
{
	return (FLOAT_LT(v1.e[0], v2.e[0]) && FLOAT_LT(v1.e[1], v2.e[1]) && FLOAT_LT(v1.e[2], v2.e[2]));
}

inline bool operator<=(const SSEVertex &v1, const SSEVertex &v2)
{
	return (FLOAT_LE(v1.e[0], v2.e[0]) && FLOAT_LE(v1.e[1], v2.e[1]) && FLOAT_LE(v1.e[2], v2.e[2]));
}

inline bool operator>(const SSEVertex &v1, const SSEVertex &v2)
{
	return (FLOAT_GT(v1.e[0], v2.e[0]) && FLOAT_GT(v1.e[1], v2.e[1]) && FLOAT_GT(v1.e[2], v2.e[2]));
}

inline bool operator>=(const SSEVertex &v1, const SSEVertex &v2)
{
	return (FLOAT_GE(v1.e[0], v2.e[0]) && FLOAT_GE(v1.e[1], v2.e[1]) && FLOAT_GE(v1.e[2], v2.e[2]));
}

inline SSEVertex& SSEVertex::operator+=(const SSEVertex &v)
{
	e[0]  += v.e[0];
	e[1]  += v.e[1];
	e[2]  += v.e[2];
	return *this;
}

inline SSEVertex& SSEVertex::operator-=(const SSEVertex& v)
{
	e[0]  -= v.e[0];
	e[1]  -= v.e[1];
	e[2]  -= v.e[2];
	return *this;
}

inline SSEVertex& SSEVertex::operator*=(const float t)
{
	e[0]  *= t;
	e[1]  *= t;
	e[2]  *= t;
	return *this;
}

inline SSEVertex& SSEVertex::operator/=(const float t)
{
	e[0]  /= t;
	e[1]  /= t;
	e[2]  /= t;
	return *this;
}

inline
SSEVertex reflect(const SSEVertex& in, const SSEVertex& normal)
{
	// assumes unit length normal
	return in - normal * (2 * dot(in, normal));
}

// Area of a triangle:
inline float triangleArea(SSEVertex v1, SSEVertex v2, SSEVertex v3)
{
	return (cross(v1, v2) + cross(v2, v3) + cross(v3, v1)).length() * 0.5f;
}

inline SSEVertex vmul(const SSEVertex &v1, const SSEVertex &v2)
{
	return SSEVertex(v1.e[0] * v2.e[0], v1.e[1] * v2.e[1], v1.e[2] * v2.e[2]);
}

typedef std::vector<SSEVertex> Vector3List;
typedef Vector3List::iterator Vector3ListIterator;


#endif
