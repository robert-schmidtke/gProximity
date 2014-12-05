/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File: PixelTextureNode.cpp
*
*	Revisions:
*
*	12/05/02
*		- Changed the super class from TextureNode to Texture2DNode.
*
******************************************************************/

#include <cybergarage/x3d/PixelTextureNode.h>

using namespace CyberX3D;

PixelTextureNode::PixelTextureNode()
{
	setHeaderFlag(false);
	setType(PIXELTEXTURE_NODE);
	
	///////////////////////////
	// Exposed Field
	///////////////////////////
	
	// image field
	imageField = new SFImage();
	addExposedField(imageFieldString, imageField);
}

PixelTextureNode::~PixelTextureNode()
{
}

////////////////////////////////////////////////
// Image
////////////////////////////////////////////////

SFImage *PixelTextureNode::getImageField()
{
	if(isInstanceNode() == false)
		return imageField;
	return (SFImage *)getExposedField(imageFieldString);
}

void PixelTextureNode::addImage(int value)
{
	getImageField()->addValue(value);
}

int PixelTextureNode::getNImages()
{
	return getImageField()->getSize();
}

int PixelTextureNode::getImage(int index)
{
	return getImageField()->get1Value(index);
}

////////////////////////////////////////////////
//	List
////////////////////////////////////////////////

PixelTextureNode *PixelTextureNode::next()
{
	return (PixelTextureNode *)Node::next(getType());
}

PixelTextureNode *PixelTextureNode::nextTraversal()
{
	return (PixelTextureNode *)Node::nextTraversalByType(getType());
}

////////////////////////////////////////////////
//	functions
////////////////////////////////////////////////

bool PixelTextureNode::isChildNodeType(Node *node)
{
	return false;
}

void PixelTextureNode::initialize()
{
}

void PixelTextureNode::uninitialize()
{
}

void PixelTextureNode::update()
{
}

////////////////////////////////////////////////
//	Imagemation
////////////////////////////////////////////////

void PixelTextureNode::outputContext(std::ostream &printStream, char *indentString)
{
	SFBool *repeatS = getRepeatSField();
	SFBool *repeatT = getRepeatTField();
	if(0 < getNImages())
	{
		SFImage *image = getImageField();
		printStream << indentString << "\t" << "image " << std::endl;
		image->MField::outputContext(printStream, indentString, "\t\t");
		printStream << indentString << "\t" << std::endl;
	}
	
	printStream << indentString << "\t" << "repeatS " << repeatS << std::endl;
	printStream << indentString << "\t" << "repeatT " << repeatT << std::endl;
}
