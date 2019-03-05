#pragma once
#include <string>
#include "Map.h"

static const std::string FILE_EXTENSION = ".vmf";

static const char TAB = '	';
static const char SPACE = ' ';
static const char BRACKET_OPEN = '{';
static const char BRACKET_CLOSE = '}';

class FileWriter
{
public:
	FileWriter();

	void writeToVmf(Map* t_map, std::string t_location, std::string t_filename);
private:
	std::string writePair(std::string t_key, std::string t_value);
	std::string writePair(std::string t_key, int t_value);
	std::string writePair(std::string t_key, SpacialPoint t_value);
	std::string writePair(std::string t_key, Face* t_value);
	std::string writePair(std::string t_key, int* t_value, float t_scale);

	std::string tabs(int t_amount);
};

