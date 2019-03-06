#include "ConnectionPoint.h"

const Texture ConnectionPoint::DEBUG_TEXTURE = "tools/toolsorigin";

ConnectionPoint::ConnectionPoint(int t_x, int t_y, int t_z, int t_pointing) : m_x(t_x), m_y(t_y), m_z(t_z), m_pointing(t_pointing)
{
}

ConnectionPoint::~ConnectionPoint()
{
}

void ConnectionPoint::connect(ConnectionPoint* t_connectionpoint)
{
	m_connectionpoint = t_connectionpoint;
}

void ConnectionPoint::move(int t_x, int t_y, int t_z, SpacialPoint t_center)
{
	int dist_x = t_center.getX() - m_x;
	int dist_y = t_center.getY() - m_y;
	int dist_z = t_center.getZ() - m_z;

	int diff_x = t_x - m_x - dist_x;
	int diff_y = t_y - m_y - dist_y;
	int diff_z = t_z - m_z - dist_z;

	m_x += diff_x;
	m_y += diff_y;
	m_z += diff_z;
}

Solid* ConnectionPoint::toSolid()
{
	Solid* pSolid = new Solid(
		m_x - SOLID_SIZE / 2,
		m_y - SOLID_SIZE / 2,
		m_z - SOLID_SIZE / 2,
		SOLID_SIZE,
		SOLID_SIZE,
		SOLID_SIZE
	);

	pSolid->setTexture(DEBUG_TEXTURE);

	return pSolid;
}
