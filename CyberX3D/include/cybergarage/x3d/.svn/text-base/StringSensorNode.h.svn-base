/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	StringSensorNode.h
*
******************************************************************/

#ifndef _CX3D_STRINGSENSORNODE_H_
#define _CX3D_STRINGSENSORNODE_H_

#include <cybergarage/x3d/KeyDeviceSensorNode.h>

namespace CyberX3D
{

	class StringSensorNode : public KeyDeviceSensorNode
	{
		SFInt32 *deletionCharacterField;
		SFString *enteredTextField;
		SFString *finalTextField;
		SFInt32 *profileField;
		SFString *terminationTextField;
		
	public:
	
		StringSensorNode();
		~StringSensorNode();
		
		////////////////////////////////////////////////
		//	DeletionCharacter
		////////////////////////////////////////////////
		
		SFInt32 *getDeletionCharacterField();
		
		void setDeletionCharacter(int value);
		int getDeletionCharacter();
		
		////////////////////////////////////////////////
		//	Profile
		////////////////////////////////////////////////
		
		SFInt32 *getProfileField();
		
		void setProfile(int value);
		int getProfile();
		
		////////////////////////////////////////////////
		//	EnteredText
		////////////////////////////////////////////////
		
		SFString *getEnteredTextField();
		
		void setEnteredText(const char *value);
		char *getEnteredText();
		
		////////////////////////////////////////////////
		//	FinalText
		////////////////////////////////////////////////
		
		SFString *getFinalTextField();
		
		void setFinalText(const char *value);
		char *getFinalText();
		
		////////////////////////////////////////////////
		//	TerminationText
		////////////////////////////////////////////////
		
		SFString *getTerminationTextField();
		
		void setTerminationText(const char *value);
		char *getTerminationText();
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		StringSensorNode *next();
		StringSensorNode *nextTraversal();
		
		////////////////////////////////////////////////
		//	functions
		////////////////////////////////////////////////
		
		bool isChildNodeType(Node *node);
		void initialize();
		void uninitialize();
		void update();
		
		////////////////////////////////////////////////
		//	Infomation
		////////////////////////////////////////////////
		
		void outputContext(std::ostream &printStream, char *indentString);
	};
	
}

#endif

