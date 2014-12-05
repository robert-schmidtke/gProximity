/******************************************************************
*
*	CyberVRML97 for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	NodeList.h
*
******************************************************************/

#ifndef _CV97_NODELIST_H_
#define _CV97_NODELIST_H_

#include <cybergarage/x3d/LinkedList.h>
#include <cybergarage/x3d/RootNode.h>

namespace CyberX3D
{

	class NodeList : public LinkedList<Node>
	{
	
	public:
	
		NodeList();
		~NodeList();
	};
	
}

#endif
