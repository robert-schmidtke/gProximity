/******************************************************************
*
*	CyberVRML97 for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	VRML97Parser.cpp
*
*	03/12/04
*		- Added the following functions to parse more minimum memory.
*		  VRML97ParserSetBufSize(), VRML97ParserGetBufSize().
*
******************************************************************/

#include <stdio.h>
#include <cybergarage/x3d/VRML97Parser.h>
#include <cybergarage/x3d/VRML97ParserFunc.h>

using namespace CyberX3D;

////////////////////////////////////////////////
//	VRML97Parser::load
////////////////////////////////////////////////

VRML97Parser::VRML97Parser()
{
	setParserResult(false);
	setParseringState(false);
}

VRML97Parser::~VRML97Parser()
{
}

////////////////////////////////////////////////
//	VRML97Parser::load
////////////////////////////////////////////////

bool VRML97Parser::load(const char *fileName, void (*callbackFn)(int nLine, void *info), void *callbackFnInfo)
{
	FILE *fp = fopen(fileName, "rt");
	
#ifdef SUPPORT_URL
	SceneGraph *sg = (SceneGraph *)this;
#endif
	
#ifdef SUPPORT_URL
	if(fp == NULL)
	{
		if(sg->getUrlStream(fileName))
		{
			char *outputFilename = sg->getUrlOutputFilename();
			fp = fopen(outputFilename, "rt");
			sg->setUrl(fileName);
		}
	}
#endif
	
	if(fp == NULL)
	{
		fprintf(stderr, "Cannot open data file %s\n", fileName);
		setParserResult(false);
		setParseringState(false);
		return false;
	}
	
#ifdef USE_MAX_LEX_BUFFER
	fseek(fp, 0, SEEK_END);
	int lexBufferSize = ftell(fp);
	fseek(fp, 0, SEEK_SET);
#else
	int lexBufferSize = VRML97ParserGetBufSize();
#endif
	
	if(GetParserObject() == NULL)
		MakeLexerBuffers(lexBufferSize, DEFAULT_LEX_LINE_BUFFER_SIZE);
		
	clearNodeList();
	clearRouteList();
	deleteDEFs();
	deletePROTOs();
	
	beginParse();
	
	SetLexCallbackFn(callbackFn, callbackFnInfo);
	SetInputFile(fp);
	setParserResult(!yyparse() ? true : false);
	
	endParse();
	
	if(GetParserObject() == NULL)
		DeleteLexerBuffers();
		
	fclose(fp);
	
#ifdef SUPPORT_URL
	sg->deleteUrlOutputFilename();
#endif
	
	return getParserResult();
}

////////////////////////////////////////////////
//	VRML97Parser::load
////////////////////////////////////////////////

static int vrml97parserBufSize = VRML97_PARSER_DEFAULT_BUF_SIZE;

void  CyberX3D::VRML97ParserSetBufSize(int bufSize)
{
	vrml97parserBufSize = bufSize;
}

int CyberX3D::VRML97ParserGetBufSize()
{
	return vrml97parserBufSize;
}
