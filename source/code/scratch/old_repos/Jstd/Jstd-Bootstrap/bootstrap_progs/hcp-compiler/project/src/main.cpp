#include <locale>
#include "program_options_creator.hpp"
#include "task_executer.hpp"

void Immediate_Checks_On_Filename_Sent_To_Compiler(std::string const& file_name);

int main(int const argc, char** const argv) {

	//Unicode please
	std::locale::global(std::locale("en_US.UTF-8"));

	//get program options from command line
	auto program_options = Program_Options_Creator::Create(argc, argv);

	//process each file at a time
	for (auto const& hcp_file: program_options.Input_Files()){
        
        //exit if anything is initially wrong with the file name sent to the compiler
        Immediate_Checks_On_Filename_Sent_To_Compiler(hcp_file);
        
        //continue on to process the file
		Task_Executer::Execute_Tasks_On_File(program_options,hcp_file);
	}

	return EXIT_SUCCESS;
}

void Immediate_Checks_On_Filename_Sent_To_Compiler(std::string const& file_name){
    
    //file must be a .hcp file
    if (Get_File_Extension(file_name) != "hcp"){
        Exit_With_Error(file_name + " must have a .hcp file extension");
    }

    //file must exist
    if (!File_Exists(file_name)){
        Exit_With_Error(file_name + " not found");
    }
}