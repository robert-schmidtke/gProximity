/******************************************************************
*
*	CyberVRML97 for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	GroupNode.h
*
******************************************************************/

#ifndef _CV97_GROUPNODE_H_
#define _CV97_GROUPNODE_H_

#include <cybergarage/x3d/BoundedGroupingNode.h>

namespace CyberX3D
{

	class GroupNode : public BoundedGroupingNode
	{
	
	public:
	
		GroupNode();
		~GroupNode();
		
		////////////////////////////////////////////////
		//	Output
		////////////////////////////////////////////////
		
		void outputContext(std::ostream &printStream, char *indentString);
		
		////////////////////////////////////////////////
		//	functions
		////////////////////////////////////////////////
		
		bool isChildNodeType(Node *node);
		void initialize();
		void uninitialize();
		void update();
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		GroupNode *next();
		GroupNode *nextTraversal();
		
	};
	
}

#endif
