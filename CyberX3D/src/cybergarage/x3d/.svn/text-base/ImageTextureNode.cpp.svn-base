/******************************************************************
*
*	CyberX3D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	ImageTextureNode.cpp
*
*	Revisions:
*
*	12/05/02
*		- Changed the super class from TextureNode to Texture2DNode.
*
******************************************************************/

#include <cybergarage/x3d/SceneGraph.h>
#include <cybergarage/x3d/ImageTextureNode.h>
#include <cybergarage/x3d/FileGIF89a.h>
#include <cybergarage/x3d/FileJPEG.h>
#include <cybergarage/x3d/FileTarga.h>
#include <cybergarage/x3d/FilePNG.h>
#include <cybergarage/x3d/Graphic3D.h>

using namespace CyberX3D;

////////////////////////////////////////////////
//	ImageTextureNode::ImageTextureNode
////////////////////////////////////////////////

ImageTextureNode::ImageTextureNode()
{
	setHeaderFlag(false);
	setType(IMAGETEXTURE_NODE);
	
	///////////////////////////
	// Exposed Field
	///////////////////////////
	
	// url field
	urlField = new MFString();
	addExposedField(urlFieldString, urlField);
	
	///////////////////////////
	// Field
	///////////////////////////
	
	mImageBuffer	= NULL;
	mFileImage		= NULL;
}

////////////////////////////////////////////////
//	ImageTextureNode::~ImageTextureNode
////////////////////////////////////////////////

ImageTextureNode::~ImageTextureNode()
{
	if(mImageBuffer)
		delete []mImageBuffer;
	if(mFileImage)
		delete mFileImage;
}

////////////////////////////////////////////////
// Url
////////////////////////////////////////////////

MFString *ImageTextureNode::getUrlField()
{
	if(isInstanceNode() == false)
		return urlField;
	return (MFString *)getExposedField(urlFieldString);
}

void ImageTextureNode::addUrl(char * value)
{
	getUrlField()->addValue(value);
}

int ImageTextureNode::getNUrls()
{
	return getUrlField()->getSize();
}

char *ImageTextureNode::getUrl(int index)
{
	return getUrlField()->get1Value(index);
}

void ImageTextureNode::setUrl(int index, char *urlString)
{
	getUrlField()->set1Value(index, urlString);
}

////////////////////////////////////////////////
//	ImageTextureNode::createImage
////////////////////////////////////////////////

bool ImageTextureNode::createImage()
{
	if(mFileImage)
	{
		delete mFileImage;
		mFileImage = NULL;
		mWidth	= 0;
		mHeight	= 0;
	}
	
	if(getNUrls() <= 0)
		return false;
		
	char *filename = getUrl(0);
	if(filename == NULL)
		return false;
		
#ifdef SUPPORT_URL
	SceneGraph	*sg			= getSceneGraph();
	bool		downloaded	= false;
#endif
	
	FILE *fp = fopen(filename, "rt");
	if(fp == NULL)
	{
#ifdef SUPPORT_URL
		if(sg->getUrlStream(filename))
		{
			downloaded = true;
			char *filename = sg->getUrlOutputFilename();
		}
		else
			return false;
#else
		return false;
#endif
	}
	else
		fclose(fp);
		
	mFileImage = NULL;
	
	switch(GetFileFormat(filename))
	{
	case FILE_FORMAT_GIF:
		mFileImage = new FileGIF89a(filename);
		break;
#ifdef SUPPORT_JPEG
	case FILE_FORMAT_JPEG:
		mFileImage = new FileJPEG(filename);
		break;
#endif
#ifdef SUPPORT_PNG
	case FILE_FORMAT_PNG:
		mFileImage = new FilePNG(filename);
		break;
#endif
	}
	
#ifdef SUPPORT_URL
	if(downloaded)
		sg->deleteUrlOutputFilename();
#endif
		
	if(!mFileImage)
		return false;
		
#ifdef SUPPORT_OPENGL
	mWidth	= GetOpenGLTextureSize(mFileImage->getWidth());
	mHeight	= GetOpenGLTextureSize(mFileImage->getHeight());
#else
	mWidth	= mFileImage->getWidth();
	mHeight	= mFileImage->getHeight();
#endif
	
	if(mImageBuffer != NULL)
		delete []mImageBuffer;
		
	mImageBuffer = mFileImage->getRGBAImage(mWidth, mHeight);
	
	if(mImageBuffer == NULL)
	{
		mWidth	= 0;
		mHeight	= 0;
	}
	
#ifdef SUPPORT_OPENGL
	setHasTransparencyColor(mFileImage->hasTransparencyColor());
#endif
	
	return true;
}

////////////////////////////////////////////////
//	ImageTextureNode::createImage
////////////////////////////////////////////////

void ImageTextureNode::initialize()
{
	if(0 < getNUrls())
		updateTexture();
	else
		setCurrentTextureName(NULL);
}

////////////////////////////////////////////////
//	ImageTextureNode::uninitialize
////////////////////////////////////////////////

void ImageTextureNode::uninitialize()
{
}

////////////////////////////////////////////////
//	ImageTextureNode::updateTexture
////////////////////////////////////////////////

void ImageTextureNode::updateTexture()
{
#ifdef SUPPORT_OPENGL
	GLuint texName = (GLuint)getTextureName();
	if(0 < texName)
		glDeleteTextures(1, &texName);
		
	if(createImage() == false)
	{
		setTextureName(0);
		setCurrentTextureName(NULL);
		return;
	}
	
	if(getWidth() == 0 || getHeight() == 0)
	{
		setTextureName(0);
		setCurrentTextureName(NULL);
		return;
	}
	
	glGenTextures(1, &texName);
	if(0 < texName)
	{
		glBindTexture(GL_TEXTURE_2D, texName);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexImage2D(GL_TEXTURE_2D, 0, 4, getWidth(), getHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, getImage());
		
		setTextureName(texName);
		
		if(0 < getNUrls())
			setCurrentTextureName(getUrl(0));
		else
			setCurrentTextureName(NULL);
	}
	else
	{
		setTextureName(0);
		setCurrentTextureName(NULL);
	}
#endif
}

////////////////////////////////////////////////
//	ImageTextureNode::update
////////////////////////////////////////////////

void ImageTextureNode::update()
{
	if(0 < getNUrls())
	{
		char *urlFilename = getUrl(0);
		char *currTexFilename = getCurrentTextureName();
		
		if(urlFilename != NULL && currTexFilename != NULL)
		{
			if(strcmp(urlFilename, currTexFilename) != 0)
				updateTexture();
		}
		if(urlFilename == NULL && currTexFilename != NULL)
			updateTexture();
		if(urlFilename != NULL && currTexFilename == NULL)
			updateTexture();
	}
}

////////////////////////////////////////////////
//	infomation
////////////////////////////////////////////////

void ImageTextureNode::outputContext(std::ostream &printStream, char *indentString)
{
	SFBool *repeatS = getRepeatSField();
	SFBool *repeatT = getRepeatTField();
	
	printStream << indentString << "\t" << "repeatS " << repeatS  << std::endl;
	printStream << indentString << "\t" << "repeatT " << repeatT  << std::endl;
	
	if(0 < getNUrls())
	{
		MFString *url = getUrlField();
		printStream << indentString << "\t" << "url [" << std::endl;
		url->MField::outputContext(printStream, indentString, "\t\t");
		printStream << indentString << "\t" << "]"  << std::endl;
	}
}
