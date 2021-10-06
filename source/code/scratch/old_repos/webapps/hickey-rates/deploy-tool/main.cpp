#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include "utilities.hpp"
#include "program_options_creator.hpp"


namespace{}



int main(int const argc, char** const argv) {

	//get program options from command line
	auto program_options = Program_Options_Creator::Create(argc, argv);

	return EXIT_SUCCESS;
}
namespace{}


