/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	IntegerTriggerNode.h
*
******************************************************************/

#ifndef _CX3D_INTEGERTRIGGERNODE_H_
#define _CX3D_INTEGERTRIGGERNODE_H_

#include <cybergarage/x3d/VRML97Fields.h>
#include <cybergarage/x3d/TriggerNode.h>

namespace CyberX3D
{

	class IntegerTriggerNode : public TriggerNode
	{
	
		SFBool *set_booleanField;
		SFInt32 *integerKeyField;
		SFInt32 *triggerValueField;
		
	public:
	
		IntegerTriggerNode();
		virtual ~IntegerTriggerNode();
		
		////////////////////////////////////////////////
		//	Boolean
		////////////////////////////////////////////////
		
		SFBool *getBooleanField();
		
		void setBoolean(bool value);
		bool getBoolean();
		bool isBoolean();
		
		////////////////////////////////////////////////
		//	IntegerKey
		////////////////////////////////////////////////
		
		SFInt32* getIntegerKeyField();
		
		void setIntegerKey(int value);
		int getIntegerKey();
		
		////////////////////////////////////////////////
		//	triggerValue
		////////////////////////////////////////////////
		
		SFInt32* getTriggerValueField();
		
		void setTriggerValue(int value);
		int getTriggerValue();
		
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
		
		IntegerTriggerNode *next();
		IntegerTriggerNode *nextTraversal();
		
	};
	
}

#endif

