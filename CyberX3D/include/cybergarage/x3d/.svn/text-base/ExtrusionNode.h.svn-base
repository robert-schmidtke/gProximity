/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	ExtrusionNode.h
*
******************************************************************/

#ifndef _CX3D_EXTRUSIONNODE_H_
#define _CX3D_EXTRUSIONNODE_H_

#include <cybergarage/x3d/Geometry3DNode.h>

namespace CyberX3D
{

	class ExtrusionNode : public Geometry3DNode
	{
		SFBool *beginCapField;
		SFBool *endCapField;
		SFBool *convexField;
		SFFloat *creaseAngleField;
		SFBool *ccwField;
		SFBool *solidField;
		MFRotation *orientationField;
		MFVec2f *scaleField;
		MFVec2f *crossSectionField;
		MFVec3f *spineField;
		
	public:
	
		ExtrusionNode();
		~ExtrusionNode();
		
		////////////////////////////////////////////////
		//	BeginCap
		////////////////////////////////////////////////
		
		SFBool *getBeginCapField();
		
		void setBeginCap(bool value);
		void setBeginCap(int value);
		bool getBeginCap();
		
		////////////////////////////////////////////////
		//	EndCap
		////////////////////////////////////////////////
		
		SFBool *getEndCapField();
		
		void setEndCap(bool value);
		void setEndCap(int value);
		bool getEndCap();
		
		////////////////////////////////////////////////
		//	Convex
		////////////////////////////////////////////////
		
		SFBool *getConvexField();
		
		void setConvex(bool value);
		void setConvex(int value);
		bool getConvex();
		
		////////////////////////////////////////////////
		//	CCW
		////////////////////////////////////////////////
		
		SFBool *getCCWField();
		
		void setCCW(bool value);
		void setCCW(int value);
		bool getCCW();
		
		////////////////////////////////////////////////
		//	Solid
		////////////////////////////////////////////////
		
		SFBool *getSolidField();
		
		void setSolid(bool value);
		void setSolid(int value);
		bool getSolid();
		
		////////////////////////////////////////////////
		//	CreaseAngle
		////////////////////////////////////////////////
		
		SFFloat *getCreaseAngleField();
		
		void setCreaseAngle(float value);
		float getCreaseAngle();
		
		////////////////////////////////////////////////
		// orientation
		////////////////////////////////////////////////
		
		MFRotation *getOrientationField();
		
		void addOrientation(float value[]);
		void addOrientation(float x, float y, float z, float angle);
		int getNOrientations();
		void getOrientation(int index, float value[]);
		
		////////////////////////////////////////////////
		// scale
		////////////////////////////////////////////////
		
		MFVec2f *getScaleField();
		
		void addScale(float value[]);
		void addScale(float x, float z);
		int getNScales();
		void getScale(int index, float value[]);
		
		////////////////////////////////////////////////
		// crossSection
		////////////////////////////////////////////////
		
		MFVec2f *getCrossSectionField();
		
		void addCrossSection(float value[]);
		void addCrossSection(float x, float z);
		int getNCrossSections();
		void getCrossSection(int index, float value[]);
		
		////////////////////////////////////////////////
		// spine
		////////////////////////////////////////////////
		
		MFVec3f *getSpineField();
		
		void addSpine(float value[]);
		void addSpine(float x, float y, float z);
		int getNSpines();
		void getSpine(int index, float value[]);
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		ExtrusionNode *next();
		ExtrusionNode *nextTraversal();
		
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
		//	recomputeDisplayList
		////////////////////////////////////////////////
		
		void recomputeDisplayList();
		
		////////////////////////////////////////////////
		//	Polygons
		////////////////////////////////////////////////
		
		int getNPolygons();
		
		////////////////////////////////////////////////
		//	Infomation
		////////////////////////////////////////////////
		
		void outputContext(std::ostream &printStream, char *indentString);
	};
	
}

#endif

