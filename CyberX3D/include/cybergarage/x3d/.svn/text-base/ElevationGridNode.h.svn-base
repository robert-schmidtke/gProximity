/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	ElevationGridNode.h
*
******************************************************************/

#ifndef _CX3D_ELEVATIONGRIDNODE_H_
#define _CX3D_ELEVATIONGRIDNODE_H_

#include <cybergarage/x3d/ComposedGeometryNode.h>
#include <cybergarage/x3d/ColorNode.h>
#include <cybergarage/x3d/NormalNode.h>
#include <cybergarage/x3d/TextureCoordinateNode.h>

namespace CyberX3D
{

	class ElevationGridNode : public ComposedGeometryNode
	{
		SFFloat *xSpacingField;
		SFFloat *zSpacingField;
		SFInt32 *xDimensionField;
		SFInt32 *zDimensionField;
		SFFloat *creaseAngleField;
		MFFloat *heightField;
		
	public:
	
		ElevationGridNode();
		~ElevationGridNode();
		
		////////////////////////////////////////////////
		//	xSpacing
		////////////////////////////////////////////////
		
		SFFloat *getXSpacingField();
		
		void setXSpacing(float value);
		float getXSpacing();
		
		////////////////////////////////////////////////
		//	zSpacing
		////////////////////////////////////////////////
		
		SFFloat *getZSpacingField();
		
		void setZSpacing(float value);
		float getZSpacing();
		
		////////////////////////////////////////////////
		//	xDimension
		////////////////////////////////////////////////
		
		SFInt32 *getXDimensionField();
		
		void setXDimension(int value);
		int getXDimension();
		
		////////////////////////////////////////////////
		//	zDimension
		////////////////////////////////////////////////
		
		SFInt32 *getZDimensionField();
		
		void setZDimension(int value);
		int getZDimension();
		
		////////////////////////////////////////////////
		//	CreaseAngle
		////////////////////////////////////////////////
		
		SFFloat *getCreaseAngleField();
		
		void setCreaseAngle(float value);
		float getCreaseAngle();
		
		////////////////////////////////////////////////
		// height
		////////////////////////////////////////////////
		
		MFFloat *getHeightField();
		
		void addHeight(float value);
		int getNHeights();
		float getHeight(int index);
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		ElevationGridNode *next();
		ElevationGridNode *nextTraversal();
		
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

