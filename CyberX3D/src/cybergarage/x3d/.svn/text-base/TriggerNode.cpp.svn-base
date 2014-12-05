/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	TriggerNode.cpp
*
******************************************************************/

#include <cybergarage/x3d/TriggerNode.h>

using namespace CyberX3D;

static const char set_triggerTimeFieldString[] = "set_triggerTime";
static const char triggerTimeFieldString[] = "triggerTime";

TriggerNode::TriggerNode()
{
	// triggerTimeField eventIn field
	set_triggerTimeField = new SFTime();
	addEventIn(set_triggerTimeFieldString, set_triggerTimeField);
	
	// triggerTimeField eventOut field
	triggerTimeField = new SFTime();
	addEventOut(triggerTimeFieldString, triggerTimeField);
}

TriggerNode::~TriggerNode()
{
}

////////////////////////////////////////////////
//	SetTriggerTime
////////////////////////////////////////////////

SFTime *TriggerNode::getSetTriggerTimeField()
{
	if(isInstanceNode() == false)
		return set_triggerTimeField;
	return (SFTime *)getEventIn(set_triggerTimeFieldString);
}

void TriggerNode::setSetTriggerTime(double value)
{
	getSetTriggerTimeField()->setValue(value);
}

double TriggerNode::getSetTriggerTime()
{
	return getSetTriggerTimeField()->getValue();
}

////////////////////////////////////////////////
//	TriggerTime
////////////////////////////////////////////////

SFTime *TriggerNode::getTriggerTimeField()
{
	if(isInstanceNode() == false)
		return triggerTimeField;
	return (SFTime *)getEventOut(triggerTimeFieldString);
}

void TriggerNode::setTriggerTime(double value)
{
	getTriggerTimeField()->setValue(value);
}

double TriggerNode::getTriggerTime()
{
	return getTriggerTimeField()->getValue();
}
