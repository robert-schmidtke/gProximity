/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	AnchorNode.cpp
*
*	Revisions;
*
*	11/19/02
*		- Changed the super class from GroupingNode to BoundedGroupingNode.
*
*	11/15/02
*		- Added the follwing new X3D fields.
*			center, enabled
*
******************************************************************/

#include <cybergarage/x3d/AnchorNode.h>

using namespace CyberX3D;

const static char enabledFieldName[] = "enabled";
const static char centerFieldName[] = "center";

AnchorNode::AnchorNode()
{
	setHeaderFlag(false);
	setType(ANCHOR_NODE);
	
	///////////////////////////
	// Exposed Field
	///////////////////////////
	
	// description exposed field
	descriptionField = new SFString("");
	addExposedField(descriptionFieldString, descriptionField);
	
	// parameter exposed field
	parameterField = new MFString();
	addExposedField(parameterFieldString, parameterField);
	
	// url exposed field
	urlField = new MFString();
	addExposedField(urlFieldString, urlField);
	
	///////////////////////////
	// X3D Field
	///////////////////////////
	
	// center exposed field
	centerField = new SFVec3f(0.0f, 0.0f, 0.0f);
	addExposedField(centerFieldName, centerField);
	
	// enabled exposed field
	enabledField = new SFBool(true);
	addExposedField(enabledFieldName, enabledField);
}

AnchorNode::~AnchorNode()
{
}

////////////////////////////////////////////////
//	Description
////////////////////////////////////////////////

SFString *AnchorNode::getDescriptionField()
{
	if(isInstanceNode() == false)
		return descriptionField;
	return (SFString *)getExposedField(descriptionFieldString);
}

void AnchorNode::setDescription(char *value)
{
	getDescriptionField()->setValue(value);
}

char *AnchorNode::getDescription()
{
	return getDescriptionField()->getValue();
}

////////////////////////////////////////////////
// Parameter
////////////////////////////////////////////////

MFString *AnchorNode::getParameterField()
{
	if(isInstanceNode() == false)
		return parameterField;
	return (MFString *)getExposedField(parameterFieldString);
}

void AnchorNode::addParameter(char *value)
{
	getParameterField()->addValue(value);
}

int AnchorNode::getNParameters()
{
	return getParameterField()->getSize();
}

char *AnchorNode::getParameter(int index)
{
	return getParameterField()->get1Value(index);
}

////////////////////////////////////////////////
// Url
////////////////////////////////////////////////

MFString *AnchorNode::getUrlField()
{
	if(isInstanceNode() == false)
		return urlField;
	return (MFString *)getExposedField(urlFieldString);
}

void AnchorNode::addUrl(char *value)
{
	getUrlField()->addValue(value);
}

int AnchorNode::getNUrls()
{
	return getUrlField()->getSize();
}

char *AnchorNode::getUrl(int index)
{
	return getUrlField()->get1Value(index);
}

void AnchorNode::setUrl(int index, char *urlString)
{
	getUrlField()->set1Value(index, urlString);
}

////////////////////////////////////////////////
//	Center (X3D)
////////////////////////////////////////////////

SFVec3f *AnchorNode::getCenterField()
{
	if(isInstanceNode() == false)
		return centerField;
	return (SFVec3f *)getExposedField(centerFieldName);
}

void AnchorNode::setCenter(float value[])
{
	getCenterField()->setValue(value);
}

void AnchorNode::setCenter(float x, float y, float z)
{
	getCenterField()->setValue(x, y, z);
}

void AnchorNode::getCenter(float value[])
{
	getCenterField()->getValue(value);
}

////////////////////////////////////////////////
//	Enabled (X3D)
////////////////////////////////////////////////

SFBool *AnchorNode::getEnabledField()
{
	if(isInstanceNode() == false)
		return enabledField;
	return (SFBool *)getExposedField(enabledFieldName);
}

void AnchorNode::setEnabled(bool value)
{
	getEnabledField()->setValue(value);
}

bool AnchorNode::getEnabled()
{
	return getEnabledField()->getValue();
}

bool AnchorNode::isEnabled()
{
	return getEnabled();
}

////////////////////////////////////////////////
//	List
////////////////////////////////////////////////

AnchorNode *AnchorNode::next()
{
	return (AnchorNode *)Node::next(getType());
}

AnchorNode *AnchorNode::nextTraversal()
{
	return (AnchorNode *)Node::nextTraversalByType(getType());
}

////////////////////////////////////////////////
//	virtual functions
////////////////////////////////////////////////

bool AnchorNode::isChildNodeType(Node *node)
{
	if(node->isCommonNode() || node->isBindableNode() || node->isInterpolatorNode() || node->isSensorNode() || node->isGroupingNode() || node->isSpecialGroupNode())
		return true;
	else
		return false;
}

void AnchorNode::initialize()
{
	recomputeBoundingBox();
}

void AnchorNode::uninitialize()
{
}

void AnchorNode::update()
{
}

void AnchorNode::outputContext(std::ostream &printStream, char *indentString)
{
	SFString *description = getDescriptionField();
	printStream << indentString << "\t" << "description " << description << std::endl;
	
	if(0 < getNParameters())
	{
		MFString *parameter = getParameterField();
		printStream << indentString << "\t" << "parameter ["  << std::endl;
		parameter->MField::outputContext(printStream, indentString, "\t\t");
		printStream << indentString << "\t" << "]" << std::endl;
	}
	
	if(0 < getNUrls())
	{
		MFString *url = getUrlField();
		printStream << indentString << "\t" << "url [" << std::endl;
		url->MField::outputContext(printStream, indentString, "\t\t");
		printStream << indentString << "\t" << "]" << std::endl;
	}
}
