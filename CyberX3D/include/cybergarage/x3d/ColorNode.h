/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	ColorNode.h
*
******************************************************************/

#ifndef _CX3D_COLORNODE_H_
#define _CX3D_COLORNODE_H_

#include <cybergarage/x3d/GeometricPropertyNode.h>

namespace CyberX3D
{

	class ColorNode : public GeometricPropertyNode
	{
	
		MFColor *colorField;
		
	public:
	
		ColorNode();
		~ColorNode();
		
		////////////////////////////////////////////////
		//	color
		////////////////////////////////////////////////
		
		MFColor *getColorField();
		
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
		
		ColorNode *next();
		ColorNode *nextTraversal();
	};
	
}

#endif
