#include "Corridor.h"

Corridor::Corridor(int t_x, int t_y, int t_z, int t_width, int t_length)
{
	m_solids.push_back(new Solid(t_x, t_y, t_z, t_width, t_length, WALL_WIDTH));
	m_solids.push_back(new Solid(t_x, t_y, t_z + CORRIDOR_HEIGHT + WALL_WIDTH, t_width, t_length, WALL_WIDTH));

	m_solids.push_back(new Solid(t_x, t_y, t_z + WALL_WIDTH, WALL_WIDTH, t_length, CORRIDOR_HEIGHT));
	m_solids.push_back(new Solid(t_x + t_width - WALL_WIDTH, t_y, t_z + WALL_WIDTH, WALL_WIDTH, t_length, CORRIDOR_HEIGHT));

}


Corridor::~Corridor()
{
}

const std::vector<Solid*> Corridor::getSolids()
{
	return m_solids;
}

Solid* Corridor::getSolid(Wall t_wall)
{
	if (t_wall >= m_solids.size()) return nullptr;
	return m_solids[t_wall];
}