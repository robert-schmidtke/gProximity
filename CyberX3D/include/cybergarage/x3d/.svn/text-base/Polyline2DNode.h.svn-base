/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	Polyline2DNode.h
*
******************************************************************/

#ifndef _CX3D_POLYLINE2D_H_
#define _CX3D_POLYLINE2D_H_

#include <cybergarage/x3d/Geometry2DNode.h>

namespace CyberX3D
{

	class Polyline2DNode : public Geometry2DNode
	{
	
		MFVec2f *lineSegmentsField;
		
	public:
	
		Polyline2DNode();
		~Polyline2DNode();
		
		////////////////////////////////////////////////
		//	LineSegments
		////////////////////////////////////////////////
		
		MFVec2f *getLineSegmentsField();
		
		int getNLineSegments();
		void addLineSegment(float point[]);
		void addLineSegment(float x, float y);
		void getLineSegment(int index, float point[]);
		void setLineSegment(int index, float point[]);
		void setLineSegment(int index, float x, float y);
		void removeLineSegment(int index);
		void removeAllLineSegments();
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		Polyline2DNode *next();
		Polyline2DNode *nextTraversal();
		
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
