#include "BoundingBox.h"
#include <complex>


BoundingBox::BoundingBox(int t_x, int t_y, int t_z, int t_width, int t_length, int t_height) : m_x(t_x), m_y(t_y), m_z(t_z), m_width(t_width), m_length(t_length), m_height(t_height)
{
}

BoundingBox::~BoundingBox()
{
}

bool BoundingBox::intersect(BoundingBox b2)
{
	if (abs(m_x - b2.getX()) < m_width + b2.getWidth())
	{
		if (std::abs(m_y - b2.getY()) < m_length + b2.getLength())
		{
			if (abs(m_z - b2.getZ()) < m_height + b2.getHeight())
			{
				return true;
			}
		}
	}

	return false;
}
