#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "utilities.hpp"
#include "program_options.hpp"

class Task_Executer{




















//A NOTE ON THE COMPILER/OPTIMIZER BEING USED:
//if no flags are passed we compile
//otherwise we do the optimizer which indirectly calls the compiler
//(the optimizer takes a lot longer and relies on a build system)

public:
static void Execute_Tasks_On_File(Program_Options const& program_options, std::string const& hcp_file);

private:

//handle class files
static void Perform_Task_On_Class_File(Program_Options const& program_options, std::string const& hcp_file,std::wifstream & infile, std::wstring const& file_type);

//handle global files
static void Perform_Task_On_Global_File(Program_Options const& program_options, std::string const& hcp_file,std::wifstream & infile, std::wstring const& file_type);
};