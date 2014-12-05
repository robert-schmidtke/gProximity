/******************************************************************
*
*	CyberVRML97 for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	SpotLightNode.h
*
******************************************************************/

#ifndef _CV97_SPOTLIGHT_H_
#define _CV97_SPOTLIGHT_H_

#include <cybergarage/x3d/LightNode.h>

namespace CyberX3D
{

	class SpotLightNode : public LightNode
	{
	
		SFVec3f *locationField;
		SFVec3f *directionField;
		SFFloat *radiusField;
		SFVec3f *attenuationField;
		SFFloat *beamWidthField;
		SFFloat *cutOffAngleField;
		
	public:
	
		SpotLightNode();
		~SpotLightNode();
		
		////////////////////////////////////////////////
		//	Location
		////////////////////////////////////////////////
		
		SFVec3f *getLocationField();
		
		void setLocation(float value[]);
		void setLocation(float x, float y, float z);
		void getLocation(float value[]);
		
		////////////////////////////////////////////////
		//	Direction
		////////////////////////////////////////////////
		
		SFVec3f *getDirectionField();
		
		void setDirection(float value[]);
		void setDirection(float x, float y, float z);
		void getDirection(float value[]);
		
		////////////////////////////////////////////////
		//	Radius
		////////////////////////////////////////////////
		
		SFFloat *getRadiusField();
		
		void setRadius(float value);
		float getRadius();
		
		////////////////////////////////////////////////
		//	Attenuation
		////////////////////////////////////////////////
		
		SFVec3f *getAttenuationField();
		
		void setAttenuation(float value[]);
		void setAttenuation(float x, float y, float z);
		void getAttenuation(float value[]);
		
		////////////////////////////////////////////////
		//	BeamWidth
		////////////////////////////////////////////////
		
		SFFloat *getBeamWidthField();
		
		void setBeamWidth(float value);
		float getBeamWidth();
		
		////////////////////////////////////////////////
		//	CutOffAngle
		////////////////////////////////////////////////
		
		SFFloat *getCutOffAngleField();
		
		void setCutOffAngle(float value);
		float getCutOffAngle();
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		SpotLightNode *next();
		SpotLightNode *nextTraversal();
		
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
