/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	BooleanToggleNode.h
*
******************************************************************/

#ifndef _CX3D_BOOLEANTOGGLENODE_H_
#define _CX3D_BOOLEANTOGGLENODE_H_

#include <cybergarage/x3d/VRML97Fields.h>
#include <cybergarage/x3d/Node.h>

namespace CyberX3D
{

	class BooleanToggleNode : public Node
	{
	
		SFBool *set_booleanField;
		SFBool *toggleField;
		
	public:
	
		BooleanToggleNode();
		~BooleanToggleNode();
		
		////////////////////////////////////////////////
		//	SetBooleanEvent
		////////////////////////////////////////////////
		
		SFBool *getBooleanField();
		
		void setBoolean(bool value);
		bool getBoolean();
		bool isBoolean();
		
		////////////////////////////////////////////////
		//	IntegerKey
		////////////////////////////////////////////////
		
		SFBool* getToggleField();
		
		void setToggle(bool value);
		bool getToggle();
		bool isToggle();
		
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
		
		BooleanToggleNode *next();
		BooleanToggleNode *nextTraversal();
		
	};
	
}

#endif

