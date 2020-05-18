#include "task_executer.hpp"
#include "scanner.hpp"
#include "utilities.hpp"
#include "global.hpp"











 void Task_Executer::Do_Needed_Tasks(Program_Options const& program_options) {

	//get the time that the program was last ran.  We will use this value to determine if certain
	//files need tasks done on them.  There are certain analysis algorithms that take significantly long,
	//and so we want to make sure, that we only operate on them when needed.
	auto last_run_time = boost::filesystem::last_write_time(constant::LAST_TIME_RAN_FILE);

	//avoid stepping into the .git repo by stepping into the root of the pseudo library
	Step_Into_Folder(constant::NAME_OF_PSEUDO_LIBRARY_FOLDER);
	Step_Into_Folder("root");

	//run scanner on all the files that are newer than the LAST_TIME_RAN_FILE
	Scanner::Scan_Changed_Files(program_options);

	//updates the "last modified" time, which was read in
	//at the beginning of the program.  this basically the same as touching the file
	std::ofstream object_created_to_touch_the_file{constant::LAST_TIME_RAN_FILE};
	object_created_to_touch_the_file << "The time stamp of this file is looked at to determine when this tool was last run\n";

	return;
}