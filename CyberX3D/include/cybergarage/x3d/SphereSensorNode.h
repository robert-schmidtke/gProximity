/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	SphereSensorNode.h
*
******************************************************************/

#ifndef _CX3D_SPHERESENSOR_H_
#define _CX3D_SPHERESENSOR_H_

#include <cybergarage/x3d/DragSensorNode.h>

namespace CyberX3D
{

	class SphereSensorNode : public DragSensorNode
	{
	
		SFRotation *offsetField;
		SFRotation *rotationField;
		
	public:
	
		SphereSensorNode();
		~SphereSensorNode();
		
		////////////////////////////////////////////////
		//	Offset
		////////////////////////////////////////////////
		
		SFRotation *getOffsetField();
		
		void setOffset(float value[]);
		void getOffset(float value[]);
		
		////////////////////////////////////////////////
		//	Rotation
		////////////////////////////////////////////////
		
		SFRotation *getRotationChangedField();
		
		void setRotationChanged(float value[]);
		void setRotationChanged(float x, float y, float z, float rot);
		void getRotationChanged(float value[]);
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		SphereSensorNode *next();
		SphereSensorNode *nextTraversal();
		
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

