/******************************************************************
*
*	CyberVRML97 for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	ParserFunc.h
*
******************************************************************/

#ifndef _CV97_PARSERFUNC_H_
#define _CV97_PARSERFUNC_H_

#include <cybergarage/x3d/Parser.h>
#include <cybergarage/x3d/ParserResult.h>

namespace CyberX3D
{

	void PushParserObject(Parser *parser);
	void PopParserObject();
	Parser *GetParserObject();
	
	void SetParserResultObject(ParserResult *parserResult);
	ParserResult *GetParserResultObject();
	
	int ParserGetCurrentNodeType(void);
	int ParserGetParentNodeType(void);
	Node *ParserGetCurrentNode(void);
	
	void ParserPushNode(int parserType, Node *node);
	void ParserPushNode(Node *node);
	void ParserPopNode(void);
	
	void ParserAddNode(Node *node);
	void ParserAddRouteInfo(char *string);
	
	Node *CreateNode(int nodeType);
	Node *CreateX3DNode(int nodeType);
	
}

#endif
