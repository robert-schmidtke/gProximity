/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2003
*
*	File:	BooleanToggleNode.cpp
*
*	Revisions;
*
*	01/08/03
*		- first revision
*
******************************************************************/

#include <cybergarage/x3d/BooleanToggleNode.h>

using namespace CyberX3D;

static const char set_booleanFieldString[] = "set_boolean";
static const char toggleFieldString[] = "toggle";

BooleanToggleNode::BooleanToggleNode()
{
	setHeaderFlag(false);
	setType(BOOLEANTOGGLE_NODE);
	
	// set_booleanEvent eventIn field
	set_booleanField = new SFBool();
	addEventIn(set_booleanFieldString, set_booleanField);
	
	// toggle eventIn field
	toggleField = new SFBool(false);
	addExposedField(toggleFieldString, toggleField);
}

BooleanToggleNode::~BooleanToggleNode()
{
}

////////////////////////////////////////////////
//	setBoolean
////////////////////////////////////////////////

SFBool *BooleanToggleNode::getBooleanField()
{
	if(isInstanceNode() == false)
		return set_booleanField;
	return (SFBool*)getEventIn(set_booleanFieldString);
}

void BooleanToggleNode::setBoolean(bool value)
{
	getBooleanField()->setValue(value);
}

bool BooleanToggleNode::getBoolean()
{
	return getBooleanField()->getValue();
}

bool BooleanToggleNode::isBoolean()
{
	return getBooleanField()->getValue();
}

////////////////////////////////////////////////
//	toggle
////////////////////////////////////////////////

SFBool *BooleanToggleNode::getToggleField()
{
	if(isInstanceNode() == false)
		return toggleField;
	return (SFBool*)getExposedField(toggleFieldString);
}

void BooleanToggleNode::setToggle(bool value)
{
	getToggleField()->setValue(value);
}

bool BooleanToggleNode::getToggle()
{
	return getToggleField()->getValue();
}

bool BooleanToggleNode::isToggle()
{
	return getToggleField()->getValue();
}

////////////////////////////////////////////////
//	functions
////////////////////////////////////////////////

bool BooleanToggleNode::isChildNodeType(Node *node)
{
	return false;
}

void BooleanToggleNode::initialize()
{
}

void BooleanToggleNode::uninitialize()
{
}

void BooleanToggleNode::update()
{
}

////////////////////////////////////////////////
//	Output
////////////////////////////////////////////////

void BooleanToggleNode::outputContext(std::ostream &printStream, char *indentString)
{
}

////////////////////////////////////////////////
//	List
////////////////////////////////////////////////

BooleanToggleNode *BooleanToggleNode::next()
{
	return (BooleanToggleNode *)Node::next(getType());
}

BooleanToggleNode *BooleanToggleNode::nextTraversal()
{
	return (BooleanToggleNode *)Node::nextTraversalByType(getType());
}

