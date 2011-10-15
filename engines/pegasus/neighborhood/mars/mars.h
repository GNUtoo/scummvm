/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * Additional copyright for this file:
 * Copyright (C) 1995-1997 Presto Studios, Inc.
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
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef PEGASUS_NEIGHBORHOOD_MARS_MARS_H
#define PEGASUS_NEIGHBORHOOD_MARS_MARS_H

#include "pegasus/neighborhood/neighborhood.h"
#include "pegasus/neighborhood/mars/reactor.h"

namespace Pegasus {

class InventoryItem;
class Mars;

enum tMarsTimerCode {
	kMarsLaunchTubeReached,
	kMarsCanyonChaseFinished,
	kMarsSpaceChaseFinished // Player ran out of time...
};

struct tMarsTimerEvent {
	Mars *mars;
	tMarsTimerCode event;
};

enum tShuttleWeaponSelection {
	kNoWeapon,
	kEnergyBeam,
	kGravitonCannon,
	kTractorBeam
};

const tRoomID kMars0A = 0;
const tRoomID kMars35 = 38;
const tRoomID kMars39 = 42;
const tRoomID kMars60 = 58;
const tRoomID kMarsMaze004 = 60;
const tRoomID kMarsMaze200 = 224;

class Mars : public Neighborhood {
friend void robotTimerExpiredFunction(FunctionPtr *, void *);
friend void lockThawTimerExpiredFunction(FunctionPtr *, void *);
friend void bombTimerExpiredFunction(FunctionPtr *, void *);
friend void bombTimerExpiredInGameFunction(FunctionPtr *, void *);
friend void airStageExpiredFunction(FunctionPtr *, void *);

public:
	Mars(InputHandler *, PegasusEngine *);
	virtual ~Mars();

	void flushGameState();

	virtual uint16 getDateResID() const;

	virtual tAirQuality getAirQuality(const tRoomID);

	void checkAirMask();

	Common::String getBriefingMovie();
	Common::String getEnvScanMovie();
	uint getNumHints();
	Common::String getHintMovie(uint);

	virtual void shieldOn();
	virtual void shieldOff();

	void checkContinuePoint(const tRoomID, const tDirectionConstant);

	bool canSolve();
	void doSolve();

	bool inColorMatchingGame();

	// TODO: Space chase functions

protected:
	enum {
		kMarsPrivatePodStorageOpenFlag,
		kMarsPrivatePodTurnLeftFlag,
		kMarsPrivatePodTurnRightFlag,
		kMarsPrivateRobotTiredOfWaitingFlag,
		kMarsPrivatePlatformZoomedInFlag,
		kMarsPrivateBombExposedFlag,
		kMarsPrivateDraggingBombFlag,
		kMarsPrivateInSpaceChaseFlag,
		kMarsPrivateGotMapChipFlag,
		kMarsPrivateGotOpticalChipFlag,
		kMarsPrivateGotShieldChipFlag,
		kNumMarsPrivateFlags
	};
	
	void init();
	void start();
	void setUpAIRules();
	void arriveAt(const tRoomID, const tDirectionConstant);
	void takeItemFromRoom(Item *);
	void dropItemIntoRoom(Item *, Hotspot *);
	void activateHotspots();
	void activateOneHotspot(HotspotInfoTable::Entry &, Hotspot *);
	void clickInHotspot(const Input &, const Hotspot *);
	tInputBits getInputFilter();
	
	TimeValue getViewTime(const tRoomID, const tDirectionConstant);
	void getZoomEntry(const tHotSpotID, ZoomTable::Entry &);
	void findSpotEntry(const tRoomID, const tDirectionConstant, tSpotFlags, SpotTable::Entry &);
	tCanOpenDoorReason canOpenDoor(DoorTable::Entry &);
	void openDoor();
	void closeDoorOffScreen(const tRoomID, const tDirectionConstant);
	int16 getStaticCompassAngle(const tRoomID, const tDirectionConstant);
	void getExitCompassMove(const ExitTable::Entry &, FaderMoveSpec &);
	void getExtraCompassMove(const ExtraTable::Entry &, FaderMoveSpec &);
	void turnTo(const tDirectionConstant);
	void receiveNotification(Notification *, const tNotificationFlags);
	void doorOpened();
	void setUpReactorEnergyDrain();
	Hotspot *getItemScreenSpot(Item *, DisplayElement *);
	void lockThawed();
	void robotTiredOfWaiting();
	
	void setUpReactorLevel1();
	void setUpNextReactorLevel();
	void makeColorSequence();
	void doUndoOneGuess();
	void doReactorGuess(int32 guess);
	void bombExplodesInGame();
	void didntFindBomb();
	tCanMoveForwardReason canMoveForward(ExitTable::Entry &);
	void cantMoveThatWay(tCanMoveForwardReason);
	void moveForward();
	void bumpIntoWall();
	void turnLeft();
	void turnRight();
	void airStageExpired();
	void loadAmbientLoops();
	void checkAirlockDoors();
	void pickedUpItem(Item *item);
	void cantOpenDoor(tCanOpenDoorReason);
	void launchMaze007Robot();
	void launchMaze015Robot();
	void launchMaze101Robot();
	void launchMaze104Robot();
	void launchMaze133Robot();
	void launchMaze136Robot();
	void launchMaze184Robot();
	void timerExpired(const uint32);
	void spotCompleted();

	// TODO: Space chase functions

	Common::String getSoundSpotsName();
	Common::String getNavMovieName();
	
	InventoryItem *_attackingItem;
	FuseFunction _bombFuse;
	FuseFunction _noAirFuse;
	FuseFunction _utilityFuse;
	FlagsArray<byte, kNumMarsPrivateFlags> _privateFlags;
	uint _reactorStage, _nextGuess;
	int32 _currentGuess[3];
	ReactorGuess _guessObject;
	Picture _undoPict;
	ReactorHistory _guessHistory;
	ReactorChoiceHighlight _choiceHighlight;

	Picture _shuttleInterface1;
	Picture _shuttleInterface2;
	Picture _shuttleInterface3;
	Picture _shuttleInterface4;
	Movie _canyonChaseMovie;

	// TODO: Space chase variables
};

} // End of namespace Pegasus

#endif
