/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	CoordinateNode.h
*
******************************************************************/

#ifndef _CX3D_COOORDINATENODE_H_
#define _CX3D_COOORDINATENODE_H_

#include <cybergarage/x3d/VRML97Fields.h>
#include <cybergarage/x3d/GeometricPropertyNode.h>

namespace CyberX3D
{

	class CoordinateNode : public GeometricPropertyNode
	{
	
		MFVec3f *pointField;
		
	public:
	
		CoordinateNode();
		~CoordinateNode();
		
		////////////////////////////////////////////////
		//	point
		////////////////////////////////////////////////
		
		MFVec3f *getPointField();
		
		void addPoint(float point[]);
		void addPoint(float x, float y, float z);
		int getNPoints();
		void getPoint(int index, float point[]);
		void setPoint(int index, float point[]);
		void setPoint(int index, float x, float y, float z);
		void removePoint(int index);
		void removeLastPoint();
		void removeFirstPoint();
		void removeAllPoints();
		
		////////////////////////////////////////////////
		//	functions
		////////////////////////////////////////////////
		
		bool isChildNodeType(Node *node);
		void initialize();
		void uninitialize();
		void update();
		
		////////////////////////////////////////////////
		//	Output
		////////////////////////////////////////////////
		
		void outputContext(std::ostream &printStream, char *indentString);
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		CoordinateNode *next();
		CoordinateNode *nextTraversal();
	};
	
}

#endif

