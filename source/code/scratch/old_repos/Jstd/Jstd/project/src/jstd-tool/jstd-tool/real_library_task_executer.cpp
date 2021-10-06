#include "real_library_task_executer.hpp"
#include "exporter.hpp"
#include "builder.hpp"
#include "documenter.hpp"
#include "utilities.hpp"

void Real_Library_Task_Executer::Excute_Needed_Tasks(Program_Options const& program_options, std::time_t const& last_run_time) {

	//+----------------------------------------------------------+
	//| EXPORT                                                   |
	//+----------------------------------------------------------+
	//export the library if the command line flag permits it.
	//The exporter should handle its own exceptions.  If it does throw something,
	//we'll catch it and immediately quit the program.  The cached exception below should never happen.
	//IF THE EXCEPTION BELOW DOES HAPPEN AND GETS CAUGHT,  THERE IS SOMETHING WRONG WITH THE EXPORTER.
	try{Exporter::Export_If_Needed(program_options,last_run_time);}
	catch(...){Exit_With_Error_Message(Error_Message("EXPORTER"));}

	//+----------------------------------------------------------+
	//| BUILD                                                    |
	//+----------------------------------------------------------+
	//build static/dynamic libraries for windows/linux if the command line flag permits it.
	//The builder should handle its own exceptions.  If it does throw something,
	//we'll catch it and immediately quit the program.  The cached exception below should never happen.
	//IF THE EXCEPTION BELOW DOES HAPPEN AND GETS CAUGHT,  THERE IS SOMETHING WRONG WITH THE BUILDER.
	try{Builder::Build_If_Needed(program_options,last_run_time);}
	catch(...){Exit_With_Error_Message(Error_Message("BUILDER"));}

	//+----------------------------------------------------------+
	//| DOCUMENT                                                 |
	//+----------------------------------------------------------+
	//create documentation if the command line flag permits it.
	//The documenter should handle its own exceptions.  If it does throw something,
	//we'll catch it and immediately quit the program.  The cached exception below should never happen.
	//IF THE EXCEPTION BELOW DOES HAPPEN AND GETS CAUGHT,  THERE IS SOMETHING WRONG WITH THE DOCUMENTER.
	try{Documenter::Create_Documentation_If_Needed(program_options,last_run_time);}
	catch(...){Exit_With_Error_Message(Error_Message("DOCUMENTER"));}

	return;
}
