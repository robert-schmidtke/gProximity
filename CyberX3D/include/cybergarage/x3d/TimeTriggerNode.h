/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	TimeTriggerNode.h
*
******************************************************************/

#ifndef _CX3D_TIMETRIGGERNODE_H_
#define _CX3D_TIMETRIGGERNODE_H_

#include <cybergarage/x3d/VRML97Fields.h>
#include <cybergarage/x3d/TriggerNode.h>

namespace CyberX3D
{

	class TimeTriggerNode : public TriggerNode
	{
	
		SFBool *set_booleanField;
		SFTime *triggerTimeField;
		
	public:
	
		TimeTriggerNode();
		virtual ~TimeTriggerNode();
		
		////////////////////////////////////////////////
		//	Boolean
		////////////////////////////////////////////////
		
		SFBool *getBooleanField();
		
		void setBoolean(bool value);
		bool getBoolean();
		bool isBoolean();
		
		////////////////////////////////////////////////
		//	triggerTime
		////////////////////////////////////////////////
		
		SFTime* getTriggerTimeField();
		
		void setTriggerTime(double value);
		double getTriggerTime();
		
		////////////////////////////////////////////////
		//	functions
		////////////////////////////////////////////////
		
		bool isChildNodeType(Node *node);
		void initialize();
		void uninitialize();
		void update();
		
		////////////////////////////////////////////////
		//	Output
		////////////////////////////////////////////////
		
		void outputContext(std::ostream &printStream, char *indentString);
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		TimeTriggerNode *next();
		TimeTriggerNode *nextTraversal();
		
	};
	
}

#endif
