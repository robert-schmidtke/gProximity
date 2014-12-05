/******************************************************************
*
*	CyberVRML97 for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	ParserNode.h
*
******************************************************************/

#ifndef _CV97_PARSERNODE_H_
#define _CV97_PARSERNODE_H_

#include <cybergarage/x3d/LinkedList.h>
#include <cybergarage/x3d/Node.h>

namespace CyberX3D
{

	class ParserNode : public LinkedListNode<ParserNode>
	{
		Node		*mNode;
		int			mType;
	public:
	
		ParserNode(Node *node, int type);
		~ParserNode();
		
		Node *getNode();
		int getType();
	};
	
}

#endif

