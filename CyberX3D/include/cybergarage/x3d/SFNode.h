/******************************************************************
*
*	CyberVRML97 for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	SFNode.h
*
******************************************************************/

#ifndef _CV97_SFNODE_H_
#define _CV97_SFNODE_H_

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cybergarage/x3d/Field.h>

namespace CyberX3D
{

	class Node;
	
	class SFNode : public Field
	{
	
		static	int	mInit;
		
		Node	*mValue;
		
	public:
	
		SFNode();
		SFNode(Node *value);
		SFNode(SFNode *value);
		
		void InitializeJavaIDs();
		
		~SFNode();
		
		void setValue(Node *value);
		void setValue(SFNode *value);
		Node *getValue();
		
		int getValueCount()
		{
			return 1;
		}
		
		////////////////////////////////////////////////
		//	Output
		////////////////////////////////////////////////
		
		friend std::ostream& operator<<(std::ostream &s, SFNode &node);
		friend std::ostream& operator<<(std::ostream &s, SFNode *node);
		
		////////////////////////////////////////////////
		//	String
		////////////////////////////////////////////////
		
		void setValue(const char *buffer);
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
