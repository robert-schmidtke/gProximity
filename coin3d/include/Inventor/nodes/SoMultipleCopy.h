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

#ifndef COIN_SOMULTIPLECOPY_H
#define COIN_SOMULTIPLECOPY_H

#include <Inventor/nodes/SoSubNode.h>
#include <Inventor/nodes/SoGroup.h>
#include <Inventor/fields/SoMFMatrix.h>


class COIN_DLL_API SoMultipleCopy : public SoGroup
{
	typedef SoGroup inherited;
	
	SO_NODE_HEADER(SoMultipleCopy);
	
public:
	static void initClass(void);
	SoMultipleCopy(void);
	
	SoMFMatrix matrix;
	
	virtual SbBool affectsState(void) const;
	
	virtual void doAction(SoAction * action);
	virtual void callback(SoCallbackAction * action);
	virtual void GLRender(SoGLRenderAction * action);
	virtual void pick(SoPickAction * action);
	virtual void getBoundingBox(SoGetBoundingBoxAction * action);
	virtual void handleEvent(SoHandleEventAction * action);
	virtual void getMatrix(SoGetMatrixAction * action);
	virtual void search(SoSearchAction * action);
	virtual void getPrimitiveCount(SoGetPrimitiveCountAction * action);
	
protected:
	virtual ~SoMultipleCopy();
};

#endif // !COIN_SOMULTIPLECOPY_H
