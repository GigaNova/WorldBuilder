#include <iostream>
#include "Map.h"
#include "FileWriter.h"
#include "RandomRoomDungeon.h"
#include "ComplexDungeon.h"

static const short PROGRAM_VERSION_MAJOR = 0;
static const short PROGRAM_VERSION_MINOR = 5;

static const std::string OUTPUT_FOLDER = ".\\output\\";
static const std::string MAP_NAME = "test_map";

int main()
{
    std::cout << "Welcome to World Builder " << PROGRAM_VERSION_MAJOR << "." << PROGRAM_VERSION_MINOR << std::endl;

	std::cout << "Making world..." << std::endl;
	Map* pMap = new Map();

	std::cout << "Generating random rooms..." << std::endl;
	ComplexDungeon* pDungeon = new ComplexDungeon();
	pMap->addDungeon(pDungeon);

	std::cout << pMap->getAmountOfFaces() / AMOUNT_OF_FACES << " solids/" << pMap->getAmountOfFaces() << " faces..." << std::endl;

	std::cout << "Generating .vmf file..." << std::endl;
	FileWriter fileWriter;
	fileWriter.writeToVmf(pMap, OUTPUT_FOLDER, MAP_NAME);

	std::cout << "Done!" << std::endl;
}