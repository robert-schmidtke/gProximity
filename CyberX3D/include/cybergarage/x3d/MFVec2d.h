/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	MFVec2d.h
*
******************************************************************/

#ifndef _CV97_MFVEC2D_H_
#define _CV97_MFVEC2D_H_

#include <cybergarage/x3d/MField.h>
#include <cybergarage/x3d/SFVec2d.h>

namespace CyberX3D
{

	class MFVec2d : public MField
	{
	
	public:
	
		MFVec2d();
		
		void addValue(double x, double y);
		void addValue(double value[]);
		void addValue(SFVec2d *vector);
		void addValue(const char *value);
		
		void insertValue(int index, double x, double y);
		void insertValue(int index, double value[]);
		void insertValue(int index, SFVec2d *vector);
		
		void get1Value(int index, double value[]);
		void set1Value(int index, double value[]);
		void set1Value(int index, double x, double y);
		
		void setValue(MField *mfield);
		void setValue(MFVec2d *vectors);
		void setValue(int size, double vectors[][2]);
		
		int getValueCount()
		{
			return 2;
		}
		
		////////////////////////////////////////////////
		//	Output
		////////////////////////////////////////////////
		
		void outputContext(std::ostream& printStream, char *indentString);
		
	};
	
}

#endif
