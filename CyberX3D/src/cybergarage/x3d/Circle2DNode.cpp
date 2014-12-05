/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	Circle2DNode.cpp
*
******************************************************************/

#include <cybergarage/x3d/Circle2DNode.h>
#include <cybergarage/x3d/Graphic3D.h>

using namespace CyberX3D;

Circle2DNode::Circle2DNode()
{
	setHeaderFlag(false);
	setType(CIRCLE2D_NODE);
	
	///////////////////////////
	// Field
	///////////////////////////
	
	// radius field
	radiusField = new SFFloat(1.0f);
	addField(radiusFieldString, radiusField);
}

Circle2DNode::~Circle2DNode()
{
}

////////////////////////////////////////////////
//	Radius
////////////////////////////////////////////////

SFFloat *Circle2DNode::getRadiusField()
{
	if(isInstanceNode() == false)
		return radiusField;
	return (SFFloat *)getField(radiusFieldString);
}

void Circle2DNode::setRadius(float value)
{
	getRadiusField()->setValue(value);
}

float Circle2DNode::getRadius()
{
	return getRadiusField()->getValue();
}

////////////////////////////////////////////////
//	List
////////////////////////////////////////////////

Circle2DNode *Circle2DNode::next()
{
	return (Circle2DNode *)Node::next(getType());
}

Circle2DNode *Circle2DNode::nextTraversal()
{
	return (Circle2DNode *)Node::nextTraversalByType(getType());
}

////////////////////////////////////////////////
//	functions
////////////////////////////////////////////////

bool Circle2DNode::isChildNodeType(Node *node)
{
	return false;
}

void Circle2DNode::initialize()
{
	recomputeBoundingBox();
#ifdef SUPPORT_OPENGL
	recomputeDisplayList();
#endif
}

void Circle2DNode::uninitialize()
{
}

void Circle2DNode::update()
{
}

////////////////////////////////////////////////
//	Infomation
////////////////////////////////////////////////

void Circle2DNode::outputContext(std::ostream &printStream, char *indentString)
{
}

////////////////////////////////////////////////
//	Circle2DNode::recomputeDisplayList
////////////////////////////////////////////////

#ifdef SUPPORT_OPENGL

void Circle2DNode::recomputeDisplayList()
{
};

#endif
