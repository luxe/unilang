#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "program_options_creator.hpp"

//this is where we expect git-it to place the repo
const std::string LIBRARY_DIRECTORY = "~/.github/Jstd/pre-Jstd/project/src/library_data/";

int main(int const argc, char** const argv) {

	auto program_options = Program_Options_Creator::Create(argc, argv);

	//copy the library over
	system(("cp -r " + LIBRARY_DIRECTORY + "pre-jstd .").c_str());
	system(("cp " + LIBRARY_DIRECTORY + "utilities.cpp .").c_str());
	system(("cp " + LIBRARY_DIRECTORY + "utilities.hpp .").c_str());

	return EXIT_SUCCESS;
}
