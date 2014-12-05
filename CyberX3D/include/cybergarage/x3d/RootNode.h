/******************************************************************
*
*	CyberVRML97 for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	RouteNode.h
*
******************************************************************/

#ifndef _CV97_ROOTNODE_H_
#define _CV97_ROOTNODE_H_

#include <cybergarage/x3d/VRML97Fields.h>
#include <cybergarage/x3d/Node.h>

namespace CyberX3D
{

	class RootNode : public Node
	{
	
	public:
	
		RootNode();
		~RootNode();
		
		////////////////////////////////////////////////
		//	functions
		////////////////////////////////////////////////
		
		bool isChildNodeType(Node *node);
		void initialize();
		void uninitialize();
		void update();
		
		////////////////////////////////////////////////
		//	infomation
		////////////////////////////////////////////////
		
		void outputContext(std::ostream& printStream, char * indentString);
	};
	
}

#endif
