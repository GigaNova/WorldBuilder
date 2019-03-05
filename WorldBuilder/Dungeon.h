#pragma once
#include "Room.h"

class Dungeon
{
public:
	Dungeon();
	~Dungeon();

	std::vector<Room*> getRooms() const { return m_rooms; }

protected:
	std::vector<Room*> m_rooms;
};

