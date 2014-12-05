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
 
#ifndef __RGB_H_
#define __RGB_H_

#include <math.h>
#include <xmmintrin.h>
#include <assert.h>
#include <iostream>
#include <ostream>

class rgb
{
public:

	rgb() {}
	rgb(float r, float g, float b)
	{
		data[0] = r;
		data[1] = g;
		data[2] = b;
	}
	rgb(const rgb &c)
	{
		data[0] = c.r();
		data[1] = c.g();
		data[2] = c.b();
	}
	//rgb(const rgb3f &c)
	//{ data[0] = c.r(); data[1] = c.g(); data[2] = c.b(); }
	float r() const
	{
		return data[0];
	}
	float g() const
	{
		return data[1];
	}
	float b() const
	{
		return data[2];
	}
	float sum() const
	{
		return data[0] + data[1] + data[2];
	}
	float sumabs() const
	{
		return fabs(data[0]) + fabs(data[1]) + fabs(data[2]);
	}
	
	//rgb &operator=(const rgb3f &c) {
	//	data[0] = c.r(); data[1] = c.g(); data[2] = c.b();
	//	return *this;
	//}
	
	void reset()
	{
		data[0] = 0.0f;
		data[1] = 0.0f;
		data[2] = 0.0f;
		data[3] = 0.0f;
	}
	
	rgb operator+() const
	{
		return rgb(data[0], data[1], data[2]);
	}
	rgb operator-() const
	{
		return rgb(-data[0], -data[1], -data[2]);
	}
	float operator[](int i) const
	{
		assert(i >= 0 && i < 3);
		return data[i];
	}
	float& operator[](int i)
	{
		assert(i >= 0 && i < 3);
		return data[i];
	}
	
	rgb& operator+=(const rgb &c)
	{
		data[0] += c[0];
		data[1] += c[1];
		data[2] += c[2];
		return *this;
	}
	rgb& operator-=(const rgb &c)
	{
		data[0] -= c[0];
		data[1] -= c[1];
		data[2] -= c[2];
		return *this;
	}
	rgb& operator*=(const rgb &c)
	{
		data[0] *= c[0];
		data[1] *= c[1];
		data[2] *= c[2];
		return *this;
	}
	rgb& operator/=(const rgb &c)
	{
		data[0] /= c[0];
		data[1] /= c[1];
		data[2] /= c[2];
		return *this;
	}
	rgb& operator*=(float f)
	{
		data[0] *= f;
		data[1] *= f;
		data[2] *= f;
		return *this;
	}
	rgb& operator/=(float f)
	{
		data[0] /= f;
		data[1] /= f;
		data[2] /= f;
		return *this;
	}
	
	inline float* getarray()
	{
		return data;
	}
	
	// RGB data as float values. The fourth value is for padding only
	// to make the structure 16-bytes long and therefore usable for SIMD
	// operations. The last index in the array is never used.
	float data[4];
};

inline bool operator==(rgb c1, rgb c2)
{
	return (c1.r() == c2.r() && c1.g() == c2.g() && c1.b() == c2.b());
}
inline bool operator!=(rgb c1, rgb c2)
{
	return (c1.r() != c2.r() || c1.g() != c2.g() || c1.b() != c2.b());
}

inline bool operator<(rgb c1, rgb c2)
{
	return (c1.sumabs() < c2.sumabs());
}
inline bool operator<=(rgb c1, rgb c2)
{
	return (c1.sumabs() <= c2.sumabs());
}
inline bool operator>(rgb c1, rgb c2)
{
	return (c1.sumabs() > c2.sumabs());
}
inline bool operator>=(rgb c1, rgb c2)
{
	return (c1.sumabs() >= c2.sumabs());
}

inline rgb operator+(rgb c1, rgb c2)
{
	return rgb(c1.r() + c2.r(), c1.g() + c2.g(), c1.b() + c2.b());
}
inline rgb operator-(rgb c1, rgb c2)
{
	return rgb(c1.r() - c2.r(), c1.g() - c2.g(), c1.b() - c2.b());
}
inline rgb operator*(rgb c1, rgb c2)
{
	return rgb(c1.r() * c2.r(), c1.g() * c2.g(), c1.b() * c2.b());
}
inline rgb operator/(rgb c1, rgb c2)
{
	return rgb(c1.r() / c2.r(), c1.g() / c2.g(), c1.b() / c2.b());
}
inline rgb operator*(rgb c, float f)
{
	return rgb(c.r() * f, c.g() * f, c.b() * f);
}
inline rgb operator*(float f, rgb c)
{
	return rgb(c.r() * f, c.g() * f, c.b() * f);
}
inline rgb operator/(rgb c, float f)
{
	return rgb(c.r() / f, c.g() / f, c.b() / f);
}

inline std::ostream &operator<<(std::ostream &os, const rgb &t)
{
	os << t[0] << " " << t[1] << " " << t[2];
	return os;
}



