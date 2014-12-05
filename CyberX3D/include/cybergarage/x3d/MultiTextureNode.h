/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	MultiTextureNodeNode.h
*
******************************************************************/

#ifndef _CX3D_MULTITEXTURENODE_H_
#define _CX3D_MULTITEXTURENODE_H_

#include <cybergarage/x3d/X3DFields.h>
#include <cybergarage/x3d/TextureNode.h>

namespace CyberX3D
{

	class MultiTextureNode : public TextureNode
	{
		SFBool *materialColorField;
		SFBool *materialAlphaField;
		SFBool *transparentField;
		SFBool *nomipmapField;
		MFString *modeField;
		SFNode *textureField;
		SFNode *texTransformField;
		SFColor *colorField;
		SFFloat *alphaField;
		
	public:
	
		MultiTextureNode();
		~MultiTextureNode();
		
		////////////////////////////////////////////////
		//	SFNode Field
		////////////////////////////////////////////////
		
		SFNode *getTextureField();
		SFNode *getTextureTransformField();
		
		////////////////////////////////////////////////
		//	MaterialColor
		////////////////////////////////////////////////
		
		SFBool *getMaterialColorField();
		
		void setMaterialColor(bool value);
		bool getMaterialColor();
		bool isMaterialColor();
		
		////////////////////////////////////////////////
		//	MaterialAlpha
		////////////////////////////////////////////////
		
		SFBool *getMaterialAlphaField();
		
		void setMaterialAlpha(bool value);
		bool getMaterialAlpha();
		bool isMaterialAlpha();
		
		////////////////////////////////////////////////
		//	Transparent
		////////////////////////////////////////////////
		
		SFBool *getTransparentField();
		
		void setTransparent(bool value);
		bool getTransparent();
		bool isTransparent();
		
		////////////////////////////////////////////////
		//	Nomipmap
		////////////////////////////////////////////////
		
		SFBool *getNomipmapField();
		
		void setNomipmap(bool value);
		bool getNomipmap();
		bool isNomipmap();
		
		////////////////////////////////////////////////
		// Mode
		////////////////////////////////////////////////
		
		MFString *getModeField();
		
		void	addMode(char *value);
		int		getNModes();
		char *getMode(int index);
		
		////////////////////////////////////////////////
		//	Alpha
		////////////////////////////////////////////////
		
		SFFloat *getAlphaField();
		
		void setAlpha(float value);
		float getAlpha();
		
		////////////////////////////////////////////////
		//	Color
		////////////////////////////////////////////////
		
		SFColor *getColorField();
		
		void setColor(float value[]);
		void setColor(float r, float g, float b);
		void getColor(float value[]);
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		MultiTextureNode	*next();
		MultiTextureNode	*nextTraversal();
		
		////////////////////////////////////////////////
		//	virtual functions
		////////////////////////////////////////////////
		
		bool	isChildNodeType(Node *node);
		void	initialize();
		void	uninitialize();
		void	update();
		void	outputContext(std::ostream &printStream, char *indentString);
		
	};
	
}

#endif
