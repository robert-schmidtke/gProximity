/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	SFVec2d.h
*
******************************************************************/

#ifndef _CV97_SFVEC2D_H_
#define _CV97_SFVEC2D_H_

#include <iostream>
#include <math.h>
#include <stdio.h>
#include <cybergarage/x3d/Field.h>

namespace CyberX3D
{

	class SFVec2d : public Field
	{
	
		double mValue[2];
		
	public:
	
		SFVec2d();
		SFVec2d(double x, double y);
		SFVec2d(double value[]);
		SFVec2d(SFVec2d *value);
		
		////////////////////////////////////////////////
		//	get value
		////////////////////////////////////////////////
		
		void getValue(double value[]);
		double *getValue();
		double getX();
		double getY();
		
		int getValueCount()
		{
			return 2;
		}
		
		////////////////////////////////////////////////
		//	set value
		////////////////////////////////////////////////
		
		void setValue(double x, double y);
		void setValue(double value[]);
		void setValue(SFVec2d *vector);
		void setX(double x);
		void setY(double y);
		
		////////////////////////////////////////////////
		//	add value
		////////////////////////////////////////////////
		
		void add(double x, double y);
		void add(double value[]);
		void add(SFVec2d value);
		void translate(double x, double y);
		void translate(double value[]);
		void translate(SFVec2d value);
		
		////////////////////////////////////////////////
		//	sub value
		////////////////////////////////////////////////
		
		void sub(double x, double y);
		void sub(double value[]);
		void sub(SFVec2d value);
		
		////////////////////////////////////////////////
		//	scale
		////////////////////////////////////////////////
		
		void scale(double value);
		void scale(double xscale, double yscale);
		void scale(double value[2]);
		
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
		//	Output
		////////////////////////////////////////////////
		
		friend std::ostream& operator<<(std::ostream &s, SFVec2d &vector);
		friend std::ostream& operator<<(std::ostream &s, SFVec2d *vector);
		
		////////////////////////////////////////////////
		//	String
		////////////////////////////////////////////////
		
		void setValue(const char *value);
		char *getValue(char *buffer, int bufferLen);
		
		////////////////////////////////////////////////
		//	Compare
		////////////////////////////////////////////////
		
		bool equals(Field *field);
		bool equals(double value[2]);
		bool equals(double x, double y);
		
	};
	
}

#endif
