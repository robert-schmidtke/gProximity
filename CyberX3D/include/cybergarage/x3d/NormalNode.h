/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	NormalNode.h
*
******************************************************************/

#ifndef _CX3D_NORMALNODE_H_
#define _CX3D_NORMALNODE_H_

#include <cybergarage/x3d/VRML97Fields.h>
#include <cybergarage/x3d/GeometricPropertyNode.h>

namespace CyberX3D
{

	class NormalNode : public GeometricPropertyNode
	{
	
		MFVec3f *vectorField;
		
	public:
	
		NormalNode();
		~NormalNode();
		
		////////////////////////////////////////////////
		//	vector
		////////////////////////////////////////////////
		
		MFVec3f *getVectorField();
		
		void addVector(float value[]);
		int getNVectors();
		void getVector(int index, float value[]);
		
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
		
		NormalNode *next();
		NormalNode *nextTraversal();
	};
	
}

#endif

