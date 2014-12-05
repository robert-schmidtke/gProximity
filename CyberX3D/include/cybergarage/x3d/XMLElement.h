/******************************************************************
*
*	CyberVRML97 for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	XMLElement.h
*
******************************************************************/

#ifndef _CV97_XMLELEMENT_H_
#define _CV97_XMLELEMENT_H_

#include <iostream>
#include <cybergarage/x3d/Field.h>
#include <cybergarage/x3d/StringUtil.h>

namespace CyberX3D
{

	class XMLElement : public Field
	{
	
		static	int	mInit;
		
		String	mValue;
		
	public:
	
		XMLElement();
		XMLElement(const char *value);
		XMLElement(XMLElement *value);
		
		~XMLElement();
		
		void setValue(const char *value);
		void setValue(XMLElement *value);
		char *getValue();
		
		int getValueCount()
		{
			return 1;
		}
		
		////////////////////////////////////////////////
		//	Output
		////////////////////////////////////////////////
		
		friend std::ostream& operator<<(std::ostream &s, XMLElement &string);
		friend std::ostream& operator<<(std::ostream &s, XMLElement *string);
		
		////////////////////////////////////////////////
		//	String
		////////////////////////////////////////////////
		
		char *getValue(char *buffer, int bufferLen);
		char *getValue(String &buffer);
		
		////////////////////////////////////////////////
		//	Compare
		////////////////////////////////////////////////
		
		bool equals(Field *field);
		
	};
	
}

#endif
