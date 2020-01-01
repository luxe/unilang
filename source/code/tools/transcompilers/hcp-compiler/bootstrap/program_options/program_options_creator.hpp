#pragma once
#include "code/tools/transcompilers/hcp-compiler/bootstrap/program_options/program_options.hpp"
#include "code/tools/transcompilers/hcp-compiler/bootstrap/program_options/program_options_checker.hpp"

class Program_Options_Creator{

	public: static Program_Options Create(int const argc, char** const argv);
};

