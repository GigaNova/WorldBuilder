#pragma once
#include "Face.h"
#include <vector>

static const short AMOUNT_OF_FACES = 6;
static const Texture DEFAULT_TEXTURE = "BRICK/BRICKWALL003A";

class Solid
{
public:
	Solid(int t_x, int t_y, int t_z, int t_width, int t_length, int t_height);

	int getId() const { return m_id; }
	std::vector<Face*> getFaces() const { return m_faces; }
private:
	int m_id;
	std::vector<Face*> m_faces;
};

