/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	TriangleSet2DNode.cpp
*
******************************************************************/

#include <cybergarage/x3d/TriangleSet2DNode.h>
#include <cybergarage/x3d/Graphic3D.h>

using namespace CyberX3D;

static const char verticesFieldString[] = "vertices";

TriangleSet2DNode::TriangleSet2DNode()
{
	setHeaderFlag(false);
	setType(TRIANGLESET2D_NODE);
	
	///////////////////////////
	// Field
	///////////////////////////
	
	// vertices field
	verticesField = new MFVec2f();
	addField(verticesFieldString, verticesField);
}

TriangleSet2DNode::~TriangleSet2DNode()
{
}

////////////////////////////////////////////////
//	Vertices
////////////////////////////////////////////////

MFVec2f *TriangleSet2DNode::getVerticesField()
{
	if(isInstanceNode() == false)
		return verticesField;
	return	(MFVec2f *)getField(verticesFieldString);
}

int TriangleSet2DNode::getNVertices()
{
	return getVerticesField()->getSize();
}

void TriangleSet2DNode::addVertex(float point[])
{
	getVerticesField()->addValue(point);
}

void TriangleSet2DNode::addVertex(float x, float y)
{
	getVerticesField()->addValue(x, y);
}

void TriangleSet2DNode::getVertex(int index, float point[])
{
	getVerticesField()->get1Value(index, point);
}

void TriangleSet2DNode::setVertex(int index, float point[])
{
	getVerticesField()->set1Value(index, point);
}

void TriangleSet2DNode::setVertex(int index, float x, float y)
{
	getVerticesField()->set1Value(index, x, y);
}

void TriangleSet2DNode::removeVertex(int index)
{
	getVerticesField()->remove(index);
}

void TriangleSet2DNode::removeAllVertices()
{
	getVerticesField()->clear();
}

////////////////////////////////////////////////
//	List
////////////////////////////////////////////////

TriangleSet2DNode *TriangleSet2DNode::next()
{
	return (TriangleSet2DNode *)Node::next(getType());
}

TriangleSet2DNode *TriangleSet2DNode::nextTraversal()
{
	return (TriangleSet2DNode *)Node::nextTraversalByType(getType());
}

////////////////////////////////////////////////
//	functions
////////////////////////////////////////////////

bool TriangleSet2DNode::isChildNodeType(Node *node)
{
	return false;
}

void TriangleSet2DNode::initialize()
{
	recomputeBoundingBox();
#ifdef SUPPORT_OPENGL
	recomputeDisplayList();
#endif
}

void TriangleSet2DNode::uninitialize()
{
}

void TriangleSet2DNode::update()
{
}

////////////////////////////////////////////////
//	Infomation
////////////////////////////////////////////////

void TriangleSet2DNode::outputContext(std::ostream &printStream, char *indentString)
{
}

////////////////////////////////////////////////
//	TriangleSet2DNode::recomputeDisplayList
////////////////////////////////////////////////

#ifdef SUPPORT_OPENGL

void TriangleSet2DNode::recomputeDisplayList()
{
};

#endif
