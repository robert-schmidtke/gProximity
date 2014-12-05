/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	MultiTextureTransformNode.h
*
******************************************************************/

#ifndef _CX3D_MULTITEXTURETRANSFORMNODE_H_
#define _CX3D_MULTITEXTURETRANSFORMNODE_H_

#include <cybergarage/x3d/X3DFields.h>
#include <cybergarage/x3d/Node.h>

namespace CyberX3D
{

	class MultiTextureTransformNode : public Node
	{
		MFNode *textureTransformField;
		
	public:
	
		MultiTextureTransformNode();
		~MultiTextureTransformNode();
		
		////////////////////////////////////////////////
		//	textureTransform
		////////////////////////////////////////////////
		
		MFNode *getTextureTransformField();
		
		void addTextureTransform(Node *value);
		int getNTextureTransforms();
		Node *getTextureTransform(int index);
		
		////////////////////////////////////////////////
		//	functions
		////////////////////////////////////////////////
		
		bool isChildNodeType(Node *node);
		void initialize();
		void uninitialize();
		void update();
		
		////////////////////////////////////////////////
		//	Output
		////////////////////////////////////////////////
		
		void outputContext(std::ostream &printStream, char *indentString);
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		MultiTextureTransformNode *next();
		MultiTextureTransformNode *nextTraversal();
	};
	
}

#endif
