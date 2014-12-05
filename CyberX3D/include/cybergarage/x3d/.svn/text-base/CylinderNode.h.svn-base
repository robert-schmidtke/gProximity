/******************************************************************
*
*	CyberVRML97 for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	CylinderNode.h
*
******************************************************************/

#ifndef _CV97_CYLINDER_H_
#define _CV97_CYLINDER_H_

#include <cybergarage/x3d/Geometry3DNode.h>

namespace CyberX3D
{

	const int DEFAULT_CYLINDERNODE_SLICES = 12;
	
	class CylinderNode : public Geometry3DNode
	{
	
		SFFloat *radiusField;
		SFFloat *heightField;
		SFBool *topField;
		SFBool *sideField;
		SFBool *bottomField;
		
	public:
	
		CylinderNode();
		~CylinderNode();
		
		////////////////////////////////////////////////
		//	radius
		////////////////////////////////////////////////
		
		SFFloat *getRadiusField();
		
		void setRadius(float value);
		float getRadius();
		
		////////////////////////////////////////////////
		//	height
		////////////////////////////////////////////////
		
		SFFloat *getHeightField();
		
		void setHeight(float value);
		float getHeight();
		
		////////////////////////////////////////////////
		//	top
		////////////////////////////////////////////////
		
		SFBool *getTopField();
		
		void setTop(bool value);
		void setTop(int value);
		bool getTop();
		
		////////////////////////////////////////////////
		//	side
		////////////////////////////////////////////////
		
		SFBool *getSideField();
		
		void setSide(bool value);
		void setSide(int value);
		bool getSide();
		
		////////////////////////////////////////////////
		//	bottom
		////////////////////////////////////////////////
		
		SFBool *getBottomField();
		
		void setBottom(bool  value);
		void setBottom(int value);
		bool  getBottom();
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		CylinderNode *next();
		CylinderNode *nextTraversal();
		
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

