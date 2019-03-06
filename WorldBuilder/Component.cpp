#include "Component.h"
#include <algorithm>

Component::Component() : m_boundingbox(nullptr)
{
}

Component::~Component()
{
}

SpacialPoint Component::getOrigin()
{
	int x = 0;
	int y = 0;
	int z = 0;

	int lowest_point = INT_MAX;
	int highest_point = INT_MIN;
	int most_right = INT_MIN;
	int most_left = INT_MAX;
	int closest_point = INT_MAX;
	int furthest_point = INT_MIN;

	for(Solid* pSolid : m_solids)
	{
		if(pSolid->getX() < most_left)
		{
			most_left = pSolid->getX();
		}

		if (pSolid->getY() < closest_point)
		{
			closest_point = pSolid->getY();
		}

		if (pSolid->getZ() < lowest_point)
		{
			lowest_point = pSolid->getZ();
		}

		if (pSolid->getX() + pSolid->getWidth() > most_right)
		{
			most_right = pSolid->getX() + pSolid->getWidth();
		}

		if (pSolid->getY() + pSolid->getLength() > furthest_point)
		{
			furthest_point = pSolid->getY() + pSolid->getLength();
		}

		if (pSolid->getZ() + pSolid->getHeight() > highest_point)
		{
			highest_point = pSolid->getZ() + pSolid->getHeight();
		}
	}

	x = most_left + (most_right - most_left) / 2;
	y = closest_point + (furthest_point - closest_point) / 2;
	z = lowest_point + (highest_point - lowest_point) / 2;

	return SpacialPoint(x, y, z);
}

ConnectionPoint* Component::getFreeConnectionPoint()
{
	std::random_shuffle(m_connectionpoints.begin(), m_connectionpoints.end());

	for(int i = 0; i < m_connectionpoints.size(); ++i)
	{
		if(!m_connectionpoints[i]->isConnected())
		{
			return m_connectionpoints[i];
		}
	}
	return nullptr;
}


void Component::linkComponent(ConnectionPoint* t_connectionpoint)
{
	ConnectionPoint* pFreePoint = getFreeConnectionPoint();

	if(pFreePoint)
	{
		pFreePoint->connect(t_connectionpoint);
		move(t_connectionpoint->getX(), t_connectionpoint->getY(), t_connectionpoint->getZ(), pFreePoint->getLocation());
	}
}