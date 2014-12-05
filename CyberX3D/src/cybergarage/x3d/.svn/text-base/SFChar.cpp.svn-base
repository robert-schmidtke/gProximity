/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	SFChar.cpp
*
******************************************************************/

#include <cybergarage/x3d/SFChar.h>

using namespace CyberX3D;

SFChar::SFChar()
{
	setType(fieldTypeSFChar);
	setValue(' ');
}

SFChar::SFChar(char value)
{
	setType(fieldTypeSFChar);
	setValue(value);
}

SFChar::SFChar(SFChar *value)
{
	setType(fieldTypeSFChar);
	setValue(value);
}

void SFChar::setValue(char value)
{
	mValue = value;
}

void SFChar::setValue(SFChar *fvalue)
{
	mValue = fvalue->getValue();
}

char SFChar::getValue()
{
	return mValue;
}

////////////////////////////////////////////////
//	Output
////////////////////////////////////////////////

std::ostream& CyberX3D::operator<<(std::ostream &s, SFChar &value)
{
	return s << value.getValue();
}

std::ostream& CyberX3D::operator<<(std::ostream &s, SFChar *value)
{
	return s << value->getValue();
}

////////////////////////////////////////////////
//	String
////////////////////////////////////////////////

void SFChar::setValue(const char *value)
{
	if(!value)
		return;
	if(strlen(value) <= 0)
		return;
	setValue((char)value[0]);
}

char *SFChar::getValue(char *buffer, int bufferLen)
{
	sprintf(buffer, "%c", getValue());
	return buffer;
}

////////////////////////////////////////////////
//	Compare
////////////////////////////////////////////////

bool SFChar::equals(Field *field)
{
	SFChar *charField = (SFChar *)field;
	if(getValue() == charField->getValue())
		return true;
	return false;
}
