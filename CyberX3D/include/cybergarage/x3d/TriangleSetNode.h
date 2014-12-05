/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	TriangleSetNode.h
*
******************************************************************/

#ifndef _CX3D_TRIANGLESETNODE_H_
#define _CX3D_TRIANGLESETNODE_H_

#include <cybergarage/x3d/ComposedGeometryNode.h>
#include <cybergarage/x3d/NormalNode.h>
#include <cybergarage/x3d/ColorNode.h>
#include <cybergarage/x3d/CoordinateNode.h>
#include <cybergarage/x3d/TextureCoordinateNode.h>

namespace CyberX3D
{

	class TriangleSetNode : public ComposedGeometryNode
	{
		SFBool *convexField;
		SFFloat *creaseAngleField;
		
	public:
	
		TriangleSetNode();
		~TriangleSetNode();
		
		////////////////////////////////////////////////
		//	Convex
		////////////////////////////////////////////////
		
		SFBool *getConvexField();
		
		void setConvex(bool value);
		void setConvex(int value);
		bool getConvex();
		
		////////////////////////////////////////////////
		//	CreaseAngle
		////////////////////////////////////////////////
		
		SFFloat *getCreaseAngleField();
		
		void setCreaseAngle(float value);
		float getCreaseAngle();
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		TriangleSetNode *next();
		TriangleSetNode *nextTraversal();
		
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

