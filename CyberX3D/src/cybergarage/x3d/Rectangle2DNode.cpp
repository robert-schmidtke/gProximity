/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	Rectangle2DNode.cpp
*
******************************************************************/

#include <cybergarage/x3d/Rectangle2DNode.h>
#include <cybergarage/x3d/Graphic3D.h>

using namespace CyberX3D;

static const char isFilledFieldString[] = "isFilled";

Rectangle2DNode::Rectangle2DNode()
{
	setHeaderFlag(false);
	setType(RECTANGLE2D_NODE);
	
	///////////////////////////
	// Field
	///////////////////////////
	
	// size field
	sizeField = new MFVec2f();
	addField(sizeFieldString, sizeField);
	
	// isFilled exposed field
	isFilledField = new SFBool(true);
	addExposedField(isFilledFieldString, isFilledField);
}

Rectangle2DNode::~Rectangle2DNode()
{
}

////////////////////////////////////////////////
//	Size
////////////////////////////////////////////////

MFVec2f *Rectangle2DNode::getSizeField()
{
	if(isInstanceNode() == false)
		return sizeField;
	return	(MFVec2f *)getField(sizeFieldString);
}

int Rectangle2DNode::getNSize()
{
	return getSizeField()->getSize();
}

void Rectangle2DNode::addSize(float point[])
{
	getSizeField()->addValue(point);
}

void Rectangle2DNode::addSize(float x, float y)
{
	getSizeField()->addValue(x, y);
}

void Rectangle2DNode::getSize(int index, float point[])
{
	getSizeField()->get1Value(index, point);
}

void Rectangle2DNode::setSize(int index, float point[])
{
	getSizeField()->set1Value(index, point);
}

void Rectangle2DNode::setSize(int index, float x, float y)
{
	getSizeField()->set1Value(index, x, y);
}

void Rectangle2DNode::removeSize(int index)
{
	getSizeField()->remove(index);
}

void Rectangle2DNode::removeAllSize()
{
	getSizeField()->clear();
}

////////////////////////////////////////////////
//	side
////////////////////////////////////////////////

SFBool *Rectangle2DNode::getIsFilledField()
{
	if(isInstanceNode() == false)
		return isFilledField;
	return (SFBool *)getExposedField(isFilledFieldString);
}

void Rectangle2DNode::setIsFilled(bool value)
{
	getIsFilledField()->setValue(value);
}

void Rectangle2DNode::setIsFilled(int value)
{
	setIsFilled(value ? true : false);
}

bool Rectangle2DNode::getIsFilled()
{
	return getIsFilledField()->getValue();
}

bool Rectangle2DNode::isFilled()
{
	return getIsFilledField()->getValue();
}

////////////////////////////////////////////////
//	List
////////////////////////////////////////////////

Rectangle2DNode *Rectangle2DNode::next()
{
	return (Rectangle2DNode *)Node::next(getType());
}

Rectangle2DNode *Rectangle2DNode::nextTraversal()
{
	return (Rectangle2DNode *)Node::nextTraversalByType(getType());
}

////////////////////////////////////////////////
//	functions
////////////////////////////////////////////////

bool Rectangle2DNode::isChildNodeType(Node *node)
{
	return false;
}

void Rectangle2DNode::initialize()
{
	recomputeBoundingBox();
#ifdef SUPPORT_OPENGL
	recomputeDisplayList();
#endif
}

void Rectangle2DNode::uninitialize()
{
}

void Rectangle2DNode::update()
{
}

////////////////////////////////////////////////
//	Infomation
////////////////////////////////////////////////

void Rectangle2DNode::outputContext(std::ostream &printStream, char *indentString)
{
}

////////////////////////////////////////////////
//	Rectangle2DNode::recomputeDisplayList
////////////////////////////////////////////////

#ifdef SUPPORT_OPENGL

void Rectangle2DNode::recomputeDisplayList()
{
};

#endif
