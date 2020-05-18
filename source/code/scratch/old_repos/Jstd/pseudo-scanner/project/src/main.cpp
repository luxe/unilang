#include "program_options_creator.hpp"
#include "task_executer.hpp"
#include "utilities.hpp"
#include "global.hpp"

int main(int const argc, char** const argv) {

	//get program options from command line
	auto program_options = Program_Options_Creator::Create(argc, argv);

	//check to make sure that the program is being run inside the root of the pseudo library
	if (Current_Folder_Name() != constant::NAME_OF_PSEUDO_LIBRARY_FOLDER){
		Exit_With_Error("The program needs to run inside the pseudo library folder named " + constant::NAME_OF_PSEUDO_LIBRARY_FOLDER);
	}

	//choose what task to do (this handles all of the flag options)
	Task_Executer::Do_Needed_Tasks(program_options);

	return EXIT_SUCCESS;
}