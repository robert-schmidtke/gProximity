/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File: ShapeNode.h
*
*	Revisions:
*
*	12/02/02
*		- Changed the super class from Node to BoundedNode.
*		- Added the follwing new X3D fields.
*			appearance, geometry
*
******************************************************************/

#ifndef _CX3D_SHAPENODE_H_
#define _CX3D_SHAPENODE_H_

#include <cybergarage/x3d/VRML97Fields.h>
#include <cybergarage/x3d/BoundedNode.h>
#include <cybergarage/x3d/AppearanceNode.h>
#include <cybergarage/x3d/Geometry3DNode.h>

namespace CyberX3D
{

	class ShapeNode : public BoundedNode
	{
	
		SFNode *appField;
		SFNode *geomField;
		
	public:
	
		ShapeNode();
		~ShapeNode();
		
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
		
		ShapeNode *next();
		ShapeNode *nextTraversal();
		
		////////////////////////////////////////////////
		//	Geometry
		////////////////////////////////////////////////
		
		Geometry3DNode *getGeometry3D();
		
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

