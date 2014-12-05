/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	LinePropertiesNode.h
*
******************************************************************/

#ifndef _CX3D_LINEPROPERTIESNODE_H_
#define _CX3D_LINEPROPERTIESNODE_H_

#include <cybergarage/x3d/VRML97Fields.h>
#include <cybergarage/x3d/AppearanceChildNode.h>

namespace CyberX3D
{

	class LinePropertiesNode : public AppearanceChildNode
	{
	
		SFInt32 *lineStyleField;
		SFFloat *widthField;
		
	public:
	
		LinePropertiesNode();
		~LinePropertiesNode();
		
		////////////////////////////////////////////////
		//	LineStyle
		////////////////////////////////////////////////
		
		SFInt32 *getLineStyleField();
		
		void setLineStyle(int value);
		int getLineStyle();
		
		////////////////////////////////////////////////
		//	Width
		////////////////////////////////////////////////
		
		SFFloat *getWidthField();
		
		void setWidth(float value);
		float getWidth();
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		LinePropertiesNode *next();
		LinePropertiesNode *nextTraversal();
		
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
