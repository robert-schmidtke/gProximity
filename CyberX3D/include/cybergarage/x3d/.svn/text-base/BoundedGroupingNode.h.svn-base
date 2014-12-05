/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	BoundedGroupingNode.h
*
******************************************************************/

#ifndef _CX3D_BOUNDEDGROUPINGNODE_H_
#define _CX3D_BOUNDEDGROUPINGNODE_H_

#include <cybergarage/x3d/GroupingNode.h>
#include <cybergarage/x3d/BoundedObject.h>
#include <cybergarage/x3d/BoundingBox.h>

namespace CyberX3D
{

	class BoundedGroupingNode : public GroupingNode, public BoundedObject
	{
	
		SFVec3f *bboxCenterField;
		SFVec3f *bboxSizeField;
		
	public:
	
		BoundedGroupingNode();
		virtual ~BoundedGroupingNode();
		
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
		void updateBoundingBox();
	};
	
	void UpdateBoundingBox(Node *node, BoundingBox *bbox);
	
}

#endif

