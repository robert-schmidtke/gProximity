/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	TextureCoordinateGeneratorNode.cpp
*
******************************************************************/

#include <cybergarage/x3d/VRML97Fields.h>
#include <cybergarage/x3d/TextureCoordinateGeneratorNode.h>

using namespace CyberX3D;

static const char modeFieldString[] = "mode";

TextureCoordinateGeneratorNode::TextureCoordinateGeneratorNode()
{
	setHeaderFlag(false);
	setType(TEXCOORDGEN_NODE);
	
	// parameter exposed field
	parameterField = new MFFloat();
	addExposedField(parameterFieldString, parameterField);
	
	// set_mode eventIn field
	modeField = new SFString("SPHERE");
	addEventIn(modeFieldString, modeField);
}

TextureCoordinateGeneratorNode::~TextureCoordinateGeneratorNode()
{
}

////////////////////////////////////////////////
//	parameter
////////////////////////////////////////////////

MFFloat *TextureCoordinateGeneratorNode::getParameterField()
{
	if(isInstanceNode() == false)
		return parameterField;
	return (MFFloat *)getExposedField(parameterFieldString);
}

void TextureCoordinateGeneratorNode::addParameter(float value)
{
	getParameterField()->addValue(value);
}

int TextureCoordinateGeneratorNode::getNParameters()
{
	return getParameterField()->getSize();
}

float TextureCoordinateGeneratorNode::getParameter(int index)
{
	return getParameterField()->get1Value(index);
}


////////////////////////////////////////////////
//	mode
////////////////////////////////////////////////

SFString *TextureCoordinateGeneratorNode::getModeField()
{
	if(isInstanceNode() == false)
		return modeField;
	return (SFString *)getEventIn(modeFieldString);
}

void TextureCoordinateGeneratorNode::setMode(const char *value)
{
	getModeField()->setValue(value);
}

char *TextureCoordinateGeneratorNode::getMode()
{
	return getModeField()->getValue();
}

////////////////////////////////////////////////
//	List
////////////////////////////////////////////////

TextureCoordinateGeneratorNode *TextureCoordinateGeneratorNode::next()
{
	return (TextureCoordinateGeneratorNode *)Node::next(getType());
}

TextureCoordinateGeneratorNode *TextureCoordinateGeneratorNode::nextTraversal()
{
	return (TextureCoordinateGeneratorNode *)Node::nextTraversalByType(getType());
}

////////////////////////////////////////////////
//	virtual functions
////////////////////////////////////////////////

bool TextureCoordinateGeneratorNode::isChildNodeType(Node *node)
{
	return false;
}

void TextureCoordinateGeneratorNode::initialize()
{
}

void TextureCoordinateGeneratorNode::uninitialize()
{
}

void TextureCoordinateGeneratorNode::update()
{
}

void TextureCoordinateGeneratorNode::outputContext(std::ostream &printStream, char *indentString)
{
}


