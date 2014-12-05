/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	LoadSensorNode.h
*
******************************************************************/

#ifndef _CX3D_LOADSENSORNODE_H_
#define _CX3D_LOADSENSORNODE_H_

#include <cybergarage/x3d/X3DFields.h>
#include <cybergarage/x3d/NetworkSensorNode.h>

namespace CyberX3D
{

	class LoadSensorNode : public NetworkSensorNode
	{
	
		MFNode* watchListField;
		SFBool *enabledField;
		SFTime *timeoutField;
		SFBool *isActiveField;
		SFBool *isLoadedField;
		SFTime *loadTimeField;
		SFFloat *progressField;
		
	public:
	
		LoadSensorNode();
		~LoadSensorNode();
		
		////////////////////////////////////////////////
		//	watchList
		////////////////////////////////////////////////
		
		MFNode* getWatchListField();
		
		////////////////////////////////////////////////
		//	Enabled
		////////////////////////////////////////////////
		
		SFBool *getEnabledField();
		
		void setEnabled(bool value);
		bool getEnabled();
		bool isEnabled();
		
		////////////////////////////////////////////////
		//	timeout
		////////////////////////////////////////////////
		
		SFTime *getTimeoutField();
		
		void setTimeout(double value);
		double getTimeout();
		
		////////////////////////////////////////////////
		//	isActive
		////////////////////////////////////////////////
		
		SFBool *getIsActiveField();
		
		void setIsActive(bool value);
		bool getIsActive();
		bool isActive();
		
		////////////////////////////////////////////////
		//	isLoaded
		////////////////////////////////////////////////
		
		SFBool *getIsLoadedField();
		
		void setIsLoaded(bool value);
		bool getIsLoaded();
		bool isLoaded();
		
		////////////////////////////////////////////////
		//	loadTime
		////////////////////////////////////////////////
		
		SFTime *getLoadTimeField();
		
		void setLoadTime(double value);
		double getLoadTime();
		
		////////////////////////////////////////////////
		//	progress
		////////////////////////////////////////////////
		
		SFFloat *getProgressField();
		
		void setProgress(float value);
		float getProgress();
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		LoadSensorNode *next();
		LoadSensorNode *nextTraversal();
		
		////////////////////////////////////////////////
		//	Virtual functions
		////////////////////////////////////////////////
		
		bool isChildNodeType(Node *node);
		void initialize();
		void uninitialize();
		void update();
		void outputContext(std::ostream &printStream, char *indentString);
	};
	
}

#endif

