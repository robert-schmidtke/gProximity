/******************************************************************
*
*	CyberVRML97 for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	RouteList.cpp
*
******************************************************************/

#include <cybergarage/x3d/RouteList.h>

using namespace CyberX3D;

RouteList::RouteList()
{
}

RouteList::~RouteList()
{
}

void RouteList::addRoute(Route *route)
{
	addNode(route);
}

Route *RouteList::getRoutes()
{
	return (Route *)getNodes();
}

Route *RouteList::getRoute(int n)
{
	return (Route *)getNode(n);
}

int RouteList::getNRoutes()
{
	return getNNodes();
}
