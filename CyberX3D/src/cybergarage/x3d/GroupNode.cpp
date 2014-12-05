/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	GroupNode.cpp
*
*	11/19/02
*		- Changed the super class from GroupingNode to BoundedGroupingNode.
*
******************************************************************/

#include <cybergarage/x3d/GroupNode.h>

using namespace CyberX3D;

GroupNode::GroupNode()
{
	setHeaderFlag(false);
	setType(GROUP_NODE);
}

GroupNode::~GroupNode()
{
}

////////////////////////////////////////////////
//	Output
////////////////////////////////////////////////

void GroupNode::outputContext(std::ostream &printStream, char *indentString)
{
}

////////////////////////////////////////////////
//	functions
////////////////////////////////////////////////

bool GroupNode::isChildNodeType(Node *node)
{
	if(node->isCommonNode() || node->isBindableNode() || node->isInterpolatorNode() || node->isSensorNode() || node->isGroupingNode() || node->isSpecialGroupNode())
		return true;
	else
		return false;
}

void GroupNode::initialize()
{
	recomputeBoundingBox();
}

void GroupNode::uninitialize()
{
}

void GroupNode::update()
{
}

////////////////////////////////////////////////
//	List
////////////////////////////////////////////////

GroupNode *GroupNode::next()
{
	return (GroupNode *)Node::next(getType());
}

GroupNode *GroupNode::nextTraversal()
{
	return (GroupNode *)Node::nextTraversalByType(getType());
}

