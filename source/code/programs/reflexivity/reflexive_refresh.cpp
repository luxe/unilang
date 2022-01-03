#include "code/programs/reflexivity/reflexive_refresher.hpp"
#include "code/utilities/program/common_actions/main/catching_main.hpp"


int main(int argc, char** argv){
    
    return Catching_Main::Run([&](){
        Reflexive_Refresher::Refresh();
        return 0;
    });
}