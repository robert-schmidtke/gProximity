/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	FillPropertiesNode.h
*
******************************************************************/

#ifndef _CX3D_FILLPROPERTIESNODE_H_
#define _CX3D_FILLPROPERTIESNODE_H_

#include <cybergarage/x3d/VRML97Fields.h>
#include <cybergarage/x3d/AppearanceChildNode.h>

namespace CyberX3D
{

	class FillPropertiesNode : public AppearanceChildNode
	{
	
		SFString *fillStyleField;
		SFInt32 *hatchStyleField;
		SFColor *hatchColorField;
		
	public:
	
		FillPropertiesNode();
		~FillPropertiesNode();
		
		////////////////////////////////////////////////
		//	FillStyle
		////////////////////////////////////////////////
		
		SFString *getFillStyleField();
		
		void setFillStyle(const char *value);
		char *getFillStyle();
		
		////////////////////////////////////////////////
		//	HatchStyle
		////////////////////////////////////////////////
		
		SFInt32 *getHatchStyleField();
		
		void setHatchStyle(int value);
		int getHatchStyle();
		
		////////////////////////////////////////////////
		//	HatchColor
		////////////////////////////////////////////////
		
		SFColor *getHatchColorField();
		
		void setHatchColor(float value[]);
		void setHatchColor(float r, float g, float b);
		void getHatchColor(float value[]);
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		FillPropertiesNode *next();
		FillPropertiesNode *nextTraversal();
		
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
