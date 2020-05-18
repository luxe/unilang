//generates a program_options object, and other objects that aid it

//STD headers
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <locale>

//my headers
#include "global.hpp"
#include "utilities.hpp"
#include "program_options.hpp"
#include "flag_line.hpp"
#include "flag_extractor.hpp"
#include "flag_checker.hpp"

#include "file_generator.hpp"

int main(int const argc, char** const argv) {

	//unicode please
	std::locale::global(std::locale(""));

	//read in program options
	Program_Options program_options(argc, argv);

	//check the command lines passed in
	Flag_Checker::Run_Check(program_options);

	//generate all of the files based on the command line arguments
	File_Generator::Generate_Files(program_options);

	return EXIT_SUCCESS;
}