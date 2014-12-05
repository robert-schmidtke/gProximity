/******************************************************************
*
*	CyberVRML97 for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	VRML97ParserFunc.h
*
******************************************************************/

#ifndef _CV97_VRML97PARSERFUNC_H_
#define _CV97_VRML97PARSERFUNC_H_

#include <stdio.h>
#include <cybergarage/x3d/ParserFunc.h>

namespace CyberX3D
{

	class PROTO;
	
////////////////////////////////////////////////
// AddSF*
////////////////////////////////////////////////

	void AddSFColor(float color[3]);
	void AddSFRotation(float rotation[4]);
	void AddSFVec3f(float vector[3]);
	void AddSFVec2f(float vector[2]);
	void AddSFInt32(int value);
	void AddSFFloat(float value);
	void AddSFString(char *string);
	
////////////////////////////////////////////////
// PROTO/DEF
////////////////////////////////////////////////

	PROTO *AddPROTOInfo(char *name, char *string, char *fieldString);
	PROTO *IsPROTOName(char *name);
	
	void AddDEFInfo(char *name, char *string);
	char *GetDEFSrting(char *name);
	
	void SetDEFName(char *name);
	char *GetDEFName(void);
	
////////////////////////////////////////////////
// lex
////////////////////////////////////////////////

	void MakeLexerBuffers(int lexBufferSize, int lineBufferSize);
	void DeleteLexerBuffers(void);
	void SetLexCallbackFn(void (*func)(int nLine, void *info), void *fnInfo);
	int UnputString(char *pBegin);
	void CurrentLineIncrement();
	
////////////////////////////////////////////////
// yacc
////////////////////////////////////////////////

	int GetCurrentLineNumber(void);
	void SetInputFile(FILE *fp);
	char *GetErrorLineString(void);
	
}

/******************************************************************
*	yacc
******************************************************************/

int yyparse(void);

#endif
