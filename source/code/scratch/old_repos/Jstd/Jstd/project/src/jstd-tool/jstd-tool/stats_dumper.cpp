#include "stats_dumper.hpp"
#include "utilities.hpp"
#include "global.hpp"
#include <cstdlib>
#include <fstream>

void Stats_Dumper::Dump_Stats_If_Needed(Program_Options const& program_options, std::time_t const& last_run_time) {

	if (program_options.Stats()){
		Perform_Timed_Stats_Dumping(program_options, last_run_time);
	}

	return;
}

void Stats_Dumper::Perform_Timed_Stats_Dumping(Program_Options const& program_options, std::time_t const& last_run_time){

	return;
}
