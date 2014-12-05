/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File: AudioClipNode.cpp
*
*	Revisions:
*
*	12/04/02
*		- Changed the super class from Node to SoundSourceNode.
*
******************************************************************/

#ifdef WIN32
#include <windows.h>
#endif

#include <cybergarage/x3d/AudioClipNode.h>

using namespace CyberX3D;

static const char isPlayingPrivateFieldName[] = "isPlaying";

AudioClipNode::AudioClipNode()
{
	setHeaderFlag(false);
	setType(AUDIOCLIP_NODE);
	
	// loop exposed field
	loopField = new SFBool(false);
	addExposedField(loopFieldString, loopField);
	
	// startTime exposed field
	startTimeField = new SFTime(0.0f);
	addExposedField(startTimeFieldString, startTimeField);
	
	// stopTime exposed field
	stopTimeField = new SFTime(0.0f);
	addExposedField(stopTimeFieldString, stopTimeField);
}

AudioClipNode::~AudioClipNode()
{
}

////////////////////////////////////////////////
//	Loop
////////////////////////////////////////////////

SFBool *AudioClipNode::getLoopField()
{
	if(isInstanceNode() == false)
		return loopField;
	return (SFBool *)getExposedField(loopFieldString);
}

void AudioClipNode::setLoop(bool value)
{
	getLoopField()->setValue(value);
}

void AudioClipNode::setLoop(int value)
{
	setLoop(value ? true : false);
}

bool AudioClipNode::getLoop()
{
	return getLoopField()->getValue();
}

bool AudioClipNode::isLoop()
{
	return getLoop();
}

////////////////////////////////////////////////
//	Start time
////////////////////////////////////////////////

SFTime *AudioClipNode::getStartTimeField()
{
	if(isInstanceNode() == false)
		return startTimeField;
	return (SFTime *)getExposedField(startTimeFieldString);
}

void AudioClipNode::setStartTime(double value)
{
	getStartTimeField()->setValue(value);
}

double AudioClipNode::getStartTime()
{
	return getStartTimeField()->getValue();
}

////////////////////////////////////////////////
//	Stop time
////////////////////////////////////////////////

SFTime *AudioClipNode::getStopTimeField()
{
	if(isInstanceNode() == false)
		return stopTimeField;
	return (SFTime *)getExposedField(stopTimeFieldString);
}

void AudioClipNode::setStopTime(double value)
{
	getStopTimeField()->setValue(value);
}

double AudioClipNode::getStopTime()
{
	return getStopTimeField()->getValue();
}

////////////////////////////////////////////////
//	List
////////////////////////////////////////////////

AudioClipNode *AudioClipNode::next()
{
	return (AudioClipNode *)Node::next(getType());
}

AudioClipNode *AudioClipNode::nextTraversal()
{
	return (AudioClipNode *)Node::nextTraversalByType(getType());
}

////////////////////////////////////////////////
//	Virutual functions
////////////////////////////////////////////////

bool AudioClipNode::isChildNodeType(Node *node)
{
	return false;
}

void AudioClipNode::outputContext(std::ostream &printStream, char *indentString)
{
	SFString *description = getDescriptionField();
	printStream << indentString << "\t" << "description " << description << std::endl;
	
	printStream << indentString << "\t" << "pitch " << getPitch() << std::endl;
	printStream << indentString << "\t" << "startTime " << getStartTime() << std::endl;
	printStream << indentString << "\t" << "stopTime " << getStopTime() << std::endl;
	
	SFBool *loop = getLoopField();
	printStream << indentString << "\t" << "loop " << loop << std::endl;
	
	if(0 < getNUrls())
	{
		MFString *url = getUrlField();
		printStream << indentString << "\t" << "url [" << std::endl;
		url->MField::outputContext(printStream, indentString, "\t\t");
		printStream << indentString << "\t" << "]" << std::endl;
	}
}

////////////////////////////////////////////////
//	Time
////////////////////////////////////////////////

void AudioClipNode::setCurrentTime(double time)
{
	mCurrentTime = time;
}

double AudioClipNode::getCurrentTime()
{
	return mCurrentTime;
}

////////////////////////////////////////////////
//	PlayAudioClip
////////////////////////////////////////////////

static void PlayAudioClip(AudioClipNode *ac)
{
#ifdef SUPPORT_SOUND
	if(0 < ac->getNUrls())
	{
		char *filename = ac->getUrl(0);
		if(filename)
		{
#ifdef WIN32
			PlaySound(filename, NULL, SND_FILENAME | SND_ASYNC);
#endif
		}
	}
#endif
}

////////////////////////////////////////////////
//	StopAudioClip
////////////////////////////////////////////////

static void StopAudioClip(AudioClipNode *ac)
{
}

////////////////////////////////////////////////
//	AudioClipNode::initialize
////////////////////////////////////////////////

void AudioClipNode::initialize()
{
	setIsActive(false);
	StopAudioClip(this);
	setCurrentTime(-1.0);
}

////////////////////////////////////////////////
//	AudioClipNode::uninitialize
////////////////////////////////////////////////

void AudioClipNode::uninitialize()
{
	StopAudioClip(this);
}

////////////////////////////////////////////////
//	AudioClipNode::update
////////////////////////////////////////////////

void AudioClipNode::update()
{
	double currentTime = getCurrentTime();
	
	if(currentTime < 0.0)
		currentTime = GetCurrentSystemTime();
		
	double startTime = getStartTime();
	double stopTime = getStopTime();
	
	bool bActive	= isActive();
	bool bLoop		= isLoop();
	
	if(bActive == false)
	{
		if(currentTime <= startTime)
		{
			if(bLoop == true && stopTime <= startTime)
				bActive = true;
			else if(bLoop == true && startTime < stopTime)
				bActive = true;
			else if(bLoop == false && startTime < stopTime)
				bActive = true;
				
			if(bActive == true)
			{
				setIsActive(true);
				sendEvent(getIsActiveField());
				PlayAudioClip(this);
				setIsActive(false);
			}
		}
	}
	
	currentTime = GetCurrentSystemTime();
	setCurrentTime(currentTime);
	
	/*
		if (bActive == true) {
			if (bLoop == true && startTime < stopTime) {
				if (stopTime < currentTime)
					bActive = false;
			}
			else if (bLoop == false && stopTime <= startTime) {
				if (startTime + cycleInterval < currentTime)
					bActive = false;
			}
	
			if (bActive == false) {
				setIsActive(false);
				sendEvent(getIsActiveField());
			}
		}
	*/
}

