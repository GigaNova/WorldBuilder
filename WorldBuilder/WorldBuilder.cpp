#include <iostream>
#include "Map.h"
#include "FileWriter.h"

static const short PROGRAM_VERSION_MAJOR = 0;
static const short PROGRAM_VERSION_MINOR = 1;

int main()
{
    std::cout << "Welcome to World Builder " << PROGRAM_VERSION_MAJOR << "." << PROGRAM_VERSION_MINOR << std::endl;

	std::cout << "Making world..." << std::endl;
	Map* pMap = new Map();

	std::cout << "Adding test solid..." << std::endl;
	pMap->addSolid(0, 0, 0, 64, 32, 16);

	std::cout << "Generating .vmf file..." << std::endl;
	FileWriter fileWriter;
	fileWriter.writeToVmf(pMap, ".\\ouput\\", "test");

	std::cout << "Done!" << std::endl;
	getchar();
}