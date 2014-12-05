/******************************************************************
*
*	CyberVRML97 for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	PROTO.h
*
******************************************************************/

#ifndef _CV97_PROTO_H_
#define _CV97_PROTO_H_

#include <cybergarage/x3d/LinkedList.h>
#include <cybergarage/x3d/StringUtil.h>
#include <cybergarage/x3d/Field.h>
#include <cybergarage/x3d/Vector.h>

namespace CyberX3D
{

	class PROTO : public LinkedListNode<PROTO>
	{
		String				mName;
		String				mString;
		Vector<Field>		mDefaultFieldVector;
		Vector<Field>		mFieldVector;
	public:
	
		PROTO(char *name, char *string, char *fieldString);
		~PROTO(void);
		
		void		setName(char *name);
		char		*getName(void);
		
		void		setString(char *string);
		char		*getString();
		void		getString(String &returnString);
		
		void		addDefaultField(Field *field);
		void		addField(Field *field);
		
		int			getNDefaultFields();
		int			getNFields();
		
		Field		*getDefaultField(int n);
		Field		*getField(int n);
		
		void		addFieldValues(char *fieldString, int bDefaultField);
		void		addDefaultFields(char *fieldString);
		void		addFields(char *fieldString);
		void		deleteDefaultFields(void);
		void		deleteFields(void);
		
		Field		*getField(char *name);
		int			getFieldType(char *name);
	};
	
}

#endif


