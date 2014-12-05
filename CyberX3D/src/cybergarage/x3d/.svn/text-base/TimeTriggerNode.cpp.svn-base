/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	TimeTriggerNode.cpp
*
******************************************************************/

#include <cybergarage/x3d/TimeTriggerNode.h>

using namespace CyberX3D;

static const char integerKeyFieldString[] = "integerKey";
static const char set_booleanFieldString[] = "set_boolean";
static const char triggerTimeFieldString[] = "triggerTime";

TimeTriggerNode::TimeTriggerNode()
{
	setHeaderFlag(false);
	setType(TIMETRIGGER_NODE);
	
	// set_boolean eventIn field
	set_booleanField = new SFBool(false);
	addEventIn(set_booleanFieldString, set_booleanField);
	
	// triggerTime eventIOut field
	triggerTimeField = new SFTime();
	addEventOut(triggerTimeFieldString, triggerTimeField);
}

TimeTriggerNode::~TimeTriggerNode()
{
}

////////////////////////////////////////////////
//	setBoolean
////////////////////////////////////////////////

SFBool *TimeTriggerNode::getBooleanField()
{
	if(isInstanceNode() == false)
		return set_booleanField;
	return (SFBool*)getEventIn(set_booleanFieldString);
}

void TimeTriggerNode::setBoolean(bool value)
{
	getBooleanField()->setValue(value);
}

bool TimeTriggerNode::getBoolean()
{
	return getBooleanField()->getValue();
}

bool TimeTriggerNode::isBoolean()
{
	return getBooleanField()->getValue();
}

////////////////////////////////////////////////
//	TriggerTime
////////////////////////////////////////////////

SFTime *TimeTriggerNode::getTriggerTimeField()
{
	if(isInstanceNode() == false)
		return triggerTimeField;
	return (SFTime*)getEventOut(triggerTimeFieldString);
}

void TimeTriggerNode::setTriggerTime(double value)
{
	getTriggerTimeField()->setValue(value);
}

double TimeTriggerNode::getTriggerTime()
{
	return getTriggerTimeField()->getValue();
}

////////////////////////////////////////////////
//	functions
////////////////////////////////////////////////

bool TimeTriggerNode::isChildNodeType(Node *node)
{
	return false;
}

void TimeTriggerNode::initialize()
{
}

void TimeTriggerNode::uninitialize()
{
}

void TimeTriggerNode::update()
{
}

////////////////////////////////////////////////
//	Output
////////////////////////////////////////////////

void TimeTriggerNode::outputContext(std::ostream &printStream, char *indentString)
{
}

////////////////////////////////////////////////
//	List
////////////////////////////////////////////////

TimeTriggerNode *TimeTriggerNode::next()
{
	return (TimeTriggerNode *)Node::next(getType());
}

TimeTriggerNode *TimeTriggerNode::nextTraversal()
{
	return (TimeTriggerNode *)Node::nextTraversalByType(getType());
}




