/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2003
*
*	File:	RouteNode.h
*
******************************************************************/

#ifndef _CX3D_ROUTENODE_H_
#define _CX3D_ROUTENODE_H_

#include <cybergarage/x3d/VRML97Fields.h>
#include <cybergarage/x3d/Node.h>

namespace CyberX3D
{

//<ROUTE fromField="isActive" fromNode="red_pipe" toField="toggle" toNode="linkFailure"/>

	class RouteNode : public Node
	{
	
		SFString *fromField;
		SFString *fromNode;
		SFString *toField;
		SFString *toNode;
		
	public:
	
		RouteNode();
		~RouteNode();
		
		////////////////////////////////////////////////
		//	Field
		////////////////////////////////////////////////
		
		SFString *getFromField();
		SFString *getFromNode();
		SFString *getToField();
		SFString *getToNode();
		
		void setFromFieldName(const char *value);
		void setFromNodeName(const char *value);
		void setToFieldName(const char *value);
		void setToNodeName(const char *value);
		
		char *getFromFieldName();
		char *getFromNodeName();
		char *getToFieldName();
		char *getToNodeName();
		
		////////////////////////////////////////////////
		//	Output
		////////////////////////////////////////////////
		
		void outputContext(std::ostream &printStream, char *indentString);
		
		////////////////////////////////////////////////
		//	functions
		////////////////////////////////////////////////
		
		bool isChildNodeType(Node *node);
		void initialize();
		void uninitialize();
		void update();
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		RouteNode *next();
		RouteNode *nextTraversal();
	};
	
}

#endif

