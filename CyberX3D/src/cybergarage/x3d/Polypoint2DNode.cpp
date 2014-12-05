/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	Polypoint2DNode.cpp
*
******************************************************************/

#include <cybergarage/x3d/Polypoint2DNode.h>
#include <cybergarage/x3d/Graphic3D.h>

using namespace CyberX3D;

static const char pointsFieldString[] = "points";

Polypoint2DNode::Polypoint2DNode()
{
	setHeaderFlag(false);
	setType(POLYPOINT2D_NODE);
	
	///////////////////////////
	// Field
	///////////////////////////
	
	// points field
	pointsField = new MFVec2f();
	addField(pointsFieldString, pointsField);
}

Polypoint2DNode::~Polypoint2DNode()
{
}

////////////////////////////////////////////////
//	Points
////////////////////////////////////////////////

MFVec2f *Polypoint2DNode::getPointsField()
{
	if(isInstanceNode() == false)
		return pointsField;
	return	(MFVec2f *)getField(pointsFieldString);
}

int Polypoint2DNode::getNPoints()
{
	return getPointsField()->getSize();
}

void Polypoint2DNode::addPoint(float point[])
{
	getPointsField()->addValue(point);
}

void Polypoint2DNode::addPoint(float x, float y)
{
	getPointsField()->addValue(x, y);
}

void Polypoint2DNode::getPoint(int index, float point[])
{
	getPointsField()->get1Value(index, point);
}

void Polypoint2DNode::setPoint(int index, float point[])
{
	getPointsField()->set1Value(index, point);
}

void Polypoint2DNode::setPoint(int index, float x, float y)
{
	getPointsField()->set1Value(index, x, y);
}

void Polypoint2DNode::removePoint(int index)
{
	getPointsField()->remove(index);
}

void Polypoint2DNode::removeAllPoints()
{
	getPointsField()->clear();
}

////////////////////////////////////////////////
//	List
////////////////////////////////////////////////

Polypoint2DNode *Polypoint2DNode::next()
{
	return (Polypoint2DNode *)Node::next(getType());
}

Polypoint2DNode *Polypoint2DNode::nextTraversal()
{
	return (Polypoint2DNode *)Node::nextTraversalByType(getType());
}

////////////////////////////////////////////////
//	functions
////////////////////////////////////////////////

bool Polypoint2DNode::isChildNodeType(Node *node)
{
	return false;
}

void Polypoint2DNode::initialize()
{
	recomputeBoundingBox();
#ifdef SUPPORT_OPENGL
	recomputeDisplayList();
#endif
}

void Polypoint2DNode::uninitialize()
{
}

void Polypoint2DNode::update()
{
}

////////////////////////////////////////////////
//	Infomation
////////////////////////////////////////////////

void Polypoint2DNode::outputContext(std::ostream &printStream, char *indentString)
{
}

////////////////////////////////////////////////
//	Polypoint2DNode::recomputeDisplayList
////////////////////////////////////////////////

#ifdef SUPPORT_OPENGL

void Polypoint2DNode::recomputeDisplayList()
{
};

#endif
