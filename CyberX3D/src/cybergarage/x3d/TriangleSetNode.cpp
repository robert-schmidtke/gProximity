/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	TriangleSetNode.cpp
*
*	Revisions;
*
*	11/27/02
*		- The first revision.
*
******************************************************************/

#include <cybergarage/x3d/TriangleSetNode.h>
#include <cybergarage/x3d/Graphic3D.h>

using namespace CyberX3D;

TriangleSetNode::TriangleSetNode()
{
	setHeaderFlag(false);
	setType(TRIANGLESET_NODE);
	
	///////////////////////////
	// Field
	///////////////////////////
	
	// convex  field
	convexField = new SFBool(true);
	convexField->setName(convexFieldString);
	addField(convexField);
	
	// creaseAngle  field
	creaseAngleField = new SFFloat(0.0f);
	creaseAngleField->setName(creaseAngleFieldString);
	addField(creaseAngleField);
}

TriangleSetNode::~TriangleSetNode()
{
}

////////////////////////////////////////////////
//	Convex
////////////////////////////////////////////////

SFBool *TriangleSetNode::getConvexField()
{
	if(isInstanceNode() == false)
		return convexField;
	return (SFBool *)getField(convexFieldString);
}

void TriangleSetNode::setConvex(bool value)
{
	getConvexField()->setValue(value);
}

void TriangleSetNode::setConvex(int value)
{
	setConvex(value ? true : false);
}

bool TriangleSetNode::getConvex()
{
	return getConvexField()->getValue();
}

////////////////////////////////////////////////
//	CreaseAngle
////////////////////////////////////////////////

SFFloat *TriangleSetNode::getCreaseAngleField()
{
	if(isInstanceNode() == false)
		return creaseAngleField;
	return (SFFloat *)getField(creaseAngleFieldString);
}

void TriangleSetNode::setCreaseAngle(float value)
{
	getCreaseAngleField()->setValue(value);
}

float TriangleSetNode::getCreaseAngle()
{
	return getCreaseAngleField()->getValue();
}

////////////////////////////////////////////////
//	List
////////////////////////////////////////////////

TriangleSetNode *TriangleSetNode::next()
{
	return (TriangleSetNode *)Node::next(getType());
}

TriangleSetNode *TriangleSetNode::nextTraversal()
{
	return (TriangleSetNode *)Node::nextTraversalByType(getType());
}

////////////////////////////////////////////////
//	functions
////////////////////////////////////////////////

bool TriangleSetNode::isChildNodeType(Node *node)
{
	if(node->isColorNode() || node->isCoordinateNode() || node->isNormalNode() || node->isTextureCoordinateNode())
		return true;
	else
		return false;
}

void TriangleSetNode::uninitialize()
{
}

void TriangleSetNode::update()
{
}

////////////////////////////////////////////////
//	Infomation
////////////////////////////////////////////////

void TriangleSetNode::outputContext(std::ostream &printStream, char *indentString)
{
}

////////////////////////////////////////////////
//	TriangleSetNode::initialize
////////////////////////////////////////////////

void TriangleSetNode::initialize()
{
}

////////////////////////////////////////////////////////////
//	getNPolygons
////////////////////////////////////////////////////////////

int TriangleSetNode::getNPolygons()
{
	CoordinateNode *coordNode = getCoordinateNodes();
	if(!coordNode)
		return 0;
		
	int nCoordIndexes = coordNode->getNPoints();
	int nCoordIndex = nCoordIndexes / 3;
	
	return nCoordIndex;
}

////////////////////////////////////////////////
//	TriangleSetNode::recomputeDisplayList
////////////////////////////////////////////////

#ifdef SUPPORT_OPENGL

void TriangleSetNode::recomputeDisplayList()
{
}

#endif

