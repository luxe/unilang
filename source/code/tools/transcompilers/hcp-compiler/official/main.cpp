#include <locale>
#include "code/transcompilers/hcp-compiler/official/program_options/program_options_creator.hpp"
#include "code/transcompilers/hcp-compiler/official/task_executer.hpp"
#include "code/utilities/locale/lib.hpp"

void Immediate_Checks_On_Filename_Sent_To_Compiler(std::string const& file_name);

int main(int const argc, char** const argv) {

	//Unicode please
	Set_English_UTF8_Locale();

	//get program options from command line
	auto program_options = Program_Options_Creator::Create(argc, argv);
        
    //continue on to process the file
	Task_Executer::Execute_Needed_Tasks(program_options);

	return EXIT_SUCCESS;
}