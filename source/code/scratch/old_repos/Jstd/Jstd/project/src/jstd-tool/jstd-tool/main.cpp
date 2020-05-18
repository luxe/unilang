//-----------------------------------------------------------------------------------------------------------------------
// This program will scan, export, build, document, optimize, and dump meta information for the Jstd library.
// This program is used by both Jstd developers, and those who wish to use the library from local build.
// The Jstd devleopers will most likely rely on the scan process to fix problems in the pseudo library, and the optimizer
// to optimize parts of the pseudo library.  They can also use this program to generate meta information about the library.
// For those who only wish to use the library,  but not extend it, they will only need to worry about the
// export, build,  and optional documentation flags.
// They will most likely run:
// "./jstd-tool --export --build --document(if they wish to have local documentation) --other customizable flags
// So for example:
// "./jstd-tool --export --build" is my recommendation for most users.  Check the other flags, if you need to make some tweaks.

//WARNING:
//RUN THIS PROGRAM AT THE ROOT OF THE PSEUDO LIBRARY.
//IT SHOULD GET BUILT THERE ANYWAY.
//There is a check in place, to make sure that it was run in the correct directory.
//The only danger would be if you ran it in a different folder that happened to be
//named the same thing as the root pseudo library folder. So still be careful.
//tldr; cd to the folder where this is built and only run it there.
//-----------------------------------------------------------------------------------------------------------------------

//STD STUFF
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <chrono>

//C LIBS
#include <time.h>

//globals
#include "global.hpp"

//utility functions
//*this is the kind of stuff that the jstd fixes, ya know?
#include "utilities.hpp"

/* my classes */
//deal with all the program flags passed in the command line
#include "program_options.hpp"
#include "program_options_checker.hpp"

//each task executer main can call
#include "pseudo_library_task_executer.hpp"
#include "real_library_task_executer.hpp"
#include "meta_data_task_executer.hpp"


// function decelerations
auto Get_Validated_Program_Options(int const& argc, char** const argv) -> Program_Options;
auto Perform_Requested_Tasks(Program_Options const& program_options, std::time_t const& last_run_time) -> void;

//-----------------------------------------------------------------------------------------------------------------------
int main(int const argc, char** const argv) {

	//get validated program options (command line flags are scan and stored)
	auto program_options(Get_Validated_Program_Options(argc, argv));

	//turn off colors if specified in the command line
	global::COLORS_ENABLED = program_options.Colors();

	//CHECK TO MAKE SURE THE CURRENT WORKING DIRECTORY, IS THE RIGHT DIRECTORY.
	//WE EXPECT THE PROGRAM TO BE RUN IN A SPECIFICALLY NAMED FOLDER.
	//immediately exit, if the program is run in the wrong directory.
	if (Current_Folder_Name() != constant::NAME_Of_ROOT_FOLDER_THAT_EXPORTER_SHOULD_RUN_IN){
		std::cerr << "You are not running the jstd-tool in the correct directory.\n";
		exit(EXIT_FAILURE);
	}

	//get the time that the program was last ran.  We will use this value to determine if certain
	//files need tasks done on them.  There are certain analysis algorithms that take significantly long,
	//and so we want to make sure, that we only operate on them when needed.
	auto last_run_time = boost::filesystem::last_write_time(constant::LAST_TIME_RAN_FILE);

	//run all of the tasks that were specified in the command line.
	//this function does everything important from the program runner's point of view
	Perform_Requested_Tasks(program_options, last_run_time);

	//program completed successfully
	Green_Message("Everything finished successfully!\n");

	//updates the "last modified" time, which was read in
	//at the beginning of the program.  this basically the same as touching the file
	std::ofstream object_created_to_touch_the_file{constant::LAST_TIME_RAN_FILE};

	return EXIT_SUCCESS;
}
//-----------------------------------------------------------------------------------------------------------------------

// function definitions
auto Get_Validated_Program_Options(int const& argc, char** const argv) -> Program_Options{

	//read in the program options, and make sure the flag values are valid
	Program_Options program_options(argc,argv);
	Program_Options_Checker::Check(program_options);
	return program_options;
}
auto Perform_Requested_Tasks(Program_Options const& program_options, std::time_t const& last_run_time) -> void{

	std::cout <<  std::endl;
	
	//Perform pseudo library tasks (scan and optimize)
	//These tasks have the potential to change data in the pseudo library.
	Pseudo_Library_Task_Executer::Excute_Needed_Tasks(program_options, last_run_time);

	//Perform Jstd library tasks (export, build, and document)
	//These tasks have the potential to change data in the Jstd library.
	Real_Library_Task_Executer::Excute_Needed_Tasks(program_options, last_run_time);

	//Perform meta data tasks (stats and database)
	//These tasks have the potential to change data in the meta directory.
	Meta_Data_Task_Executer::Excute_Needed_Tasks(program_options, last_run_time);

	return;
}

