#include <locale>
#include "task_executer.hpp"
int main(int const argc, char** const argv) {
    
    //Unicode please
    std::locale::global(std::locale("en_US.UTF-8"));
    Task_Executer::Execute_Needed_Tasks();
    
    return EXIT_SUCCESS;
}
