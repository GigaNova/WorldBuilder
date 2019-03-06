#include "RandomRoomDungeon.h"
#include "Rectangle.h"
#include <random>
#include "SpawnPoint.h"
#include "Map.h"

RandomRoomDungeon::RandomRoomDungeon()
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> position(-MAX_DISTANCE, MAX_DISTANCE);
	std::uniform_real_distribution<double> size(4, MAX_ROOM_SIZE);

	std::vector<Rectangle*> rectangles;
	for(auto i = 0; i < MAX_TRIES; ++i)
	{
		int x = position(mt);
		int y = position(mt);
		int width = size(mt);
		int height = size(mt);

		Rectangle* pRectangle = new Rectangle(x, y, width, height);

		bool intersects = false;
		for(Rectangle* pCompareRect : rectangles)
		{
			if(pCompareRect->intersects(pRectangle))
			{
				intersects = true;
				break;
			}
		}

		if(!intersects)
		{
			rectangles.push_back(pRectangle);
		}

		if (rectangles.size() == MAX_ROOMS) break;
	}

	for(Rectangle* pRectangle : rectangles)
	{
		m_rooms.push_back(new Room(
			pRectangle->getX() * GRID_SIZE, 
			pRectangle->getY() * GRID_SIZE, 
			0, 
			pRectangle->getWidth() * GRID_SIZE, 
			pRectangle->getHeight() * GRID_SIZE
		));
	}

	std::uniform_real_distribution<double> element(0, m_rooms.size());
	Room* pRandomRoom = m_rooms.at(element(mt));
	Solid* pFloor = pRandomRoom->getSolid(FLOOR);

	SpawnPoint* pSpawnPoint = new SpawnPoint(
		pFloor->getX() + (pFloor->getWidth() / 2.0),
		pFloor->getY() + (pFloor->getLength() / 2.0),
		pFloor->getZ() + pFloor->getHeight()
	);

	m_entities.push_back(pSpawnPoint);
}


RandomRoomDungeon::~RandomRoomDungeon()
{
}

std::vector<Solid*> RandomRoomDungeon::getSolids()
{
	std::vector<Solid*> solids;

	for (Room* pRoom : m_rooms)
	{
		for (Solid* pSolid : pRoom->getSolids())
		{
			solids.push_back(pSolid);
		}
	}

	return solids;
}
