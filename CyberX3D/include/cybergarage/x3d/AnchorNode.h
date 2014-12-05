/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	AnchorNode.h
*
******************************************************************/

#ifndef _CX3D_ANCHORNODE_H_
#define _CX3D_ANCHORNODE_H_

#include <cybergarage/x3d/VRML97Fields.h>
#include <cybergarage/x3d/BoundedGroupingNode.h>

namespace CyberX3D
{

	class AnchorNode : public BoundedGroupingNode
	{
	
		SFString *descriptionField;
		MFString *parameterField;
		MFString *urlField;
		
		SFBool *enabledField;
		SFVec3f *centerField;
		
	public:
	
		AnchorNode();
		~AnchorNode();
		
		////////////////////////////////////////////////
		//	Description
		////////////////////////////////////////////////
		
		SFString *getDescriptionField();
		
		void	setDescription(char *value);
		char *getDescription();
		
		////////////////////////////////////////////////
		// Parameter
		////////////////////////////////////////////////
		
		MFString *getParameterField();
		
		void	addParameter(char *value);
		int		getNParameters();
		char *getParameter(int index);
		
		////////////////////////////////////////////////
		// Url
		////////////////////////////////////////////////
		
		MFString *getUrlField();
		
		void	addUrl(char *value);
		int		getNUrls();
		char *getUrl(int index);
		void	setUrl(int index, char *urlString);
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		AnchorNode	*next();
		AnchorNode	*nextTraversal();
		
		////////////////////////////////////////////////
		//	Center (X3D)
		////////////////////////////////////////////////
		
		SFVec3f *getCenterField();
		
		void setCenter(float value[]);
		void setCenter(float x, float y, float z);
		void setCenter(String value);
		void getCenter(float value[]);
		
		////////////////////////////////////////////////
		//	Enabled (X3D)
		////////////////////////////////////////////////
		
		SFBool *getEnabledField();
		
		void setEnabled(bool value);
		bool getEnabled();
		bool isEnabled();
		
		////////////////////////////////////////////////
		//	virtual functions
		////////////////////////////////////////////////
		
		bool	isChildNodeType(Node *node);
		void	initialize();
		void	uninitialize();
		void	update();
		void	outputContext(std::ostream &printStream, char *indentString);
		
	};
	
}

#endif
