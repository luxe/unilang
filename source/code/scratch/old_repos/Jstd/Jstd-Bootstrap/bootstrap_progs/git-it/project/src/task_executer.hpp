#pragma once
#include "program_options.hpp"

class Task_Executer{









//decides if the command line argumets passed in are for downloading, updating, or cleaning.
//It forwards any data on to the respective module for the task deduced
public: static void Do_Needed_Tasks(Program_Options const& program_options) ;};