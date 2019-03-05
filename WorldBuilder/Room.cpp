#include "Room.h"

Room::Room(int t_x, int t_y, int t_z, int t_width, int t_length)
{
	m_solids.push_back(new Solid(t_x, t_y, t_z, t_width, t_length, WALL_WIDTH));
	m_solids.push_back(new Solid(t_x, t_y, t_z + ROOM_HEIGHT + WALL_WIDTH, t_width, t_length, WALL_WIDTH));

	m_solids.push_back(new Solid(t_x, t_y, t_z + WALL_WIDTH, WALL_WIDTH, t_length, ROOM_HEIGHT));
	m_solids.push_back(new Solid(t_x + t_width - WALL_WIDTH, t_y, t_z + WALL_WIDTH, WALL_WIDTH, t_length, ROOM_HEIGHT));

	m_solids.push_back(new Solid(t_x + WALL_WIDTH, t_y, t_z + WALL_WIDTH, t_width - (WALL_WIDTH * 2), WALL_WIDTH, ROOM_HEIGHT));
	m_solids.push_back(new Solid(t_x + WALL_WIDTH, t_y + t_length - WALL_WIDTH, t_z + WALL_WIDTH, t_width - (WALL_WIDTH * 2), WALL_WIDTH, ROOM_HEIGHT));
}

Room::~Room()
{
}

const std::vector<Solid*> Room::getSolids()
{
	return m_solids;
}