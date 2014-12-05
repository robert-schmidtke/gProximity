/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	TriangleFanSetNode.h
*
******************************************************************/

#ifndef _CX3D_TRIANGLEFANSETNODE_H_
#define _CX3D_TRIANGLEFANSETNODE_H_

#include <cybergarage/x3d/TriangleSetNode.h>

namespace CyberX3D
{

	class TriangleFanSetNode : public TriangleSetNode
	{
	
		MFInt32 *fanCountField;
		
	public:
	
		TriangleFanSetNode();
		~TriangleFanSetNode();
		
		////////////////////////////////////////////////
		// FanCount
		////////////////////////////////////////////////
		
		MFInt32 *getFanCountField();
		
		void addFanCount(int value);
		int getNFanCountes();
		int getFanCount(int index);
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		TriangleFanSetNode *next();
		TriangleFanSetNode *nextTraversal();
		
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

