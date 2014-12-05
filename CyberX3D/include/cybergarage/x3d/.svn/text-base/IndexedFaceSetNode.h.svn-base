/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	IndexedFaceSetNode.h
*
******************************************************************/

#ifndef _CX3D_INDEXEDFACESETNODE_H_
#define _CX3D_INDEXEDFACESETNODE_H_

#include <cybergarage/x3d/ComposedGeometryNode.h>
#include <cybergarage/x3d/NormalNode.h>
#include <cybergarage/x3d/ColorNode.h>
#include <cybergarage/x3d/CoordinateNode.h>
#include <cybergarage/x3d/TextureCoordinateNode.h>

namespace CyberX3D
{

	class IndexedFaceSetNode : public ComposedGeometryNode
	{
		SFBool *convexField;
		SFFloat *creaseAngleField;
		MFInt32 *coordIdxField;
		MFInt32 *texCoordIndexField;
		MFInt32 *colorIndexField;
		MFInt32 *normalIndexField;
		
	public:
	
		IndexedFaceSetNode();
		~IndexedFaceSetNode();
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		IndexedFaceSetNode *next();
		IndexedFaceSetNode *nextTraversal();
		
		////////////////////////////////////////////////
		//	Convex
		////////////////////////////////////////////////
		
		SFBool *getConvexField();
		
		void setConvex(bool value);
		void setConvex(int value);
		bool getConvex();
		
		////////////////////////////////////////////////
		//	CreaseAngle
		////////////////////////////////////////////////
		
		SFFloat *getCreaseAngleField();
		
		void setCreaseAngle(float value);
		float getCreaseAngle();
		
		////////////////////////////////////////////////
		// CoordIndex
		////////////////////////////////////////////////
		
		MFInt32 *getCoordIndexField();
		
		void addCoordIndex(int value);
		int getNCoordIndexes();
		int getCoordIndex(int index);
		
		////////////////////////////////////////////////
		// TexCoordIndex
		////////////////////////////////////////////////
		
		MFInt32 *getTexCoordIndexField();
		
		void addTexCoordIndex(int value);
		int getNTexCoordIndexes();
		int getTexCoordIndex(int index);
		
		////////////////////////////////////////////////
		// ColorIndex
		////////////////////////////////////////////////
		
		MFInt32 *getColorIndexField();
		
		void addColorIndex(int value);
		int getNColorIndexes();
		int getColorIndex(int index);
		
		////////////////////////////////////////////////
		// NormalIndex
		////////////////////////////////////////////////
		
		MFInt32 *getNormalIndexField();
		
		void addNormalIndex(int value);
		int getNNormalIndexes();
		int getNormalIndex(int index);
		
		////////////////////////////////////////////////
		//	functions
		////////////////////////////////////////////////
		
		bool isChildNodeType(Node *node);
		void initialize();
		void uninitialize();
		void update();
		
		////////////////////////////////////////////////
		//	BoundingBox
		////////////////////////////////////////////////
		
		void recomputeBoundingBox();
		
		////////////////////////////////////////////////
		//	recomputeDisplayList
		////////////////////////////////////////////////
		
#ifdef SUPPORT_OPENGL
		void recomputeDisplayList();
#endif
		
		////////////////////////////////////////////////
		//	Infomation
		////////////////////////////////////////////////
		
		void outputContext(std::ostream &printStream, char *indentString);
		
		////////////////////////////////////////////////
		//	Polygon
		////////////////////////////////////////////////
		
		int getNPolygons();
		
		////////////////////////////////////////////////
		//	Normal
		////////////////////////////////////////////////
		
		bool generateNormals();
		
		////////////////////////////////////////////////
		//	TextureCoordinate
		////////////////////////////////////////////////
		
		bool generateTextureCoordinate();
		
	};
	
}

#endif

