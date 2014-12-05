/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	Polypoint2DNode.h
*
******************************************************************/

#ifndef _CX3D_POLYPOINT2D_H_
#define _CX3D_POLYPOINT2D_H_

#include <cybergarage/x3d/Geometry2DNode.h>

namespace CyberX3D
{

	class Polypoint2DNode : public Geometry2DNode
	{
	
		MFVec2f *pointsField;
		
	public:
	
		Polypoint2DNode();
		~Polypoint2DNode();
		
		////////////////////////////////////////////////
		//	Points
		////////////////////////////////////////////////
		
		MFVec2f *getPointsField();
		
		int getNPoints();
		void addPoint(float point[]);
		void addPoint(float x, float y);
		void getPoint(int index, float point[]);
		void setPoint(int index, float point[]);
		void setPoint(int index, float x, float y);
		void removePoint(int index);
		void removeAllPoints();
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		Polypoint2DNode *next();
		Polypoint2DNode *nextTraversal();
		
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
