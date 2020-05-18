#pragma once
#include "program_options.hpp"

class Documenter{

public:
	static void Create_Documentation_If_Needed(Program_Options const& program_options, std::time_t const& last_run_time);

private:
	static void Perform_Timed_Documentation(Program_Options const& program_options, std::time_t const& last_run_time);

};
