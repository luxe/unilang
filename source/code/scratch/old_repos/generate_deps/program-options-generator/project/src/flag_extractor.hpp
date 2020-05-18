#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "program_options.hpp"
#include "flag_line.hpp"

class Flag_Extractor{

	public: static std::vector<Flag_Line> Extract_Flags(Program_Options const& program_options);
};