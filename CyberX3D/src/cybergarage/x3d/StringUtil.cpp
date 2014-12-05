/******************************************************************
*
*	CyberVRML97 for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	StringUtil.cpp
*
******************************************************************/

#include <stdlib.h>
#include <ctype.h>
#include <cybergarage/x3d/StringUtil.h>

using namespace CyberX3D;

////////////////////////////////////////////////////
// STL Version
////////////////////////////////////////////////////

#ifndef NO_USE_STL

String::String()
{
}

String::String(const char *value)
{
	setValue(value);
}

String::String(const char *value, int offset, int count)
{
	setValue(value, offset, count);
}

String::~String()
{
}

void String::setValue(const char *value)
{
	clear();
	if(!value)
		return;
	if(strlen(value) <= 0)
		return;
	mValue = value;
}

void String::setValue(const char *value, int offset, int count)
{
	if(!value && (int)strlen(value) < (offset + count))
		return;
	std::string orgValue = value;
	mValue = orgValue.substr(offset, count);
}

void String::append(const char *value)
{
	if(!value)
		return;
	if(strlen(value) <= 0)
		return;
	mValue.append(value);
}

char *String::getValue()
{
	return (char *)mValue.c_str();
}

void String::clear()
{
	mValue = "";
}

int String::length()
{
	return mValue.length();
}

char String::charAt(int  index)
{
	return mValue[index];
}

#endif

////////////////////////////////////////////////////
// Normal Version
////////////////////////////////////////////////////

#ifdef NO_USE_STL

String::String()
{
	mValue = NULL;
}

String::String(const char *value)
{
	mValue = NULL;
	setValue(value);
}

String::String(const char *value, int offset, int count)
{
	mValue = NULL;
	setValue(value, offset, count);
}

String::~String()
{
	clear();
}

void String::setValue(const char *value)
{
	clear();
	if(!value)
		return;
	if(strlen(value) <= 0)
		return;
	mValue = new char[strlen(value)+1];
	strcpy(mValue, value);
}

void String::setValue(const char *value, int offset, int count)
{
	clear();
	if(!value && (int)strlen(value) < (offset + count))
		return;
	mValue = new char[count+1];
	strncpy(mValue, &value[offset], count);
}

char *String::getValue()
{
	return mValue;
}

void String::append(const char *value)
{
	if(!value)
		return;
	if(strlen(value) <= 0)
		return;
	strcat(mValue, value);
}

void String::clear()
{
	delete[] mValue;
	mValue = NULL;
}

int String::length()
{
	if(!mValue)
		return 0;
	return strlen(mValue);
}

char String::charAt(int  index)
{
	return mValue[index];
}

#endif

////////////////////////////////////////////////////
// Common
////////////////////////////////////////////////////

void String::append(char c)
{
	char value[2];
	value[0] = c;
	value[1] = '\0';
	append(value);
}

int String::compareTo(const char *anotherString)
{
	char *value = getValue();
	if(!value || !anotherString)
		return -1;
	return strcmp(value, anotherString);
}

void String::copyValueOf(const char *data)
{
	if(!data)
		return;
	strcpy((char *)data, getValue());
}

void String::copyValueOf(const char  data[], int  offset, int count)
{
	if(!data)
		return;
	char *value = getValue();
	strncpy((char *)data, &value[offset], count);
}

int String::startsWith(const char *prefix)
{
	if(!prefix)
		return -1;
	return regionMatches(0, prefix, 0, strlen(prefix));
}

int String::endsWith(const char *suffix)
{
	if(!suffix)
		return -1;
	return regionMatches(length() - strlen(suffix), suffix, 0, strlen(suffix));
}

int String::regionMatchesIgnoreCase(int toffset, const char *other, int ooffset, int len)
{
	if(!other)
		return -1;
		
	int n;
	
	int value1Len = length();
	char *value1 = new char[value1Len+1];
	strcpy(value1, getValue());
	for(n = 0; n < value1Len; n++)
		value1[n] = (char)toupper(value1[n]);
		
	int value2Len = strlen(other);
	char *value2 = new char[value2Len+1];
	strcpy(value2, other);
	for(n = 0; n < value2Len; n++)
		value2[n] = (char)toupper(value2[n]);
		
	int ret = regionMatches(toffset, other, ooffset, len);
	
	delete value1;
	delete value2;
	
	return ret;
}

int String::regionMatches(int toffset, const char *other, int ooffset, int len)
{
	char *value = getValue();
	if(!value || !other)
		return -1;
	if(length() < toffset)
		return -1;
	if((int)strlen(other) < ooffset + len)
		return -1;
	if(toffset < 0 || ooffset < 0)
		return -1;
	return strncmp(&value[toffset], &other[ooffset], len);
}

////////////////////////////////////////////////////
// operator
////////////////////////////////////////////////////

String &String::operator=(String &other)
{
	if(this == &other)
		return *this;
	setValue(other.getValue());
	return *this;
};

String &String::operator=(const char *value)
{
	setValue(value);
	return *this;
};

String &String::operator+(String &other)
{
	if(this == &other)
		return *this;
	append(other.getValue());
	return *this;
};

String &String::operator+(const char *value)
{
	append(value);
	return *this;
};

std::ostream& CyberX3D::operator<<(std::ostream &s, String &value)
{
	return s << value.getValue();
}

std::ostream& CyberX3D::operator<<(std::ostream &s, String *value)
{
	return s << value->getValue();
}

////////////////////////////////////////////////////
// Util
////////////////////////////////////////////////////

bool CyberX3D::HasString(const char *value)
{
	if(0 < StringLength(value))
		return true;
	return false;
}

int CyberX3D::StringLength(const char *value)
{
	if(value == NULL)
		return 0;
	return strlen(value);
}
