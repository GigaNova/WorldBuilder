#include "SpawnPoint.h"

SpawnPoint::SpawnPoint(int t_x, int t_y, int t_z): Entity("info_player_start", t_x, t_y, t_z)
{
	m_attributes.insert(Attribute("angles", "0 0 0"));
}


SpawnPoint::~SpawnPoint()
{
}
