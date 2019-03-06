#include "Map.h"
#include "Room.h"
#include "Dungeon.h"

Map::Map()
{
	
}

Map::~Map()
{
}

void Map::addSolid(int t_x, int t_y, int t_z, int t_width, int t_length, int t_height)
{
	m_solids.push_back(new Solid(t_x, t_y, t_z, t_width, t_length, t_height));
}

void Map::addDungeon(Dungeon* t_dungeon)
{
	for (Solid* pSolid : t_dungeon->getSolids())
	{
		m_solids.push_back(pSolid);
	}

	for (Entity* pEntity : t_dungeon->getEntities())
	{
		m_entities.push_back(pEntity);
	}
}

void Map::addEntity(Entity* t_entity)
{
	m_entities.push_back(t_entity);
}

const std::vector<Entity*> Map::getEntities()
{
	return m_entities;
}

const std::vector<Solid*> Map::getSolids()
{
	return m_solids;
}

const int Map::getAmountOfFaces()
{
	return m_solids.size() * AMOUNT_OF_FACES;
}
