#include <locale>
#include "code/programs/transcompilers/hcp-compiler/official/program_options/program_options_creator.hpp"
#include "code/programs/transcompilers/hcp-compiler/official/task_executer.hpp"
#include "code/utilities/program/common_actions/locale/lib.hpp"
#include "code/utilities/program/common_actions/signals/all_signal_setter.hpp"
#include "code/utilities/program/common_actions/backtrace/backtrace.hpp"
#include "code/utilities/program/common_actions/backtrace/exceptions.hpp"

int main(int const argc, char** const argv) {
	
    //catch any and all signals and report a backtrace before existing
    Bind_All_Signals_To_Handler([](int i){
        std::string stackTrace = get_stacktrace();
        std::cout << stackTrace << std::endl;
        exit(1);
    });
    
    try {

		//Unicode please
		Set_English_UTF8_Locale();

		//get program options from command line
		auto program_options = Program_Options_Creator::Create(argc, argv);
	        
	    //continue on to process the file
		Task_Executer::Execute_Needed_Tasks(program_options);
	}
		
    catch (std::exception e){
            std::cout << get_symbolized_stacktrace(e) << std::endl;
            exit(1);
        }

	return EXIT_SUCCESS;
} 







        
       