#include "Solid.h"
#include "Sides.h"
#include "IdentityManager.h"

Solid::Solid(int t_x, int t_y, int t_z, int t_width, int t_length, int t_height) : m_x(t_x), m_y(t_y), m_z(t_z), m_width(t_width), m_length(t_length), m_height(t_height)
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

void Solid::move(int t_x, int t_y, int t_z, SpacialPoint t_center)
{
	int dist_x = t_center.getX() - m_x;
	int dist_y = t_center.getY() - m_y;
	int dist_z = t_center.getZ() - m_z;

	int diff_x = t_x - m_x - dist_x;
	int diff_y = t_y - m_y - dist_y;
	int diff_z = t_z - m_z - dist_z;

	for(Face* pFace : m_faces)
	{
		pFace->move(diff_x, diff_y, diff_z);
	}
}

void Solid::rotate(int t_x, int t_y, int t_z, SpacialPoint t_center)
{
	for (Face* pFace : m_faces)
	{
		pFace->rotate(t_x, t_y, t_z, t_center);
	}
}

void Solid::setFaceTexture(Sides t_side, Texture t_texture)
{
	m_faces.at(t_side)->setTexture(t_texture);
}

void Solid::setTexture(Texture t_texture)
{
	setFaceTexture(FRONT, t_texture);
	setFaceTexture(BACK, t_texture);
	setFaceTexture(TOP, t_texture);
	setFaceTexture(BOTTOM, t_texture);
	setFaceTexture(LEFT, t_texture);
	setFaceTexture(RIGHT, t_texture);
}
