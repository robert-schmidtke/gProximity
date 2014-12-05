/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2003
*
*	File:	GroupNode.h
*
*	06/06/03
*		- The first release
*
******************************************************************/

#ifndef _CX3D_SCENENODE_H_
#define _CX3D_SCENENODE_H_

#include <cybergarage/x3d/Node.h>

namespace CyberX3D
{

	class SceneNode : public Node
	{
	
	public:
	
		SceneNode();
		~SceneNode();
		
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
		
		SceneNode *next();
		SceneNode *nextTraversal();
		
		////////////////////////////////////////////////
		//	Output
		////////////////////////////////////////////////
		
		void outputContext(std::ostream &printStream, char *indentString);
	};
	
}

#endif
