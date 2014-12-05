/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	SceneNode.cpp
*
*	06/06/03
*		- The first release
*
******************************************************************/

#include <cybergarage/x3d/SceneNode.h>

using namespace CyberX3D;

SceneNode::SceneNode()
{
	setHeaderFlag(false);
	setType(SCENE_NODE);
}

SceneNode::~SceneNode()
{
}

////////////////////////////////////////////////
//	Output
////////////////////////////////////////////////

void SceneNode::outputContext(std::ostream &printStream, char *indentString)
{
}

////////////////////////////////////////////////
//	functions
////////////////////////////////////////////////

bool SceneNode::isChildNodeType(Node *node)
{
	return true;
}

void SceneNode::initialize()
{
}

void SceneNode::uninitialize()
{
}

void SceneNode::update()
{
}

////////////////////////////////////////////////
//	List
////////////////////////////////////////////////

SceneNode *SceneNode::next()
{
	return (SceneNode *)Node::next(getType());
}

SceneNode *SceneNode::nextTraversal()
{
	return (SceneNode *)Node::nextTraversalByType(getType());
}

