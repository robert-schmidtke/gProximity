/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	TimeSensorNode.h
*
******************************************************************/

#ifndef _CX3D_TIMESENSORNODE_H_
#define _CX3D_TIMESENSORNODE_H_

#include <time.h>
#ifdef WIN32
#include <sys/timeb.h>
#endif

#include <cybergarage/x3d/SensorNode.h>

namespace CyberX3D
{

	class TimeSensorNode : public SensorNode
	{
	
		SFBool *loopField;
		SFTime *cycleIntervalField;
		SFTime *startTimeField;
		SFTime *stopTimeField;
		SFTime *cycleTimeField;
		SFTime *timeField;
		SFFloat *fractionChangedField;
		
		SFBool *isPausedField;
		SFTime *pauseTimeField;
		SFTime *resumeTimeField;
		SFTime *elapsedTimeField;
		SFFloat *numLoopsField;
		
	public:
	
		TimeSensorNode();
		~TimeSensorNode();
		
		////////////////////////////////////////////////
		//	Loop
		////////////////////////////////////////////////
		
		SFBool *getLoopField();
		
		void setLoop(bool value);
		void setLoop(int value);
		bool getLoop();
		bool isLoop();
		
		////////////////////////////////////////////////
		//	Cyble Interval
		////////////////////////////////////////////////
		
		SFTime *getCycleIntervalField();
		
		void setCycleInterval(double value);
		double getCycleInterval();
		
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
		//	fraction_changed
		////////////////////////////////////////////////
		
		SFFloat *getFractionChangedField();
		
		void setFractionChanged(float value);
		float getFractionChanged();
		
		////////////////////////////////////////////////
		//	Cycle time
		////////////////////////////////////////////////
		
		SFTime *getCycleTimeField();
		
		void setCycleTime(double value);
		double getCycleTime();
		
		////////////////////////////////////////////////
		//	Time
		////////////////////////////////////////////////
		
		SFTime *getTimeField();
		
		void setTime(double value);
		double getTime();
		
		////////////////////////////////////////////////
		//	IsPaused (X3D)
		////////////////////////////////////////////////
		
		SFBool *getIsPausedField();
		
		void setIsPaused(bool value);
		void setIsPaused(int value);
		bool getIsPaused();
		bool isPaused();
		
		////////////////////////////////////////////////
		//	Elapsed time (X3D)
		////////////////////////////////////////////////
		
		SFTime *getElapsedTimeField();
		
		void setElapsedTime(double value);
		double getElapsedTime();
		
		////////////////////////////////////////////////
		//	Pause time (X3D)
		////////////////////////////////////////////////
		
		SFTime *getPauseTimeField();
		
		void setPauseTime(double value);
		double getPauseTime();
		
		////////////////////////////////////////////////
		//	Resume time (X3D)
		////////////////////////////////////////////////
		
		SFTime *getResumeTimeField();
		
		void setResumeTime(double value);
		double getResumeTime();
		
		////////////////////////////////////////////////
		//	numLoops (X3D)
		////////////////////////////////////////////////
		
		SFFloat *getNumLoopsField();
		
		void setNumLoops(float value);
		float getNumLoops();
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		TimeSensorNode *next();
		TimeSensorNode *nextTraversal();
		
		////////////////////////////////////////////////
		//	Virtual functions
		////////////////////////////////////////////////
		
		bool isChildNodeType(Node *node);
		void initialize();
		void uninitialize();
		void update();
		void outputContext(std::ostream &printStream, char *indentString);
	};
	
}

#endif

