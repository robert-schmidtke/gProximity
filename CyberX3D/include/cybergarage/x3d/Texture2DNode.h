/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	Texture2DNode.h
*
******************************************************************/

#ifndef _CX3D_TEXTURE2DNODE_H_
#define _CX3D_TEXTURE2DNODE_H_

#include <cybergarage/x3d/VRML97Fields.h>
#include <cybergarage/x3d/TextureNode.h>
#include <cybergarage/x3d/FileImage.h>

#ifdef SUPPORT_OPENGL
const char textureNamePrivateFieldString[] = "oglTextureName";
const char hasTransparencyColorPrivateFieldString[] = "hasTransparencyColor";
#endif

namespace CyberX3D
{

	class Texture2DNode : public TextureNode
	{
		SFBool *repeatSField;
		SFBool *repeatTField;
		
		SFInt32 *texNameField;
		SFBool *hasTransColorField;
		
	public:
	
		Texture2DNode();
		virtual ~Texture2DNode();
		
		////////////////////////////////////////////////
		//	RepeatS
		////////////////////////////////////////////////
		
		SFBool *getRepeatSField();
		
		void setRepeatS(bool value);
		void setRepeatS(int value);
		bool getRepeatS();
		
		////////////////////////////////////////////////
		//	RepeatT
		////////////////////////////////////////////////
		
		SFBool *getRepeatTField();
		
		void setRepeatT(bool value);
		void setRepeatT(int value);
		bool getRepeatT();
		
		////////////////////////////////////////////////
		//	Virtual Methods
		////////////////////////////////////////////////
		
		virtual int getWidth()
		{
			return 0;
		}
		
		virtual int getHeight()
		{
			return 0;
		}
		
		virtual RGBAColor32	*getImage()
		{
			return NULL;
		}
		
#ifdef SUPPORT_OPENGL
		
		////////////////////////////////////////////////
		//	TextureName
		////////////////////////////////////////////////
		
		SFInt32 *getTextureNameField();
		
		void setTextureName(unsigned int n);
		unsigned int getTextureName();
		
		////////////////////////////////////////////////
		//	Transparency
		////////////////////////////////////////////////
		
		SFBool *getHasTransparencyColorField();
		
		void setHasTransparencyColor(bool value);
		bool hasTransparencyColor();
		
#endif
		
	};
	
#ifdef SUPPORT_OPENGL
	int GetOpenGLTextureSize(int size);
#endif
	
}

#endif

