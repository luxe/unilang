#pragma once
#include "program_options.hpp"
#include <boost/filesystem.hpp>
#include <vector>
#include <string>

//3rd Party
#include <gmpxx.h>

class Stats_Dumper{

public:
	static void Dump_Stats_If_Needed(Program_Options const& program_options, std::time_t const& last_run_time);
private:
	static void Perform_Timed_Stats_Dumping(Program_Options const& program_options, std::time_t const& last_run_time);
};
