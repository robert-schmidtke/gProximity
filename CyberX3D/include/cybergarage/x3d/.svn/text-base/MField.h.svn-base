/******************************************************************
*
*	CyberVRML97 for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	MFiled.h
*
******************************************************************/

#ifndef _CV97_MFIELD_H_
#define _CV97_MFIELD_H_

#include <iostream>

#include <cybergarage/x3d/Field.h>
#include <cybergarage/x3d/Vector.h>

namespace CyberX3D
{

	class MField : public Field
	{
	
		Vector<Field>	mFieldVector;
		
	public:
	
		MField();
		virtual ~MField();
		
		int getSize();
		
		int size();
		
		void add(Field *object);
		
		void insert(Field *object, int index);
		void insert(int index, Field *object);
		void setObject(int index, Field *object);
		void replace(int index, Field *object);
		
		void clear();
		
		void remove(int index);
		
		void removeLastObject();
		
		void removeFirstObject();
		
		Field *lastObject();
		Field *firstObject();
		Field *getObject(int index);
		
		void copy(MField *srcMField);
		
		virtual void addValue(const char *value) = 0;
		void setValue(const char *buffer);
		char *getValue(char *buffer, int bufferLen);
		char *getValue(String &buffer);
		
		virtual int getValueCount() = 0;
		virtual void setValue(MField *mfield) = 0;
		virtual void outputContext(std::ostream& printStream, char *indentString) = 0;
		
		void outputContext(std::ostream& printStream, char *indentString1, char *indentString2);
		
		////////////////////////////////////////////////
		//	Java
		////////////////////////////////////////////////
		
#ifdef SUPPORT_JSAI
		
		virtual jobject toJavaObject(int bConstField = 0) = 0;
		virtual void setValue(jobject field, int bConstField = 0) = 0;
		virtual void getValue(jobject field, int bConstField = 0) = 0;
		
#endif
	};
	
}

#endif
