/******************************************************************
*
*	CyberVRML97 for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	XMLElement.cpp
*
******************************************************************/

#include <cybergarage/x3d/XMLElement.h>

using namespace CyberX3D;

XMLElement::XMLElement()
{
	setType(fieldTypeXMLElement);
	setValue((char *)NULL);
}

XMLElement::XMLElement(const char *value)
{
	setType(fieldTypeXMLElement);
	setValue(value);
}

XMLElement::XMLElement(XMLElement *value)
{
	setType(fieldTypeXMLElement);
	setValue(value);
}

XMLElement::~XMLElement()
{
}

void XMLElement::setValue(const char *value)
{
	mValue.setValue(value);
}

void XMLElement::setValue(XMLElement *value)
{
	mValue.setValue(value->getValue());
}

char *XMLElement::getValue()
{
	return mValue.getValue();
}

////////////////////////////////////////////////
//	Output
////////////////////////////////////////////////

std::ostream& operator<<(std::ostream &s, XMLElement &string)
{
	if(string.getValue())
		return s << "\"" << string.getValue() << "\"";
	else
		return s << "\"" << "\"";
}

std::ostream& operator<<(std::ostream &s, XMLElement *string)
{
	if(string->getValue())
		return s << "\"" << string->getValue() << "\"";
	else
		return s << "\"" << "\"";
}

////////////////////////////////////////////////
//	String
////////////////////////////////////////////////

char *XMLElement::getValue(String &buffer)
{
	buffer.setValue(getValue());
	return buffer.getValue();
}

char *XMLElement::getValue(char *buffer, int bufferLen)
{
	sprintf(buffer, "%s", getValue());
	return buffer;
}

////////////////////////////////////////////////
//	Compare
////////////////////////////////////////////////

bool XMLElement::equals(Field *field)
{
	XMLElement *stringField = (XMLElement *)field;
	if(!getValue() && !stringField->getValue())
		return true;
	if(getValue() && stringField->getValue())
		return (!strcmp(getValue(), stringField->getValue()) ? true : false);
	else
		return false;
}
