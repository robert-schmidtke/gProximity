/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	StaticGroupNode.cpp
*
*	11/20/02
*		- The first revison.
*
******************************************************************/

#include <cybergarage/x3d/StaticGroupNode.h>

using namespace CyberX3D;

StaticGroupNode::StaticGroupNode()
{
	setHeaderFlag(false);
	setType(STATICGROUP_NODE);
}

StaticGroupNode::~StaticGroupNode()
{
}

////////////////////////////////////////////////
//	Output
////////////////////////////////////////////////

void StaticGroupNode::outputContext(std::ostream &printStream, char *indentString)
{
}

////////////////////////////////////////////////
//	functions
////////////////////////////////////////////////

bool StaticGroupNode::isChildNodeType(Node *node)
{
	if(node->isCommonNode() || node->isBindableNode() || node->isInterpolatorNode() || node->isSensorNode() || node->isGroupingNode() || node->isSpecialGroupNode())
		return true;
	else
		return false;
}

void StaticGroupNode::initialize()
{
	recomputeBoundingBox();
}

void StaticGroupNode::uninitialize()
{
}

void StaticGroupNode::update()
{
}

////////////////////////////////////////////////
//	List
////////////////////////////////////////////////

StaticGroupNode *StaticGroupNode::next()
{
	return (StaticGroupNode *)Node::next(getType());
}

StaticGroupNode *StaticGroupNode::nextTraversal()
{
	return (StaticGroupNode *)Node::nextTraversalByType(getType());
}

