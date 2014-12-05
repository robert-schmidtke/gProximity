/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	Transform2DNode.h
*
******************************************************************/

#ifndef _CX3D_TRANSFORM2DNODE_H_
#define _CX3D_TRANSFORM2DNODE_H_

#include <cybergarage/x3d/BoundedGrouping2DNode.h>

namespace CyberX3D
{

	class Transform2DNode : public BoundedGrouping2DNode
	{
	
		SFVec2f *translationField;
		SFVec2f *scaleField;
		SFRotation *rotationField;
		SFRotation *scaleOrientationField;
		
	public:
	
		Transform2DNode();
		~Transform2DNode();
		
		////////////////////////////////////////////////
		//	Translation
		////////////////////////////////////////////////
		
		SFVec2f *getTranslationField();
		
		void setTranslation(float value[]);
		void setTranslation(float x, float y);
		void getTranslation(float value[]);
		
		////////////////////////////////////////////////
		//	Scale
		////////////////////////////////////////////////
		
		SFVec2f *getScaleField();
		
		void setScale(float value[]);
		void setScale(float x, float y);
		void getScale(float value[]);
		
		////////////////////////////////////////////////
		//	Rotation
		////////////////////////////////////////////////
		
		SFRotation *getRotationField();
		
		void setRotation(float value[]);
		void setRotation(float x, float y, float z, float w);
		void getRotation(float value[]);
		
		////////////////////////////////////////////////
		//	ScaleOrientation
		////////////////////////////////////////////////
		
		SFRotation *getScaleOrientationField();
		
		void setScaleOrientation(float value[]);
		void setScaleOrientation(float x, float y, float z, float w);
		void getScaleOrientation(float value[]);
		
		////////////////////////////////////////////////
		//	Matrix
		////////////////////////////////////////////////
		
		void getSFMatrix(SFMatrix *mOut);
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		Transform2DNode *next();
		Transform2DNode *nextTraversal();
		
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
