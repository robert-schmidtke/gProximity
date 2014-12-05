/******************************************************************
*
*	CyberVRML97 for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	FileImage.h
*
******************************************************************/

#ifndef _CV97_FILEIMAGE_H_
#define _CV97_FILEIMAGE_H_

#include <cybergarage/x3d/CyberX3DConfig.h>

#ifdef SUPPORT_OLDCPP
#include <cybergarage/x3d/OldCpp.h>
#endif

#include <cybergarage/x3d/FileUtil.h>

namespace CyberX3D
{

#if !R && !G && !B
#define R	0
#define G	1
#define B	2
#endif

	typedef unsigned char RGBColor24[3];
	typedef unsigned char RGBAColor32[4];
	
	class FileImage
	{
	
	public:
	
		FileImage();
		virtual ~FileImage();
		
		bool isOk();
		
		virtual int			getFileType() = 0;
		
		virtual int			getWidth() = 0;
		virtual int			getHeight() = 0;
		virtual RGBColor24	*getImage() = 0;
		
		virtual bool hasTransparencyColor()
		{
			return false;
		}
		
		virtual void getTransparencyColor(RGBColor24 color)
		{
		};
		
		RGBColor24	*getImage(int newx, int newy);
		RGBAColor32	*getRGBAImage();
		RGBAColor32	*getRGBAImage(int newx, int newy);
	};
	
}

#endif
