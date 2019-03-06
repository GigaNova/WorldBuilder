#pragma once
#include "Component.h"

class Walkway : public Component
{
public:
	static const int WALKWAY_WIDTH = 128;

	Walkway();
	~Walkway();

	void move(int t_x, int t_y, int t_z, SpacialPoint t_center) override;
	void rotate(int t_x, int t_y, int t_z, SpacialPoint t_center) override;
private:
	void addConnectionPoint(int t_dir);
};
