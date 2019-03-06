#pragma once

class SpacialPoint;

class Matter
{
public:
	Matter();
	~Matter();

	virtual void move(int t_x, int t_y, int t_z, SpacialPoint t_center) = 0;
	virtual void rotate(int t_x, int t_y, int t_z, SpacialPoint t_center) = 0;
};

