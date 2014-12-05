/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	LightNode.h
*
******************************************************************/

#ifndef _CX3D_LIGHTNODE_H_
#define _CX3D_LIGHTNODE_H_

#include <cybergarage/x3d/VRML97Fields.h>
#include <cybergarage/x3d/Node.h>

namespace CyberX3D
{

	class LightNode : public Node
	{
	
		SFFloat *ambientIntensityField;
		SFBool *bonField;
		SFFloat *intensityField;
		SFColor *colorField;
		
	public:
	
		LightNode();
		virtual ~LightNode();
		
		////////////////////////////////////////////////
		//	AmbientIntensity
		////////////////////////////////////////////////
		
		SFFloat *getAmbientIntensityField();
		
		void setAmbientIntensity(float value);
		float getAmbientIntensity();
		
		////////////////////////////////////////////////
		//	On
		////////////////////////////////////////////////
		
		SFBool *getOnField();
		
		void setOn(bool on);
		void setOn(int value);
		bool isOn();
		
		////////////////////////////////////////////////
		//	Intensity
		////////////////////////////////////////////////
		
		SFFloat *getIntensityField();
		
		void setIntensity(float value);
		float getIntensity();
		
		////////////////////////////////////////////////
		//	Color
		////////////////////////////////////////////////
		
		SFColor *getColorField();
		
		void setColor(float value[]);
		void setColor(float r, float g, float b);
		void getColor(float value[]);
		
		////////////////////////////////////////////////
		//	Diffuse Color
		////////////////////////////////////////////////
		
		void getDiffuseColor(float value[]);
		
		////////////////////////////////////////////////
		//	Ambient Color
		////////////////////////////////////////////////
		
		void getAmbientColor(float value[]);
		
		////////////////////////////////////////////////
		//	functions
		////////////////////////////////////////////////
		
		virtual bool isChildNodeType(Node *node) = 0;
		
		virtual void initialize() = 0;
		
		virtual void uninitialize() = 0;
		
		virtual void update() = 0;
		
		////////////////////////////////////////////////
		//	Infomation
		////////////////////////////////////////////////
		
		virtual void outputContext(std::ostream &printStream, char *indentString) = 0;
	};
	
}

#endif

