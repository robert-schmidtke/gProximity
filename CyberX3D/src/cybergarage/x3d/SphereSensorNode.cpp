/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	SphereSensorNode.cpp
*
*	Revisions:
*
*	12/08/02
*		- Changed the super class from SensorNode to DragSensorNode.
*		- Moved the following fields to DragSensorNode.
*			autoOffset, trackPoint
*
******************************************************************/

#include <cybergarage/x3d/SphereSensorNode.h>

using namespace CyberX3D;

SphereSensorNode::SphereSensorNode()
{
	setHeaderFlag(false);
	setType(SPHERESENSOR_NODE);
	
	// offset exposed field
	offsetField = new SFRotation(0.0f, 0.0f, 1.0f, 0.0f);
	addExposedField(offsetFieldString, offsetField);
	
	// rotation eventOut field
	rotationField = new SFRotation(0.0f, 0.0f, 1.0f, 0.0f);
	addEventOut(rotationFieldString, rotationField);
}

SphereSensorNode::~SphereSensorNode()
{
}

////////////////////////////////////////////////
//	Offset
////////////////////////////////////////////////

SFRotation *SphereSensorNode::getOffsetField()
{
	if(isInstanceNode() == false)
		return offsetField;
	return (SFRotation *)getExposedField(offsetFieldString);
}

void SphereSensorNode::setOffset(float value[])
{
	getOffsetField()->setValue(value);
}

void SphereSensorNode::getOffset(float value[])
{
	getOffsetField()->getValue(value);
}

////////////////////////////////////////////////
//	Rotation
////////////////////////////////////////////////

SFRotation *SphereSensorNode::getRotationChangedField()
{
	if(isInstanceNode() == false)
		return rotationField;
	return (SFRotation *)getEventOut(rotationFieldString);
}

void SphereSensorNode::setRotationChanged(float value[])
{
	getRotationChangedField()->setValue(value);
}

void SphereSensorNode::setRotationChanged(float x, float y, float z, float rot)
{
	getRotationChangedField()->setValue(x, y, z, rot);
}

void SphereSensorNode::getRotationChanged(float value[])
{
	getRotationChangedField()->getValue(value);
}

////////////////////////////////////////////////
//	List
////////////////////////////////////////////////

SphereSensorNode *SphereSensorNode::next()
{
	return (SphereSensorNode *)Node::next(getType());
}

SphereSensorNode *SphereSensorNode::nextTraversal()
{
	return (SphereSensorNode *)Node::nextTraversalByType(getType());
}

////////////////////////////////////////////////
//	functions
////////////////////////////////////////////////

bool SphereSensorNode::isChildNodeType(Node *node)
{
	return false;
}

void SphereSensorNode::initialize()
{
	setIsActive(false);
}

void SphereSensorNode::uninitialize()
{
}

void SphereSensorNode::update()
{
}

////////////////////////////////////////////////
//	Infomation
////////////////////////////////////////////////

void SphereSensorNode::outputContext(std::ostream &printStream, char *indentString)
{
	SFBool *autoOffset = getAutoOffsetField();
	SFBool *enabled = getEnabledField();
	SFRotation *offset = getOffsetField();
	
	printStream << indentString << "\t" << "autoOffset " << autoOffset << std::endl;
	printStream << indentString << "\t" << "enabled " << enabled << std::endl;
	printStream << indentString << "\t" << "offset " << offset << std::endl;
}
