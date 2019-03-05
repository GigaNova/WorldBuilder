#include "Map.h"

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

const std::vector<Solid*> Map::getSolids()
{
	return m_solids;
}
