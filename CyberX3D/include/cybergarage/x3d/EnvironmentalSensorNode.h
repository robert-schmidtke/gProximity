/******************************************************************
*
*	CyberVRML97 for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	EnvironmentalSensorNode.h
*
******************************************************************/

#ifndef _CX3D_ENVIRONMENTALSENSORNODE_H_
#define _CX3D_ENVIRONMENTALSENSORNODE_H_

#include <cybergarage/x3d/SensorNode.h>

namespace CyberX3D
{

	class EnvironmentalSensorNode : public SensorNode
	{
	
		SFVec3f *centerField;
		SFVec3f *sizeField;
		SFTime *enterTimeField;
		SFTime *exitTimeField;
		
	public:
	
		EnvironmentalSensorNode();
		virtual ~EnvironmentalSensorNode();
		
		////////////////////////////////////////////////
		//	Center
		////////////////////////////////////////////////
		
		SFVec3f *getCenterField();
		
		void	setCenter(float value[]);
		void	setCenter(float x, float y, float z);
		void	getCenter(float value[]);
		
		////////////////////////////////////////////////
		//	Size
		////////////////////////////////////////////////
		
		SFVec3f *getSizeField();
		
		void	setSize(float value[]);
		void	setSize(float x, float y, float z);
		void	getSize(float value[]);
		
		////////////////////////////////////////////////
		//	EnterTime
		////////////////////////////////////////////////
		
		SFTime *getEnterTimeField();
		
		void	setEnterTime(double value);
		double	getEnterTime();
		
		////////////////////////////////////////////////
		//	ExitTime
		////////////////////////////////////////////////
		
		SFTime *getExitTimeField();
		
		void	setExitTime(double value);
		double	getExitTime();
	};
	
}

#endif

