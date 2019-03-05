#include "FileWriter.h"
#include <fstream>
#include <iostream>

FileWriter::FileWriter()
{
}

void FileWriter::writeToVmf(Map* t_map, std::string t_location, std::string t_filename)
{
	std::cout << "Writing to " + t_location + t_filename + FILE_EXTENSION + "..." << std::endl;

	std::ofstream outfile;
	outfile.open(t_location + t_filename + FILE_EXTENSION, std::ios::out | std::ios::trunc);

	//Version Info
	outfile << "versioninfo" << std::endl;
	outfile << BRACKET_OPEN << std::endl;

	outfile << TAB << writePair("editorversion", EDITOR_VERSION) << std::endl;
	outfile << TAB << writePair("editorbuild", EDITOR_BUILD) << std::endl;
	outfile << TAB << writePair("mapversion", MAP_VERSION) << std::endl;
	outfile << TAB << writePair("formatversion", FORMAT_VERSION) << std::endl;
	outfile << TAB << writePair("prefab", PREFAB) << std::endl;

	outfile << BRACKET_CLOSE << std::endl;

	//Visgroup Info
	outfile << "visgroups" << std::endl;
	outfile << BRACKET_OPEN << std::endl;
	outfile << BRACKET_CLOSE << std::endl;

	//View Settings
	outfile << "viewsettings" << std::endl;
	outfile << BRACKET_OPEN << std::endl;

	outfile << TAB << writePair("bSnapToGrid", SNAP_TO_GRID) << std::endl;
	outfile << TAB << writePair("bShowGrid", SHOW_GRID) << std::endl;
	outfile << TAB << writePair("bShowLogicalGrid", SHOW_LOGICAL_GRID) << std::endl;
	outfile << TAB << writePair("nGridSpacing", GRID_SPACING) << std::endl;
	outfile << TAB << writePair("bShow3DGrid", SHOW_3D_GRID) << std::endl;

	outfile << BRACKET_CLOSE << std::endl;

	//World
	outfile << "world" << std::endl;
	outfile << BRACKET_OPEN << std::endl;

	outfile << TAB << writePair("id", SNAP_TO_GRID) << std::endl;
	outfile << TAB << writePair("mapversion", MAP_VERSION) << std::endl;
	outfile << TAB << writePair("classname", CLASS_NAME) << std::endl;
	outfile << TAB << writePair("skyname", SKY_NAME) << std::endl;
	outfile << TAB << writePair("maxpropscreenwidth", MAX_PROP_SCREEN_WIDTH) << std::endl;
	outfile << TAB << writePair("detailvbsp", DETAIL_VBSP) << std::endl;
	outfile << TAB << writePair("detailmaterial", DETAIL_MATERIAL) << std::endl;

	for(Solid* pSolid : t_map->getSolids())
	{
		outfile << TAB << "solid" << std::endl;
		outfile << TAB << BRACKET_OPEN << std::endl;

		outfile << tabs(2) << writePair("id", pSolid->getId()) << std::endl;

		for(Face* pFace : pSolid->getFaces())
		{
			outfile << tabs(2) << "side" << std::endl;
			outfile << tabs(2) << BRACKET_OPEN << std::endl;

			outfile << tabs(3) << writePair("id", pFace->getId()) << std::endl;
			outfile << tabs(3) << writePair("plane", pFace) << std::endl;
			outfile << tabs(3) << writePair("material", pFace->getTexture()) << std::endl;
			outfile << tabs(3) << writePair("uaxis", pFace->getUAxis(), 0.25) << std::endl;
			outfile << tabs(3) << writePair("vaxis", pFace->getVAxis(), 0.25) << std::endl;
			outfile << tabs(3) << writePair("rotation", DEFAULT_ROTATION) << std::endl;
			outfile << tabs(3) << writePair("lightmapscale", DEFAULT_LIGHTMAPSCALE) << std::endl;
			outfile << tabs(3) << writePair("smoothing_groups", DEFAULT_SMOOTHINGROUPS) << std::endl;

			outfile << tabs(2) << BRACKET_CLOSE << std::endl;
		}

		outfile << TAB << BRACKET_CLOSE << std::endl;
	}

	outfile << BRACKET_CLOSE << std::endl;

	//Camera Settings
	outfile << "cameras" << std::endl;
	outfile << BRACKET_OPEN << std::endl;
	outfile << TAB << writePair("activecamera", ACTIVE_CAMERA) << std::endl;
	outfile << BRACKET_CLOSE << std::endl;

	//Cordon Settings
	outfile << "cameras" << std::endl;
	outfile << BRACKET_OPEN << std::endl;
	outfile << TAB << writePair("mins", CORDON_MINS) << std::endl;
	outfile << TAB << writePair("maxs", CORDON_MAXS) << std::endl;
	outfile << TAB << writePair("active", CORDON_ACTIVE) << std::endl;
	outfile << BRACKET_CLOSE << std::endl;
}

std::string FileWriter::writePair(std::string t_key, std::string t_value)
{
	return "\"" + t_key + "\"" + SPACE + "\"" + t_value + "\"";
}

std::string FileWriter::writePair(std::string t_key, int t_value)
{
	return "\"" + t_key + "\"" + SPACE + "\"" + std::to_string(t_value) + "\"";
}

std::string FileWriter::writePair(std::string t_key, SpacialPoint t_value)
{
	return "\"" + t_key + "\"" + SPACE + "\"" + t_value.toString() + "\"";
}

std::string FileWriter::writePair(std::string t_key, Face* t_value)
{
	return "\"" + t_key + "\"" + SPACE + "\"" + 
		t_value->getX().toString() + SPACE +
		t_value->getY().toString() + SPACE +
		t_value->getZ().toString() + SPACE
	+ "\"";
}

std::string FileWriter::writePair(std::string t_key, int* t_value, float t_scale)
{
	return "\"" + t_key + "\"" + SPACE + "\"[" + 
		std::to_string(t_value[0]) + SPACE +
		std::to_string(t_value[1]) + SPACE +
		std::to_string(t_value[2]) + SPACE +
		std::to_string(t_value[3]) +
	+ "]" + std::to_string(t_scale) + "\"";
}

std::string FileWriter::tabs(int t_amount = 1)
{
	std::string tabs = "";
	for(auto i = 0; i < t_amount; ++i)
	{
		tabs += TAB;
	}
	return tabs;
}
