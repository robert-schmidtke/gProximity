/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	SoundSourceNode.cpp
*
*	Revisions:
*
*	12/04/02
*		- The first revision.
*
******************************************************************/

#ifdef WIN32
#include <windows.h>
#endif

#include <cybergarage/x3d/SoundSourceNode.h>

using namespace CyberX3D;

SoundSourceNode::SoundSourceNode()
{
	// description exposed field
	descriptionField = new SFString("");
	addExposedField(descriptionFieldString, descriptionField);
	
	// pitch exposed field
	pitchField = new SFFloat(1.0f);
	addExposedField(pitchFieldString, pitchField);
	
	// url exposed field
	urlField = new MFString();
	addExposedField(urlFieldString, urlField);
	
	// isActive eventOut field
	isActiveField = new SFBool(false);
	addEventOut(isActiveFieldString, isActiveField);
	
	// durationChanged eventOut field
	durationChangedField = new SFTime(-1.0f);
	addEventOut(durationFieldString, durationChangedField);
}

SoundSourceNode::~SoundSourceNode()
{
}

////////////////////////////////////////////////
//	Description
////////////////////////////////////////////////

SFString *SoundSourceNode::getDescriptionField()
{
	if(isInstanceNode() == false)
		return descriptionField;
	return (SFString *)getExposedField(descriptionFieldString);
}

void SoundSourceNode::setDescription(char * value)
{
	getDescriptionField()->setValue(value);
}

char *SoundSourceNode::getDescription()
{
	return getDescriptionField()->getValue();
}

////////////////////////////////////////////////
//	Pitch
////////////////////////////////////////////////

SFFloat *SoundSourceNode::getPitchField()
{
	if(isInstanceNode() == false)
		return pitchField;
	return (SFFloat *)getExposedField(pitchFieldString);
}

void SoundSourceNode::setPitch(float value)
{
	getPitchField()->setValue(value);
}

float SoundSourceNode::getPitch()
{
	return getPitchField()->getValue();
}

////////////////////////////////////////////////
//	isActive
////////////////////////////////////////////////

SFBool *SoundSourceNode::getIsActiveField()
{
	if(isInstanceNode() == false)
		return isActiveField;
	return (SFBool *)getEventOut(isActiveFieldString);
}

void SoundSourceNode::setIsActive(bool  value)
{
	getIsActiveField()->setValue(value);
}

bool SoundSourceNode::getIsActive()
{
	return getIsActiveField()->getValue();
}

bool SoundSourceNode::isActive()
{
	return getIsActiveField()->getValue();
}

////////////////////////////////////////////////
//	duration_changed
////////////////////////////////////////////////

SFTime *SoundSourceNode::getDurationChangedField()
{
	if(isInstanceNode() == false)
		return durationChangedField;
	return (SFTime *)getEventOut(durationFieldString);
}

void SoundSourceNode::setDurationChanged(double value)
{
	getDurationChangedField()->setValue(value);
}

double SoundSourceNode::getDurationChanged()
{
	return getDurationChangedField()->getValue();
}

////////////////////////////////////////////////
// Url
////////////////////////////////////////////////

MFString *SoundSourceNode::getUrlField()
{
	if(isInstanceNode() == false)
		return urlField;
	return (MFString *)getExposedField(urlFieldString);
}

void SoundSourceNode::addUrl(char * value)
{
	getUrlField()->addValue(value);
}

int SoundSourceNode::getNUrls()
{
	return getUrlField()->getSize();
}

char *SoundSourceNode::getUrl(int index)
{
	return getUrlField()->get1Value(index);
}

void SoundSourceNode::setUrl(int index, char *urlString)
{
	getUrlField()->set1Value(index, urlString);
}
