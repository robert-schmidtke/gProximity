/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	VisibilitySensorNode.h
*
******************************************************************/

#ifndef _CX3D_VISIBILITYSENSORNODE_H_
#define _CX3D_VISIBILITYSENSORNODE_H_

#include <cybergarage/x3d/EnvironmentalSensorNode.h>

namespace CyberX3D
{

	class VisibilitySensorNode : public EnvironmentalSensorNode
	{
	
	public:
	
		VisibilitySensorNode();
		~VisibilitySensorNode();
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		VisibilitySensorNode *next();
		VisibilitySensorNode *nextTraversal();
		
		////////////////////////////////////////////////
		//	functions
		////////////////////////////////////////////////
		
		bool	isChildNodeType(Node *node);
		void	initialize();
		void	uninitialize();
		void	update();
		
		////////////////////////////////////////////////
		//	Infomation
		////////////////////////////////////////////////
		
		void	outputContext(std::ostream &printStream, char *indentString);
	};
	
}

#endif

