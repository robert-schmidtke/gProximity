/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	DragSensorNode.h
*
******************************************************************/

#ifndef _CX3D_DRAGSENSORNODE_H_
#define _CX3D_DRAGSENSORNODE_H_

#include <cybergarage/x3d/PointingDeviceSensorNode.h>

namespace CyberX3D
{

	class DragSensorNode : public PointingDeviceSensorNode
	{
		SFBool *autoOffsetField;
		SFVec3f *trackPointField;
		
	public:
	
		DragSensorNode();
		~DragSensorNode();
		
		////////////////////////////////////////////////
		//	AutoOffset
		////////////////////////////////////////////////
		
		SFBool *getAutoOffsetField();
		
		void setAutoOffset(bool  value);
		void setAutoOffset(int value);
		bool  getAutoOffset();
		bool  isAutoOffset();
		
		////////////////////////////////////////////////
		//	TrackPoint
		////////////////////////////////////////////////
		
		SFVec3f *getTrackPointChangedField();
		
		void setTrackPointChanged(float value[]);
		void setTrackPointChanged(float x, float y, float z);
		void getTrackPointChanged(float value[]);
		
	};
	
}

#endif

