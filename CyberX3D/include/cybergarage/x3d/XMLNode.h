/******************************************************************
*
*	CyberVRML97 for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	XMLNode.h
*
******************************************************************/

#ifndef _CV97_XMLNODE_H_
#define _CV97_XMLNODE_H_

#include <cybergarage/x3d/Node.h>
#include <cybergarage/x3d/XMLElement.h>

namespace CyberX3D
{

	class XMLNode : public Node
	{
	
	public:
	
		XMLNode();
		~XMLNode();
		
		////////////////////////////////////////////////
		//	Element Field
		////////////////////////////////////////////////
		
		XMLElement *getElement(const char *eleName);
		int getNElements();
		void addElement(XMLElement *ele);
		void addElement(const char *name, XMLElement *ele);
		void addElement(const char *name, const char *value);
		XMLElement *getElement(int index);
		/*
			bool removeElement(XMLElement *ele);
			bool removeElement(const char *eleName);
			int getElementNumber(XMLElement ele);
		*/
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		XMLNode *next();
		XMLNode *nextTraversal();
		
		////////////////////////////////////////////////
		//	virtual functions
		////////////////////////////////////////////////
		
		bool isChildNodeType(Node *node);
		void initialize();
		void uninitialize();
		void update();
		void outputContext(std::ostream &printStream, char *indentString);
	};
	
}

#endif
