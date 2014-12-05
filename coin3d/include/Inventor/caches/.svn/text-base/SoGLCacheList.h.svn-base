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

#ifndef COIN_SOGLCACHELIST_H
#define COIN_SOGLCACHELIST_H

#include <Inventor/SbBasic.h>
#include <Inventor/lists/SbList.h>

class SoGLRenderAction;
class SoGLRenderCache;

class SoGLCacheList
{
public:
	SoGLCacheList(int numcaches = 2);
	~SoGLCacheList();
	
	SbBool call(SoGLRenderAction * action, uint32_t pushattribbits = 0);
	
	void open(SoGLRenderAction * action, SbBool autocache = TRUE);
	void close(SoGLRenderAction * action);
	
	void invalidateAll(void);
	
private:
	SbList <SoGLRenderCache *> itemlist;
	int numcaches;
	unsigned int flags;
	SoGLRenderCache * opencache;
	SbBool savedinvalid;
	int autocachebits;
};

#endif // COIN_SOGLCACHELIST_H
