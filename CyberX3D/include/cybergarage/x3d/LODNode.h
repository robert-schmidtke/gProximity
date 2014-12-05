/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	LODNode.h
*
******************************************************************/

#ifndef _CV97_LODNODE_H_
#define _CV97_LODNODE_H_

#include <cybergarage/x3d/VRML97Fields.h>
#include <cybergarage/x3d/BoundedGroupingNode.h>

namespace CyberX3D
{

	class LODNode : public BoundedGroupingNode
	{
	
		SFVec3f *centerField;
		MFFloat *rangeField;
		
	public:
	
		LODNode();
		~LODNode();
		
		////////////////////////////////////////////////
		//	center
		////////////////////////////////////////////////
		
		SFVec3f *getCenterField();
		
		void setCenter(float value[]);
		void setCenter(float x, float y, float z);
		void getCenter(float value[]);
		
		////////////////////////////////////////////////
		//	range
		////////////////////////////////////////////////
		
		MFFloat *getRangeField();
		
		void addRange(float value);
		int getNRanges();
		float getRange(int index);
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		LODNode *next();
		LODNode *nextTraversal();
		
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
	
	void UpdateLod(LODNode *lod);
	void InitializeLod(LODNode *lod);
	void UninitializeLod(LODNode *lod);
	
}

#endif

