#include "OpenRoom.h"
#include "Room.h"

OpenRoom::OpenRoom(int t_width, int t_length)
{
	m_solids.push_back(new Solid(SPAWNPOINT_X, SPAWNPOINT_Y, 0, t_width, t_length, WALL_WIDTH));
	m_solids.push_back(new Solid(SPAWNPOINT_X, SPAWNPOINT_Y, 0 + ROOM_HEIGHT + WALL_WIDTH, t_width, t_length, WALL_WIDTH));

	m_solids.push_back(new Solid(SPAWNPOINT_X, SPAWNPOINT_Y, 0 + WALL_WIDTH, WALL_WIDTH, t_length, ROOM_HEIGHT));
	m_solids.push_back(new Solid(SPAWNPOINT_X + t_width - WALL_WIDTH, SPAWNPOINT_Y, 0 + WALL_WIDTH, WALL_WIDTH, t_length, ROOM_HEIGHT));

	m_solids.push_back(new Solid(SPAWNPOINT_X + WALL_WIDTH, SPAWNPOINT_Y, 0 + WALL_WIDTH, t_width - (WALL_WIDTH * 2), WALL_WIDTH, ROOM_HEIGHT));
	m_solids.push_back(new Solid(SPAWNPOINT_X + WALL_WIDTH, SPAWNPOINT_Y + t_length - WALL_WIDTH, 0 + WALL_WIDTH, t_width - (WALL_WIDTH * 2), WALL_WIDTH, ROOM_HEIGHT));

	m_solids.at(0)->setFaceTexture(TOP, FLOOR_TEXTURE);
	m_solids.at(1)->setFaceTexture(BOTTOM, CEILING_TEXTURE);
	m_solids.at(2)->setFaceTexture(BACK, WALL_TEXTURE);
	m_solids.at(3)->setFaceTexture(FRONT, WALL_TEXTURE);
	m_solids.at(4)->setFaceTexture(LEFT, WALL_TEXTURE);
	m_solids.at(5)->setFaceTexture(RIGHT, WALL_TEXTURE);
}

OpenRoom::~OpenRoom()
{
}

const std::vector<Solid*> OpenRoom::getSolids()
{
	return m_solids;
}

Solid* OpenRoom::getSolid(Wall t_wall)
{
	if (t_wall >= m_solids.size()) return nullptr;
	return m_solids[t_wall];
}

void OpenRoom::move(int t_x, int t_y, int t_z, SpacialPoint t_center)
{
	for(Solid* pSolid : m_solids)
	{
		pSolid->move(t_x, t_y, t_z, t_center);
	}
}

void OpenRoom::rotate(int t_x, int t_y, int t_z, SpacialPoint t_center)
{
	for (Solid* pSolid : m_solids)
	{
		pSolid->rotate(t_x, t_y, t_z, t_center);
	}
}
