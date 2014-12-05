/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	PositionInterpolator2DNode.h
*
******************************************************************/

#ifndef _CX3D_POSITIONINTERPOLATOR2D_H_
#define _CX3D_POSITIONINTERPOLATOR2D_H_

#include <cybergarage/x3d/InterpolatorNode.h>

namespace CyberX3D
{

	class PositionInterpolator2DNode : public InterpolatorNode
	{
	
		MFVec2f *keyValueField;
		SFVec2f *valueField;
		
	public:
	
		PositionInterpolator2DNode();
		~PositionInterpolator2DNode();
		
		////////////////////////////////////////////////
		//	keyValue
		////////////////////////////////////////////////
		
		MFVec2f *getKeyValueField();
		
		void addKeyValue(float vector[]);
		int getNKeyValues();
		void getKeyValue(int index, float vector[]);
		
		////////////////////////////////////////////////
		//	value
		////////////////////////////////////////////////
		
		SFVec2f *getValueField();
		
		void setValue(float vector[]);
		void getValue(float vector[]);
		
		////////////////////////////////////////////////
		//	Virtual functions
		////////////////////////////////////////////////
		
		bool isChildNodeType(Node *node);
		void initialize();
		void uninitialize();
		void update();
		
		void outputContext(std::ostream &printStream, char *indentString);
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		PositionInterpolator2DNode *next();
		PositionInterpolator2DNode *nextTraversal();
	};
	
}

#endif

