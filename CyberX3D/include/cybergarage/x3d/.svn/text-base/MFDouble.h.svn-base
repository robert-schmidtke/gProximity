/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	MFDouble.h
*
******************************************************************/

#ifndef _CV97_MFDOUBLE_H_
#define _CV97_MFDOUBLE_H_

#include <cybergarage/x3d/MField.h>
#include <cybergarage/x3d/SFDouble.h>

namespace CyberX3D
{

	class MFDouble : public MField
	{
	
	public:
	
		MFDouble();
		
		void addValue(double value);
		void addValue(SFDouble *sfvalue);
		void addValue(const char *value);
		
		void insertValue(int index, double value);
		double get1Value(int index);
		void set1Value(int index, double value);
		
		void setValue(MField *mfield);
		void setValue(MFDouble *values);
		void setValue(int size, double values[]);
		
		int getValueCount()
		{
			return 1;
		}
		
		////////////////////////////////////////////////
		//	Output
		////////////////////////////////////////////////
		
		void outputContext(std::ostream& printStream, char *indentString);
		
	};
	
}

#endif
