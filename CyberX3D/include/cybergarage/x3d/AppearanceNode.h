/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	AppearanceNode.h
*
******************************************************************/

#ifndef _CX3D_APPEARANCENODE_H_
#define _CX3D_APPEARANCENODE_H_

#include <cybergarage/x3d/VRML97Fields.h>
#include <cybergarage/x3d/Node.h>
#include <cybergarage/x3d/MaterialNode.h>
#include <cybergarage/x3d/TextureTransformNode.h>

namespace CyberX3D
{

	class AppearanceNode : public Node
	{
	
		SFNode *materialField;
		SFNode *textureField;
		SFNode *texTransformField;
		SFNode *linePropertiesField;
		SFNode *fillPropertiesField;
		
	public:
	
		AppearanceNode();
		~AppearanceNode();
		
		////////////////////////////////////////////////
		//	SFNode Field
		////////////////////////////////////////////////
		
		SFNode *getMaterialField();
		SFNode *getTextureField();
		SFNode *getTextureTransformField();
		SFNode *getLinePropertiesField();
		SFNode *getFillPropertiesField();
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		AppearanceNode *next();
		AppearanceNode *nextTraversal();
		
		////////////////////////////////////////////////
		//	virtual functions
		////////////////////////////////////////////////
		
		bool isChildNodeType(Node *node);
		void initialize();
		void uninitialize();
		void update();
		void outputContext(std::ostream &printStream, char *indentString);
	};
	
}

#endif
