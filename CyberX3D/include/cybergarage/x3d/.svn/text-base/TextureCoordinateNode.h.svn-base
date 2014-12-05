/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	TextureCoordinateNode.h
*
******************************************************************/

#ifndef _CX3D_TEXTURECOORDINATENODE_H_
#define _CX3D_TEXTURECOORDINATENODE_H_

#include <cybergarage/x3d/VRML97Fields.h>
#include <cybergarage/x3d/GeometricPropertyNode.h>

namespace CyberX3D
{

	class TextureCoordinateNode : public GeometricPropertyNode
	{
	
		MFVec2f *pointField;
		
	public:
	
		TextureCoordinateNode();
		~TextureCoordinateNode();
		
		////////////////////////////////////////////////
		//	point
		////////////////////////////////////////////////
		
		MFVec2f *getPointField();
		
		void addPoint(float point[]);
		int getNPoints();
		void getPoint(int index, float point[]);
		
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
		
		TextureCoordinateNode *next();
		TextureCoordinateNode *nextTraversal();
		
	};
	
}

#endif

