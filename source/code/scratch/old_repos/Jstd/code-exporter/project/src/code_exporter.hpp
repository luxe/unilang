#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "program_options.hpp"

class Code_Exporter{










public: static void Export_Pseudo_Library(Program_Options const& program_options, std::string export_path) ;


private: static void Start_The_Library_Conversion(Program_Options const& program_options, std::string & export_path) ;
};