#include "Room.h"

Room::Room(int t_x, int t_y, int t_z, int t_width, int t_length)
{
	m_solids.push_back(new Solid(t_x, t_y, t_z, t_width, t_length, WALL_WIDTH));
	m_solids.push_back(new Solid(t_x, t_y, t_z + ROOM_HEIGHT + WALL_WIDTH, t_width, t_length, WALL_WIDTH));

	m_solids.push_back(new Solid(t_x, t_y, t_z + WALL_WIDTH, WALL_WIDTH, t_length, ROOM_HEIGHT));
	m_solids.push_back(new Solid(t_x + t_width - WALL_WIDTH, t_y, t_z + WALL_WIDTH, WALL_WIDTH, t_length, ROOM_HEIGHT));

	m_solids.push_back(new Solid(t_x + WALL_WIDTH, t_y, t_z + WALL_WIDTH, t_width - (WALL_WIDTH * 2), WALL_WIDTH, ROOM_HEIGHT));
	m_solids.push_back(new Solid(t_x + WALL_WIDTH, t_y + t_length - WALL_WIDTH, t_z + WALL_WIDTH, t_width - (WALL_WIDTH * 2), WALL_WIDTH, ROOM_HEIGHT));

	m_solids.at(0)->setFaceTexture(TOP, FLOOR_TEXTURE);
	m_solids.at(1)->setFaceTexture(BOTTOM, CEILING_TEXTURE);
	m_solids.at(2)->setFaceTexture(BACK, WALL_TEXTURE);
	m_solids.at(3)->setFaceTexture(FRONT, WALL_TEXTURE);
	m_solids.at(4)->setFaceTexture(LEFT, WALL_TEXTURE);
	m_solids.at(5)->setFaceTexture(RIGHT, WALL_TEXTURE);
}

Room::~Room()
{
}

const std::vector<Solid*> Room::getSolids()
{
	return m_solids;
}

Solid* Room::getSolid(Wall t_wall)
{
	if (t_wall >= m_solids.size()) return nullptr;
	return m_solids[t_wall];
}
