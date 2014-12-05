/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	IntegerSequencer.h
*
******************************************************************/

#ifndef _CX3D_INTEGERSEQUENCERNODE_H_
#define _CX3D_INTEGERSEQUENCERNODE_H_

#include <cybergarage/x3d/SequencerNode.h>
#include <cybergarage/x3d/X3DFields.h>

namespace CyberX3D
{

	class IntegerSequencerNode : public SequencerNode
	{
	
		MFInt32 *keyValueField;
		SFInt32 *valueField;
		
	public:
	
		IntegerSequencerNode();
		~IntegerSequencerNode();
		
		////////////////////////////////////////////////
		//	keyValue
		////////////////////////////////////////////////
		
		MFInt32 *getKeyValueField();
		
		void addKeyValue(int value);
		int getNKeyValues();
		int getKeyValue(int index);
		
		////////////////////////////////////////////////
		//	value
		////////////////////////////////////////////////
		
		SFInt32 *getValueField();
		
		void setValue(int vector);
		int getValue();
		
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
		
		IntegerSequencerNode *next();
		IntegerSequencerNode *nextTraversal();
	};
	
}

#endif
