/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	InlineNode.h
*
******************************************************************/

#ifndef _CV97_INLINENODE_H_
#define _CV97_INLINENODE_H_

#include <cybergarage/x3d/BoundedNode.h>

namespace CyberX3D
{

	class InlineNode : public BoundedNode
	{
	
		MFString *urlField;
		SFBool *loadField;
		
	public:
	
		InlineNode();
		~InlineNode();
		
		////////////////////////////////////////////////
		// Url
		////////////////////////////////////////////////
		
		MFString *getUrlField();
		
		void addUrl(char *value);
		int getNUrls();
		char *getUrl(int index);
		void setUrl(int index, char *urlString);
		
		////////////////////////////////////////////////
		//	Load (X3D)
		////////////////////////////////////////////////
		
		SFBool *getLoadField();
		
		void setLoad(bool value);
		bool getLoad();
		bool isLoad();
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		InlineNode *next();
		InlineNode *nextTraversal();
		
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

