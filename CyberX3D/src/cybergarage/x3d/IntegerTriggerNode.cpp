/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	IntegerTriggerNode.cpp
*
******************************************************************/

#include <cybergarage/x3d/IntegerTriggerNode.h>

using namespace CyberX3D;

static const char integerKeyFieldString[] = "integerKey";
static const char set_booleanFieldString[] = "set_boolean";
static const char triggerValueFieldString[] = "triggerValue";

IntegerTriggerNode::IntegerTriggerNode()
{
	setHeaderFlag(false);
	setType(INTEGERTRIGGER_NODE);
	
	// set_boolean eventIn field
	set_booleanField = new SFBool(false);
	addEventIn(set_booleanFieldString, set_booleanField);
	
	// integerKey exposed field
	integerKeyField = new SFInt32(-1);
	addExposedField(integerKeyFieldString, integerKeyField);
	
	// triggerValue eventIn field
	triggerValueField = new SFInt32();
	addEventOut(triggerValueFieldString, triggerValueField);
}

IntegerTriggerNode::~IntegerTriggerNode()
{
}

////////////////////////////////////////////////
//	setBoolean
////////////////////////////////////////////////

SFBool *IntegerTriggerNode::getBooleanField()
{
	if(isInstanceNode() == false)
		return set_booleanField;
	return (SFBool*)getEventIn(set_booleanFieldString);
}

void IntegerTriggerNode::setBoolean(bool value)
{
	getBooleanField()->setValue(value);
}

bool IntegerTriggerNode::getBoolean()
{
	return getBooleanField()->getValue();
}

bool IntegerTriggerNode::isBoolean()
{
	return getBooleanField()->getValue();
}

////////////////////////////////////////////////
//	IntegerKey
////////////////////////////////////////////////

SFInt32 *IntegerTriggerNode::getIntegerKeyField()
{
	if(isInstanceNode() == false)
		return integerKeyField;
	return (SFInt32*)getExposedField(integerKeyFieldString);
}

void IntegerTriggerNode::setIntegerKey(int value)
{
	getIntegerKeyField()->setValue(value);
}

int IntegerTriggerNode::getIntegerKey()
{
	return getIntegerKeyField()->getValue();
}

////////////////////////////////////////////////
//	TriggerValue
////////////////////////////////////////////////

SFInt32 *IntegerTriggerNode::getTriggerValueField()
{
	if(isInstanceNode() == false)
		return triggerValueField;
	return (SFInt32*)getEventOut(triggerValueFieldString);
}

void IntegerTriggerNode::setTriggerValue(int value)
{
	getTriggerValueField()->setValue(value);
}

int IntegerTriggerNode::getTriggerValue()
{
	return getTriggerValueField()->getValue();
}

////////////////////////////////////////////////
//	functions
////////////////////////////////////////////////

bool IntegerTriggerNode::isChildNodeType(Node *node)
{
	return false;
}

void IntegerTriggerNode::initialize()
{
}

void IntegerTriggerNode::uninitialize()
{
}

void IntegerTriggerNode::update()
{
}

////////////////////////////////////////////////
//	Output
////////////////////////////////////////////////

void IntegerTriggerNode::outputContext(std::ostream &printStream, char *indentString)
{
}

////////////////////////////////////////////////
//	List
////////////////////////////////////////////////

IntegerTriggerNode *IntegerTriggerNode::next()
{
	return (IntegerTriggerNode *)Node::next(getType());
}

IntegerTriggerNode *IntegerTriggerNode::nextTraversal()
{
	return (IntegerTriggerNode *)Node::nextTraversalByType(getType());
}




