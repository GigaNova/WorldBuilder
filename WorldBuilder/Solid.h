#pragma once
#include "Face.h"
#include <vector>
#include "Sides.h"

static const short AMOUNT_OF_FACES = 6;
static const Texture DEFAULT_TEXTURE = "tools/toolsnodraw";

class Solid
{
public:
	Solid(int t_x, int t_y, int t_z, int t_width, int t_length, int t_height);

	int getWidth() const { return m_width; }
	int getLength() const { return m_length; }
	int getHeight() const { return m_height; }

	int getX() const { return m_x; }
	int getY() const { return m_y; }
	int getZ() const { return m_z; }

	int getId() const { return m_id; }
	std::vector<Face*> getFaces() const { return m_faces; }

	void setFaceTexture(Sides t_side, Texture t_texture);
private:
	int m_id;
	std::vector<Face*> m_faces;

	int m_width;
	int m_length;
	int m_height;
	int m_x;
	int m_y;
	int m_z;
};

