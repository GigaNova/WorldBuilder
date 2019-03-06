#pragma once
#include "Sides.h"
#include <vector>
#include "Solid.h"
#include "Component.h"

class OpenRoom : public Component
{
public:
	static const int ROOM_HEIGHT = 128;
	static const int WALL_WIDTH = 32;

	OpenRoom(int t_width, int t_length);
	~OpenRoom();

	const std::vector<Solid*> getSolids();
	Solid* getSolid(Wall t_wall);

	void move(int t_x, int t_y, int t_z, SpacialPoint t_center) override;
	void rotate(int t_x, int t_y, int t_z, SpacialPoint t_center) override;
};

