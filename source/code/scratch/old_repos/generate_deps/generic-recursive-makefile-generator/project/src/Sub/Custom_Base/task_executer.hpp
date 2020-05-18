#pragma once
#include "utilities.hpp"
#include "systems.hpp"
#include "program_options.hpp"
#include "program_input.hpp"
#include "composed_program_options.hpp"

class Task_Executer{







public: static void Execute_Needed_Tasks(Program_Input const& input) ;

public: static void Copy_Static_Dependency_Files_Over();



public: static void Create_Link_Rule(Composed_Program_Options const& program_options) ;
};