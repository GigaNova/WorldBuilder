#include "Solid.h"
#include "Sides.h"
#include "IdentityManager.h"

Solid::Solid(int t_x, int t_y, int t_z, int t_width, int t_length, int t_height)
{
	for(auto face = 0; face < AMOUNT_OF_FACES; ++face)
	{
		Face* p_face = nullptr;

		m_id = IdentityManager::getInstance().getSolidId();

		switch (face)
		{
		case TOP:
			p_face = new Face(
				DEFAULT_TEXTURE,
				SpacialPoint(t_x, t_y + t_length, t_z + t_height),
				SpacialPoint(t_x + t_width, t_y + t_length, t_z + t_height),
				SpacialPoint(t_x + t_width, t_y, t_z + t_height)
			);
			p_face->setUAxis(1, 0, 0, 256);
			p_face->setVAxis(0, -1, 0, 0);
			break;
		case BOTTOM:
			p_face = new Face(
				DEFAULT_TEXTURE,
				SpacialPoint(t_x, t_y, t_z),
				SpacialPoint(t_x + t_width, t_y, t_z),
				SpacialPoint(t_x + t_width, t_y + t_length, t_z)
			);
			p_face->setUAxis(1, 0, 0, 256);
			p_face->setVAxis(0, -1, 0, 0);
			break;
		case FRONT:
			p_face = new Face(
				DEFAULT_TEXTURE,
				SpacialPoint(t_x, t_y + t_length, t_z + t_height),
				SpacialPoint(t_x, t_y, t_z + t_height),
				SpacialPoint(t_x, t_y, t_z)
			);
			p_face->setUAxis(0, 1, 0, 256);
			p_face->setVAxis(0, 0, -1, 0);
			break;
		case BACK:
			p_face = new Face(
				DEFAULT_TEXTURE,
				SpacialPoint(t_x + t_width, t_y + t_length, t_z),
				SpacialPoint(t_x + t_width, t_y, t_z),
				SpacialPoint(t_x + t_width, t_y, t_z + t_height)
			);
			p_face->setUAxis(0, 1, 0, 256);
			p_face->setVAxis(0, 0, -1, 0);
			break;
		case LEFT:
			p_face = new Face(
				DEFAULT_TEXTURE,
				SpacialPoint(t_x + t_width, t_y + t_length, t_z + t_height),
				SpacialPoint(t_x, t_y + t_length, t_z + t_height),
				SpacialPoint(t_x, t_y + t_length, t_z)
			);
			p_face->setUAxis(1, 0, 0, 256);
			p_face->setVAxis(0, 0, -1, 0);
			break;
		case RIGHT:
			p_face = new Face(
				DEFAULT_TEXTURE,
				SpacialPoint(t_x + t_width, t_y, t_z),
				SpacialPoint(t_x, t_y, t_z),
				SpacialPoint(t_x, t_y, t_z + t_height)
			);
			p_face->setUAxis(1, 0, 0, 256);
			p_face->setVAxis(0, 0, -1, 0);
			break;
		default:
			throw std::exception("Unknown face position " + face);
		}

		m_faces.push_back(p_face);
	}
}

void Solid::setFaceTexture(Sides t_side, Texture t_texture)
{
	m_faces.at(t_side)->setTexture(t_texture);
}
