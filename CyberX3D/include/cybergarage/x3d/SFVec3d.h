/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	SFVec3d.h
*
******************************************************************/

#ifndef _CV97_SFVEC3D_H_
#define _CV97_SFVEC3D_H_

#include <iostream>
#include <math.h>
#include <stdio.h>
#include <cybergarage/x3d/Field.h>

namespace CyberX3D
{

	class SFRotation;
	
	class SFVec3d : public Field
	{
	
		double	mValue[3];
		
	public:
	
		SFVec3d();
		SFVec3d(double x, double y, double z);
		SFVec3d(double value[]);
		SFVec3d(SFVec3d *value);
		
		////////////////////////////////////////////////
		//	get value
		////////////////////////////////////////////////
		
		void getValue(double value[]);
		double *getValue();
		double getX();
		double getY();
		double getZ();
		
		int getValueCount()
		{
			return 3;
		}
		
		////////////////////////////////////////////////
		//	set value
		////////////////////////////////////////////////
		
		void setValue(double x, double y, double z);
		void setValue(double value[]);
		void setValue(SFVec3d *vector);
		void setX(double x);
		void setY(double y);
		void setZ(double z);
		
		////////////////////////////////////////////////
		//	add value
		////////////////////////////////////////////////
		
		void add(double x, double y, double z);
		void add(double value[]);
		void add(SFVec3d value);
		void translate(double x, double y, double z);
		void translate(double value[]);
		void translate(SFVec3d value);
		
		////////////////////////////////////////////////
		//	sub value
		////////////////////////////////////////////////
		
		void sub(double x, double y, double z);
		void sub(double value[]);
		void sub(SFVec3d value);
		
		////////////////////////////////////////////////
		//	scale
		////////////////////////////////////////////////
		
		void scale(double value);
		void scale(double xscale, double yscale, double zscale);
		void scale(double value[3]);
		
		////////////////////////////////////////////////
		//	rotate
		////////////////////////////////////////////////
		
		void rotate(SFRotation *rotation);
		void rotate(double x, double y, double z, double angle);
		void rotate(double value[3]);
		
		////////////////////////////////////////////////
		//	invert
		////////////////////////////////////////////////
		
		void invert();
		
		////////////////////////////////////////////////
		//	scalar
		////////////////////////////////////////////////
		
		double getScalar();
		
		////////////////////////////////////////////////
		//	normalize
		////////////////////////////////////////////////
		
		void normalize();
		
		////////////////////////////////////////////////
		//	Overload
		////////////////////////////////////////////////
		
		friend std::ostream& operator<<(std::ostream &s, SFVec3d &vector);
		friend std::ostream& operator<<(std::ostream &s, SFVec3d *vector);
		
		////////////////////////////////////////////////
		//	String
		////////////////////////////////////////////////
		
		void setValue(const char *value);
		char *getValue(char *buffer, int bufferLen);
		
		////////////////////////////////////////////////
		//	Compare
		////////////////////////////////////////////////
		
		bool equals(Field *field);
		bool equals(double value[3]);
		bool equals(double x, double y, double z);
		
	};
	
}

#endif
