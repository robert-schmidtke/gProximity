/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	TriangleSet2DNode.h
*
******************************************************************/

#ifndef _CX3D_TRIANGLESET2D_H_
#define _CX3D_TRIANGLESET2D_H_

#include <cybergarage/x3d/Geometry2DNode.h>

namespace CyberX3D
{

	class TriangleSet2DNode : public Geometry2DNode
	{
	
		MFVec2f *verticesField;
		
	public:
	
		TriangleSet2DNode();
		~TriangleSet2DNode();
		
		////////////////////////////////////////////////
		//	Vertices
		////////////////////////////////////////////////
		
		MFVec2f *getVerticesField();
		
		int getNVertices();
		void addVertex(float point[]);
		void addVertex(float x, float y);
		void getVertex(int index, float point[]);
		void setVertex(int index, float point[]);
		void setVertex(int index, float x, float y);
		void removeVertex(int index);
		void removeAllVertices();
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		TriangleSet2DNode *next();
		TriangleSet2DNode *nextTraversal();
		
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
