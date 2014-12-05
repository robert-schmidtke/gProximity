/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	Arc2DNode.cpp
*
******************************************************************/

#include <cybergarage/x3d/Arc2DNode.h>
#include <cybergarage/x3d/Graphic3D.h>
#include <cybergarage/x3d/MathUtil.h>

using namespace CyberX3D;

static const char startAngleFieldString[] = "startAngle";
static const char endAngleFieldString[] = "endAngle";

Arc2DNode::Arc2DNode()
{
	setHeaderFlag(false);
	setType(ARC2D_NODE);
	
	///////////////////////////
	// Field
	///////////////////////////
	
	// radius field
	radiusField = new SFFloat(1.0f);
	addField(radiusFieldString, radiusField);
	
	// startAngle field
	startAngleField = new SFFloat(0.0f);
	addField(startAngleFieldString, startAngleField);
	
	// endAngle field
	endAngleField = new SFFloat(PI / 2.0f);
	addField(endAngleFieldString, endAngleField);
}

Arc2DNode::~Arc2DNode()
{
}

////////////////////////////////////////////////
//	Radius
////////////////////////////////////////////////

SFFloat *Arc2DNode::getRadiusField()
{
	if(isInstanceNode() == false)
		return radiusField;
	return (SFFloat *)getField(radiusFieldString);
}

void Arc2DNode::setRadius(float value)
{
	getRadiusField()->setValue(value);
}

float Arc2DNode::getRadius()
{
	return getRadiusField()->getValue();
}

////////////////////////////////////////////////
//	StartAngle
////////////////////////////////////////////////

SFFloat *Arc2DNode::getStartAngleField()
{
	if(isInstanceNode() == false)
		return startAngleField;
	return (SFFloat *)getField(startAngleFieldString);
}

void Arc2DNode::setStartAngle(float value)
{
	getStartAngleField()->setValue(value);
}

float Arc2DNode::getStartAngle()
{
	return getStartAngleField()->getValue();
}

////////////////////////////////////////////////
//	EndAngle
////////////////////////////////////////////////

SFFloat *Arc2DNode::getEndAngleField()
{
	if(isInstanceNode() == false)
		return endAngleField;
	return (SFFloat *)getField(endAngleFieldString);
}

void Arc2DNode::setEndAngle(float value)
{
	getEndAngleField()->setValue(value);
}

float Arc2DNode::getEndAngle()
{
	return getEndAngleField()->getValue();
}

////////////////////////////////////////////////
//	List
////////////////////////////////////////////////

Arc2DNode *Arc2DNode::next()
{
	return (Arc2DNode *)Node::next(getType());
}

Arc2DNode *Arc2DNode::nextTraversal()
{
	return (Arc2DNode *)Node::nextTraversalByType(getType());
}

////////////////////////////////////////////////
//	functions
////////////////////////////////////////////////

bool Arc2DNode::isChildNodeType(Node *node)
{
	return false;
}

void Arc2DNode::initialize()
{
#ifdef SUPPORT_OPENGL
	recomputeDisplayList();
#endif
}

void Arc2DNode::uninitialize()
{
}

void Arc2DNode::update()
{
}

////////////////////////////////////////////////
//	outputContext
////////////////////////////////////////////////

void Arc2DNode::outputContext(std::ostream &printStream, char *indentString)
{
}

////////////////////////////////////////////////
//	Arc2DNode::recomputeDisplayList
////////////////////////////////////////////////

#ifdef SUPPORT_OPENGL

void Arc2DNode::recomputeDisplayList()
{
};

#endif
