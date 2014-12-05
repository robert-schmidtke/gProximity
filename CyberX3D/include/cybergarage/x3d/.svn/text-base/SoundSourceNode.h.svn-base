/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	SoundSourceNode.h
*
******************************************************************/

#ifndef _CX3D_SOUNDSOURCENODE_H_
#define _CX3D_SOUNDSOURCENODE_H_

#include <cybergarage/x3d/VRML97Fields.h>
#include <cybergarage/x3d/Node.h>

namespace CyberX3D
{

	const char isPlayingPrivateFieldName[] = "isPlaying";
	
	class SoundSourceNode : public Node
	{
	
		SFString *descriptionField;
		SFFloat *pitchField;
		MFString *urlField;
		SFBool *isActiveField;
		SFTime *durationChangedField;
		
	public:
	
		SoundSourceNode();
		~SoundSourceNode();
		
		////////////////////////////////////////////////
		//	Description
		////////////////////////////////////////////////
		
		SFString *getDescriptionField();
		
		void setDescription(char * value);
		char *getDescription();
		
		////////////////////////////////////////////////
		//	Pitch
		////////////////////////////////////////////////
		
		SFFloat *getPitchField();
		
		void setPitch(float value);
		float getPitch();
		
		////////////////////////////////////////////////
		//	isActive
		////////////////////////////////////////////////
		
		SFBool *getIsActiveField();
		
		void setIsActive(bool  value);
		bool  getIsActive();
		bool  isActive();
		
		////////////////////////////////////////////////
		//	duration_changed
		////////////////////////////////////////////////
		
		SFTime *getDurationChangedField();
		
		void setDurationChanged(double value);
		double getDurationChanged();
		
		////////////////////////////////////////////////
		// Url
		////////////////////////////////////////////////
		
		MFString *getUrlField();
		
		void addUrl(char * value);
		int getNUrls();
		char *getUrl(int index);
		void setUrl(int index, char *urlString);
	};
	
}

#endif
