/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	ColorRGBANode.h
*
******************************************************************/

#ifndef _CX3D_COLORRGBANODE_H_
#define _CX3D_COLORRGBANODE_H_

#include <cybergarage/x3d/GeometricPropertyNode.h>

namespace CyberX3D
{

	class ColorRGBANode : public GeometricPropertyNode
	{
	
		MFColorRGBA *colorField;
		
	public:
	
		ColorRGBANode();
		~ColorRGBANode();
		
		////////////////////////////////////////////////
		//	color
		////////////////////////////////////////////////
		
		MFColorRGBA *getColorField();
		
		void addColor(float color[]);
		int getNColors();
		void getColor(int index, float color[]);
		
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
		
		ColorRGBANode *next();
		ColorRGBANode *nextTraversal();
	};
	
}

#endif
