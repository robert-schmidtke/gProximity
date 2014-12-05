/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	SwitchNode.h
*
******************************************************************/

#ifndef _CV97_SWITCHNODE_H_
#define _CV97_SWITCHNODE_H_

#include <cybergarage/x3d/VRML97Fields.h>
#include <cybergarage/x3d/BoundedGroupingNode.h>

namespace CyberX3D
{

	class SwitchNode : public BoundedGroupingNode
	{
	
		SFInt32 *whichChoiceField;
		
	public:
	
		SwitchNode();
		~SwitchNode();
		
		////////////////////////////////////////////////
		//	whichChoice
		////////////////////////////////////////////////
		
		SFInt32 *getWhichChoiceField();
		
		void setWhichChoice(int value);
		int getWhichChoice();
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		SwitchNode *next();
		SwitchNode *nextTraversal();
		
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

