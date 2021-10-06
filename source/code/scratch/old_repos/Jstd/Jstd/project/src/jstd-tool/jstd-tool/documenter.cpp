#include "documenter.hpp"
void Documenter::Create_Documentation_If_Needed(Program_Options const& program_options, std::time_t const& last_run_time) {

	if (program_options.Documentation()){
		Perform_Timed_Documentation(program_options, last_run_time);
	}

	return;
}
void Documenter::Perform_Timed_Documentation(Program_Options const& program_options, std::time_t const& last_run_time) {

	return;
}
