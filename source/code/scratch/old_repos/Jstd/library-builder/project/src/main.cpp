#include "program_options_creator.hpp"
#include "task_executer.hpp"

int main(int const argc, char** const argv) {

	//get program options from command line
	auto program_options = Program_Options_Creator::Create(argc, argv);

	//choose what task to do (this handles all of the flag options)
	Task_Executer::Do_Needed_Tasks(program_options);

	return EXIT_SUCCESS;
}