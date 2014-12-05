/******************************************************************
*
*	CyberVRML97 for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	DEFNode.cpp
*
******************************************************************/

#include <cybergarage/x3d/DEFNode.h>

using namespace CyberX3D;

DEFNode::DEFNode()
{
	setHeaderFlag(false);
	setType(DEF_NODE);
}

DEFNode::~DEFNode()
{
}

////////////////////////////////////////////////
//	List
////////////////////////////////////////////////

DEFNode *DEFNode::next()
{
	return (DEFNode *)Node::next(getType());
}

DEFNode *DEFNode::nextTraversal()
{
	return (DEFNode *)Node::nextTraversalByType(getType());
}

////////////////////////////////////////////////
//	functions
////////////////////////////////////////////////

bool DEFNode::isChildNodeType(Node *node)
{
	return false;
}

void DEFNode::initialize()
{
}

void DEFNode::uninitialize()
{
}

void DEFNode::update()
{
}

void DEFNode::outputContext(std::ostream &printStream, char *indentString)
{
}

