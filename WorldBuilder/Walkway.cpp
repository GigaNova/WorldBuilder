#include "Walkway.h"
#include <random>
#include <iostream>
#include "NumberHelper.h"

Walkway::Walkway()
{
	m_solids.push_back(new Solid(
		SPAWNPOINT_X,
		SPAWNPOINT_Y,
		0,
		WALKWAY_WIDTH,
		128,
		WALKWAY_WIDTH / 2
	));

	std::vector<int> randomNumbers = NumberHelper::getRandomNumbers(2, 1, 4);
	for(auto i = 0; i < 2; ++i)
	{
		addConnectionPoint(randomNumbers.at(i));
	}
}


Walkway::~Walkway()
{
}

void Walkway::move(int t_x, int t_y, int t_z, SpacialPoint t_center)
{
	m_solids[0]->move(t_x, t_y, t_z, t_center);

	for(ConnectionPoint* pConnectionPoint : m_connectionpoints)
	{
		pConnectionPoint->move(t_x, t_y, t_z, t_center);
	}
}

void Walkway::rotate(int t_x, int t_y, int t_z, SpacialPoint t_center)
{
	m_solids[0]->rotate(t_x, t_y, t_z, t_center);
}

void Walkway::addConnectionPoint(int t_dir)
{
	int rot = 0;
	int c_x = 0;
	int c_y = 0;
	int c_z = 0;

	switch (t_dir)
	{
	case 1:
		rot = 0;
		c_x = SPAWNPOINT_X + (WALKWAY_WIDTH / 2);
		c_y = SPAWNPOINT_Y;
		c_z = 0;
		break;
	case 2:
		rot = 90;
		c_x = SPAWNPOINT_X + WALKWAY_WIDTH;
		c_y = SPAWNPOINT_Y + (WALKWAY_WIDTH / 2);
		c_z = 0;
		break;
	case 3:
		rot = 180;
		c_x = SPAWNPOINT_X + (WALKWAY_WIDTH / 2);
		c_y = SPAWNPOINT_Y + WALKWAY_WIDTH;
		c_z = 0;
		break;
	case 4:
		rot = 270;
		c_x = SPAWNPOINT_X;
		c_y = SPAWNPOINT_Y + (WALKWAY_WIDTH / 2);
		c_z = 0;
		break;
	}

	m_connectionpoints.push_back(new ConnectionPoint(
		c_x,
		c_y,
		c_z,
		rot
	));
}
