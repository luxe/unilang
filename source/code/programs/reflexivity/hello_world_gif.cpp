#include <iostream>
#include "code/utilities/code/artifacts/animate/unilang_hello_world_gif.hpp"
#include "code/utilities/filesystem/paths/lib.hpp"
#include "code/utilities/program/common_actions/signals/all_signal_setter.hpp"
#include "code/utilities/program/common_actions/backtrace/backtrace.hpp"
#include "code/utilities/program/common_actions/backtrace/exceptions.hpp"


int main(int argc, char** argv){
    
    
    Bind_All_Signals_To_Handler([](int i){
        std::string stackTrace = get_stacktrace();
        std::cout << stackTrace << std::endl;
        exit(1);
    });
    
    try {
        Unilang_Hello_World_Gif::Create();
    }
    catch (std::exception e){
            std::cout << get_symbolized_stacktrace(e) << std::endl;
            exit(1);
        }
}


