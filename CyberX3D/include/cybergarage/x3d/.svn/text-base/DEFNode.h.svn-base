/******************************************************************
*
*	VRML library for C++
*
*	Copyright (C) Satoshi Konno 1996-1997
*
*	File:	DEFNode.h
*
******************************************************************/

#ifndef _DEFNODE_H_
#define _DEFNODE_H_

#include <cybergarage/x3d/Node.h>

namespace CyberX3D
{

	class DEFNode : public Node
	{
	
	public:
	
		DEFNode();
		~DEFNode();
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		DEFNode *next();
		DEFNode *nextTraversal();
		
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

