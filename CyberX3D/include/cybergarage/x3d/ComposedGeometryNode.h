/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	ComposedGeometryNode.h
*
******************************************************************/

#ifndef _CX3D_COMPOSEDGEOMETRYNODE_H_
#define _CX3D_COMPOSEDGEOMETRYNODE_H_

#include <cybergarage/x3d/Geometry3DNode.h>
#include <cybergarage/x3d/NormalNode.h>
#include <cybergarage/x3d/ColorNode.h>
#include <cybergarage/x3d/CoordinateNode.h>
#include <cybergarage/x3d/TextureCoordinateNode.h>

namespace CyberX3D
{

	class ComposedGeometryNode : public Geometry3DNode
	{
		SFBool *ccwField;
		SFBool *colorPerVertexField;
		SFBool *normalPerVertexField;
		SFBool *solidField;
		
		SFNode *colorField;
		SFNode *coordField;
		SFNode *normalField;
		SFNode *texCoordField;
		
	public:
	
		ComposedGeometryNode();
		~ComposedGeometryNode();
		
		////////////////////////////////////////////////
		//	Color
		////////////////////////////////////////////////
		
		SFNode *getColorField();
		
		////////////////////////////////////////////////
		//	Coord
		////////////////////////////////////////////////
		
		SFNode *getCoordField();
		
		////////////////////////////////////////////////
		//	Normal
		////////////////////////////////////////////////
		
		SFNode *getNormalField();
		
		////////////////////////////////////////////////
		//	texCoord
		////////////////////////////////////////////////
		
		SFNode *getTexCoordField();
		
		////////////////////////////////////////////////
		//	CCW
		////////////////////////////////////////////////
		
		SFBool *getCCWField();
		
		void setCCW(bool value);
		void setCCW(int value);
		bool getCCW();
		
		////////////////////////////////////////////////
		//	ColorPerVertex
		////////////////////////////////////////////////
		
		SFBool *getColorPerVertexField();
		
		void setColorPerVertex(bool value);
		void setColorPerVertex(int value);
		bool getColorPerVertex();
		
		////////////////////////////////////////////////
		//	NormalPerVertex
		////////////////////////////////////////////////
		
		SFBool *getNormalPerVertexField();
		
		void setNormalPerVertex(bool value);
		void setNormalPerVertex(int value);
		bool getNormalPerVertex();
		
		////////////////////////////////////////////////
		//	Solid
		////////////////////////////////////////////////
		
		SFBool *getSolidField();
		
		void setSolid(bool value);
		void setSolid(int value);
		bool getSolid();
		
		////////////////////////////////////////////////
		//	BoundingBox
		////////////////////////////////////////////////
		
		void recomputeBoundingBox();
	};
	
}

#endif

