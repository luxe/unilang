#pragma once
#include "program_options.hpp"
#include "warn_machine.hpp"
#include "scan_stats.hpp"
#include <vector>
#include <string>
#include <utility>

//3rd Party
#include <gmpxx.h>

class Scanner{

	//non-constructible
	Scanner()=delete;

public:

	//called by pseudo library task executer
	static void Scan_If_Needed(Program_Options const& program_options, std::time_t const& last_run_time);

private:

	//functional decomposition of public Scan function
	static void Perform_Timed_Scan(Program_Options const& program_options, std::time_t const& last_run_time);
	[[noreturn]] static void Stop_Scan(Program_Options const& program_options, Warn_Machine & warn_machine);

	//data
	static Scan_Stats stats;



};
