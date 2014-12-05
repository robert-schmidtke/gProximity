/******************************************************************
*
*	CyberVRML97 for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	SensorNode.h
*
******************************************************************/

#ifndef _CV97_SENSORNODE_H_
#define _CV97_SENSORNODE_H_

#include <cybergarage/x3d/VRML97Fields.h>
#include <cybergarage/x3d/Node.h>

namespace CyberX3D
{

	class SensorNode : public Node
	{
	
		SFBool *enabledField;
		SFBool *isActiveField;
		
	public:
	
		SensorNode();
		virtual ~SensorNode();
		
		////////////////////////////////////////////////
		//	Enabled
		////////////////////////////////////////////////
		
		SFBool *getEnabledField();
		
		void setEnabled(bool  value);
		void setEnabled(int value);
		bool  getEnabled();
		bool  isEnabled();
		
		////////////////////////////////////////////////
		//	isActive
		////////////////////////////////////////////////
		
		SFBool *getIsActiveField();
		
		void setIsActive(bool  value);
		void setIsActive(int value);
		bool  getIsActive();
		bool isActive();
		
	};
	
}

#endif

