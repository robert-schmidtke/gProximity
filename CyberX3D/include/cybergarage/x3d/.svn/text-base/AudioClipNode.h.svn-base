/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	AudioClipNode.h
*
******************************************************************/

#ifndef _CX3D_AUDIOCLLIPNODE_H_
#define _CX3D_AUDIOCLLIPNODE_H_

#include <cybergarage/x3d/VRML97Fields.h>
#include <cybergarage/x3d/SoundSourceNode.h>

namespace CyberX3D
{

	class AudioClipNode : public SoundSourceNode
	{
		SFBool *loopField;
		SFTime *startTimeField;
		SFTime *stopTimeField;
		
		double	mCurrentTime;
		
	public:
	
		AudioClipNode();
		~AudioClipNode();
		
		////////////////////////////////////////////////
		//	Loop
		////////////////////////////////////////////////
		
		SFBool *getLoopField();
		
		void setLoop(bool value);
		void setLoop(int value);
		bool getLoop();
		bool isLoop();
		
		////////////////////////////////////////////////
		//	Start time
		////////////////////////////////////////////////
		
		SFTime *getStartTimeField();
		
		void setStartTime(double value);
		double getStartTime();
		
		////////////////////////////////////////////////
		//	Stop time
		////////////////////////////////////////////////
		
		SFTime *getStopTimeField();
		
		void setStopTime(double value);
		double getStopTime();
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		AudioClipNode *next();
		AudioClipNode *nextTraversal();
		
		////////////////////////////////////////////////
		//	Virutual functions
		////////////////////////////////////////////////
		
		bool isChildNodeType(Node *node);
		void initialize();
		void uninitialize();
		void update();
		
		void outputContext(std::ostream &printStream, char *indentString);
		
		////////////////////////////////////////////////
		//	Time
		////////////////////////////////////////////////
		
		void setCurrentTime(double time);
		double getCurrentTime();
	};
	
}

#endif
