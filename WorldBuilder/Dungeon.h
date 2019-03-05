#pragma once
#include "Room.h"
#include "Entity.h"

class Dungeon
{
public:
	Dungeon();
	~Dungeon();

	std::vector<Room*> getRooms() const { return m_rooms; }
	std::vector<Entity*> getEntities() const { return m_entities; }
protected:
	std::vector<Room*> m_rooms;
	std::vector<Entity*> m_entities;
};

