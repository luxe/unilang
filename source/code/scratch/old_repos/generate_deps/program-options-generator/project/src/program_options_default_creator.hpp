#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "program_options.hpp"

class Program_Options_Default_Creator {

	public: static void Create_HPP(std::ofstream & outfile, Program_Options const& program_options);
	public: static void Create_CPP(std::ofstream & outfile, Program_Options const& program_options);

};
