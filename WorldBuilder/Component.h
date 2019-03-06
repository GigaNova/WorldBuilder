#pragma once
#include "BoundingBox.h"
#include "ConnectionPoint.h"
#include <vector>
#include "Solid.h"
#include "Matter.h"

class Component : public Matter
{
public:
	static const int SPAWNPOINT_X = 36000;
	static const int SPAWNPOINT_Y = 36000;

	Component();
	~Component();

	SpacialPoint getOrigin();
	ConnectionPoint* getFreeConnectionPoint();
	void linkComponent(ConnectionPoint* t_connectionpoint);

	void move(int t_x, int t_y, int t_z, SpacialPoint t_center) override = 0;
	void rotate(int t_x, int t_y, int t_z, SpacialPoint t_center) override = 0;

	BoundingBox* getBoundingBox() const { return m_boundingbox; }
	std::vector<ConnectionPoint*> getConnectionPoints() const { return m_connectionpoints; }
	std::vector<Solid*> getSolids() const { return m_solids; };
protected:
	BoundingBox* m_boundingbox;
	std::vector<ConnectionPoint*> m_connectionpoints;
	std::vector<Solid*> m_solids;
};

