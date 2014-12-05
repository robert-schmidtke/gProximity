/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	ArcClose2DNode.h
*
******************************************************************/

#ifndef _CX3D_ARCCLOSE2DNODE_H_
#define _CX3D_ARCCLOSE2DNODE_H_

#include <cybergarage/x3d/Arc2DNode.h>

namespace CyberX3D
{

	class ArcClose2DNode : public Arc2DNode
	{
	
		SFString *closureTypeField;
		
	public:
	
		ArcClose2DNode();
		~ArcClose2DNode();
		
		////////////////////////////////////////////////
		//	ClosureType
		////////////////////////////////////////////////
		
		SFString *getClosureTypeField();
		
		void setClosureType(const char *value);
		char *getClosureType();
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		ArcClose2DNode *next();
		ArcClose2DNode *nextTraversal();
		
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