class rgb3f
{
public:
	rgb3f() { }
	rgb3f(float r, float g, float b)
	{
		data[0] = r;
		data[1] = g;
		data[2] = b;
	}
	rgb3f(const rgb3f &c)
	{
		data[0] = c.r();
		data[1] = c.g();
		data[2] = c.b();
	}
	rgb3f(const rgb &c)
	{
		data[0] = c.r();
		data[1] = c.g();
		data[2] = c.b();
	}
	float r() const
	{
		return data[0];
	}
	float g() const
	{
		return data[1];
	}
	float b() const
	{
		return data[2];
	}
	float sum() const
	{
		return data[0] + data[1] + data[2];
	}
	float sumabs() const
	{
		return fabs(data[0]) + fabs(data[1]) + fabs(data[2]);
	}
	
	rgb3f &operator=(const rgb &c)
	{
		data[0] = c.r();
		data[1] = c.g();
		data[2] = c.b();
		return *this;
	}
	
	void reset()
	{
		data[0] = 0.0f;
		data[1] = 0.0f;
		data[2] = 0.0f;
	}
	
	rgb3f operator+() const
	{
		return rgb3f(data[0], data[1], data[2]);
	}
	rgb3f operator-() const
	{
		return rgb3f(-data[0], -data[1], -data[2]);
	}
	float operator[](int i) const
	{
		assert(i >= 0 && i < 3);
		return data[i];
	}
	float& operator[](int i)
	{
		assert(i >= 0 && i < 3);
		return data[i];
	}
	
	rgb3f& operator+=(const rgb3f &c)
	{
		data[0] += c[0];
		data[1] += c[1];
		data[2] += c[2];
		return *this;
	}
	rgb3f& operator-=(const rgb3f &c)
	{
		data[0] -= c[0];
		data[1] -= c[1];
		data[2] -= c[2];
		return *this;
	}
	rgb3f& operator*=(const rgb3f &c)
	{
		data[0] *= c[0];
		data[1] *= c[1];
		data[2] *= c[2];
		return *this;
	}
	rgb3f& operator/=(const rgb3f &c)
	{
		data[0] /= c[0];
		data[1] /= c[1];
		data[2] /= c[2];
		return *this;
	}
	rgb3f& operator*=(float f)
	{
		data[0] *= f;
		data[1] *= f;
		data[2] *= f;
		return *this;
	}
	rgb3f& operator/=(float f)
	{
		data[0] /= f;
		data[1] /= f;
		data[2] /= f;
		return *this;
	}
	
	// rgb3f data as float values.
	float data[3];
};

inline bool operator==(rgb3f c1, rgb3f c2)
{
	return (c1.r() == c2.r() && c1.g() == c2.g() && c1.b() == c2.b());
}
inline bool operator!=(rgb3f c1, rgb3f c2)
{
	return (c1.r() != c2.r() || c1.g() != c2.g() || c1.b() != c2.b());
}

inline bool operator<(rgb3f c1, rgb3f c2)
{
	return (c1.sumabs() < c2.sumabs());
}
inline bool operator<=(rgb3f c1, rgb3f c2)
{
	return (c1.sumabs() <= c2.sumabs());
}
inline bool operator>(rgb3f c1, rgb3f c2)
{
	return (c1.sumabs() > c2.sumabs());
}
inline bool operator>=(rgb3f c1, rgb3f c2)
{
	return (c1.sumabs() >= c2.sumabs());
}

inline rgb3f operator+(rgb3f c1, rgb3f c2)
{
	return rgb3f(c1.r() + c2.r(), c1.g() + c2.g(), c1.b() + c2.b());
}
inline rgb3f operator-(rgb3f c1, rgb3f c2)
{
	return rgb3f(c1.r() - c2.r(), c1.g() - c2.g(), c1.b() - c2.b());
}
inline rgb3f operator*(rgb3f c1, rgb3f c2)
{
	return rgb3f(c1.r() * c2.r(), c1.g() * c2.g(), c1.b() * c2.b());
}
inline rgb3f operator/(rgb3f c1, rgb3f c2)
{
	return rgb3f(c1.r() / c2.r(), c1.g() / c2.g(), c1.b() / c2.b());
}
inline rgb3f operator*(rgb3f c, float f)
{
	return rgb3f(c.r() * f, c.g() * f, c.b() * f);
}
inline rgb3f operator*(float f, rgb3f c)
{
	return rgb3f(c.r() * f, c.g() * f, c.b() * f);
}
inline rgb3f operator/(rgb3f c, float f)
{
	return rgb3f(c.r() / f, c.g() / f, c.b() / f);
}

inline std::ostream &operator<<(std::ostream &os, const rgb3f &t)
{
	os << t[0] << " " << t[1] << " " << t[2];
	return os;
}



#endif