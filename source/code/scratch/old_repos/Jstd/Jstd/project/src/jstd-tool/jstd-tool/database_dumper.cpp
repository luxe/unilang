#include "database_dumper.hpp"
#include "utilities.hpp"
#include "global.hpp"
#include <cstdlib>
#include <fstream>

void Database_Dumper::Dump_Database_If_Needed(Program_Options const& program_options, std::time_t const& last_run_time) {

	if (program_options.Database()){
		Perform_Timed_Database_Dumping(program_options, last_run_time);
	}

	return;
}

void Database_Dumper::Perform_Timed_Database_Dumping(Program_Options const& program_options, std::time_t const& last_run_time){

	return;
}
