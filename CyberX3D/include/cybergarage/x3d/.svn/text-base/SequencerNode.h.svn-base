/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	SequencerNode.h
*
******************************************************************/

#ifndef _CX3D_SEQUENCERNODE_H_
#define _CX3D_SEQUENCERNODE_H_

#include <cybergarage/x3d/Node.h>

namespace CyberX3D
{

	class SequencerNode : public Node
	{
	
		MFFloat *keyField;
		SFFloat *fractionField;
		
	public:
	
		SequencerNode();
		virtual ~SequencerNode();
		
		////////////////////////////////////////////////
		//	key
		////////////////////////////////////////////////
		
		MFFloat *getKeyField();
		
		void addKey(float value);
		int getNKeys();
		float getKey(int index);
		
		////////////////////////////////////////////////
		//	fraction
		////////////////////////////////////////////////
		
		SFFloat *getFractionField();
		
		void setFraction(float value);
		float getFraction();
	};
	
}

#endif
