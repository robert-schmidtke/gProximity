/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	TextureCoordinateNode.cpp
*
*	Revisions:
*
*	11/25/02
*		- Changed the super class from Node to GeometricPropertyNode.
*
******************************************************************/

#include <cybergarage/x3d/TextureCoordinateNode.h>

using namespace CyberX3D;

TextureCoordinateNode::TextureCoordinateNode()
{
	setHeaderFlag(false);
	setType(TEXTURECOORDINATE_NODE);
	
	// point exposed field
	pointField = new MFVec2f();
	pointField->setName(pointFieldString);
	addExposedField(pointField);
}

TextureCoordinateNode::~TextureCoordinateNode()
{
}

////////////////////////////////////////////////
//	point
////////////////////////////////////////////////

MFVec2f *TextureCoordinateNode::getPointField()
{
	if(isInstanceNode() == false)
		return pointField;
	return (MFVec2f *)getExposedField(pointFieldString);
}

void TextureCoordinateNode::addPoint(float point[])
{
	getPointField()->addValue(point);
}

int TextureCoordinateNode::getNPoints()
{
	return getPointField()->getSize();
}

void TextureCoordinateNode::getPoint(int index, float point[])
{
	getPointField()->get1Value(index, point);
}

////////////////////////////////////////////////
//	functions
////////////////////////////////////////////////

bool TextureCoordinateNode::isChildNodeType(Node *node)
{
	return false;
}

void TextureCoordinateNode::initialize()
{
}

void TextureCoordinateNode::uninitialize()
{
}

void TextureCoordinateNode::update()
{
}

////////////////////////////////////////////////
//	Output
////////////////////////////////////////////////

void TextureCoordinateNode::outputContext(std::ostream &printStream, char *indentString)
{
	if(0 < getNPoints())
	{
		MFVec2f *point = getPointField();
		printStream <<  indentString << "\t" << "point ["  << std::endl;
		point->MField::outputContext(printStream, indentString, "\t\t");
		printStream << indentString << "\t" << "]" << std::endl;
	}
}

////////////////////////////////////////////////
//	List
////////////////////////////////////////////////

TextureCoordinateNode *TextureCoordinateNode::next()
{
	return (TextureCoordinateNode *)Node::next(getType());
}

TextureCoordinateNode *TextureCoordinateNode::nextTraversal()
{
	return (TextureCoordinateNode *)Node::nextTraversalByType(getType());
}
