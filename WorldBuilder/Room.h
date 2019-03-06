#pragma once
#include <vector>
#include "Solid.h"

static const Texture CEILING_TEXTURE = "concrete/concreteceiling001a";
static const Texture FLOOR_TEXTURE = "concrete/concretefloor009a";
static const Texture WALL_TEXTURE = "brick/brickwall003a";

class Room
{
public:
	static const int ROOM_HEIGHT = 128;
	static const int WALL_WIDTH = 32;

	Room(int t_x, int t_y, int t_z, int t_width, int t_length);
	~Room();

	const std::vector<Solid*> getSolids();
	Solid* getSolid(Wall t_wall);
private:
	std::vector<Solid*> m_solids;
};

