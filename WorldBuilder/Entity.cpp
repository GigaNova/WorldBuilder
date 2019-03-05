#include "Entity.h"
#include "IdentityManager.h"

Entity::Entity(std::string t_classname, int t_x, int t_y, int t_z) : m_classname(t_classname), m_x(t_x), m_y(t_y), m_z(t_z)
{
	m_id = IdentityManager::getInstance().getEntityId();
}

Entity::~Entity()
{
}
