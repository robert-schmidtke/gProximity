/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	TextNode.h
*
******************************************************************/

#ifndef _CX3D_TEXTNODE_H_
#define _CX3D_TEXTNODE_H_

#include <cybergarage/x3d/Geometry3DNode.h>
#include <cybergarage/x3d/FontStyleNode.h>

#if defined(SUPPORT_OPENGL) && defined(WIN32)

namespace CyberX3D
{

	class OGLFontOutline : public LinkedListNode<OGLFontOutline>
	{
	private:
		int				mFamily;
		int				mStyle;
		unsigned int	mListBaseID;
	public:
		OGLFontOutline(int family, int style, unsigned int id);
		void setFamily(int family);
		int getFamily();
		void setStyle(int style);
		int getStyle();
		void setListBaseID(unsigned int id);
		int getListBaseID();
		OGLFontOutline *next();
	};
	
}

#endif

namespace CyberX3D
{

	class TextNode : public Geometry3DNode
	{
	
		SFNode *fontStyleField;
		SFFloat *maxExtentField;
		MFFloat *lengthField;
		MFString *stringField;
		
	public:
	
		TextNode();
		~TextNode();
		
		////////////////////////////////////////////////
		//	FontStyle
		////////////////////////////////////////////////
		
		SFNode *getFontStyleField();
		
		////////////////////////////////////////////////
		//	MaxExtent
		////////////////////////////////////////////////
		
		SFFloat *getMaxExtentField();
		
		void setMaxExtent(float value);
		float getMaxExtent();
		
		////////////////////////////////////////////////
		// String
		////////////////////////////////////////////////
		
		MFString *getStringField();
		
		void addString(char *value);
		int getNStrings();
		char *getString(int index);
		void setString(int index, char* value);
		
		////////////////////////////////////////////////
		// length
		////////////////////////////////////////////////
		
		MFFloat *getLengthField();
		
		void addLength(float value);
		int getNLengths();
		float getLength(int index);
		
		////////////////////////////////////////////////
		//	List
		////////////////////////////////////////////////
		
		TextNode *next();
		TextNode *nextTraversal();
		
		////////////////////////////////////////////////
		//	functions
		////////////////////////////////////////////////
		
		bool isChildNodeType(Node *node);
		void initialize();
		void uninitialize();
		void update();
		
		////////////////////////////////////////////////
		//	BoundingBox
		////////////////////////////////////////////////
		
		void recomputeBoundingBox();
		
		////////////////////////////////////////////////
		//	functions
		////////////////////////////////////////////////
		
		int getNPolygons()
		{
			return 0;
		}
		
		////////////////////////////////////////////////
		//	recomputeDisplayList
		////////////////////////////////////////////////
		
#ifdef SUPPORT_OPENGL
		void recomputeDisplayList();
#endif
		
		////////////////////////////////////////////////
		//	FontStyle
		////////////////////////////////////////////////
		
		int getFontStyleFamilyNumber();
		int getFontStyleStyleNumber();
		
		////////////////////////////////////////////////
		//	SUPPORT_OPENGL
		////////////////////////////////////////////////
		
#ifdef SUPPORT_OPENGL
		void draw();
#endif
		
#if defined(SUPPORT_OPENGL) && defined(WIN32)
		static LinkedList<OGLFontOutline>	mOGLFontOutlines;
		OGLFontOutline *getOGLFontOutlines();
		OGLFontOutline *getOGLFontOutline(int family, int style);
		void addOGLFontOutline(OGLFontOutline *node);
		unsigned int createUseFontOutline(int family, int style);
		void addOGLFontOutline(int family, int style, unsigned int id);
		int getNOGLFontOutlines();
#endif
		
		////////////////////////////////////////////////
		//	Stringmation
		////////////////////////////////////////////////
		
		void outputContext(std::ostream &printStream, char *indentString);
	};
	
}

#endif

