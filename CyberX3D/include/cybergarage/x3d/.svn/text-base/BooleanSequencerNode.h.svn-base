/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	BooleanSequencer.h
*
******************************************************************/

#ifndef _CX3D_BOOLEANSEQUENCERNODE_H_
#define _CX3D_BOOLEANSEQUENCERNODE_H_

#include <cybergarage/x3d/X3DFields.h>
#include <cybergarage/x3d/SequencerNode.h>

namespace CyberX3D
{

	class BooleanSequencerNode : public SequencerNode
	{
	
		MFBool *keyValueField;
		SFBool *valueField;
		
	public:
	
		BooleanSequencerNode();
		~BooleanSequencerNode();
		
		////////////////////////////////////////////////
		//	keyValue
		////////////////////////////////////////////////
		
		MFBool *getKeyValueField();
		
		void addKeyValue(bool value);
		int getNKeyValues();
		bool getKeyValue(int index);
		
		////////////////////////////////////////////////
		//	value
		////////////////////////////////////////////////
		
		SFBool *getValueField();
		
		void setValue(bool vector);
		bool getValue();
		
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
		
		BooleanSequencerNode *next();
		BooleanSequencerNode *nextTraversal();
	};
	
}

#endif
