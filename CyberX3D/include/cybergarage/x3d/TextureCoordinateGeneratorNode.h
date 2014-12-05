/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	TextureCoordinateGeneratorNode.h
*
******************************************************************/

#ifndef _CX3D_TEXCOORDGENNODE_H_
#define _CX3D_TEXCOORDGENNODE_H_

#include <cybergarage/x3d/Node.h>

namespace CyberX3D
{

	class TextureCoordinateGeneratorNode : public Node
	{
		MFFloat *parameterField;
		SFString *modeField;
		
	public:
	
		TextureCoordinateGeneratorNode();
		~TextureCoordinateGeneratorNode();
		
		////////////////////////////////////////////////
		//	parameter
		////////////////////////////////////////////////
		
		MFFloat *getParameterField();
		
		void addParameter(float value);
		int getNParameters();
		float getParameter(int index);
		
		////////////////////////////////////////////////
		//	mode
		////////////////////////////////////////////////
		
		SFString *getModeField();
		
		void setMode(const char *value);
		char *getMode();
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		TextureCoordinateGeneratorNode	*next();
		TextureCoordinateGeneratorNode	*nextTraversal();
		
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
