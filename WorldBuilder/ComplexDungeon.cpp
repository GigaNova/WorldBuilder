#include "ComplexDungeon.h"
#include <random>
#include "Walkway.h"
#include "Map.h"
#include "OpenRoom.h"

ComplexDungeon::ComplexDungeon()
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> position(-MAX_DISTANCE, MAX_DISTANCE);

	int x = position(mt) * GRID_SIZE;
	int y = position(mt) * GRID_SIZE;

	ConnectionPoint* masterPoint = new ConnectionPoint(x, y, 0, 0);
	Walkway* pWalkway = new Walkway();
	pWalkway->rotate(180, 0, 0, pWalkway->getOrigin());
	pWalkway->linkComponent(masterPoint);
	m_components.push_back(pWalkway);

	return;
	for(auto index = 0; index < m_components.size(); ++index)
	{
		Component* pComponent = m_components[index];
		for(ConnectionPoint* pConnectionPoint : pComponent->getConnectionPoints())
		{
			if (pConnectionPoint->isConnected()) continue;

			Walkway* pNewWalkWay = new Walkway();
			pNewWalkWay->linkComponent(pConnectionPoint);
			m_components.push_back(pNewWalkWay);
		}

		if (m_components.size() == MAX_COMPONENTS) break;
	}
}


ComplexDungeon::~ComplexDungeon()
{
}

std::vector<Solid*> ComplexDungeon::getSolids()
{
	std::vector<Solid*> solids;

	for (Component* pComponent : m_components)
	{
		for (Solid* pSolid : pComponent->getSolids())
		{
			solids.push_back(pSolid);
		}

#ifdef DEBUG_CONNECTION_POINTS
		for (ConnectionPoint* pConnectionPoint : pComponent->getConnectionPoints())
		{
			solids.push_back(pConnectionPoint->toSolid());
		}
#endif
	}

	return solids;
}

void ComplexDungeon::addComponent(Component* t_component)
{
	m_components.push_back(t_component);
}
