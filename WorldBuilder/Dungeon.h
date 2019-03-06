#pragma once
#include "Room.h"
#include "Entity.h"

class Dungeon
{
public:
	Dungeon();
	~Dungeon();

	std::vector<Entity*> getEntities() const { return m_entities; }
	virtual std::vector<Solid*> getSolids() = 0;
protected:
	std::vector<Room*> m_rooms;
	std::vector<Entity*> m_entities;
};

