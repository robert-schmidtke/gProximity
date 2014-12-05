/******************************************************************
*
*	CyberVRML97 for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	NodeList.cpp
*
******************************************************************/

#include <cybergarage/x3d/NodeList.h>

using namespace CyberX3D;

NodeList::NodeList()
{
	RootNode *rootNode = new RootNode();
	setRootNode(rootNode);
}

NodeList::~NodeList()
{
}
