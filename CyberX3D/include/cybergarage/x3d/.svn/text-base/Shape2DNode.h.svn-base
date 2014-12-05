/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File: Shape2DNode.h
*
*	Revisions:
*
*	12/02/02
*		- The first revision.
*
******************************************************************/

#ifndef _CX3D_SHAPE2DNODE_H_
#define _CX3D_SHAPE2DNODE_H_

#include <cybergarage/x3d/VRML97Fields.h>
#include <cybergarage/x3d/Bounded2DNode.h>

namespace CyberX3D
{

	class Shape2DNode : public Bounded2DNode
	{
	
		SFNode *appField;
		SFNode *geomField;
		
	public:
	
		Shape2DNode();
		~Shape2DNode();
		
		////////////////////////////////////////////////
		//	Appearance
		////////////////////////////////////////////////
		
		SFNode *getAppearanceField();
		
		////////////////////////////////////////////////
		//	Geometry
		////////////////////////////////////////////////
		
		SFNode *getGeometryField();
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		Shape2DNode *next();
		Shape2DNode *nextTraversal();
		
		////////////////////////////////////////////////
		//	functions
		////////////////////////////////////////////////
		
		bool isChildNodeType(Node *node);
		void initialize();
		void uninitialize();
		void update();
		
		////////////////////////////////////////////////
		//	Infomation
		////////////////////////////////////////////////
		
		void outputContext(std::ostream &printStream, char *indentString);
	};
	
}

#endif

