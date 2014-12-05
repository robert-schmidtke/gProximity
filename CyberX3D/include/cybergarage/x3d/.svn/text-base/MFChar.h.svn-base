/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	MFChar.h
*
******************************************************************/

#ifndef _CV97_MFCHAR_H_
#define _CV97_MFCHAR_H_

#include <cybergarage/x3d/MField.h>
#include <cybergarage/x3d/SFChar.h>

namespace CyberX3D
{

	class MFChar : public MField
	{
	
	public:
	
		MFChar();
		
		void addValue(char value);
		void addValue(SFChar *sfvalue);
		void addValue(const char *value);
		
		void insertValue(int index, char value);
		char get1Value(int index);
		void set1Value(int index, char value);
		
		void setValue(MField *mfield);
		void setValue(MFChar *values);
		void setValue(int size, char values[]);
		
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
