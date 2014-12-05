/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	MultiTextureNode.cpp
*
*	Revisions;
*
*	12/06/02
*		- The first revision.
*
******************************************************************/

#include <cybergarage/x3d/MultiTextureNode.h>

using namespace CyberX3D;

static const char materialColorFieldName[] = "materialColor";
static const char materialAlphaFieldName[] = "materialAlpha";
static const char transparentFieldName[] = "transparent";
static const char nomipmapFieldName[] = "nomipmap";
static const char textureExposedFieldName[] = "texture";
static const char textureTransformExposedFieldName[] = "textureTransform";
static const char modeFieldString[] = "mode";
static const char colorFieldString[] = "color";
static const char alphaFieldString[] = "alpha";

MultiTextureNode::MultiTextureNode()
{
	setHeaderFlag(false);
	setType(MULTITEXTURE_NODE);
	
	// materialColor exposed field
	materialColorField = new SFBool(true);
	addExposedField(materialColorFieldName, materialColorField);
	
	// materialAlpha exposed field
	materialAlphaField = new SFBool(true);
	addExposedField(materialAlphaFieldName, materialAlphaField);
	
	// transparent exposed field
	transparentField = new SFBool(true);
	addExposedField(transparentFieldName, transparentField);
	
	// nomipmap exposed field
	nomipmapField = new SFBool(true);
	addExposedField(nomipmapFieldName, nomipmapField);
	
	// mode exposed field
	modeField = new MFString();
	addExposedField(modeFieldString, modeField);
	
	// texture exposed field
	textureField = new SFNode();
	addExposedField(textureExposedFieldName, textureField);
	
	// textureTransform exposed field
	texTransformField = new SFNode();
	addExposedField(textureTransformExposedFieldName, texTransformField);
	
	// color exposed field
	colorField = new SFColor(1.0f, 1.0f, 1.0f);
	colorField->setName(colorFieldString);
	addExposedField(colorField);
	
	// alpha exposed field
	alphaField = new SFFloat(1.0f);
	alphaField->setName(alphaFieldString);
	addExposedField(alphaField);
}

MultiTextureNode::~MultiTextureNode()
{
}

////////////////////////////////////////////////
//	SFNodes
////////////////////////////////////////////////

SFNode *MultiTextureNode::getTextureField()
{
	if(isInstanceNode() == false)
		return textureField;
	return (SFNode *)getExposedField(textureExposedFieldName);
}

SFNode *MultiTextureNode::getTextureTransformField()
{
	if(isInstanceNode() == false)
		return texTransformField;
	return (SFNode *)getExposedField(textureTransformExposedFieldName);
}

////////////////////////////////////////////////
//	materialColor
////////////////////////////////////////////////

SFBool *MultiTextureNode::getMaterialColorField()
{
	if(isInstanceNode() == false)
		return materialColorField;
	return (SFBool *)getExposedField(materialColorFieldName);
}

void MultiTextureNode::setMaterialColor(bool value)
{
	getMaterialColorField()->setValue(value);
}

bool MultiTextureNode::getMaterialColor()
{
	return getMaterialColorField()->getValue();
}

bool MultiTextureNode::isMaterialColor()
{
	return getMaterialColor();
}

////////////////////////////////////////////////
//	materialAlpha
////////////////////////////////////////////////

SFBool *MultiTextureNode::getMaterialAlphaField()
{
	if(isInstanceNode() == false)
		return materialAlphaField;
	return (SFBool *)getExposedField(materialAlphaFieldName);
}

void MultiTextureNode::setMaterialAlpha(bool value)
{
	getMaterialAlphaField()->setValue(value);
}

bool MultiTextureNode::getMaterialAlpha()
{
	return getMaterialAlphaField()->getValue();
}

bool MultiTextureNode::isMaterialAlpha()
{
	return getMaterialAlpha();
}

////////////////////////////////////////////////
//	transparent
////////////////////////////////////////////////

SFBool *MultiTextureNode::getTransparentField()
{
	if(isInstanceNode() == false)
		return transparentField;
	return (SFBool *)getExposedField(transparentFieldName);
}

void MultiTextureNode::setTransparent(bool value)
{
	getTransparentField()->setValue(value);
}

bool MultiTextureNode::getTransparent()
{
	return getTransparentField()->getValue();
}

bool MultiTextureNode::isTransparent()
{
	return getTransparent();
}

////////////////////////////////////////////////
//	nomipmap
////////////////////////////////////////////////

SFBool *MultiTextureNode::getNomipmapField()
{
	if(isInstanceNode() == false)
		return nomipmapField;
	return (SFBool *)getExposedField(nomipmapFieldName);
}

void MultiTextureNode::setNomipmap(bool value)
{
	getNomipmapField()->setValue(value);
}

bool MultiTextureNode::getNomipmap()
{
	return getNomipmapField()->getValue();
}

bool MultiTextureNode::isNomipmap()
{
	return getNomipmap();
}

////////////////////////////////////////////////
// Mode
////////////////////////////////////////////////

MFString *MultiTextureNode::getModeField()
{
	if(isInstanceNode() == false)
		return modeField;
	return (MFString *)getExposedField(modeFieldString);
}

void MultiTextureNode::addMode(char *value)
{
	getModeField()->addValue(value);
}

int MultiTextureNode::getNModes()
{
	return getModeField()->getSize();
}

char *MultiTextureNode::getMode(int index)
{
	return getModeField()->get1Value(index);
}

////////////////////////////////////////////////
//	Color
////////////////////////////////////////////////

SFColor *MultiTextureNode::getColorField()
{
	if(isInstanceNode() == false)
		return colorField;
	return (SFColor *)getExposedField(colorFieldString);
}

void MultiTextureNode::setColor(float value[])
{
	getColorField()->setValue(value);
}

void MultiTextureNode::setColor(float r, float g, float b)
{
	getColorField()->setValue(r, g, b);
}

void MultiTextureNode::getColor(float value[])
{
	getColorField()->getValue(value);
}

////////////////////////////////////////////////
//	Alpha
////////////////////////////////////////////////

SFFloat *MultiTextureNode::getAlphaField()
{
	if(isInstanceNode() == false)
		return alphaField;
	return (SFFloat *)getExposedField(alphaFieldString);
}

void MultiTextureNode::setAlpha(float value)
{
	getAlphaField()->setValue(value);
}

float MultiTextureNode::getAlpha()
{
	return getAlphaField()->getValue();
}

////////////////////////////////////////////////
//	List
////////////////////////////////////////////////

MultiTextureNode *MultiTextureNode::next()
{
	return (MultiTextureNode *)Node::next(getType());
}

MultiTextureNode *MultiTextureNode::nextTraversal()
{
	return (MultiTextureNode *)Node::nextTraversalByType(getType());
}

////////////////////////////////////////////////
//	virtual functions
////////////////////////////////////////////////

bool MultiTextureNode::isChildNodeType(Node *node)
{
	return false;
}

void MultiTextureNode::initialize()
{
}

void MultiTextureNode::uninitialize()
{
}

void MultiTextureNode::update()
{
}

void MultiTextureNode::outputContext(std::ostream &printStream, char *indentString)
{
}
