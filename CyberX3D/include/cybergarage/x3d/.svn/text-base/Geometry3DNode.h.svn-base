/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	Geometry3DNode.h
*
******************************************************************/

#ifndef _CV97_GEOMETRY3DNODE_H_
#define _CV97_GEOMETRY3DNODE_H_

#include <cybergarage/x3d/X3DFields.h>
#include <cybergarage/x3d/GeometryNode.h>
#include <cybergarage/x3d/BoundingBox.h>

namespace CyberX3D
{

	const char bboxCenterPrivateFieldName[] = "bboxCenter";
	const char bboxSizePrivateFieldName[] = "bboxSize";
	
	class Geometry3DNode : public GeometryNode
	{
	
		SFVec3f *bboxCenterField;
		SFVec3f *bboxSizeField;
		
		int slices;
		
	public:
	
		Geometry3DNode();
		virtual ~Geometry3DNode();
		
		////////////////////////////////////////////////
		//	BoundingBoxSize
		////////////////////////////////////////////////
		
		SFVec3f *getBoundingBoxSizeField();
		
		void setBoundingBoxSize(float value[]);
		void setBoundingBoxSize(float x, float y, float z);
		void getBoundingBoxSize(float value[]);
		
		////////////////////////////////////////////////
		//	BoundingBoxCenter
		////////////////////////////////////////////////
		
		SFVec3f *getBoundingBoxCenterField();
		
		void setBoundingBoxCenter(float value[]);
		void setBoundingBoxCenter(float x, float y, float z);
		void getBoundingBoxCenter(float value[]);
		
		////////////////////////////////////////////////
		//	BoundingBox
		////////////////////////////////////////////////
		
		void setBoundingBox(BoundingBox *bbox);
		
		////////////////////////////////////////////////
		//	Slices
		////////////////////////////////////////////////
		
		void setSlices(int value)
		{
			slices = value;
		}
		
		int getSlices()
		{
			return slices;
		}
		
		////////////////////////////////////////////////
		//	Polygons
		////////////////////////////////////////////////
		
		virtual int getNPolygons() = 0;
	};
	
}

#endif
