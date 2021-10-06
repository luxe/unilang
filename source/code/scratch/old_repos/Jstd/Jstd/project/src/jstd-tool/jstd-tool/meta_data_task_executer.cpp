#include "meta_data_task_executer.hpp"
#include "stats_dumper.hpp"
#include "database_dumper.hpp"
#include "utilities.hpp"

void Meta_Data_Task_Executer::Excute_Needed_Tasks(Program_Options const& program_options, std::time_t const& last_run_time) {

	//+----------------------------------------------------------+
	//| STATS                                                    |
	//+----------------------------------------------------------+
	//dump stats about the library if the command line flag permits it.
	//The stats dumper should handle its own exceptions.  If it does throw something,
	//we'll catch it and immediately quit the program.  The cached exception below should never happen.
	//IF THE EXCEPTION BELOW DOES HAPPEN AND GETS CAUGHT,  THERE IS SOMETHING WRONG WITH THE STATS_DUMPER.
	try{Stats_Dumper::Dump_Stats_If_Needed(program_options,last_run_time);}
	catch(...){Exit_With_Error_Message(Error_Message("STATS DUMPER"));}

	//+----------------------------------------------------------+
	//| DATABASE                                                 |
	//+----------------------------------------------------------+
	//dump database about the library if the command line flag permits it.
	//The database dumper should handle its own exceptions.  If it does throw something,
	//we'll catch it and immediately quit the program.  The cached exception below should never happen.
	//IF THE EXCEPTION BELOW DOES HAPPEN AND GETS CAUGHT,  THERE IS SOMETHING WRONG WITH THE DATABASE DUMPER.
	try{Database_Dumper::Dump_Database_If_Needed(program_options,last_run_time);}
	catch(...){Exit_With_Error_Message(Error_Message("DATABASE DUMPER"));}

	return;
}
