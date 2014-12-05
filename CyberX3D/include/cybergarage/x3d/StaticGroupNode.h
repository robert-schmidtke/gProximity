/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	StaticGroupNode.h
*
******************************************************************/

#ifndef _CX3D_STATICGROUPNODE_H_
#define _CX3D_STATICGROUPNODE_H_

#include <cybergarage/x3d/BoundedGroupingNode.h>

namespace CyberX3D
{

	class StaticGroupNode : public BoundedGroupingNode
	{
	
	public:
	
		StaticGroupNode();
		~StaticGroupNode();
		
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
		
		StaticGroupNode *next();
		StaticGroupNode *nextTraversal();
		
	};
	
}

#endif
