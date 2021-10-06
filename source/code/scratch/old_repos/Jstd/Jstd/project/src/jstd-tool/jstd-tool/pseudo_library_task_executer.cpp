#include "pseudo_library_task_executer.hpp"
#include "scanner.hpp"
#include "optimizer.hpp"
#include "utilities.hpp"

void Pseudo_Library_Task_Executer::Excute_Needed_Tasks(Program_Options const& program_options, std::time_t const& last_run_time) {

	//+----------------------------------------------------------+
	//| SCAN                                                     |
	//+----------------------------------------------------------+
	//scan the pseudo library if the command line flag permits it.
	//The scanner should handle its own exceptions.  If it does throw something,
	//we'll catch it and immediately quit the program.  The cached exception below should never happen.
	//IF THE EXCEPTION BELOW DOES HAPPEN AND GETS CAUGHT,  THERE IS SOMETHING WRONG WITH THE SCANNER.
	try{Scanner::Scan_If_Needed(program_options,last_run_time);}
	catch(...){Exit_With_Error_Message(Error_Message("SCANNER"));}

	//+----------------------------------------------------------+
	//| OPTIMIZE                                                 |
	//+----------------------------------------------------------+
	//optimize the pseudo library if the command line flag permits it.
	//The optimizer should handle its own exceptions.  If it does throw something,
	//we'll catch it and immediately quit the program.  The cached exception below should never happen.
	//IF THE EXCEPTION BELOW DOES HAPPEN AND GETS CAUGHT,  THERE IS SOMETHING WRONG WITH THE OPTIMIZER.
	try{Optimizer::Optimize_If_Needed(program_options,last_run_time);}
	catch(...){Exit_With_Error_Message(Error_Message("OPTIMIZER"));}

	return;
}
