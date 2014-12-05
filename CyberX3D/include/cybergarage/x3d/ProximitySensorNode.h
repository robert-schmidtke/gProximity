/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	ProximitySensorNode.h
*
******************************************************************/

#ifndef _CX3D_PROXIMITYSENSORNODE_H_
#define _CX3D_PROXIMITYSENSORNODE_H_

#include <cybergarage/x3d/EnvironmentalSensorNode.h>

namespace CyberX3D
{

	class ProximitySensorNode : public EnvironmentalSensorNode
	{
		SFVec3f *positionField;
		SFRotation *orientationField;
		SFBool *inRegionField;
		
	public:
	
		ProximitySensorNode();
		~ProximitySensorNode();
		
		////////////////////////////////////////////////
		//	Position
		////////////////////////////////////////////////
		
		SFVec3f *getPositionChangedField();
		
		void setPositionChanged(float value[]);
		void setPositionChanged(float x, float y, float z);
		void getPositionChanged(float value[]);
		
		////////////////////////////////////////////////
		//	Orientation
		////////////////////////////////////////////////
		
		SFRotation *getOrientationChangedField();
		
		void setOrientationChanged(float value[]);
		void setOrientationChanged(float x, float y, float z, float rot);
		void getOrientationChanged(float value[]);
		
		////////////////////////////////////////////////
		//	inRegion
		////////////////////////////////////////////////
		
		SFBool *getInRegionField();
		
		void setInRegion(bool value);
		bool inRegion();
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		ProximitySensorNode *next();
		ProximitySensorNode *nextTraversal();
		
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

