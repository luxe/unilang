#pragma once
#include <iostream>
#include <string>
#include <chrono>
#include <cstdlib>
#include "program_options.hpp"
#include "task_executer.hpp"

class Meta_Data_Task_Executer: Task_Executer {

//non-constructible
Meta_Data_Task_Executer()=delete;

public:
	static void Excute_Needed_Tasks(Program_Options const& program_options, std::time_t const& last_run_time);

};
