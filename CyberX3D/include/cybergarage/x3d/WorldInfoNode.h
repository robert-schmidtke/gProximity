/******************************************************************
*
*	CyberVRML97 for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	WorldInfoNode.h
*
******************************************************************/

#ifndef _CV97_WORLDINFONODE_H_
#define _CV97_WORLDINFONODE_H_

#include <cybergarage/x3d/VRML97Fields.h>
#include <cybergarage/x3d/InfoNode.h>

namespace CyberX3D
{

	class WorldInfoNode : public InfoNode
	{
	
		SFString *titleField;
		MFString *infoField;
		
	public:
	
		WorldInfoNode();
		~WorldInfoNode();
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		WorldInfoNode *next();
		WorldInfoNode *nextTraversal();
		
		////////////////////////////////////////////////
		//	Title
		////////////////////////////////////////////////
		
		SFString *getTitleField();
		
		void setTitle(char *value);
		char *getTitle();
		
		////////////////////////////////////////////////
		// Info
		////////////////////////////////////////////////
		
		MFString *getInfoField();
		
		void addInfo(char *value);
		int getNInfos();
		char *getInfo(int index);
		
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
		
		void outputContext(std::ostream& printStream, char *indentString);
	};
	
}

#endif
