#include <locale>
#include "program_options_creator.hpp"
#include "task_executer.hpp"
int main(int const argc, char** const argv) {
    
    //Unicode please
    std::locale::global(std::locale("en_US.UTF-8"));
    
    //get program options from command line
    auto program_options = Program_Options_Creator::Create(argc, argv);
    
    //execute all the needed tasks based on the program option flags
    Task_Executer::Execute_Needed_Tasks(program_options);
    
    return EXIT_SUCCESS;
}
