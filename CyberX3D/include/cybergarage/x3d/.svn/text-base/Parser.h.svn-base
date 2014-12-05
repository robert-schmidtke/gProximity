/******************************************************************
*
*	CyberVRML97 for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	Parser.h
*
******************************************************************/

#ifndef _CV97_PARSER_H_
#define _CV97_PARSER_H_

#include <cybergarage/x3d/Scene.h>
#include <cybergarage/x3d/ParserNode.h>
#include <cybergarage/x3d/ParserResult.h>
#include <cybergarage/x3d/PROTO.h>
#include <cybergarage/x3d/DEF.h>
#include <cybergarage/x3d/StringUtil.h>
#include <cybergarage/x3d/LinkedListNode.h>

namespace CyberX3D
{

	const int DEFAULT_LEX_LINE_BUFFER_SIZE = 64 * 1024;
	
	class Parser : public Scene, public ParserResult, public LinkedListNode<Parser>
	{
	
		LinkedList<ParserNode>	mParserNodeList;
		LinkedList<DEF>		mDEFList;
		LinkedList<PROTO>		mPROTOList;
		String					mDefName;
		
		bool					mbParsering;
		
	public:
	
		Parser();
		~Parser();
		
		///////////////////////////////////////////////
		//	Praser action
		///////////////////////////////////////////////
		
		void addNode(Node *node, bool initialize = true);
		void addNodeAtFirst(Node *node, bool initialize = true);
		
		void moveNode(Node *node);
		void moveNodeAtFirst(Node *node);
		
		void pushNode(Node *node, int type);
		void popNode();
		
		Node *getCurrentNode();
		int getCurrentNodeType();
		int getPrevNodeType();
		
		void beginParse();
		void endParse();
		
		///////////////////////////////////////////////
		//	DEF
		///////////////////////////////////////////////
		
		void setDefName(const char *name)
		{
			mDefName.setValue(name);
		}
		
		char *getDefName()
		{
			return mDefName.getValue();
		}
		
		///////////////////////////////////////////////
		//	Load
		///////////////////////////////////////////////
		
		void	setParseringState(bool state)
		{
			mbParsering = state;
		}
		bool	getParseringState()
		{
			return mbParsering;
		}
		
		int		getNLines(const char *fileName);
		
		virtual bool load(const char *fileName, void (*callbackFn)(int nLine, void *info) = NULL, void *callbackFnInfo = NULL) = 0;
		
		///////////////////////////////////////////////
		//	DEF
		///////////////////////////////////////////////
		
		DEF *getDEFs();
		char *getDEFString(const char *name);
		void addDEF(DEF *def);
		void addDEF(const char *name, char *string);
		void deleteDEFs();
		
		///////////////////////////////////////////////
		//	PROTO
		///////////////////////////////////////////////
		
		PROTO *getPROTOs();
		PROTO *getPROTO(const char *name);
		void addPROTO(PROTO *proto);
		void deletePROTOs();
	};
	
}

#endif
