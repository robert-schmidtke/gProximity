/******************************************************************
*
*	CyberVRML97 for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	ParserResult.h
*
******************************************************************/

#ifndef _CV97_PARSERRESULT_H_
#define _CV97_PARSERRESULT_H_

#include <cybergarage/x3d/StringUtil.h>

namespace CyberX3D
{

	class ParserResult
	{
	
		int						mErrorLineNumber;
		String					mErrorMsg;
		String					mErrorToken;
		String					mErrorLineString;
		bool					mIsOK;
		
	public:
	
		ParserResult()
		{
		}
		
		~ParserResult()
		{
		}
		
		void init()
		{
			setParserResult(false);
			setErrorLineNumber(0);
			setErrorMessage("");
			setErrorToken("");
			setErrorLineString("");
		}
		
		void setParserResult(bool bOK)
		{
			mIsOK = bOK;
		}
		bool getParserResult()
		{
			return mIsOK;
		}
		bool isOK(void)
		{
			return getParserResult();
		}
		
		void setErrorLineNumber(int n)
		{
			mErrorLineNumber = n;
		}
		int	getErrorLineNumber(void)
		{
			return mErrorLineNumber;
		}
		
		void setErrorMessage(char *msg)
		{
			mErrorMsg.setValue(msg);
		}
		char *getErrorMessage(void)
		{
			return mErrorMsg.getValue();
		}
		
		void setErrorToken(char *error)
		{
			mErrorToken.setValue(error);
		}
		char *getErrorToken(void)
		{
			return mErrorToken.getValue();
		}
		
		void setErrorLineString(char *error)
		{
			mErrorLineString.setValue(error);
		}
		char *getErrorLineString(void)
		{
			return mErrorLineString.getValue();
		}
	};
	
}

#endif


