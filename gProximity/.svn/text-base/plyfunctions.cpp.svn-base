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

#include "plyfunctions.h"

bool PLYLoader::plyOpen(const char *filename)
{
	return false;
}

bool PLYLoader::plyParseHeader()
{
	return false;
}

void PLYLoader::plyClose()
{
	if(fp)
		fclose(fp);
	currentState = PLY_CLOSED;
}

bool PLYLoader::plyHasFeature(PlyFeature query)
{
	switch(query)
	{
	case PLY_COLOR:
		return b_hasColor;
	case PLY_NORMAL:
		return b_hasNormal;
	default:
		return false;
	}
}

unsigned int PLYLoader::plyGetNumVertices()
{
	return 0;
}

unsigned int PLYLoader::plyGetNumFaces()
{
	return 0;
}

bool PLYLoader::plyNextVertex()
{
	return false;
}

void PLYLoader::plyGetVertex(Vector3 &dest)
{
}

void PLYLoader::plyGetVertexColor(rgb &dest)
{
}

void PLYLoader::plyGetVertexNormal(Vector3 &dest)
{
}

bool PLYLoader::plyNextFace()
{
	return false;
}

void PLYLoader::plyGetFaceIndices(unsigned int *dest)
{

}