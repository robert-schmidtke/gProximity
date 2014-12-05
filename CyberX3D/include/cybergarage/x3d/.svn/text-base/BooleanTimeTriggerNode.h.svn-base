/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	BooleanTimeTriggerNode.h
*
******************************************************************/

#ifndef _CX3D_BOOLEANTIMETRIGGERNODE_H_
#define _CX3D_BOOLEANTIMETRIGGERNODE_H_

#include <cybergarage/x3d/VRML97Fields.h>
#include <cybergarage/x3d/TriggerNode.h>

namespace CyberX3D
{

	class BooleanTimeTriggerNode : public TriggerNode
	{
	
		SFBool *set_booleanTrueField;
		SFBool *set_booleanFalseField;
		SFBool *trueTriggerField;
		SFBool *falseTriggerField;
		
	public:
	
		BooleanTimeTriggerNode();
		virtual ~BooleanTimeTriggerNode();
		
		////////////////////////////////////////////////
		//	SetBooleanTrue
		////////////////////////////////////////////////
		
		SFBool *getSetBooleanTrueField();
		
		void setSetBooleanTrue(bool value);
		bool getSetBooleanTrue();
		
		////////////////////////////////////////////////
		//	SetBooleanFalse
		////////////////////////////////////////////////
		
		SFBool *getSetBooleanFalseField();
		
		void setSetBooleanFalse(bool value);
		bool getSetBooleanFalse();
		
		////////////////////////////////////////////////
		//	TrueTrigger
		////////////////////////////////////////////////
		
		SFBool *getTrueTriggerField();
		
		void setTrueTrigger(bool value);
		bool getTrueTrigger();
		
		////////////////////////////////////////////////
		//	FalseTrigger
		////////////////////////////////////////////////
		
		SFBool *getFalseTriggerField();
		
		void setFalseTrigger(bool value);
		bool getFalseTrigger();
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		BooleanTimeTriggerNode *next();
		BooleanTimeTriggerNode *nextTraversal();
		
		////////////////////////////////////////////////
		//	functions
		////////////////////////////////////////////////
		
		bool isChildNodeType(Node *node);
		void initialize();
		void uninitialize();
		void update();
		
		////////////////////////////////////////////////
		//	Infomation
		////////////////////////////////////////////////
		
		void outputContext(std::ostream &printStream, char *indentString);
	};
	
}

#endif

