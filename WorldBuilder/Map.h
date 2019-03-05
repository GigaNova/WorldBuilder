#pragma once
#include <string>
#include "Solid.h"

//Version Info
static const int EDITOR_VERSION = 400;
static const int EDITOR_BUILD = 6412;
static const int MAP_VERSION = 1;
static const int FORMAT_VERSION = 100;
static const int PREFAB = 0;

//View Settings
static const bool SNAP_TO_GRID = true;
static const bool SHOW_GRID = true;
static const bool SHOW_LOGICAL_GRID = false;
static const int GRID_SPACING = 64;
static const bool SHOW_3D_GRID = false;

//World Settings
static const int ID = 1;
static const std::string CLASS_NAME = "worldspawn";
static const std::string SKY_NAME = "sky_day01_01";
static const int MAX_PROP_SCREEN_WIDTH = -1;
static const std::string DETAIL_VBSP = "detail.vbsp";
static const std::string DETAIL_MATERIAL = "detail/detailsprites";

//Camera Settings
static const int ACTIVE_CAMERA = -1;

//Cordon Settings
static const SpacialPoint CORDON_MINS = SpacialPoint(-1024, -1024, -1024);
static const SpacialPoint CORDON_MAXS = SpacialPoint(1024, 1024, 1024);
static const bool CORDON_ACTIVE = false;

class Map
{
public:
	Map();
	~Map();

	void addSolid(int t_x, int t_y, int t_z, int t_width, int t_length, int t_height);
	const std::vector<Solid*> getSolids();
private:
	std::vector<Solid*> m_solids;
};

