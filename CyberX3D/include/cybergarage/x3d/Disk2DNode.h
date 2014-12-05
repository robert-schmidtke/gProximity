/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	Disk2DNode.h
*
******************************************************************/

#ifndef _CX3D_DISK2D_H_
#define _CX3D_DISK2D_H_

#include <cybergarage/x3d/Geometry2DNode.h>

namespace CyberX3D
{

	class Disk2DNode : public Geometry2DNode
	{
	
		SFFloat *outerRadiusField;
		SFFloat *innerRadiusField;
		
	public:
	
		Disk2DNode();
		~Disk2DNode();
		
		////////////////////////////////////////////////
		//	Radius
		////////////////////////////////////////////////
		
		SFFloat *getOuterRadiusField();
		
		void setOuterRadius(float value);
		float getOuterRadius();
		
		////////////////////////////////////////////////
		//	Radius
		////////////////////////////////////////////////
		
		SFFloat *getInnerRadiusField();
		
		void setInnerRadius(float value);
		float getInnerRadius();
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		Disk2DNode *next();
		Disk2DNode *nextTraversal();
		
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
