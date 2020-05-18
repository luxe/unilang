#include <locale>
#include "program_options_creator.hpp"
#include "root_exception_handler.hpp"
#include "composed_program_options.hpp"
#include "program_options_composer.hpp"
#include "task_executer.hpp"

//This is a bit of boilerplate that I think is nice to have in every program I write.  
//No matter how small a program is, it inevitably grows,
//and its nice to have these facilities pre-implemented.

//decelerations
void Setup_And_Run_Program_Wrapped_In_Generated_Exception_Catcher(int const argc, char** const argv);
void Setup_And_Run_Program(int const argc, char** const argv);
void Set_Up_Locale();

//definitions
int main(int const argc, char** const argv) {
    
    //sets up, runs program, and directs all uncaught exceptions to a generated root exception handler
    Setup_And_Run_Program_Wrapped_In_Generated_Exception_Catcher(argc,argv);
    
    //exit successfully (assuming we didn't bail out)
    return EXIT_SUCCESS;
}

void Setup_And_Run_Program_Wrapped_In_Generated_Exception_Catcher(int const argc, char** const argv){
    
    //setup and run program
    //direct any uncaught exceptions to the root exception handler
    try{Setup_And_Run_Program(argc,argv);}
    catch(...){Root_Exception_Handler::Handle_Exceptions();}
}

void Setup_And_Run_Program(int const argc, char** const argv){
    
    //setup the locale and facets
    Set_Up_Locale();
    
    //get program options from command line
    auto program_options = Program_Options_Creator::Create(argc, argv);
    
    //execute all the needed tasks based on the program option flags
    Task_Executer::Execute_Needed_Tasks(program_options);
}

void Set_Up_Locale(){
    
    //Unicode please
    std::locale::global(std::locale("en_US.UTF-8"));
    
    //in case we print money or something
    std::cout.imbue(std::locale("en_US.utf8"));
}
