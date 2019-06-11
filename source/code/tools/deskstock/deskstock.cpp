#include <iostream>
#include "code/tools/deskstock/deskstock_runner.hpp"
#include "code/tools/deskstock/meta_settings.hpp"

int main(){
    
    //should probably do prog args and stuff
    
    Meta_Settings meta;
    meta.program_name = "deskstock";
    Deskstock_Runner::Run(meta);
}
