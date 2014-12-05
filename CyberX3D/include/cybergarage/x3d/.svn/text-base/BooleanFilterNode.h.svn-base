/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	BooleanFilterNode.h
*
******************************************************************/

#ifndef _CX3D_BOOLEANFILTERNODE_H_
#define _CX3D_BOOLEANFILTERNODE_H_

#include <cybergarage/x3d/VRML97Fields.h>
#include <cybergarage/x3d/Node.h>

namespace CyberX3D
{

	class BooleanFilterNode : public Node
	{
		SFBool *set_booleanField;
		SFBool *inputFalseField;
		SFBool *inputNegateField;
		SFBool *inputTrueField;
		
	public:
	
		BooleanFilterNode();
		~BooleanFilterNode();
		
		////////////////////////////////////////////////
		//	setBoolean
		////////////////////////////////////////////////
		
		SFBool *getBooleanField();
		
		void setBoolean(bool value);
		bool getBoolean();
		bool isBoolean();
		
		////////////////////////////////////////////////
		//	inputFalse
		////////////////////////////////////////////////
		
		SFBool* getInputFalseField();
		
		void setInputFalse(bool value);
		bool getInputFalse();
		bool isInputFalse();
		
		////////////////////////////////////////////////
		//	inputNegate
		////////////////////////////////////////////////
		
		SFBool* getInputNegateField();
		
		void setInputNegate(bool value);
		bool getInputNegate();
		bool isInputNegate();
		
		////////////////////////////////////////////////
		//	inputTrue
		////////////////////////////////////////////////
		
		SFBool* getInputTrueField();
		
		void setInputTrue(bool value);
		bool getInputTrue();
		bool isInputTrue();
		
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
		
		BooleanFilterNode *next();
		BooleanFilterNode *nextTraversal();
		
	};
	
}

#endif

