#pragma once
#include "Room.h"
#include "Dungeon.h"

static const int GRID_SIZE = 64;
static const int MAX_ROOMS = 32;
static const int MAX_TRIES = 500;
static const int MAX_ROOM_SIZE = 16;
static const int MAX_DISTANCE = 64;

class RandomRoomDungeon : public Dungeon
{
public:
	RandomRoomDungeon();
	~RandomRoomDungeon();
};

