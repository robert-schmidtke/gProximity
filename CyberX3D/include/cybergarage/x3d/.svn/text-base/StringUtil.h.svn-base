/******************************************************************
*
*	CyberVRML97 for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	StringUtil.h
*
******************************************************************/

#ifndef _CV97_STRINGUTIL_H_
#define _CV97_STRINGUTIL_H_

#ifndef NO_USE_STL
#include <string>
#endif
#include <iostream>

namespace CyberX3D
{

////////////////////////////////////////////////////////////////////////////////
// String
////////////////////////////////////////////////////////////////////////////////

	class  String
	{
	
#ifndef NO_USE_STL
		std::string	mValue;
#else
		char	*mValue;
#endif
		
	public:
	
		String();
		String(const char *value);
		String(const char *value, int offset, int count);
		
		~String();
		
		String &operator=(String &value);
		String &operator=(const char *value);
		String &operator+(String &value);
		String &operator+(const char *value);
		friend std::ostream& operator<<(std::ostream &s, String &value);
		friend std::ostream& operator<<(std::ostream &s, String *value);
		
		void setValue(const char *value);
		void setValue(const char *value, int offset, int count);
		void append(const char *value);
		void append(const char c);
		
		char *getValue();
		void clear();
		
		int length();
		
		char charAt(int  index);
		
		int compareTo(const char *anotherString);
		int compareToIgnoreCase(const char *anotherString);
		
		void concat(const char *str);
		void copyValueOf(const char *data);
		void copyValueOf(const char  *data, int  offset, int count);
		
		int regionMatches(int toffset, const char *other, int ooffset, int len);
		int regionMatchesIgnoreCase(int toffset, const char *other, int ooffset, int len);
		
		int startsWith(const char *prefix);
		int endsWith(const char *suffix);
	};
	
////////////////////////////////////////////////////////////////////////////////
// String Functions
////////////////////////////////////////////////////////////////////////////////

	bool HasString(const char *value);
	int StringLength(const char *value);
	
}

#endif
