/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	TriangleStripSetNode.h
*
******************************************************************/

#ifndef _CX3D_TRIANGLESTRIPSETNODE_H_
#define _CX3D_TRIANGLESTRIPSETNODE_H_

#include <cybergarage/x3d/TriangleSetNode.h>

namespace CyberX3D
{

	class TriangleStripSetNode : public TriangleSetNode
	{
	
		MFInt32 *stripCountField;
		
	public:
	
		TriangleStripSetNode();
		~TriangleStripSetNode();
		
		////////////////////////////////////////////////
		// StripCount
		////////////////////////////////////////////////
		
		MFInt32 *getStripCountField();
		
		void addStripCount(int value);
		int getNStripCountes();
		int getStripCount(int index);
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		TriangleStripSetNode *next();
		TriangleStripSetNode *nextTraversal();
		
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
		//	Polygon
		////////////////////////////////////////////////
		
		int getNPolygons();
		
		////////////////////////////////////////////////
		//	Infomation
		////////////////////////////////////////////////
		
		void outputContext(std::ostream &printStream, char *indentString);
	};
	
}

#endif

