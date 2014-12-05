/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	NodeSequencer.h
*
******************************************************************/

#ifndef _CX3D_NODESEQUENCERNODE_H_
#define _CX3D_NODESEQUENCERNODE_H_

#include <cybergarage/x3d/X3DFields.h>
#include <cybergarage/x3d/SequencerNode.h>

namespace CyberX3D
{

	class NodeSequencerNode : public SequencerNode
	{
	
		MFNode *keyValueField;
		SFNode *valueField;
		
	public:
	
		NodeSequencerNode();
		~NodeSequencerNode();
		
		////////////////////////////////////////////////
		//	keyValue
		////////////////////////////////////////////////
		
		MFNode *getKeyValueField();
		
		void addKeyValue(Node *value);
		int getNKeyValues();
		Node *getKeyValue(int index);
		
		////////////////////////////////////////////////
		//	value
		////////////////////////////////////////////////
		
		SFNode *getValueField();
		
		void setValue(Node *value);
		Node *getValue();
		
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
		
		NodeSequencerNode *next();
		NodeSequencerNode *nextTraversal();
	};
	
}

#endif
