/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	SFDouble.h
*
******************************************************************/

#ifndef _CV97_SFDOUBLE_H_
#define _CV97_SFDOUBLE_H_

#include <iostream>
#include <stdio.h>
#include <cybergarage/x3d/Field.h>

namespace CyberX3D
{

	class SFDouble : public Field
	{
	
		double mValue;
		
	public:
	
		SFDouble();
		SFDouble(double value);
		SFDouble(SFDouble *value);
		
		void setValue(double value);
		void setValue(SFDouble *fvalue);
		double getValue();
		
		////////////////////////////////////////////////
		//	Output
		////////////////////////////////////////////////
		
		friend std::ostream& operator<<(std::ostream &s, SFDouble &value);
		friend std::ostream& operator<<(std::ostream &s, SFDouble *value);
		
		////////////////////////////////////////////////
		//	String
		////////////////////////////////////////////////
		
		void setValue(const char *value);
		char *getValue(char *buffer, int bufferLen);
		
		int getValueCount()
		{
			return 1;
		}
		
		////////////////////////////////////////////////
		//	Compare
		////////////////////////////////////////////////
		
		bool equals(Field *field);
		
	};
	
}

#endif
