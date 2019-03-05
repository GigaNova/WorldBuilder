#pragma once
#include <vector>
#include "Solid.h"

static const int ROOM_HEIGHT = 128;
static const int WALL_WIDTH = 64;

class Room
{
public:
	Room(int t_x, int t_y, int t_z, int t_width, int t_length);
	~Room();

	const std::vector<Solid*> getSolids();
private:
	std::vector<Solid*> m_solids;
};

