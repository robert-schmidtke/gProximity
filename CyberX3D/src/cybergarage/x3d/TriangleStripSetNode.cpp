/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	TriangleStripSetNode.cpp
*
*	Revisions;
*
*	11/27/02
*		- The first revision.
*
******************************************************************/

#include <cybergarage/x3d/TriangleStripSetNode.h>
#include <cybergarage/x3d/Graphic3D.h>

using namespace CyberX3D;

static const char stripCountFieldString[] = "stripCount";

TriangleStripSetNode::TriangleStripSetNode()
{
	setHeaderFlag(false);
	setType(TRIANGLESTRIPSET_NODE);
	
	///////////////////////////
	// Field
	///////////////////////////
	
	// stripCount  field
	stripCountField = new MFInt32();
	stripCountField->setName(stripCountFieldString);
	addField(stripCountField);
}

TriangleStripSetNode::~TriangleStripSetNode()
{
}

////////////////////////////////////////////////
// StripCount
////////////////////////////////////////////////

MFInt32 *TriangleStripSetNode::getStripCountField()
{
	if(isInstanceNode() == false)
		return stripCountField;
	return (MFInt32 *)getField(stripCountFieldString);
}

void TriangleStripSetNode::addStripCount(int value)
{
	getStripCountField()->addValue(value);
}

int TriangleStripSetNode::getNStripCountes()
{
	return getStripCountField()->getSize();
}

int TriangleStripSetNode::getStripCount(int index)
{
	return getStripCountField()->get1Value(index);
}

////////////////////////////////////////////////
//	List
////////////////////////////////////////////////

TriangleStripSetNode *TriangleStripSetNode::next()
{
	return (TriangleStripSetNode *)Node::next(getType());
}

TriangleStripSetNode *TriangleStripSetNode::nextTraversal()
{
	return (TriangleStripSetNode *)Node::nextTraversalByType(getType());
}

////////////////////////////////////////////////
//	functions
////////////////////////////////////////////////

bool TriangleStripSetNode::isChildNodeType(Node *node)
{
	if(node->isColorNode() || node->isCoordinateNode() || node->isNormalNode() || node->isTextureCoordinateNode())
		return true;
	return false;
}

void TriangleStripSetNode::uninitialize()
{
}

void TriangleStripSetNode::update()
{
}

////////////////////////////////////////////////
//	Infomation
////////////////////////////////////////////////

void TriangleStripSetNode::outputContext(std::ostream &printStream, char *indentString)
{
}

////////////////////////////////////////////////
//	TriangleStripSetNode::initialize
////////////////////////////////////////////////

void TriangleStripSetNode::initialize()
{
}

////////////////////////////////////////////////////////////
//	getNPolygons
////////////////////////////////////////////////////////////

int TriangleStripSetNode::getNPolygons()
{
	int nStrips = getNStripCountes();
	return nStrips - 2;
}

////////////////////////////////////////////////
//	recomputeDisplayList
////////////////////////////////////////////////

#ifdef SUPPORT_OPENGL

void TriangleStripSetNode::recomputeDisplayList()
{
}

#endif


