/******************************************************************
*
*	CyberVRML97 for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	DEF.h
*
******************************************************************/

#ifndef _CV97_DEF_H_
#define _CV97_DEF_H_

#include <cybergarage/x3d/StringUtil.h>
#include <cybergarage/x3d/LinkedListNode.h>

namespace CyberX3D
{

	class DEF : public LinkedListNode<DEF>
	{
	
		String		mName;
		String		mString;
		
	public:
	
		DEF(const char *name, const char *string);
		~DEF();
		
		////////////////////////////////////////////////
		//	Name
		////////////////////////////////////////////////
		
		void setName(const char *name);
		char *getName();
		
		////////////////////////////////////////////////
		//	Name
		////////////////////////////////////////////////
		
		void setString(const char *string);
		char *getString();
	};
	
}

#endif


