#include <iostream>
#include "code/tools/noogle/meta_settings.hpp"
#include "code/tools/noogle/noogle_runner.hpp"

int main(){
    
    //should probably do prog args and stuff
    
    Meta_Settings meta;
    meta.program_name = "noogle";
    Noogle_Runner::Run(meta);
}
