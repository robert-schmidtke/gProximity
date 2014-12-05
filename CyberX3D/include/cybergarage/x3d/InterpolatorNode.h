/******************************************************************
*
*	CyberVRML97 for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	InterpolatorNode.h
*
******************************************************************/

#ifndef _CV97_INTERPOLATOR_H_
#define _CV97_INTERPOLATOR_H_

#include <cybergarage/x3d/Node.h>

namespace CyberX3D
{

	class InterpolatorNode : public Node
	{
	
		MFFloat *keyField;
		SFFloat *fractionField;
		
	public:
	
		InterpolatorNode();
		virtual ~InterpolatorNode();
		
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
