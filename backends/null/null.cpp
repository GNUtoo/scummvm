/* ScummVM - Scumm Interpreter
 * Copyright (C) 2001-2004 The ScummVM project
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * $Header$
 *
 */

#include "stdafx.h"
#include "common/scummsys.h"
#include "common/system.h"

#if defined(USE_NULL_DRIVER)

#include "common/util.h"
#include "common/rect.h"
#include "common/savefile.h"

class OSystem_NULL : public OSystem {
public:
	static OSystem *instance();

public:

	OSystem_NULL();
	virtual ~OSystem_NULL();

	virtual bool hasFeature(Feature f);
	virtual void setFeatureState(Feature f, bool enable);
	virtual bool getFeatureState(Feature f);
	virtual const GraphicsMode *getSupportedGraphicsModes() const;
	virtual int getDefaultGraphicsMode() const;
	virtual bool setGraphicsMode(int mode);
	bool setGraphicsMode(const char *name);
	virtual int getGraphicsMode() const;
	virtual void initSize(uint width, uint height);
	virtual int16 getHeight();
	virtual int16 getWidth();
	virtual void setPalette(const byte *colors, uint start, uint num);
	virtual void copyRectToScreen(const byte *buf, int pitch, int x, int y, int w, int h);
	virtual void updateScreen();
	virtual void move_screen(int dx, int dy, int height);
	virtual void set_shake_pos(int shakeOffset);

	virtual void showOverlay();
	virtual void hideOverlay();
	virtual void clearOverlay();
	virtual void grabOverlay(OverlayColor *buf, int pitch);
	virtual void copyRectToOverlay(const OverlayColor *buf, int pitch, int x, int y, int w, int h);
	virtual int16 getOverlayHeight();
	virtual int16 getOverlayWidth();

	virtual OverlayColor RGBToColor(uint8 r, uint8 g, uint8 b);
	virtual void colorToRGB(OverlayColor color, uint8 &r, uint8 &g, uint8 &b);
	
	virtual bool showMouse(bool visible);

	virtual void warpMouse(int x, int y);
	virtual void setMouseCursor(const byte *buf, uint w, uint h, int hotspotX, int hotspotY, byte keycolor = 255);

	virtual bool poll_event(Event *event);
	virtual uint32 get_msecs();
	virtual void delay_msecs(uint msecs);

	virtual void setTimerCallback(TimerProc callback, int interval);

	virtual MutexRef createMutex(void);
	virtual void lockMutex(MutexRef mutex);
	virtual void unlockMutex(MutexRef mutex);
	virtual void deleteMutex(MutexRef mutex);

	virtual bool setSoundCallback(SoundProc proc, void *param);
	virtual void clearSoundCallback();
	virtual int getOutputSampleRate() const;

	virtual bool openCD(int drive);
	virtual bool poll_cdrom();

	virtual void play_cdrom(int track, int num_loops, int start_frame, int duration);
	virtual void stop_cdrom();
	virtual void update_cdrom();

	virtual void quit();

	virtual void setWindowCaption(const char *caption);

	virtual void displayMessageOnOSD(const char *msg);

	virtual SaveFileManager *get_savefile_manager();

};

static const OSystem::GraphicsMode s_supportedGraphicsModes[] = {
	{0, 0, 0}
};

OSystem_NULL::OSystem_NULL()
{
}

OSystem_NULL::~OSystem_NULL()
{
}

bool OSystem_NULL::hasFeature(Feature f)
{
	return false;
}

void OSystem_NULL::setFeatureState(Feature f, bool enable)
{
}

bool OSystem_NULL::getFeatureState(Feature f)
{
	return false;
}

const OSystem::GraphicsMode* OSystem_NULL::getSupportedGraphicsModes() const
{
	return s_supportedGraphicsModes;
}


int OSystem_NULL::getDefaultGraphicsMode() const
{
	return -1;
}

bool OSystem_NULL::setGraphicsMode(int mode)
{
	return true;
}

bool OSystem_NULL::setGraphicsMode(const char *name)
{
	return true;
}

int OSystem_NULL::getGraphicsMode() const
{
	return -1;
}

void OSystem_NULL::initSize(uint width, uint height)
{
}

int16 OSystem_NULL::getHeight()
{
	return 320;
}

int16 OSystem_NULL::getWidth()
{
	return 200;
}

void OSystem_NULL::setPalette(const byte *colors, uint start, uint num)
{
}

void OSystem_NULL::copyRectToScreen(const byte *buf, int pitch, int x, int y, int w, int h)
{
}

void OSystem_NULL::updateScreen()
{
}

void OSystem_NULL::move_screen(int dx, int dy, int height)
{
}

void OSystem_NULL::set_shake_pos(int shakeOffset)
{
}

void OSystem_NULL::showOverlay ()
{
}

void OSystem_NULL::hideOverlay ()
{
}

void OSystem_NULL::clearOverlay ()
{
}

void OSystem_NULL::grabOverlay (OverlayColor *buf, int pitch)
{
}

void OSystem_NULL::copyRectToOverlay (const OverlayColor *buf, int pitch, int x, int y, int w, int h)
{
}

int16 OSystem_NULL::getOverlayHeight()
{
	return getHeight();
}

int16 OSystem_NULL::getOverlayWidth()
{
	return getWidth();
}

OverlayColor OSystem_NULL::RGBToColor(uint8 r, uint8 g, uint8 b)
{
	return 0;
}

void OSystem_NULL::colorToRGB(OverlayColor color, uint8 &r, uint8 &g, uint8 &b)
{
}
	
bool OSystem_NULL::showMouse(bool visible)
{
	return true;
}

void OSystem_NULL::warpMouse(int x, int y)
{
}

void OSystem_NULL::setMouseCursor(const byte *buf, uint w, uint h, int hotspotX, int hotspotY, byte keycolor)
{
}

bool OSystem_NULL::poll_event(Event *event)
{
	return false;
}

uint32 OSystem_NULL::get_msecs()
{
	return 0;
}

void OSystem_NULL::delay_msecs(uint msecs)
{	
}

void OSystem_NULL::setTimerCallback(TimerProc callback, int interval)
{
}

OSystem::MutexRef OSystem_NULL::createMutex(void)
{
	return NULL;
}

void OSystem_NULL::lockMutex(MutexRef mutex)
{
}

void OSystem_NULL::unlockMutex(MutexRef mutex)
{
}

void OSystem_NULL::deleteMutex(MutexRef mutex)
{
}

bool OSystem_NULL::setSoundCallback(SoundProc proc, void *param)
{
	return true;
}

void OSystem_NULL::clearSoundCallback()
{
}

int OSystem_NULL::getOutputSampleRate() const
{
	return 22050;
}

bool OSystem_NULL::openCD(int drive)
{
	return true;
}

bool OSystem_NULL::poll_cdrom()
{
	return true;
}

void OSystem_NULL::play_cdrom(int track, int num_loops, int start_frame, int duration)
{
}

void OSystem_NULL::stop_cdrom()
{
}

void OSystem_NULL::update_cdrom()
{
}

void OSystem_NULL::quit()
{
}

void OSystem_NULL::setWindowCaption(const char *caption)
{
}

void OSystem_NULL::displayMessageOnOSD(const char *msg)
{
}

SaveFileManager* OSystem_NULL::get_savefile_manager()
{
	return NULL;
}


OSystem *OSystem_NULL_create() {
	return new OSystem_NULL();
}
#else /* USE_NULL_DRIVER */

OSystem *OSystem_NULL_create() {
	return NULL;
}

#endif
