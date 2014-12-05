/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	SoundNode.cpp
*
*	Revisions:
*
*	12/04/02
*		- Added new source field.
*
******************************************************************/

#include <cybergarage/x3d/SoundNode.h>
#include <cybergarage/x3d/AudioClipNode.h>
#include <cybergarage/x3d/MovieTextureNode.h>

using namespace CyberX3D;

static const char sourceFieldString[] = "source";

SoundNode::SoundNode()
{
	setHeaderFlag(false);
	setType(SOUND_NODE);
	
	///////////////////////////
	// Exposed Field
	///////////////////////////
	
	// minFront exposed field
	minFrontField = new SFFloat(1.0f);
	addExposedField(minFrontFieldString, minFrontField);
	
	// maxFront exposed field
	maxFrontField = new SFFloat(10.0f);
	addExposedField(maxFrontFieldString, maxFrontField);
	
	// minBack exposed field
	minBackField = new SFFloat(1.0f);
	addExposedField(minBackFieldString, minBackField);
	
	// maxBack exposed field
	maxBackField = new SFFloat(10.0f);
	addExposedField(maxBackFieldString, maxBackField);
	
	// intensity exposed field
	intensityField = new SFFloat(10.0f);
	addExposedField(intensityFieldString, intensityField);
	
	// priority exposed field
	priorityField = new SFFloat(0.0f);
	addExposedField(priorityFieldString, priorityField);
	
	// direction exposed field
	directionField = new SFVec3f(0.0f, 0.0f, 1.0f);
	addExposedField(directionFieldString, directionField);
	
	// location exposed field
	locationField = new SFVec3f(0.0f, 0.0f, 0.0f);
	addExposedField(locationFieldString, locationField);
	
	// source exposed field
	sourceField = new SFNode();
	addExposedField(sourceFieldString, sourceField);
	
	///////////////////////////
	// Field
	///////////////////////////
	
	// spatialize exposed field
	spatializeField = new SFBool(true);
	addField(spatializeFieldString, spatializeField);
}

SoundNode::~SoundNode()
{
}

////////////////////////////////////////////////
//	Source
////////////////////////////////////////////////

SFNode *SoundNode::getSourceField()
{
	if(isInstanceNode() == false)
		return sourceField;
	return (SFNode *)getExposedField(sourceFieldString);
}

////////////////////////////////////////////////
//	Direction
////////////////////////////////////////////////

SFVec3f *SoundNode::getDirectionField()
{
	if(isInstanceNode() == false)
		return directionField;
	return (SFVec3f *)getExposedField(directionFieldString);
}

void SoundNode::setDirection(float value[])
{
	getDirectionField()->setValue(value);
}

void SoundNode::setDirection(float x, float y, float z)
{
	getDirectionField()->setValue(x, y, z);
}

void SoundNode::getDirection(float value[])
{
	getDirectionField()->getValue(value);
}

////////////////////////////////////////////////
//	Location
////////////////////////////////////////////////

SFVec3f *SoundNode::getLocationField()
{
	if(isInstanceNode() == false)
		return locationField;
	return (SFVec3f *)getExposedField(locationFieldString);
}

void SoundNode::setLocation(float value[])
{
	getLocationField()->setValue(value);
}

void SoundNode::setLocation(float x, float y, float z)
{
	getLocationField()->setValue(x, y, z);
}

void SoundNode::getLocation(float value[])
{
	getLocationField()->getValue(value);
}

////////////////////////////////////////////////
//	MinFront
////////////////////////////////////////////////

SFFloat *SoundNode::getMinFrontField()
{
	if(isInstanceNode() == false)
		return minFrontField;
	return (SFFloat *)getExposedField(minFrontFieldString);
}

void SoundNode::setMinFront(float value)
{
	getMinFrontField()->setValue(value);
}

float SoundNode::getMinFront()
{
	return getMinFrontField()->getValue();
}

////////////////////////////////////////////////
//	MaxFront
////////////////////////////////////////////////

SFFloat *SoundNode::getMaxFrontField()
{
	if(isInstanceNode() == false)
		return maxFrontField;
	return (SFFloat *)getExposedField(maxFrontFieldString);
}

void SoundNode::setMaxFront(float value)
{
	getMaxFrontField()->setValue(value);
}

float SoundNode::getMaxFront()
{
	return getMaxFrontField()->getValue();
}

////////////////////////////////////////////////
//	MinBack
////////////////////////////////////////////////

SFFloat *SoundNode::getMinBackField()
{
	if(isInstanceNode() == false)
		return minBackField;
	return (SFFloat *)getExposedField(minBackFieldString);
}

void SoundNode::setMinBack(float value)
{
	getMinBackField()->setValue(value);
}

float SoundNode::getMinBack()
{
	return getMinBackField()->getValue();
}

////////////////////////////////////////////////
//	MaxBack
////////////////////////////////////////////////

