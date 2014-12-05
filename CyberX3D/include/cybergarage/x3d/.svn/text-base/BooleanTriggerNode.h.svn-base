/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	BooleanTriggerNode.h
*
******************************************************************/

#ifndef _CX3D_BOOLEANTRIGGERNODE_H_
#define _CX3D_BOOLEANTRIGGERNODE_H_

#include <cybergarage/x3d/VRML97Fields.h>
#include <cybergarage/x3d/TriggerNode.h>

namespace CyberX3D
{

	class BooleanTriggerNode : public Node
	{
	
		SFTime *set_triggerTimeField;
		SFBool *triggerTrueField;
		
	public:
	
		BooleanTriggerNode();
		virtual ~BooleanTriggerNode();
		
		////////////////////////////////////////////////
		//	TriggerTimeEvent
		////////////////////////////////////////////////
		
		SFTime *getTriggerTimeField();
		
		void setTriggerTime(double value);
		double getTriggerTime();
		
		////////////////////////////////////////////////
		//	IntegerKey
		////////////////////////////////////////////////
		
		SFBool* getTriggerTrueField();
		
		void setTriggerTrue(bool value);
		bool getTriggerTrue();
		bool isTriggerTrue();
		
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
		
		BooleanTriggerNode *next();
		BooleanTriggerNode *nextTraversal();
		
	};
	
}

#endif

