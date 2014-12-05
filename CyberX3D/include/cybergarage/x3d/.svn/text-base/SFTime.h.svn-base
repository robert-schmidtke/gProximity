/******************************************************************
*
*	CyberVRML97 for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	SFTime.h
*
******************************************************************/

#ifndef _CV97_SFTIME_H_
#define _CV97_SFTIME_H_

#include <iostream>
#include <stdio.h>
#include <cybergarage/x3d/Field.h>

namespace CyberX3D
{

	double GetCurrentSystemTime();
	
	class SFTime : public Field
	{
	
		static	int	mInit;
		
		double mValue;
		
	public:
	
		SFTime();
		SFTime(double value);
		SFTime(SFTime *value);
		void InitializeJavaIDs();
		
		void setValue(double value);
		void setValue(SFTime *value);
		double getValue();
		
		int getValueCount()
		{
			return 1;
		}
		
		////////////////////////////////////////////////
		//	Output
		////////////////////////////////////////////////
		
		friend std::ostream& operator<<(std::ostream &s, SFTime &time);
		friend std::ostream& operator<<(std::ostream &s, SFTime *time);
		
		////////////////////////////////////////////////
		//	String
		////////////////////////////////////////////////
		
		void setValue(const char *value);
		char *getValue(char *buffer, int bufferLen);
		
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
