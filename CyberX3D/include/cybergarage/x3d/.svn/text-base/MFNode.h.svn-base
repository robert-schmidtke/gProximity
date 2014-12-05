/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	MFNode.h
*
******************************************************************/

#ifndef _CX3D_MFNODE_H_
#define _CX3D_MFNODE_H_

#include <cybergarage/x3d/MField.h>
#include <cybergarage/x3d/SFNode.h>

namespace CyberX3D
{

	class MFNode : public MField
	{
	
		static	int	mInit;
		
	public:
	
		MFNode();
		
		void addValue(Node *value);
		void addValue(SFNode *sfvalue);
		void addValue(const char *value);
		
		void insertValue(int index, Node *value);
		Node *get1Value(int index);
		void set1Value(int index, Node *value);
		
		void setValue(MField *mfield);
		void setValue(MFNode *values);
		void setValue(int size, Node *values[]);
		
		int getValueCount()
		{
			return 1;
		}
		
		////////////////////////////////////////////////
		//	Output
		////////////////////////////////////////////////
		
		void outputContext(std::ostream& printStream, char *indentString);
		
	};
	
}

#endif
