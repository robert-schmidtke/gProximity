/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	KeyDeviceSensorNode.h
*
******************************************************************/

#ifndef _CX3D_KEYDEVICESENSORNODE_H_
#define _CX3D_KEYDEVICESENSORNODE_H_

#include <cybergarage/x3d/VRML97Fields.h>
#include <cybergarage/x3d/SensorNode.h>

namespace CyberX3D
{

	class KeyDeviceSensorNode : public SensorNode
	{
	
		SFInt32 *actionKeyPressField;
		SFInt32 *actionKeyReleaseField;
		SFBool *altKeyField;
		SFBool *controlKeyField;
		SFBool *shiftKeyField;
		SFInt32 *keyPressField;
		SFInt32 *keyReleaseField;
		
	public:
	
		KeyDeviceSensorNode();
		virtual ~KeyDeviceSensorNode();
		
		////////////////////////////////////////////////
		//	AltKey
		////////////////////////////////////////////////
		
		SFBool *getAltKeyField();
		
		void setAltKey(bool value);
		void setAltKey(int value);
		bool getAltKey();
		
		////////////////////////////////////////////////
		//	ControlKey
		////////////////////////////////////////////////
		
		SFBool *getControlKeyField();
		
		void setControlKey(bool value);
		void setControlKey(int value);
		bool getControlKey();
		
		////////////////////////////////////////////////
		//	ShiftKey
		////////////////////////////////////////////////
		
		SFBool *getShiftKeyField();
		
		void setShiftKey(bool value);
		void setShiftKey(int value);
		bool getShiftKey();
		
		////////////////////////////////////////////////
		//	ActionKeyPress
		////////////////////////////////////////////////
		
		SFInt32 *getActionKeyPressField();
		
		void setActionKeyPress(int value);
		int getActionKeyPress();
		
		////////////////////////////////////////////////
		//	ActionKeyRelease
		////////////////////////////////////////////////
		
		SFInt32 *getActionKeyReleaseField();
		
		void setActionKeyRelease(int value);
		int getActionKeyRelease();
		
		////////////////////////////////////////////////
		//	KeyPress
		////////////////////////////////////////////////
		
		SFInt32 *getKeyPressField();
		
		void setKeyPress(int value);
		int getKeyPress();
		
		////////////////////////////////////////////////
		//	KeyRelease
		////////////////////////////////////////////////
		
		SFInt32 *getKeyReleaseField();
		
		void setKeyRelease(int value);
		int getKeyRelease();
	};
	
}

#endif

