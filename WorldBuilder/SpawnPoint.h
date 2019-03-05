#pragma once
#include "Entity.h"

class SpawnPoint : public Entity
{
public:
	SpawnPoint(int t_x, int t_y, int t_z);
	~SpawnPoint();
};

