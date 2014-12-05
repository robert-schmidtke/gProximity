/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	PixelTextureNode.h
*
******************************************************************/

#ifndef _CX3D_PIXELTEXTURENODE_H_
#define _CX3D_PIXELTEXTURENODE_H_

#include <cybergarage/x3d/VRML97Fields.h>
#include <cybergarage/x3d/Texture2DNode.h>

namespace CyberX3D
{

	class PixelTextureNode : public Texture2DNode
	{
	
		SFImage *imageField;
		
	public:
	
		PixelTextureNode();
		~PixelTextureNode();
		
		////////////////////////////////////////////////
		// Image
		////////////////////////////////////////////////
		
		SFImage *getImageField();
		
		void addImage(int value);
		int getNImages();
		int getImage(int index);
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		PixelTextureNode *next();
		PixelTextureNode *nextTraversal();
		
		////////////////////////////////////////////////
		//	functions
		////////////////////////////////////////////////
		
		bool isChildNodeType(Node *node);
		void initialize();
		void uninitialize();
		void update();
		
		////////////////////////////////////////////////
		//	Imagemation
		////////////////////////////////////////////////
		
		void outputContext(std::ostream &printStream, char *indentString);
	};
	
}

#endif

