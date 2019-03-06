#pragma once
#include "Solid.h"

class Corridor
{
public:
	static const int CORRIDOR_HEIGHT = 128;
	static const int CORRIDOR_WIDTH = 128;
	static const int WALL_WIDTH = 32;

	Corridor(int t_x, int t_y, int t_z, int t_width, int t_length);
	~Corridor();

	const std::vector<Solid*> getSolids();
	Solid* getSolid(Wall t_wall);
private:
	std::vector<Solid*> m_solids;
};

