/******************************************************************
*
*	CyberVRML97 for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	SphereNode.h
*
******************************************************************/

#ifndef _CV97_SPHERENODE_H_
#define _CV97_SPHERENODE_H_

#include <cybergarage/x3d/Geometry3DNode.h>

namespace CyberX3D
{

	const int DEFAULT_SPHERE_SLICES = 16;
	
	class SphereNode : public Geometry3DNode
	{
	
		SFFloat *radiusField;
		
	public:
	
		SphereNode();
		~SphereNode();
		
		////////////////////////////////////////////////
		//	Radius
		////////////////////////////////////////////////
		
		SFFloat *getRadiusField();
		
		void setRadius(float value);
		float getRadius();
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		SphereNode *next();
		SphereNode *nextTraversal();
		
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
		
		int getNPolygons();
		
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

