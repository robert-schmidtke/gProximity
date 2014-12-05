/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	Polyline2DNode.cpp
*
******************************************************************/

#include <cybergarage/x3d/Polyline2DNode.h>
#include <cybergarage/x3d/Graphic3D.h>

using namespace CyberX3D;

static const char lineSegmentsFieldString[] = "lineSegments";

Polyline2DNode::Polyline2DNode()
{
	setHeaderFlag(false);
	setType(POLYLINE2D_NODE);
	
	///////////////////////////
	// Field
	///////////////////////////
	
	// lineSegments field
	lineSegmentsField = new MFVec2f();
	addField(lineSegmentsFieldString, lineSegmentsField);
}

Polyline2DNode::~Polyline2DNode()
{
}

////////////////////////////////////////////////
//	LineSegments
////////////////////////////////////////////////

MFVec2f *Polyline2DNode::getLineSegmentsField()
{
	if(isInstanceNode() == false)
		return lineSegmentsField;
	return	(MFVec2f *)getField(lineSegmentsFieldString);
}

int Polyline2DNode::getNLineSegments()
{
	return getLineSegmentsField()->getSize();
}

void Polyline2DNode::addLineSegment(float point[])
{
	getLineSegmentsField()->addValue(point);
}

void Polyline2DNode::addLineSegment(float x, float y)
{
	getLineSegmentsField()->addValue(x, y);
}

void Polyline2DNode::getLineSegment(int index, float point[])
{
	getLineSegmentsField()->get1Value(index, point);
}

void Polyline2DNode::setLineSegment(int index, float point[])
{
	getLineSegmentsField()->set1Value(index, point);
}

void Polyline2DNode::setLineSegment(int index, float x, float y)
{
	getLineSegmentsField()->set1Value(index, x, y);
}

void Polyline2DNode::removeLineSegment(int index)
{
	getLineSegmentsField()->remove(index);
}

void Polyline2DNode::removeAllLineSegments()
{
	getLineSegmentsField()->clear();
}

////////////////////////////////////////////////
//	List
////////////////////////////////////////////////

Polyline2DNode *Polyline2DNode::next()
{
	return (Polyline2DNode *)Node::next(getType());
}

Polyline2DNode *Polyline2DNode::nextTraversal()
{
	return (Polyline2DNode *)Node::nextTraversalByType(getType());
}

////////////////////////////////////////////////
//	functions
////////////////////////////////////////////////

bool Polyline2DNode::isChildNodeType(Node *node)
{
	return false;
}

void Polyline2DNode::initialize()
{
	recomputeBoundingBox();
#ifdef SUPPORT_OPENGL
	recomputeDisplayList();
#endif
}

void Polyline2DNode::uninitialize()
{
}

void Polyline2DNode::update()
{
}

////////////////////////////////////////////////
//	Infomation
////////////////////////////////////////////////

void Polyline2DNode::outputContext(std::ostream &printStream, char *indentString)
{
}

////////////////////////////////////////////////
//	Polyline2DNode::recomputeDisplayList
////////////////////////////////////////////////

#ifdef SUPPORT_OPENGL

void Polyline2DNode::recomputeDisplayList()
{
};

#endif
