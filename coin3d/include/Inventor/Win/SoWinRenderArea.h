/**************************************************************************
 *
 *  This file is part of the Coin GUI binding libraries.
 *  Copyright (C) 2000 by Systems in Motion.  All rights reserved.
 *
 *  The libraries this file is part of is free software; you can
 *  redistribute them and/or modify them under the terms of the GNU
 *  Lesser General Public License version 2.1 as published by the
 *  Free Software Foundation.  See the file LICENSE.LGPL at the root
 *  directory of the distribution for all the details.
 *
 *  If you want to use the Coin GUI binding libraries for applications
 *  not compatible with the LGPL, contact SIM about acquiring a
 *  Professional Edition License.
 *
 *  Systems in Motion, Prof Brochs gate 6, N-7030 Trondheim, NORWAY
 *  http://www.sim.no/ support@sim.no Voice: +47 22114160 Fax: +47 22207097
 *
 **************************************************************************/

// Generated automatically from SoGuiRenderArea.h.in by configure.
// $Id: SoWinRenderArea.h,v 1.1 2008/09/30 19:09:56 zlj Exp $

#ifndef SOWIN_RENDERAREA_H
#define SOWIN_RENDERAREA_H

#include <Inventor/SbColor.h>
#include <Inventor/SbViewportRegion.h>
#include <Inventor/actions/SoGLRenderAction.h>
#include <Inventor/SoSceneManager.h>

#include <Inventor/Win/SoWinGLWidget.h>

class SbColor;
class SoNode;
class SoSelection;

class SoWinDevice;

typedef SbBool SoWinRenderAreaEventCB(void * closure, MSG * event);

// *************************************************************************

class SOWIN_DLL_API SoWinRenderArea : public SoWinGLWidget
{
	SOWIN_OBJECT_HEADER(SoWinRenderArea, SoWinGLWidget);
	
	
public:
	SoWinRenderArea(
	    HWND parent = NULL,
	    const char * name = NULL,
	    SbBool embed = TRUE,
	    SbBool mouseInput = TRUE,
	    SbBool keyboardInput = TRUE);
	~SoWinRenderArea(void);
	
	virtual void setSceneGraph(SoNode * scene);
	virtual SoNode * getSceneGraph(void);
	void setOverlaySceneGraph(SoNode * scene);
	SoNode * getOverlaySceneGraph(void);
	
	void registerDevice(SoWinDevice * device);
	void unregisterDevice(SoWinDevice * device);
	void setBackgroundColor(const SbColor & color);
	const SbColor & getBackgroundColor(void) const;
	void setBackgroundIndex(int idx);
	int getBackgroundIndex(void) const;
	void setOverlayBackgroundIndex(int idx);
	int getOverlayBackgroundIndex(void) const;
	void setColorMap(int start, int num, const SbColor * colors);
	void setOverlayColorMap(int start, int num, const SbColor * colors);
	void setViewportRegion(const SbViewportRegion & newRegion);
	const SbViewportRegion & getViewportRegion(void) const;
	void setTransparencyType(SoGLRenderAction::TransparencyType type);
	SoGLRenderAction::TransparencyType getTransparencyType(void) const;
	void setAntialiasing(SbBool smoothing, int numPasses);
	void getAntialiasing(SbBool & smoothing, int & numPasses) const;
	void setClearBeforeRender(SbBool enable, SbBool zbEnable = TRUE);
	SbBool isClearBeforeRender(void) const;
	SbBool isClearZBufferBeforeRender(void) const;
	void setClearBeforeOverlayRender(SbBool enable);
	SbBool isClearBeforeOverlayRender(void) const;
	void setAutoRedraw(SbBool enable);
	SbBool isAutoRedraw(void) const;
	void setRedrawPriority(uint32_t priority);
	uint32_t getRedrawPriority(void) const;
	static uint32_t getDefaultRedrawPriority(void);
	void render(void);
	void renderOverlay(void);
	void scheduleRedraw(void);
	void scheduleOverlayRedraw(void);
	void redrawOnSelectionChange(SoSelection * selection);
	void redrawOverlayOnSelectionChange(SoSelection * selection);
	void setEventCallback(SoWinRenderAreaEventCB * func, void * user = NULL);
	void setSceneManager(SoSceneManager * manager);
	SoSceneManager * getSceneManager(void) const;
	void setOverlaySceneManager(SoSceneManager * manager);
	SoSceneManager * getOverlaySceneManager(void) const;
	void setGLRenderAction(SoGLRenderAction * action);
	SoGLRenderAction * getGLRenderAction(void) const;
	void setOverlayGLRenderAction(SoGLRenderAction * action);
	SoGLRenderAction * getOverlayGLRenderAction(void) const;
	
protected:
	SoWinRenderArea(
	    HWND parent,
	    const char * name,
	    SbBool embed,
	    SbBool mouseInput,
	    SbBool keyboardInput,
	    SbBool build);
	    
	virtual void redraw(void);
	virtual void actualRedraw(void);
	virtual void redrawOverlay(void);
	virtual void actualOverlayRedraw(void);
	
	virtual SbBool processSoEvent(const SoEvent * const event);
	virtual void processEvent(MSG * event);
	virtual void initGraphic(void);
	virtual void initOverlayGraphic(void);
	virtual void sizeChanged(const SbVec2s size);
	virtual void widgetChanged(HWND widget);
	virtual void afterRealizeHook(void);
	
	HWND buildWidget(HWND parent);
	
	virtual const char * getDefaultWidgetName(void) const;
	virtual const char * getDefaultTitle(void) const;
	virtual const char * getDefaultIconTitle(void) const;
	
	virtual SbBool glScheduleRedraw(void);
	
	SbBool invokeAppCB(MSG * event);
	
	const SoEvent * getSoEvent(MSG * event);
	
	SbPList * deviceList;
	
	SoWinRenderAreaEventCB * appEventHandler;
	void * appEventHandlerData;
	
private:
	class SoWinRenderAreaP * priv;
	
	void constructor(SbBool mouseInput, SbBool keyboardInput, SbBool build);
	static void renderCB(void * user, SoSceneManager * manager);
	static void selection_redraw_cb(void * data, SoSelection * sel);
	void setDevicesWindowSize(const SbVec2s size);
	
}; // class SoWinRenderArea

// *************************************************************************

#endif // ! SOWIN_RENDERAREA_H
