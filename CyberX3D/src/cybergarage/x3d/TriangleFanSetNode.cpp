/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	TriangleFanSetNode.cpp
*
*	Revisions;
*
*	11/27/02
*		- The first revision.
*
******************************************************************/

#include <cybergarage/x3d/TriangleFanSetNode.h>
#include <cybergarage/x3d/Graphic3D.h>

using namespace CyberX3D;

static const char fanCountFieldString[] = "fanCount";

TriangleFanSetNode::TriangleFanSetNode()
{
	setHeaderFlag(false);
	setType(TRIANGLEFANSET_NODE);
	
	///////////////////////////
	// Field
	///////////////////////////
	
	// fanCount  field
	fanCountField = new MFInt32();
	fanCountField->setName(fanCountFieldString);
	addField(fanCountField);
}

TriangleFanSetNode::~TriangleFanSetNode()
{
}

////////////////////////////////////////////////
// FanCount
////////////////////////////////////////////////

MFInt32 *TriangleFanSetNode::getFanCountField()
{
	if(isInstanceNode() == false)
		return fanCountField;
	return (MFInt32 *)getField(fanCountFieldString);
}

void TriangleFanSetNode::addFanCount(int value)
{
	getFanCountField()->addValue(value);
}

int TriangleFanSetNode::getNFanCountes()
{
	return getFanCountField()->getSize();
}

int TriangleFanSetNode::getFanCount(int index)
{
	return getFanCountField()->get1Value(index);
}

////////////////////////////////////////////////
//	List
////////////////////////////////////////////////

TriangleFanSetNode *TriangleFanSetNode::next()
{
	return (TriangleFanSetNode *)Node::next(getType());
}

TriangleFanSetNode *TriangleFanSetNode::nextTraversal()
{
	return (TriangleFanSetNode *)Node::nextTraversalByType(getType());
}

////////////////////////////////////////////////
//	functions
////////////////////////////////////////////////

bool TriangleFanSetNode::isChildNodeType(Node *node)
{
	if(node->isColorNode() || node->isCoordinateNode() || node->isNormalNode() || node->isTextureCoordinateNode())
		return true;
	return false;
}

void TriangleFanSetNode::uninitialize()
{
}

void TriangleFanSetNode::update()
{
}

////////////////////////////////////////////////
//	Infomation
////////////////////////////////////////////////

void TriangleFanSetNode::outputContext(std::ostream &printStream, char *indentString)
{
}

////////////////////////////////////////////////
//	TriangleFanSetNode::initialize
////////////////////////////////////////////////

void TriangleFanSetNode::initialize()
{
}


////////////////////////////////////////////////////////////
//	getNPolygons
////////////////////////////////////////////////////////////

int TriangleFanSetNode::getNPolygons()
{
	int nFans = getNFanCountes();
	return nFans - 3;
}

////////////////////////////////////////////////
//	TriangleFanSetNode::recomputeDisplayList
////////////////////////////////////////////////

#ifdef SUPPORT_OPENGL

void TriangleFanSetNode::recomputeDisplayList()
{
}

#endif


