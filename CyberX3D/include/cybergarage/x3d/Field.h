/******************************************************************
*
*	CyberVRML97 for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	Field.h
*
******************************************************************/

#ifndef _CV97_FIELD_H_
#define _CV97_FIELD_H_

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cybergarage/x3d/StringUtil.h>
#include <cybergarage/x3d/JavaVM.h>

#ifdef SUPPORT_OLDCPP
#include <cybergarage/x3d/OldCpp.h>
#endif

namespace CyberX3D
{

	enum
	{
		fieldTypeNone,
		fieldTypeSFBool,
		fieldTypeSFFloat,
		fieldTypeSFDouble,
		fieldTypeSFInt32,
		fieldTypeSFVec2f,
		fieldTypeSFVec3f,
		fieldTypeSFVec2d,
		fieldTypeSFVec3d,
		fieldTypeSFString,
		fieldTypeSFColor,
		fieldTypeSFTime,
		fieldTypeSFRotation,
		fieldTypeSFImage,
		fieldTypeSFNode,
		fieldTypeSFChar,
		fieldTypeMFBool,
		fieldTypeMFFloat,
		fieldTypeMFDouble,
		fieldTypeMFInt32,
		fieldTypeMFVec2f,
		fieldTypeMFVec3f,
		fieldTypeMFVec2d,
		fieldTypeMFVec3d,
		fieldTypeMFString,
		fieldTypeMFColor,
		fieldTypeMFTime,
		fieldTypeMFRotation,
		fieldTypeMFImage,
		fieldTypeMFNode,
		fieldTypeMFChar,
		fieldTypeXMLElement,
		fieldTypeMaxNum,
	};
	
	class	SFBool;
	class	SFFloat;
	class	SFInt32;
	class	SFVec2f;
	class	SFVec3f;
	class	SFString;
	class	SFColor;
	class	SFTime;
	class	SFRotation;
//class	SFNode;
	class	MFFloat;
	class	MFInt32;
	class	MFVec2f;
	class	MFVec3f;
	class	MFString;
	class	MFColor;
	class	MFTime;
	class	MFRotation;
//class	MFNode;

#define	eventInStripString		"set_"
#define eventOutStripString		"_changed"

#define JAVAOBJECT_FIELD		0
#define JAVAOBJECT_CONSTFIELD	1

#define FIELD_MIN_BUFFERSIZE	256

#ifdef SUPPORT_JSAI
	class Field : public CJavaVM
	{
#else
	class Field
	{
#endif
	
		String	mName;
		int		mType;
		
	public:
	
		Field()
		{
			mType = fieldTypeNone;
		}
		
		virtual ~Field()
		{
		}
		
		char *getTypeName();
		
		void setType(int type)
		{
			mType = type;
		}
		
		void setType(const char *type);
		
		int getType()
		{
			return mType;
		}
		
		void setName(const char *name)
		{
			mName.setValue(name);
		}
		
		char *getName()
		{
			return mName.getValue();
		}
		
		friend std::ostream& operator<<(std::ostream &s, Field &value);
		friend std::ostream& operator<<(std::ostream &s, Field *value);
		
		////////////////////////////////////////////////
		//	String
		////////////////////////////////////////////////
		
		virtual void setValue(const char *value) = 0;
		virtual char *getValue(char *buffer, int bufferLen = -1) = 0;
		virtual int getValueCount() = 0;
		
		virtual char *getValue(String &strBuffer)
		{
			char buffer[FIELD_MIN_BUFFERSIZE];
			getValue(buffer, FIELD_MIN_BUFFERSIZE);
			strBuffer.setValue(buffer);
			return strBuffer.getValue();
		}
		
		////////////////////////////////////////////////
		//	XML String
		////////////////////////////////////////////////
		
		virtual char *toXMLString()
		{
			static String strBuffer;
			return getValue(strBuffer);
		}
		
		////////////////////////////////////////////////
		//	Compare
		////////////////////////////////////////////////
		
