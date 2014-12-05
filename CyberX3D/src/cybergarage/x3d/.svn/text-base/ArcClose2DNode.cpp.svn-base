/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	ArcClose2DNode.cpp
*
******************************************************************/

#include <cybergarage/x3d/ArcClose2DNode.h>
#include <cybergarage/x3d/Graphic3D.h>

using namespace CyberX3D;

static const char closureTypeFieldString[] = "closureType";

ArcClose2DNode::ArcClose2DNode()
{
	setHeaderFlag(false);
	setType(ARCCLOSE2D_NODE);
	
	///////////////////////////
	// Exposed Field
	///////////////////////////
	
	// closureType exposed field
	closureTypeField = new SFString("PIE");
	addField(closureTypeFieldString, closureTypeField);
}

ArcClose2DNode::~ArcClose2DNode()
{
}

////////////////////////////////////////////////
//	ClosureType
////////////////////////////////////////////////

SFString *ArcClose2DNode::getClosureTypeField()
{
	if(isInstanceNode() == false)
		return closureTypeField;
	return (SFString *)getField(closureTypeFieldString);
}

void ArcClose2DNode::setClosureType(const char *value)
{
	getClosureTypeField()->setValue(value);
}

char *ArcClose2DNode::getClosureType()
{
	return getClosureTypeField()->getValue();
}

////////////////////////////////////////////////
//	List
////////////////////////////////////////////////

ArcClose2DNode *ArcClose2DNode::next()
{
	return (ArcClose2DNode *)Node::next(getType());
}

ArcClose2DNode *ArcClose2DNode::nextTraversal()
{
	return (ArcClose2DNode *)Node::nextTraversalByType(getType());
}

////////////////////////////////////////////////
//	functions
////////////////////////////////////////////////

bool ArcClose2DNode::isChildNodeType(Node *node)
{
	return false;
}

void ArcClose2DNode::initialize()
{
#ifdef SUPPORT_OPENGL
	recomputeDisplayList();
#endif
}

void ArcClose2DNode::uninitialize()
{
}

void ArcClose2DNode::update()
{
}

////////////////////////////////////////////////
//	outputContext
////////////////////////////////////////////////

void ArcClose2DNode::outputContext(std::ostream &printStream, char *indentString)
{
}

////////////////////////////////////////////////
//	ArcClose2DNode::recomputeDisplayList
////////////////////////////////////////////////

#ifdef SUPPORT_OPENGL

void ArcClose2DNode::recomputeDisplayList()
{
};

#endif
