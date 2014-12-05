/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	SFChar.h
*
******************************************************************/

#ifndef _CV97_SFCHAR_H_
#define _CV97_SFCHAR_H_

#include <iostream>
#include <stdio.h>
#include <cybergarage/x3d/Field.h>

namespace CyberX3D
{

	class SFChar : public Field
	{
	
		char mValue;
		
	public:
	
		SFChar();
		SFChar(char value);
		SFChar(SFChar *value);
		
		void setValue(char value);
		void setValue(SFChar *fvalue);
		char getValue();
		
		int getValueCount()
		{
			return 1;
		}
		
		////////////////////////////////////////////////
		//	Output
		////////////////////////////////////////////////
		
		friend std::ostream& operator<<(std::ostream &s, SFChar &value);
		friend std::ostream& operator<<(std::ostream &s, SFChar *value);
		
		////////////////////////////////////////////////
		//	String
		////////////////////////////////////////////////
		
		void setValue(const char *value);
		char *getValue(char *buffer, int bufferLen);
		
		////////////////////////////////////////////////
		//	Compare
		////////////////////////////////////////////////
		
		bool equals(Field *field);
		
	};
	
}

#endif