		virtual bool equals(Field *field)
		{
			return false;
		}
		
		////////////////////////////////////////////////
		//	isSF*
		////////////////////////////////////////////////
		
		bool isSFBool()
		{
			return (fieldTypeSFBool == mType) ? true : false;
		}
		
		bool isSFFloat()
		{
			return (fieldTypeSFFloat == mType) ? true : false;
		}
		
		bool isSFInt32()
		{
			return (fieldTypeSFInt32 == mType) ? true : false;
		}
		
		bool isSFVec2f()
		{
			return (fieldTypeSFVec2f == mType) ? true : false;
		}
		
		bool isSFVec3f()
		{
			return (fieldTypeSFVec3f == mType) ? true : false;
		}
		
		bool isSFString()
		{
			return (fieldTypeSFString == mType) ? true : false;
		}
		
		bool isSFColor()
		{
			return (fieldTypeSFColor == mType) ? true : false;
		}
		
		bool isSFTime()
		{
			return (fieldTypeSFTime == mType) ? true : false;
		}
		
		bool isSFRotatioin()
		{
			return (fieldTypeSFRotation == mType) ? true : false;
		}
		
		bool isSFImage()
		{
			return (fieldTypeSFImage == mType) ? true : false;
		}
		
		bool isSFNode()
		{
			return (fieldTypeSFNode == mType) ? true : false;
		}
		
		////////////////////////////////////////////////
		//	isMF*
		////////////////////////////////////////////////
		
		bool isMFFloat()
		{
			return (fieldTypeMFFloat == mType) ? true : false;
		}
		
		bool isMFInt32()
		{
			return (fieldTypeMFInt32 == mType) ? true : false;
		}
		
		bool isMFVec2f()
		{
			return (fieldTypeMFVec2f == mType) ? true : false;
		}
		
		bool isMFVec3f()
		{
			return (fieldTypeMFVec3f == mType) ? true : false;
		}
		
		bool isMFString()
		{
			return (fieldTypeMFString == mType) ? true : false;
		}
		
		bool isMFColor()
		{
			return (fieldTypeMFColor == mType) ? true : false;
		}
		
		bool isMFTime()
		{
			return (fieldTypeMFTime == mType) ? true : false;
		}
		
		bool isMFRotatioin()
		{
			return (fieldTypeMFRotation == mType) ? true : false;
		}
		
		bool isMFNode()
		{
			return (fieldTypeMFNode == mType) ? true : false;
		}
		
		bool isXMLElement()
		{
			return (fieldTypeXMLElement == mType) ? true : false;
		}
		
		////////////////////////////////////////////////
		//	is(MF|SF)Field
		////////////////////////////////////////////////
		
		bool isSField()
		{
			return !isMField();
		}
		
		bool isMField()
		{
			if(isMFFloat())
				return true;
			if(isMFInt32())
				return true;
			if(isMFVec2f())
				return true;
			if(isMFVec3f())
				return true;
			if(isMFString())
				return true;
			if(isMFColor())
				return true;
			if(isMFTime())
				return true;
			if(isMFRotatioin())
				return true;
			if(isMFNode())
				return true;
			return false;
		}
		
		bool isSingleValueMField()
		{
			if(isMFFloat())
				return true;
			if(isMFInt32())
				return true;
			if(isMFNode())
				return true;
			if(isMFString())
				return true;
			if(isMFTime())
				return true;
			return false;
		}
		
		////////////////////////////////////////////////
		//	Java
		////////////////////////////////////////////////
		
#ifdef SUPPORT_JSAI
		virtual jobject toJavaObject(int bConstField = 0)
		{
			assert(0);
			return NULL;
		};
		virtual void setValue(jobject field, int bConstField = 0)
		{
			assert(0);
		};
		virtual void getValue(jobject field, int bConstField = 0)
		{
			assert(0);
		};
#endif
	};
	
}

#endif
