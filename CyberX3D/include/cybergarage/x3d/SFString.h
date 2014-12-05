/******************************************************************
*
*	CyberVRML97 for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	SFString.h
*
******************************************************************/

#ifndef _CV97_SFSTRING_H_
#define _CV97_SFSTRING_H_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cybergarage/x3d/Field.h>
#include <cybergarage/x3d/StringUtil.h>

namespace CyberX3D
{

	class SFString : public Field
	{
	
		static	int	mInit;
		
		String	mValue;
		
	public:
	
		SFString();
		SFString(const char *value);
		SFString(SFString *value);
		
		void InitializeJavaIDs();
		
		~SFString();
		
		void setValue(const char *value);
		void setValue(SFString *value);
		char *getValue();
		
		int getValueCount()
		{
			return 1;
		}
		
		////////////////////////////////////////////////
		//	Output
		////////////////////////////////////////////////
		
		friend std::ostream& operator<<(std::ostream &s, SFString &string);
		friend std::ostream& operator<<(std::ostream &s, SFString *string);
		
		////////////////////////////////////////////////
		//	String
		////////////////////////////////////////////////
		
		char *getValue(char *buffer, int bufferLen);
		char *getValue(String &buffer);
		
		////////////////////////////////////////////////
		//	Compare
		////////////////////////////////////////////////
		
		bool equals(Field *field);
		
		////////////////////////////////////////////////
		//	Java
		////////////////////////////////////////////////
		
#ifdef SUPPORT_JSAI
		
	private:
	
		static jclass		mFieldClassID;
		static jclass		mConstFieldClassID;
		
		static jmethodID	mInitMethodID;
		static jmethodID	mSetValueMethodID;
		static jmethodID	mGetValueMethodID;
		static jmethodID	mSetNameMethodID;
		
		static jmethodID	mConstInitMethodID;
		static jmethodID	mConstSetValueMethodID;
		static jmethodID	mConstGetValueMethodID;
		static jmethodID	mConstSetNameMethodID;
		
	public:
	
		void		setJavaIDs();
		
		jclass		getFieldID()
		{
			return mFieldClassID;
		}
		jclass		getConstFieldID()
		{
			return mConstFieldClassID;
		}
		
		jmethodID	getInitMethodID()
		{
			return mInitMethodID;
		}
		jmethodID	getSetValueMethodID()
		{
			return mSetValueMethodID;
		}
		jmethodID	getGetValueMethodID()
		{
			return mGetValueMethodID;
		}
		jmethodID	getSetNameMethodID()
		{
			return mSetNameMethodID;
		}
		
		jmethodID	getConstInitMethodID()
		{
			return mConstInitMethodID;
		}
		jmethodID	getConstSetValueMethodID()
		{
			return mConstSetValueMethodID;
		}
		jmethodID	getConstGetValueMethodID()
		{
			return mConstGetValueMethodID;
		}
		jmethodID	getConstSetNameMethodID()
		{
			return mConstSetNameMethodID;
		}
		
		jobject toJavaObject(int bConstField = 0);
		void setValue(jobject field, int bConstField = 0);
		void getValue(jobject field, int bConstField = 0);
		
#endif
		
	};
	
}

#endif
