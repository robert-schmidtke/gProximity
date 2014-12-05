/******************************************************************
*
*	CyberVRML97 for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	RouteNode.cpp
*
******************************************************************/

#include <cybergarage/x3d/RootNode.h>

using namespace CyberX3D;

RootNode::RootNode()
{
	setHeaderFlag(true);
	setType(ROOT_NODE);
}

RootNode::~RootNode()
{
}

////////////////////////////////////////////////
//	functions
////////////////////////////////////////////////

bool RootNode::isChildNodeType(Node *node)
{
	if(node->isCommonNode() || node->isBindableNode() || node->isInterpolatorNode() || node->isSensorNode() || node->isGroupingNode() || node->isSpecialGroupNode())
		return true;
	else
		return false;
}

void RootNode::initialize()
{
}

void RootNode::uninitialize()
{
}

void RootNode::update()
{
}

////////////////////////////////////////////////
//	infomation
////////////////////////////////////////////////

void RootNode::outputContext(std::ostream& printStream, char * indentString)
{
}
