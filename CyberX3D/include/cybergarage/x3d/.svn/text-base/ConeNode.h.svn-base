/******************************************************************
*
*	CyberVRML97 for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	ConeNode.h
*
******************************************************************/

#ifndef _CV97_CONE_H_
#define _CV97_CONE_H_

#include <cybergarage/x3d/Geometry3DNode.h>

namespace CyberX3D
{

	const int DEFAULT_CONENODE_SLICES = 15;
	
	class ConeNode : public Geometry3DNode
	{
	
		SFFloat *bottomRadiusField;
		SFFloat *heightField;
		SFBool *sideField;
		SFBool *bottomField;
		
	public:
	
		ConeNode();
		~ConeNode();
		
		////////////////////////////////////////////////
		//	bottomRadius
		////////////////////////////////////////////////
		
		SFFloat *getBottomRadiusField();
		
		void setBottomRadius(float value);
		float getBottomRadius();
		
		////////////////////////////////////////////////
		//	height
		////////////////////////////////////////////////
		
		SFFloat *getHeightField();
		
		void setHeight(float value);
		float getHeight();
		
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
		
		void setBottom(bool value);
		void setBottom(int value);
		bool getBottom();
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		ConeNode *next();
		ConeNode *nextTraversal();
		
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

