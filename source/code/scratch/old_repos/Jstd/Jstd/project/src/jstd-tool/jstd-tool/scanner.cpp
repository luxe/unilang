#include "scanner.hpp"
#include "scan_stats.hpp"
#include "utilities.hpp"
#include "global.hpp"
#include "pseudo_library_scanner.hpp"
#include "pseudo_library_resource_scanner.hpp"

Scan_Stats Scanner::stats;

void Scanner::Scan_If_Needed(Program_Options const& program_options, std::time_t const& last_run_time){

	//perform a scan on the pseudo library (assuming you want to)
	//and output information about its success or failures
	if (program_options.Scan()){
		Perform_Timed_Scan(program_options, last_run_time);
   }

	return;
  }
void Scanner::Perform_Timed_Scan(Program_Options const& program_options, std::time_t const& last_run_time){

	//start recording the time it takes to perform the scan
	stats.Start_Timer();

	std::cout <<  colorize_forground("Scan Process",220) << std::endl;

	//an object that will count the errors,
	//and help quit the scan early if there are too many of them.
	Warn_Machine warn_machine(program_options.Warn_Amount());

	//there are two main things to scan.  the pseudo library,  and library resources
	if (!Pseudo_Library_Scanner::Scan(program_options, warn_machine, last_run_time))          {Stop_Scan(program_options, warn_machine);}
	if (!Pseudo_Library_Resource_Scanner::Scan(program_options, warn_machine, last_run_time)) {Stop_Scan(program_options, warn_machine);}

	std::cout << std::endl;

	//scan is done. stop the timer
	stats.End_Timer();

	//possibly fix warnings [the warnings may already get fixed in the middle of the scan when the program halts.]
	if (program_options.Fix_Warnings()){
		warn_machine.Fix_Warnings(program_options.Prompt_Automatic_Warning_Fixes());
	}

	return;
 }
void Scanner::Stop_Scan(Program_Options const& program_options, Warn_Machine & warn_machine){

	//halt and maybe fix errors
	Red_Message("Scan Halted.\n");
	if (program_options.Fix_Warnings()){
		warn_machine.Fix_Warnings(program_options.Prompt_Automatic_Warning_Fixes());
   }

	exit(EXIT_FAILURE);
  }




