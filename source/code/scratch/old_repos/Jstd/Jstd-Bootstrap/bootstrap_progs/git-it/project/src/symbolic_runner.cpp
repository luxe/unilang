#include "symbolic_runner.hpp"
#include "utilities.hpp"






 void Symbolic_Runner::Run_Symbolic_Pullin_Program(std::string const& dependency_path, std::string const& flags, std::string const& path_to_file, Repository repo, size_t const& depth){

	if (!File_Exists(dependency_path + "/main.symsource")){
		execute_quietly("cd " + dependency_path + "/project/src/; make");
	}

	if (!File_Exists(dependency_path + "/main.symsource")){
		Exit_With_Error("\nprogram could not be created. " + dependency_path);
	}

	Create_Path_If_It_Doesnt_Already_Exist(As_Removed_Suffix(path_to_file) + ".pulled/");

	auto return_value = Get_Return_Value_Of_Running("cd " + As_Removed_Suffix(path_to_file) + ".pulled/; " + dependency_path + "/main.symsource " + flags);
	if (return_value){Exit_With_Error("FAIL!\n");}

	auto generated_files =  Get_Everything_At_Path(As_Removed_Suffix(path_to_file) + ".pulled/");

	for (auto const& it: generated_files){

		//create all the symbolic links
		return_value = Get_Return_Value_Of_Running("cd ..; ln -s .pulls/" + As_Removed_Suffix(path_to_file) + ".pulled/" + it + " . > /dev/null 2>&1");
	}

    return;
}
