#pragma once
#include "utilities.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include "program_options.hpp"
#include "composed_program_options.hpp"
#include "global.hpp"

class Task_Executer{












public: static void Execute_Needed_Tasks(Program_Options const& input) ;

private: static void Possibly_Print_STD_Headers(std::ofstream & outfile,Program_Options const& program_options);
private: static void Possibly_Print_Boost_Headers(std::ofstream & outfile,Program_Options const& program_options);
private: static void Possibly_Print_QT_Headers(std::ofstream & outfile,Program_Options const& program_options);
private: static void Possibly_Print_NCurses_Headers(std::ofstream & outfile,Program_Options const& program_options);
private: static void Print_Headers(std::ofstream & outfile,Include_Category const& include_category,Program_Options const& program_options);
private: static void Print_All_The_Added_Headers(std::ofstream & outfile,Program_Options const& program_options);

private: static bool System_Library_Exists(std::string file_name, const std::vector<std::string> system_paths);
};