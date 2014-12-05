/******************************************************************
*
*	BoundingBox2D for C++
*
*	Copyright (C) Satoshi Konno 1996-2002
*
*	File:	BoundingBox2D.h
*
******************************************************************/

#ifndef _CX3D_BOUNDINGBOX2D_H_
#define _CX3D_BOUNDINGBOX2D_H_

namespace CyberX3D
{

	class BoundingBox2D
	{
	
		float	mMaxPosition[2];
		float	mMinPosition[2];
		int		mNPoints;
		
	public:
	
		BoundingBox2D();
		BoundingBox2D(BoundingBox2D *bbox);
		BoundingBox2D(float center[2], float size[2]);
		
		~BoundingBox2D();
		
		void	initialize();
		
		void	addPoint(float point[2]);
		void	addPoint(float x, float y);
		void	addBoundingBox2D(float center[2], float size[2]);
		void	addBoundingBox2D(BoundingBox2D *bbox);
		
		void	setNPoints(int npoints);
		int		getNPoints();
		
		void	setMinPosition(float pos[2]);
		void	setMaxPosition(float pos[2]);
		
		void	setMinPosition(float x, float y);
		void	setMaxPosition(float x, float y);
		
		void	getMinPosition(float pos[2]);
		void	getMaxPosition(float pos[2]);
		
		void	set(float center[2], float size[2]);
		void	set(BoundingBox2D *bbox);
		
		void	getCenter(float center[2]);
		void	getSize(float size[2]);
		
	};
	
}

#endif
