/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	Arc2DNode.h
*
******************************************************************/

#ifndef _CX3D_ARC2DNODE_H_
#define _CX3D_ARC2DNODE_H_

#include <cybergarage/x3d/Geometry2DNode.h>

namespace CyberX3D
{

	class Arc2DNode : public Geometry2DNode
	{
	
		SFFloat *radiusField;
		SFFloat *startAngleField;
		SFFloat *endAngleField;
		
	public:
	
		Arc2DNode();
		~Arc2DNode();
		
		////////////////////////////////////////////////
		//	Radius
		////////////////////////////////////////////////
		
		SFFloat *getRadiusField();
		
		void setRadius(float value);
		float getRadius();
		
		////////////////////////////////////////////////
		//	startAngle
		////////////////////////////////////////////////
		
		SFFloat *getStartAngleField();
		
		void setStartAngle(float value);
		float getStartAngle();
		
		////////////////////////////////////////////////
		//	endAngle
		////////////////////////////////////////////////
		
		SFFloat *getEndAngleField();
		
		void setEndAngle(float value);
		float getEndAngle();
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		Arc2DNode *next();
		Arc2DNode *nextTraversal();
		
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
