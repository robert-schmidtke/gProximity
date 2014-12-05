/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2003
*
*	File: Graphic3D.h
*
******************************************************************/

#ifndef _CX3D_GRAPHIC3D_H_
#define _CX3D_GRAPHIC3D_H_

#include <cybergarage/x3d/CyberX3DConfig.h>

#ifdef SUPPORT_OPENGL

#ifdef WIN32
#include <windows.h>
#endif // WIN32

#ifdef MACOSX
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#endif // MACOSX

#ifdef WIN32
typedef GLvoid(CALLBACK*GLUtessCallBackFunc)(void);
#else
typedef GLvoid(*GLUtessCallBackFunc)(void);
#endif // WIN32

#endif // SUPPORT_OPENGL

#endif
