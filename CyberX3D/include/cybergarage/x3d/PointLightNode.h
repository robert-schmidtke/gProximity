/******************************************************************
*
*	CyberVRML97 for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	PointLightNode.h
*
******************************************************************/

#ifndef _CX3D_POINTLIGHTNODE_H_
#define _CX3D_POINTLIGHTNODE_H_

#include <cybergarage/x3d/LightNode.h>

namespace CyberX3D
{

	class PointLightNode : public LightNode
	{
	
		SFVec3f *locationField;
		SFFloat *radiusField;
		SFVec3f *attenuationField;
		
	public:
	
		PointLightNode();
		~PointLightNode();
		
		////////////////////////////////////////////////
		//	Location
		////////////////////////////////////////////////
		
		SFVec3f *getLocationField();
		
		void setLocation(float value[]);
		void setLocation(float x, float y, float z);
		void getLocation(float value[]);
		
		////////////////////////////////////////////////
		//	Radius
		////////////////////////////////////////////////
		
		SFFloat *getRadiusField();
		
		void setRadius(float value);
		float getRadius();
		
		////////////////////////////////////////////////
		//	Attenuation
		////////////////////////////////////////////////
		
		SFVec3f *getAttenuationField();
		
		void setAttenuation(float value[]);
		void setAttenuation(float x, float y, float z);
		void getAttenuation(float value[]);
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		PointLightNode *next();
		PointLightNode *nextTraversal();
		
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
