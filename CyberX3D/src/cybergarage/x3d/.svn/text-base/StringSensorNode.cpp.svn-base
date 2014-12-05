/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	StringSensorNode.cpp
*
******************************************************************/

#include <cybergarage/x3d/StringSensorNode.h>

using namespace CyberX3D;

static const char deletionCharacterFieldString[] = "deletionCharacter";
static const char enteredTextFieldString[] = "enteredText";
static const char finalTextFieldString[] = "finalText";
static const char profileFieldString[] = "profile";
static const char terminationTextFieldString[] = "terminationText";

StringSensorNode::StringSensorNode()
{
	setHeaderFlag(false);
	setType(STRINGSENSOR_NODE);
	
	// deletionCharacter eventOut field
	deletionCharacterField = new SFInt32(0);
	addEventOut(deletionCharacterFieldString, deletionCharacterField);
	
	// profile eventOut field
	profileField = new SFInt32(0);
	addEventOut(profileFieldString, profileField);
	
	// enteredText field
	enteredTextField = new SFString("");
	addEventOut(enteredTextFieldString, enteredTextField);
	
	// finalText field
	finalTextField = new SFString("");
	addEventOut(finalTextFieldString, finalTextField);
	
	// terminationText field
	terminationTextField = new SFString("");
	addEventOut(terminationTextFieldString, terminationTextField);
}

StringSensorNode::~StringSensorNode()
{
}

////////////////////////////////////////////////
//	DeletionCharacter
////////////////////////////////////////////////

SFInt32 *StringSensorNode::getDeletionCharacterField()
{
	if(isInstanceNode() == false)
		return deletionCharacterField;
	return (SFInt32 *)getEventOut(deletionCharacterFieldString);
}

void StringSensorNode::setDeletionCharacter(int value)
{
	getDeletionCharacterField()->setValue(value);
}

int StringSensorNode::getDeletionCharacter()
{
	return getDeletionCharacterField()->getValue();
}

////////////////////////////////////////////////
//	Profile
////////////////////////////////////////////////

SFInt32 *StringSensorNode::getProfileField()
{
	if(isInstanceNode() == false)
		return profileField;
	return (SFInt32 *)getEventOut(profileFieldString);
}

void StringSensorNode::setProfile(int value)
{
	getProfileField()->setValue(value);
}

int StringSensorNode::getProfile()
{
	return getProfileField()->getValue();
}

////////////////////////////////////////////////
//	EnteredText
////////////////////////////////////////////////

SFString *StringSensorNode::getEnteredTextField()
{
	if(isInstanceNode() == false)
		return enteredTextField;
	return (SFString *)getEventOut(enteredTextFieldString);
}

void StringSensorNode::setEnteredText(const char *value)
{
	getEnteredTextField()->setValue(value);
}

char *StringSensorNode::getEnteredText()
{
	return getEnteredTextField()->getValue();
}

////////////////////////////////////////////////
//	FinalText
////////////////////////////////////////////////

SFString *StringSensorNode::getFinalTextField()
{
	if(isInstanceNode() == false)
		return finalTextField;
	return (SFString *)getEventOut(finalTextFieldString);
}

void StringSensorNode::setFinalText(const char *value)
{
	getFinalTextField()->setValue(value);
}

char *StringSensorNode::getFinalText()
{
	return getFinalTextField()->getValue();
}

////////////////////////////////////////////////
//	TerminationText
////////////////////////////////////////////////

SFString *StringSensorNode::getTerminationTextField()
{
	if(isInstanceNode() == false)
		return terminationTextField;
	return (SFString *)getEventOut(terminationTextFieldString);
}

void StringSensorNode::setTerminationText(const char *value)
{
	getTerminationTextField()->setValue(value);
}

char *StringSensorNode::getTerminationText()
{
	return getTerminationTextField()->getValue();
}

////////////////////////////////////////////////
//	List
////////////////////////////////////////////////

StringSensorNode *StringSensorNode::next()
{
	return (StringSensorNode *)Node::next(getType());
}

StringSensorNode *StringSensorNode::nextTraversal()
{
	return (StringSensorNode *)Node::nextTraversalByType(getType());
}

////////////////////////////////////////////////
//	functions
////////////////////////////////////////////////

bool StringSensorNode::isChildNodeType(Node *node)
{
	return false;
}

void StringSensorNode::initialize()
{
}

void StringSensorNode::uninitialize()
{
}

void StringSensorNode::update()
{
}

////////////////////////////////////////////////
//	Infomation
////////////////////////////////////////////////

void StringSensorNode::outputContext(std::ostream &printStream, char *indentString)
{
}
