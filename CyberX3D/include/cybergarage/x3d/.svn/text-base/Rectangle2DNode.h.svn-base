/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	Rectangle2DNode.h
*
******************************************************************/

#ifndef _CX3D_RECTANGLE2D_H_
#define _CX3D_RECTANGLE2D_H_

#include <cybergarage/x3d/Geometry2DNode.h>

namespace CyberX3D
{

	class Rectangle2DNode : public Geometry2DNode
	{
	
		MFVec2f *sizeField;
		SFBool *isFilledField;
		
	public:
	
		Rectangle2DNode();
		~Rectangle2DNode();
		
		////////////////////////////////////////////////
		//	Size
		////////////////////////////////////////////////
		
		MFVec2f *getSizeField();
		
		int getNSize();
		void addSize(float point[]);
		void addSize(float x, float y);
		void getSize(int index, float point[]);
		void setSize(int index, float point[]);
		void setSize(int index, float x, float y);
		void removeSize(int index);
		void removeAllSize();
		
		////////////////////////////////////////////////
		//	side
		////////////////////////////////////////////////
		
		SFBool *getIsFilledField();
		
		void setIsFilled(bool value);
		void setIsFilled(int value);
		bool getIsFilled();
		bool isFilled();
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		Rectangle2DNode *next();
		Rectangle2DNode *nextTraversal();
		
		////////////////////////////////////////////////
		//	functions
		////////////////////////////////////////////////
		
		bool isChildNodeType(Node *node);
		void initialize();
		void uninitialize();
		void update();
		
		////////////////////////////////////////////////
		//	recomputeDisplayList
		////////////////////////////////////////////////
		
#ifdef SUPPORT_OPENGL
		void recomputeDisplayList();
#endif
		
		////////////////////////////////////////////////
		//	Infomation
		////////////////////////////////////////////////
		
		void outputContext(std::ostream &printStream, char *indentString);
	};
	
}

#endif
