#include "optimizer.hpp"
#include "utilities.hpp"
#include "global.hpp"
#include <cstdlib>
#include <fstream>

void Optimizer::Optimize_If_Needed(Program_Options const& program_options, std::time_t const& last_run_time) {

	if (program_options.Optimize()){
		Perform_Timed_Optimization(program_options, last_run_time);
	}

	return;
}

void Optimizer::Perform_Timed_Optimization(Program_Options const& program_options, std::time_t const& last_run_time){

	return;
}
