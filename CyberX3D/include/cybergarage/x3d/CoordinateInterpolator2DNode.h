/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	CoordinateInterpolator2DNode.h
*
******************************************************************/

#ifndef _CX3D_COORDINATEINTERPOLATOR2D_H_
#define _CX3D_COORDINATEINTERPOLATOR2D_H_

#include <cybergarage/x3d/X3DFields.h>
#include <cybergarage/x3d/InterpolatorNode.h>

namespace CyberX3D
{

	class CoordinateInterpolator2DNode : public InterpolatorNode
	{
	
		MFVec2f *keyValueField;
		SFVec2f *valueField;
		
	public:
	
		CoordinateInterpolator2DNode();
		~CoordinateInterpolator2DNode();
		
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
		//	functions
		////////////////////////////////////////////////
		
		bool isChildNodeType(Node *node);
		void initialize();
		void uninitialize();
		void update();
		
		////////////////////////////////////////////////
		//	Output
		////////////////////////////////////////////////
		
		void outputContext(std::ostream &printStream, char *indentString);
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		CoordinateInterpolator2DNode *next();
		CoordinateInterpolator2DNode *nextTraversal();
	};
	
}

#endif

