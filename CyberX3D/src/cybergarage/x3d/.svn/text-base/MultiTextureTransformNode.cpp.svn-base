/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	MultiTextureTransformNode.cpp
*
*	Revisions;
*
*	12/06/02
*		- The first revision.
*
******************************************************************/

#include <cybergarage/x3d/MultiTextureTransformNode.h>

using namespace CyberX3D;

static const char textureTransformFieldString[] = "textureTransform";

MultiTextureTransformNode::MultiTextureTransformNode()
{
	setHeaderFlag(false);
	setType(MULTITEXTURETRANSFORM_NODE);
	
	// textureTransform exposed field
	textureTransformField = new MFNode();
	addExposedField(textureTransformFieldString, textureTransformField);
}

MultiTextureTransformNode::~MultiTextureTransformNode()
{
}

////////////////////////////////////////////////
//	textureTransform
////////////////////////////////////////////////

MFNode *MultiTextureTransformNode::getTextureTransformField()
{
	if(isInstanceNode() == false)
		return textureTransformField;
	return (MFNode *)getExposedField(textureTransformFieldString);
}

void MultiTextureTransformNode::addTextureTransform(Node *value)
{
	getTextureTransformField()->addValue(value);
}

int MultiTextureTransformNode::getNTextureTransforms()
{
	return getTextureTransformField()->getSize();
}

Node *MultiTextureTransformNode::getTextureTransform(int index)
{
	return getTextureTransformField()->get1Value(index);
}

////////////////////////////////////////////////
//	functions
////////////////////////////////////////////////

bool MultiTextureTransformNode::isChildNodeType(Node *node)
{
	return false;
}

void MultiTextureTransformNode::initialize()
{
}

void MultiTextureTransformNode::uninitialize()
{
}

void MultiTextureTransformNode::update()
{
	/*
		float fraction = getFraction();
		int index = -1;
		int nKey = getNKeys();
		for (int n=0; n<(nKey-1); n++) {
			if (getKey(n) <= fraction && fraction <= getKey(n+1)) {
				index = n;
				break;
			}
		}
		if (index == -1)
			return;
	
		float scale = (fraction - getKey(index)) / (getKey(index+1) - getKey(index));
	
		float value1 = getTextureTransform(index);
		float value2 = getTextureTransform(index+1);
		float valueOut = value1 + (value2 - value1)*scale;
	
		setValue(valueOut);
		sendEvent(getValueField());
	*/
}

////////////////////////////////////////////////
//	Output
////////////////////////////////////////////////

void MultiTextureTransformNode::outputContext(std::ostream &printStream, char *indentString)
{
}

////////////////////////////////////////////////
//	List
////////////////////////////////////////////////

MultiTextureTransformNode *MultiTextureTransformNode::next()
{
	return (MultiTextureTransformNode *)Node::next(getType());
}

MultiTextureTransformNode *MultiTextureTransformNode::nextTraversal()
{
	return (MultiTextureTransformNode *)Node::nextTraversalByType(getType());
}
