/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	DirectionalLightNode.h
*
******************************************************************/

#ifndef _CX3D_DIRECTIONALLIGHTNODE_H_
#define _CX3D_DIRECTIONALLIGHTNODE_H_

#include <cybergarage/x3d/VRML97Fields.h>
#include <cybergarage/x3d/LightNode.h>

namespace CyberX3D
{

	class DirectionalLightNode : public LightNode
	{
	
		SFVec3f *directionField;
		
	public:
	
		DirectionalLightNode();
		~DirectionalLightNode();
		
		////////////////////////////////////////////////
		//	Direction
		////////////////////////////////////////////////
		
		SFVec3f *getDirectionField();
		
		void setDirection(float value[]);
		void setDirection(float x, float y, float z);
		void getDirection(float value[]);
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		DirectionalLightNode *next();
		DirectionalLightNode *nextTraversal();
		
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

