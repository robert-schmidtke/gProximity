/**************************************************************************\
 *
 *  This file is part of the Coin 3D visualization library.
 *  Copyright (C) 1998-2002 by Systems in Motion. All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public License
 *  version 2.1 as published by the Free Software Foundation. See the
 *  file LICENSE.LGPL at the root directory of the distribution for
 *  more details.
 *
 *  If you want to use Coin for applications not compatible with the
 *  LGPL, please contact SIM to acquire a Professional Edition license.
 *
 *  Systems in Motion, Prof Brochs gate 6, 7030 Trondheim, NORWAY
 *  http://www.sim.no support@sim.no Voice: +47 22114160 Fax: +47 22207097
 *
\**************************************************************************/

#ifndef COIN_SOGLRENDERCACHE_H
#define COIN_SOGLRENDERCACHE_H

#include <Inventor/caches/SoCache.h>
#include <Inventor/lists/SbList.h>

class SoGLDisplayList;

class SoGLRenderCache : public SoCache
{
	typedef SoCache inherited;
public:

	SoGLRenderCache(SoState * state);
	~SoGLRenderCache();
	
	void open(SoState * state);
	void close(void);
	void call(SoState * state);
	
	int getCacheContext(void) const;
	
	virtual SbBool isValid(const SoState * state) const;
	virtual void addNestedCache(SoGLDisplayList * child);
	
protected:
	virtual void  destroy(SoState *state);
	
private:
	SoGLDisplayList * displaylist;
	SoState * openstate;
	SbList <SoGLDisplayList*> nestedcachelist;
};

#endif // COIN_SOGLRENDERCACHE
