/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	IndexedLinSet.h
*
******************************************************************/

#ifndef _CX3D_INDEXEDLINESETNODE_H_
#define _CX3D_INDEXEDLINESETNODE_H_

#include <cybergarage/x3d/GeometryNode.h>
#include <cybergarage/x3d/ColorNode.h>
#include <cybergarage/x3d/CoordinateNode.h>

namespace CyberX3D
{

	class IndexedLineSetNode : public GeometryNode
	{
	
		SFBool *colorPerVertexField;
		MFInt32 *coordIndexField;
		MFInt32 *colorIndexField;
		SFFloat *lineWidthField;
		
		MFInt32 *set_coordIndexField;
		MFInt32 *set_colorIndexField;
		
		SFNode *colorField;
		SFNode *coordField;
		
	public:
	
		IndexedLineSetNode();
		~IndexedLineSetNode();
		
		////////////////////////////////////////////////
		//	Color
		////////////////////////////////////////////////
		
		SFNode *getColorField();
		
		////////////////////////////////////////////////
		//	Coord
		////////////////////////////////////////////////
		
		SFNode *getCoordField();
		
		////////////////////////////////////////////////
		// set_coordIndex
		////////////////////////////////////////////////
		
		MFInt32 *getSetCoordIndexField();
		
		////////////////////////////////////////////////
		// set_colorIndex
		////////////////////////////////////////////////
		
		MFInt32 *getSetColorIndexField();
		
		////////////////////////////////////////////////
		//	ColorPerVertex
		////////////////////////////////////////////////
		
		SFBool *getColorPerVertexField();
		
		void setColorPerVertex(bool value);
		void setColorPerVertex(int value);
		bool getColorPerVertex();
		
		////////////////////////////////////////////////
		// CoordIndex
		////////////////////////////////////////////////
		
		MFInt32 *getCoordIndexField();
		
		void addCoordIndex(int value);
		int getNCoordIndexes();
		int getCoordIndex(int index);
		void clearCoordIndex();
		
		////////////////////////////////////////////////
		// ColorIndex
		////////////////////////////////////////////////
		
		MFInt32 *getColorIndexField();
		
		void addColorIndex(int value);
		int getNColorIndexes();
		int getColorIndex(int index);
		void clearColorIndex();
		
		////////////////////////////////////////////////
		//	LineWidth
		////////////////////////////////////////////////
		
		SFFloat *getLineWidthField();
		void setLineWidth(float value);
		float getLineWidth();
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		IndexedLineSetNode *next();
		IndexedLineSetNode *nextTraversal();
		
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
		
		//void recomputeBoundingBox();
		
		////////////////////////////////////////////////
		//	Polygons
		////////////////////////////////////////////////
		
		int getNPolygons()
		{
			return 0;
		}
		
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
	};
	
}

#endif
