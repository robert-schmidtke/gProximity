/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	X3DParserTokenizer.h
*
******************************************************************/

#include <cybergarage/x3d/CyberX3DConfig.h>

#ifdef SUPPORT_X3D

#ifndef _CV97_X3DPARSERTOKENIZER_H_
#define _CV97_X3DPARSERTOKENIZER_H_

#include <xercesc/util/XMLStringTokenizer.hpp>

namespace CyberX3D
{

	class X3DParserTokenizer : public xercesc::XMLStringTokenizer
	{
	
	public:
	
		X3DParserTokenizer(const XMLCh *const srcStr);
		~X3DParserTokenizer();
		
	};
	
}

#endif

#endif
