/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	BoundedGrouping2DNode.h
*
******************************************************************/

#ifndef _CX3D_BOUNDEDGROUPING2DNODE_H_
#define _CX3D_BOUNDEDGROUPING2DNODE_H_

#include <cybergarage/x3d/Grouping2DNode.h>
#include <cybergarage/x3d/Bounded2DObject.h>
#include <cybergarage/x3d/BoundingBox2D.h>

namespace CyberX3D
{

	class BoundedGrouping2DNode : public Grouping2DNode, public Bounded2DObject
	{
	
		SFVec2f *bboxCenterField;
		SFVec2f *bboxSizeField;
		
	public:
	
		BoundedGrouping2DNode();
		virtual ~BoundedGrouping2DNode();
		
		////////////////////////////////////////////////
		//	BoundingBoxSize
		////////////////////////////////////////////////
		
		SFVec2f *getBoundingBoxSizeField();
		
		void setBoundingBoxSize(float value[]);
		void setBoundingBoxSize(float x, float y);
		void getBoundingBoxSize(float value[]);
		
		////////////////////////////////////////////////
		//	BoundingBoxCenter
		////////////////////////////////////////////////
		
		SFVec2f *getBoundingBoxCenterField();
		
		void setBoundingBoxCenter(float value[]);
		void setBoundingBoxCenter(float x, float y);
		void getBoundingBoxCenter(float value[]);
		
		////////////////////////////////////////////////
		//	BoundingBox2D
		////////////////////////////////////////////////
		
		void setBoundingBox(BoundingBox2D *bbox);
		void updateBoundingBox();
	};
	
	void UpdateBoundingBox(Node *node, BoundingBox2D *bbox);
	
}

#endif

