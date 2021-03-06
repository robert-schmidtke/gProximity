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

#ifndef COIN_SOSFIELD_H
#define COIN_SOSFIELD_H

#include <Inventor/fields/SoField.h>


class COIN_DLL_API SoSField : public SoField
{
	typedef SoField inherited;
	
public:
	virtual ~SoSField();
	
	static void initClass(void);
	static SoType getClassTypeId(void);
	
protected:
	SoSField(void);
	
private:
	static SoType classTypeId;
};

#endif // !COIN_SOSFIELD_H
