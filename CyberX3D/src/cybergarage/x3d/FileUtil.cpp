/******************************************************************
*
*	CyberVRML97 for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	FileUtil.cpp
*
******************************************************************/

#include <stdio.h>
#include <string.h>

#include <cybergarage/x3d/FileUtil.h>

using namespace CyberX3D;

////////////////////////////////////////////////
//	GetFileFormat
////////////////////////////////////////////////

int CyberX3D::GetFileFormat(const char *filename)
{
	FILE *fp = fopen(filename, "rb");
	if(!fp)
		return FILE_FORMAT_NONE;
		
	unsigned char signature[5];
	
	if(fread(signature, 5, 1, fp) != 1)
	{
		fclose(fp);
		return FILE_FORMAT_NONE;
	}
	
	fclose(fp);
	
	int fileType = FILE_FORMAT_NONE;
	
	if(!strncmp("#VRML", (char *)signature, 5))
		fileType = FILE_FORMAT_VRML;
		
	if(!strncmp("<?xml", (char *)signature, 5))
		fileType = FILE_FORMAT_XML;
		
	if(!strncmp("GIF", (char *)signature, 3))
		fileType = FILE_FORMAT_GIF;
		
	if(signature[0] == 0xff && signature[1] == 0xd8)
		fileType = FILE_FORMAT_JPEG;
		
	if(!strncmp("PNG", (char *)(signature + 1), 3))
		fileType = FILE_FORMAT_PNG;
		
	return fileType;
}
