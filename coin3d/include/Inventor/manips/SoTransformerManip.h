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

#ifndef COIN_SOTRANSFORMERMANIP_H
#define COIN_SOTRANSFORMERMANIP_H

#include <Inventor/manips/SoTransformManip.h>


class COIN_DLL_API SoTransformerManip : public SoTransformManip
{
	typedef SoTransformManip inherited;
	
	SO_NODE_HEADER(SoTransformerManip);
	
public:
	static void initClass(void);
	SoTransformerManip(void);
	
	SbBool isLocateHighlighting(void);
	void setLocateHighlighting(SbBool onoff);
	
	void unsquishKnobs(void);
	
protected:
	~SoTransformerManip();
};

#endif // !COIN_SOTRANSFORMERMANIP_H