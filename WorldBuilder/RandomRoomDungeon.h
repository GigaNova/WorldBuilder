#pragma once
#include "Room.h"
#include "Dungeon.h"

class RandomRoomDungeon : public Dungeon
{
public:
	static const int MAX_ROOMS = 128;
	static const int MAX_TRIES = 500;
	static const int MAX_ROOM_SIZE = 16;
	static const int MAX_DISTANCE = 64;

	RandomRoomDungeon();
	~RandomRoomDungeon();

	std::vector<Solid*> getSolids() override;
};

