/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	SFDouble.cpp
*
******************************************************************/

#include <cybergarage/x3d/SFDouble.h>

using namespace CyberX3D;

SFDouble::SFDouble()
{
	setType(fieldTypeSFDouble);
	setValue(0.0);
}

SFDouble::SFDouble(double value)
{
	setType(fieldTypeSFDouble);
	setValue(value);
}

SFDouble::SFDouble(SFDouble *value)
{
	setType(fieldTypeSFDouble);
	setValue(value);
}

void SFDouble::setValue(double value)
{
	mValue = value;
}

void SFDouble::setValue(SFDouble *fvalue)
{
	mValue = fvalue->getValue();
}

double SFDouble::getValue()
{
	return mValue;
}

////////////////////////////////////////////////
//	Output
////////////////////////////////////////////////

std::ostream& CyberX3D::operator<<(std::ostream &s, SFDouble &value)
{
	return s << value.getValue();
}

std::ostream& CyberX3D::operator<<(std::ostream &s, SFDouble *value)
{
	return s << value->getValue();
}

////////////////////////////////////////////////
//	String
////////////////////////////////////////////////

void SFDouble::setValue(const char *value)
{
	if(!value)
		return;
	setValue(atof(value));
}

char *SFDouble::getValue(char *buffer, int bufferLen)
{
	sprintf(buffer, "%g", getValue());
	return buffer;
}

////////////////////////////////////////////////
//	Compare
////////////////////////////////////////////////

bool SFDouble::equals(Field *field)
{
	SFDouble *doubleField = (SFDouble *)field;
	if(getValue() == doubleField->getValue())
		return true;
	else
		return false;
}
