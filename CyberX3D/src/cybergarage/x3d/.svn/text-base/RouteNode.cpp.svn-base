/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2003
*
*	File:	RouteNode.cpp
*
******************************************************************/

#include <cybergarage/x3d/RouteNode.h>

using namespace CyberX3D;

static const char fromNodeString[] = "fromNode";
static const char fromFieldString[] = "fromField";
static const char toNodeString[] = "toNode";
static const char toFieldString[] = "toField";

RouteNode::RouteNode()
{
	// fromNode
	fromNode = new SFString();
	addExposedField(fromNodeString, fromNode);
	
	// fromField
	fromField = new SFString();
	addExposedField(fromFieldString, fromField);
	
	// toNode
	toNode = new SFString();
	addExposedField(toNodeString, toNode);
	
	// toField
	toField = new SFString();
	addExposedField(toFieldString, toField);
}

RouteNode::~RouteNode()
{
}

////////////////////////////////////////////////
//	FromField
////////////////////////////////////////////////

SFString *RouteNode::getFromField()
{
	if(isInstanceNode() == false)
		return fromField;
	return (SFString *)getExposedField(fromFieldString);
}

void RouteNode::setFromFieldName(const char *value)
{
	getFromField()->setValue(value);
}

char *RouteNode::getFromFieldName()
{
	return getFromField()->getValue();
}

////////////////////////////////////////////////
//	FromField
////////////////////////////////////////////////

SFString *RouteNode::getFromNode()
{
	if(isInstanceNode() == false)
		return fromNode;
	return (SFString *)getExposedField(fromNodeString);
}

void RouteNode::setFromNodeName(const char *value)
{
	getFromNode()->setValue(value);
}

char *RouteNode::getFromNodeName()
{
	return getFromNode()->getValue();
}

////////////////////////////////////////////////
//	ToField
////////////////////////////////////////////////

SFString *RouteNode::getToField()
{
	if(isInstanceNode() == false)
		return toField;
	return (SFString *)getExposedField(toFieldString);
}

void RouteNode::setToFieldName(const char *value)
{
	getToField()->setValue(value);
}

char *RouteNode::getToFieldName()
{
	return getToField()->getValue();
}

////////////////////////////////////////////////
//	ToNode
////////////////////////////////////////////////

SFString *RouteNode::getToNode()
{
	if(isInstanceNode() == false)
		return toNode;
	return (SFString *)getExposedField(toNodeString);
}

void RouteNode::setToNodeName(const char *value)
{
	getToNode()->setValue(value);
}

char *RouteNode::getToNodeName()
{
	return getToNode()->getValue();
}

////////////////////////////////////////////////
//	Output
////////////////////////////////////////////////

void RouteNode::outputContext(std::ostream &printStream, char *indentString)
{
}

////////////////////////////////////////////////
//	functions
////////////////////////////////////////////////

bool RouteNode::isChildNodeType(Node *node)
{
	return false;
}

void RouteNode::initialize()
{
}

void RouteNode::uninitialize()
{
}

void RouteNode::update()
{
}

////////////////////////////////////////////////
//	List
////////////////////////////////////////////////

RouteNode *RouteNode::next()
{
	return (RouteNode *)Node::next(getType());
}

RouteNode *RouteNode::nextTraversal()
{
	return (RouteNode *)Node::nextTraversalByType(getType());
}

