/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	KeySensorNode.h
*
******************************************************************/

#ifndef _CX3D_KEYSENSORNODE_H_
#define _CX3D_KEYSENSORNODE_H_

#include <cybergarage/x3d/KeyDeviceSensorNode.h>

namespace CyberX3D
{

	class KeySensorNode : public KeyDeviceSensorNode
	{
	
	public:
	
		KeySensorNode();
		~KeySensorNode();
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		KeySensorNode *next();
		KeySensorNode *nextTraversal();
		
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

