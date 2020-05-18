#include "task_executer.hpp"
#include "cleaner.hpp"
#include "global_git_ignore_file_generator.hpp"
#include "root_repo_getter.hpp"
#include "updater.hpp"
#include "utilities.hpp"










//decides if the command line argumets passed in are for downloading, updating, or cleaning.
//It forwards any data on to the respective module for the task deduced
 void Task_Executer::Do_Needed_Tasks(Program_Options const& program_options) {

	if (program_options.Clear_Local_Repo_Cache()){
		execute(std::string("rm -rf ") + "~/.github/*");
		exit(EXIT_SUCCESS);
	}

	//download repo with/without dependencies
	if      (!program_options.Deps() && !program_options.URL().empty()) {Root_Repo_Getter::Get_Root_Repo(false,program_options.URL(),program_options.Allow_Nested_Git_Repos());}
	else if (program_options.Deps() && !program_options.URL().empty())  {Root_Repo_Getter::Get_Root_Repo(true,program_options.URL(),program_options.Allow_Nested_Git_Repos());}

	//clean dependencies from already in the repo
	else if (program_options.Clean()) {
		if (program_options.All()) {Cleaner::Clean_All_Dependencies();}
		else if (program_options.Recursive()) {Cleaner::Clean_Dependencies_Recursively();}
		else if (!program_options.Symfiles().empty()) {Cleaner::Clean_Listed_Dependencies_Of_Dir(program_options.Symfiles());}
		else {Cleaner::Clean_Dependencies_Of_Current_Dir();}
	}

	//update dependencies from already in the repo
	else if (!program_options.Symfiles().empty()) {Updater::Update_Specific_Symbolic_Pull_Ins(program_options.Symfiles());}
	else if (program_options.Recursive()) {Updater::Update_Symbolic_Pull_Ins_Recursively();}
	else if (program_options.All()) {Updater::Update_Symbolic_Pull_Ins_For_The_Whole_Repo();}
	else {Updater::Update_Symbolic_Pull_Ins_For_Current_Directory();}

    //this global .gitignore file is created so we don't accidentally commit generated dependency files
	if (program_options.Generate_Ignore()){
		Global_Git_Ignore_File_Generator::Generate_Ignore_File_At_Project_Root();
	}

	return;
}