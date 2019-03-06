#pragma once
#include "Solid.h"

class ConnectionPoint
{
public:
	static const int SOLID_SIZE = 16;
	static const Texture DEBUG_TEXTURE;

	ConnectionPoint(int t_x, int t_y, int t_z, int t_pointing);
	~ConnectionPoint();

	void connect(ConnectionPoint* t_connectionpoint);
	void move(int t_x, int t_y, int t_z, SpacialPoint t_center);

	bool isConnected() const { return m_connectionpoint != nullptr; }

	int getPointing() const { return m_pointing; }
	int getX() const { return m_x; }
	int getY() const { return m_y; }
	int getZ() const { return m_z; }

	SpacialPoint getLocation() const { return {m_x, m_y, m_z}; }

	Solid* toSolid();
private:
	ConnectionPoint* m_connectionpoint;

	int m_pointing;
	int m_x;
	int m_y;
	int m_z;
};

