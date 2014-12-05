/******************************************************************
*
*	CyberVRML97 for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	PointSetNode.h
*
******************************************************************/

#ifndef _CV97_POINTSET_H_
#define _CV97_POINTSET_H_

#include <cybergarage/x3d/Geometry3DNode.h>
#include <cybergarage/x3d/ColorNode.h>
#include <cybergarage/x3d/CoordinateNode.h>

namespace CyberX3D
{

	class PointSetNode : public Geometry3DNode
	{
	
	public:
	
		PointSetNode();
		~PointSetNode();
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		PointSetNode *next();
		PointSetNode *nextTraversal();
		
		////////////////////////////////////////////////
		//	functions
		////////////////////////////////////////////////
		
		bool isChildNodeType(Node *node);
		void initialize();
		void uninitialize();
		void update();
		
		////////////////////////////////////////////////
		//	BoundingBox
		////////////////////////////////////////////////
		
		void recomputeBoundingBox();
		
		////////////////////////////////////////////////
		//	Polygons
		////////////////////////////////////////////////
		
		int getNPolygons()
		{
			return 0;
		}
		
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

