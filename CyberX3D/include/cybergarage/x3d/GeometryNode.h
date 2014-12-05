/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	GeometryNode.h
*
******************************************************************/

#ifndef _CV97_GEOMETRYNODE_H_
#define _CV97_GEOMETRYNODE_H_

#include <cybergarage/x3d/VRML97Fields.h>
#include <cybergarage/x3d/Node.h>

namespace CyberX3D
{

#ifdef SUPPORT_OPENGL
	const char displayListPrivateFieldString[] = "oglDisplayList";
#endif
	
	class GeometryNode : public Node
	{
	
#ifdef SUPPORT_OPENGL
		SFInt32 *dispListField;
#endif
		
	public:
	
		GeometryNode();
		virtual ~GeometryNode();
		
		////////////////////////////////////////////////
		//	DisplayList
		////////////////////////////////////////////////
		
#ifdef SUPPORT_OPENGL
		
		SFInt32 *getDisplayListField();
		void setDisplayList(unsigned int n);
		unsigned int getDisplayList();
		virtual void draw();
		
#endif
	};
	
}

#endif
