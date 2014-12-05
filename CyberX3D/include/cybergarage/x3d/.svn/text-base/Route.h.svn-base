/******************************************************************
*
*	CyberVRML97 for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	Route.h
*
******************************************************************/

#ifndef _CV97_ROUTE_H_
#define _CV97_ROUTE_H_

#include <iostream>
#include <cybergarage/x3d/LinkedList.h>
#include <cybergarage/x3d/VRML97Fields.h>
#include <cybergarage/x3d/VRML97Nodes.h>
#include <cybergarage/x3d/JavaVM.h>

namespace CyberX3D
{

#ifdef SUPPORT_JSAI
	class Route : public LinkedListNode<Route>, public CJavaVM
	{
#else
	class Route : public LinkedListNode<Route>
	{
#endif
	
		Node	*mEventOutNode;
		Node	*mEventInNode;
		Field	*mEventOutField;
		Field	*mEventInField;
		
		bool	mIsActive;
		void	*mValue;
		
	public:
	
		Route(Node *eventOutNode, Field *eventOutField, Node *eventInNode, Field *eventInField);
		Route(Route *route);
		~Route();
		
		void	setEventOutNode(Node *node);
		void	setEventInNode(Node *node);
		Node	*getEventOutNode();
		Node	*getEventInNode();
		void	setEventOutField(Field *field);
		Field	*getEventOutField();
		void	setEventInField(Field *field);
		Field	*getEventInField();
		
		////////////////////////////////////////////////
		//	Active
		////////////////////////////////////////////////
		
		void setIsActive(bool active);
		bool	isActive();
		
		////////////////////////////////////////////////
		//	update
		////////////////////////////////////////////////
		
		void initialize();
		void update();
		
		////////////////////////////////////////////////
		//	update
		////////////////////////////////////////////////
		
		void setValue(void *value);
		void *getValue();
		
		////////////////////////////////////////////////
		//	output
		////////////////////////////////////////////////
		
		void output(std::ostream& printStream);
		void outputXML(std::ostream& printStream);
		
		void print()
		{
			output(std::cout);
		}
		
		void printXML()
		{
			outputXML(std::cout);
		}
	};
	
}

#endif
