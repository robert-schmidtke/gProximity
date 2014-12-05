/******************************************************************
*
*	CyberVRML97 for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	RouteList.h
*
******************************************************************/

#ifndef _CV97_ROUTELIST_H_
#define _CV97_ROUTELIST_H_

#include <cybergarage/x3d/LinkedList.h>
#include <cybergarage/x3d/Route.h>

namespace CyberX3D
{

	class RouteList : public LinkedList<Route>
	{
	
	public:
	
		RouteList();
		~RouteList();
		
		void addRoute(Route *route);
		Route *getRoutes();
		Route *getRoute(int n);
		int getNRoutes();
	};
	
}

#endif
