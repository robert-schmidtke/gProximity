/*

The interface routines for reading and writing PLY polygon files.

Greg Turk, February 1994

---------------------------------------------------------------

A PLY file contains a single polygonal _object_.

An object is composed of lists of _elements_.  Typical elements are
vertices, faces, edges and materials.

Each type of element for a given object has one or more _properties_
associated with the element type.  For instance, a vertex element may
have as properties the floating-point values x,y,z and the three unsigned
chars representing red, green and blue.

---------------------------------------------------------------

Copyright (c) 1994 The Board of Trustees of The Leland Stanford
Junior University.  All rights reserved.

Permission to use, copy, modify and distribute this software and its
documentation for any purpose is hereby granted without fee, provided
that the above copyright notice and this permission notice appear in
all copies of this software and that you do not sell the software.

THE SOFTWARE IS PROVIDED "AS IS" AND WITHOUT WARRANTY OF ANY KIND,
EXPRESS, IMPLIED OR OTHERWISE, INCLUDING WITHOUT LIMITATION, ANY
WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.

*/

#ifndef __PLYFUNCTIONS_H_
#define __PLYFUNCTIONS_H_

#include "Vector3.h"
#include "rgb.h"

enum PlyState
{
	PLY_NOTLOADED = 0x01,
	PLY_OPENED = 0x02,
	PLY_HEADERPARSED = 0x03,
	PLY_READVERTICES = 0x04,
	PLY_READFACES = 0x05,
	PLY_FINISHED = 0x06,
	PLY_CLOSED = 0x0A,
	PLY_FOPENERROR = 0x07,
	PLY_HEADERERROR = 0x08,
	PLY_PARSEERROR = 0x09,
};

enum PlyFeature
{
	PLY_COLOR = 0x01,
	PLY_NORMAL = 0x02
};

class PLYLoader
{
public:
	PLYLoader()
	{
		currentState = PLY_NOTLOADED;
		fp = NULL;
		vertexScanStr = NULL;
		faceScanStr = NULL;
		
		b_hasColor = false;
		b_hasNormal = false;
	}
	
	~PLYLoader()
	{
		if(currentState != PLY_CLOSED &&
		        currentState != PLY_FOPENERROR &&
		        currentState != PLY_NOTLOADED &&
		        fp != NULL)
			fclose(fp);
	}
	
	bool plyOpen(const char *filename);
	
	bool plyParseHeader();
	void plyClose();
	
	bool plyHasFeature(PlyFeature query);
	unsigned int plyGetNumVertices();
	unsigned int plyGetNumFaces();
	
	bool plyNextVertex();
	void plyGetVertex(Vector3 &dest);
	void plyGetVertexColor(rgb &dest);
	void plyGetVertexNormal(Vector3 &dest);
	
	bool plyNextFace();
	void plyGetFaceIndices(unsigned int *dest);
	
protected:

	PlyState currentState;
	FILE *fp;
	
	char *vertexScanStr;
	char *faceScanStr;
	
	// feature flags:
	bool b_hasColor;
	bool b_hasNormal;
	
private:
};


#endif