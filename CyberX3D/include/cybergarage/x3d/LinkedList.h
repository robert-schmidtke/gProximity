/******************************************************************
*
*	CyberVRML97 for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	LinkedList.h
*
******************************************************************/

#ifndef _CV97_LINKEDLIST_H_
#define _CV97_LINKEDLIST_H_

#include <cybergarage/x3d/LinkedListNode.h>

#ifndef NO_USE_STL
#include <list>
#endif

namespace CyberX3D
{

#ifndef NO_USE_STL

#include <list>

	template <class T>
	class LinkedList
	{
	
		LinkedListNode<T>	*mHeaderNode;
		
	public:
	
		LinkedList()
		{
			mHeaderNode = new LinkedListNode<T>(true);
		}
		
		~LinkedList()
		{
			deleteNodes();
			delete mHeaderNode;
		}
		
		void setRootNode(LinkedListNode<T> *obj)
		{
			mHeaderNode = obj;
		}
		
		T *getRootNode()
		{
			return (T *)mHeaderNode;
		}
		
		T *getNodes()
		{
			return (T *)mHeaderNode->next();
		}
		
		T *getNode(int number)
		{
			if(number < 0)
				return (T *)NULL;
			LinkedListNode<T> *node = (LinkedListNode<T> *)getNodes();
			for(int n = 0; n < number && node; n++)
				node = (LinkedListNode<T> *)node->next();
			return (T *)node;
		}
		
		T *getLastNode()
		{
			LinkedListNode<T> *lastNode = (LinkedListNode<T> *)mHeaderNode->prev();
			if(lastNode->isHeaderNode())
				return NULL;
			else
				return (T *)lastNode;
		}
		
		int getNNodes()
		{
			int n = 0;
			for(LinkedListNode<T> *listNode = (LinkedListNode<T> *)getNodes(); listNode; listNode = (LinkedListNode<T> *)listNode->next())
				n++;
			return n;
		}
		
		void addNode(LinkedListNode<T> *node)
		{
			node->remove();
			node->insert((LinkedListNode<T> *)mHeaderNode->prev());
		}
		
		void addNodeAtFirst(LinkedListNode<T> *node)
		{
			node->remove();
			node->insert(mHeaderNode);
		}
		
		void deleteNodes()
		{
			LinkedListNode<T> *rootNode = (LinkedListNode<T> *)getRootNode();
			if(!rootNode)
				return;
			while(rootNode->next())
				delete rootNode->mNextNode;
		}
	};
	
#else
	
	template <class T>
	class LinkedList
	{
	
		LinkedListNode<T>	*mHeaderNode;
	
	public:
	
		LinkedList()
		{
			mHeaderNode = new LinkedListNode<T>(true);
		}
	
		~LinkedList()
		{
			deleteNodes();
			delete mHeaderNode;
		}
	
		void setRootNode(LinkedListNode<T> *obj)
		{
			mHeaderNode = obj;
		}
	
		T *getRootNode()
		{
			return (T *)mHeaderNode;
		}
	
		T *getNodes()
		{
			return (T *)mHeaderNode->next();
		}
	
		T *getNode(int number)
		{
			if(number < 0)
				return (T *)NULL;
			LinkedListNode<T> *node = (LinkedListNode<T> *)getNodes();
			for(int n = 0; n < number && node; n++)
				node = (LinkedListNode<T> *)node->next();
			return (T *)node;
		}
	
		T *getLastNode()
		{
			LinkedListNode<T> *lastNode = (LinkedListNode<T> *)mHeaderNode->prev();
			if(lastNode->isHeaderNode())
				return NULL;
			else
				return (T *)lastNode;
		}
	
		int getNNodes()
		{
			int n = 0;
			for(LinkedListNode<T> *listNode = (LinkedListNode<T> *)getNodes(); listNode; listNode = (LinkedListNode<T> *)listNode->next())
				n++;
			return n;
		}
	
		void addNode(LinkedListNode<T> *node)
		{
			node->remove();
			node->insert((LinkedListNode<T> *)mHeaderNode->prev());
		}
	
		void addNodeAtFirst(LinkedListNode<T> *node)
		{
			node->remove();
			node->insert(mHeaderNode);
		}
	
		void deleteNodes()
		{
			LinkedListNode<T> *rootNode = (LinkedListNode<T> *)getRootNode();
			if(!rootNode)
				return;
			while(rootNode->next())
				delete rootNode->mNextNode;
		}
	};
	
#endif
	
}

#endif

