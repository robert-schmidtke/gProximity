/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	Circle2DNode.h
*
******************************************************************/

#ifndef _CX3D_CIRCLE2D_H_
#define _CX3D_CIRCLE2D_H_

#include <cybergarage/x3d/Geometry2DNode.h>

namespace CyberX3D
{

	class Circle2DNode : public Geometry2DNode
	{
	
		SFFloat *radiusField;
		
	public:
	
		Circle2DNode();
		~Circle2DNode();
		
		////////////////////////////////////////////////
		//	Radius
		////////////////////////////////////////////////
		
		SFFloat *getRadiusField();
		
		void setRadius(float value);
		float getRadius();
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		Circle2DNode *next();
		Circle2DNode *nextTraversal();
		
		////////////////////////////////////////////////
		//	functions
		////////////////////////////////////////////////
		
		bool isChildNodeType(Node *node);
		void initialize();
		void uninitialize();
		void update();
		
		////////////////////////////////////////////////
		//	recomputeDisplayList
		////////////////////////////////////////////////
		
#ifdef SUPPORT_OPENGL
		void recomputeDisplayList();
#endif
		
		////////////////////////////////////////////////
		//	Infomation
		////////////////////////////////////////////////
		
		void outputContext(std::ostream &printStream, char *indentString);
	};
	
}

#endif

