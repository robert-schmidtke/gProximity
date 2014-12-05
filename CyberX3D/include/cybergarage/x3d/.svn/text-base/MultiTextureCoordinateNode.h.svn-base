/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	MultiTextureCoordinateNode.h
*
******************************************************************/

#ifndef _CX3D_MULTITEXTURECOORDINATENODE_H_
#define _CX3D_MULTITEXTURECOORDINATENODE_H_

#include <cybergarage/x3d/X3DFields.h>
#include <cybergarage/x3d/Node.h>

namespace CyberX3D
{

	class MultiTextureCoordinateNode : public Node
	{
		MFNode *texCoordField;
		
	public:
	
		MultiTextureCoordinateNode();
		~MultiTextureCoordinateNode();
		
		////////////////////////////////////////////////
		//	texCoord
		////////////////////////////////////////////////
		
		MFNode *getTexCoordField();
		
		void addTexCoord(Node *value);
		int getNTexCoords();
		Node *getTexCoord(int index);
		
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
		
		MultiTextureCoordinateNode *next();
		MultiTextureCoordinateNode *nextTraversal();
	};
	
}

#endif
