/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	PlaneSensorNode.h
*
******************************************************************/

#ifndef _CX3D_PLANESENSOR_H_
#define _CX3D_PLANESENSOR_H_

#include <cybergarage/x3d/DragSensorNode.h>

namespace CyberX3D
{

	class PlaneSensorNode : public DragSensorNode
	{
	
		SFVec2f *minPositionField;
		SFVec2f *maxPositionField;
		SFVec3f *offsetField;
		SFVec3f *translationField;
		
	public:
	
		PlaneSensorNode();
		~PlaneSensorNode();
		
		////////////////////////////////////////////////
		//	MinPosition
		////////////////////////////////////////////////
		
		SFVec2f *getMinPositionField();
		
		void setMinPosition(float value[]);
		void setMinPosition(float x, float y);
		void getMinPosition(float value[]);
		void getMinPosition(float *x, float *y);
		
		////////////////////////////////////////////////
		//	MaxPosition
		////////////////////////////////////////////////
		
		SFVec2f *getMaxPositionField();
		
		void setMaxPosition(float value[]);
		void setMaxPosition(float x, float y);
		void getMaxPosition(float value[]);
		void getMaxPosition(float *x, float *y);
		
		////////////////////////////////////////////////
		//	Offset
		////////////////////////////////////////////////
		
		SFVec3f *getOffsetField();
		
		void setOffset(float value[]);
		void getOffset(float value[]);
		
		////////////////////////////////////////////////
		//	Translation
		////////////////////////////////////////////////
		
		SFVec3f *getTranslationChangedField();
		
		void setTranslationChanged(float value[]);
		void setTranslationChanged(float x, float y, float z);
		void getTranslationChanged(float value[]);
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		PlaneSensorNode *next();
		PlaneSensorNode *nextTraversal();
		
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

