#pragma once
#include <string>
#include "SpacialPoint.h"
#include "Matter.h"

typedef std::string Texture;

static const short DEFAULT_ROTATION = 0;
static const short DEFAULT_LIGHTMAPSCALE = 16;
static const short DEFAULT_SMOOTHINGROUPS = 0;

class Face
{
public:
	Face(Texture t_texture, SpacialPoint t_x, SpacialPoint t_y, SpacialPoint t_z);

	int getId() const { return m_id; }

	SpacialPoint getX() const { return m_x; }
	SpacialPoint getY() const { return m_y; }
	SpacialPoint getZ() const { return m_z; }

	void setTexture(Texture t_texture);
	Texture getTexture() const { return m_texture; }

	void setUAxis(int t_x, int t_y, int t_z, int t_v);
	void setVAxis(int t_x, int t_y, int t_z, int t_v);
	int* getUAxis() { return m_uaxis; }
	int* getVAxis() { return m_vaxis; }

	short getRotation() const{ return m_rotation; }
	short getLightMapScale() const { return m_lightmapscale; }
	short getSmoothingGroups() const { return m_smoothinggroups; }

	void rotate(int t_x, int t_y, int t_z, SpacialPoint t_center);
	void move(int t_x, int t_y, int t_z);
private:
	int m_id;

	Texture m_texture;

	SpacialPoint m_x;
	SpacialPoint m_y;
	SpacialPoint m_z;

	int m_uaxis[4];
	int m_vaxis[4];

	short m_rotation;
	short m_lightmapscale;
	short m_smoothinggroups;
};