SFFloat *SoundNode::getMaxBackField()
{
	if(isInstanceNode() == false)
		return maxBackField;
	return (SFFloat *)getExposedField(maxBackFieldString);
}

void SoundNode::setMaxBack(float value)
{
	getMaxBackField()->setValue(value);
}

float SoundNode::getMaxBack()
{
	return getMaxBackField()->getValue();
}

////////////////////////////////////////////////
//	Intensity
////////////////////////////////////////////////

SFFloat *SoundNode::getIntensityField()
{
	if(isInstanceNode() == false)
		return intensityField;
	return (SFFloat *)getExposedField(intensityFieldString);
}

void SoundNode::setIntensity(float value)
{
	getIntensityField()->setValue(value);
}

float SoundNode::getIntensity()
{
	return getIntensityField()->getValue();
}

////////////////////////////////////////////////
//	Priority
////////////////////////////////////////////////

SFFloat *SoundNode::getPriorityField()
{
	if(isInstanceNode() == false)
		return priorityField;
	return (SFFloat *)getExposedField(priorityFieldString);
}

void SoundNode::setPriority(float value)
{
	getPriorityField()->setValue(value);
}

float SoundNode::getPriority()
{
	return getPriorityField()->getValue();
}

////////////////////////////////////////////////
//	Spatialize
////////////////////////////////////////////////

SFBool *SoundNode::getSpatializeField()
{
	if(isInstanceNode() == false)
		return spatializeField;
	return (SFBool *)getField(spatializeFieldString);
}

void SoundNode::setSpatialize(bool value)
{
	getSpatializeField()->setValue(value);
}

void SoundNode::setSpatialize(int value)
{
	setSpatialize(value ? true : false);
}

bool SoundNode::getSpatialize()
{
	return getSpatializeField()->getValue();
}

////////////////////////////////////////////////
//	List
////////////////////////////////////////////////

SoundNode *SoundNode::next()
{
	return (SoundNode *)Node::next(getType());
}

SoundNode *SoundNode::nextTraversal()
{
	return (SoundNode *)Node::nextTraversalByType(getType());
}

////////////////////////////////////////////////
//	functions
////////////////////////////////////////////////

bool SoundNode::isChildNodeType(Node *node)
{
	if(node->isAudioClipNode() || node->isMovieTextureNode())
		return true;
	else
		return false;
}

void SoundNode::initialize()
{
}

void SoundNode::uninitialize()
{
}

void SoundNode::update()
{
}

////////////////////////////////////////////////
//	Infomation
////////////////////////////////////////////////

void SoundNode::outputContext(std::ostream &printStream, char *indentString)
{
	SFBool *spatialize = getSpatializeField();
	SFVec3f *direction = getDirectionField();
	SFVec3f *location = getLocationField();
	
	printStream << indentString << "\t" << "direction " << direction << std::endl;
	printStream << indentString << "\t" << "location " << location << std::endl;
	printStream << indentString << "\t" << "maxFront " << getMaxFront() << std::endl;
	printStream << indentString << "\t" << "minFront " << getMinFront() << std::endl;
	printStream << indentString << "\t" << "maxBack " << getMaxBack() << std::endl;
	printStream << indentString << "\t" << "minBack " << getMinBack() << std::endl;
	printStream << indentString << "\t" << "intensity " << getIntensity() << std::endl;
	printStream << indentString << "\t" << "priority " << getPriority() << std::endl;
	printStream << indentString << "\t" << "spatialize " << spatialize << std::endl;
	
	AudioClipNode *aclip = getAudioClipNodes();
	if(aclip != NULL)
	{
		if(aclip->isInstanceNode() == false)
		{
			if(aclip->getName() != NULL && strlen(aclip->getName()))
				printStream << indentString << "\t" << "source " << "DEF " << aclip->getName() << " AudioClip {" << std::endl;
			else
				printStream << indentString << "\t" << "source AudioClip {" << std::endl;
			aclip->Node::outputContext(printStream, indentString, "\t");
			printStream << indentString << "\t" << "}" << std::endl;
		}
		else
			printStream << indentString << "\t" << "source USE " << aclip->getName() << std::endl;
	}
	
	MovieTextureNode *mtexture = getMovieTextureNodes();
	if(mtexture != NULL)
	{
		if(mtexture->isInstanceNode() == false)
		{
			if(mtexture->getName() != NULL && strlen(mtexture->getName()))
				printStream << indentString << "\t" << "source " << "DEF " << mtexture->getName() << " MovieTexture {" << std::endl;
			else
				printStream << indentString << "\t" << "source MovieTexture {" << std::endl;
			mtexture->Node::outputContext(printStream, indentString, "\t");
			printStream << indentString << "\t" << "}" << std::endl;
		}
		else
			printStream << indentString << "\t" << "source USE " << mtexture->getName() << std::endl;
	}
}
