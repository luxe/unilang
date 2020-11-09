#include <iostream>
#include <string>
#include "code/utilities/program/wrappers/git/sync_fork/fork_syncer.hpp"

int main(int const argc, char** const argv){
    
    std::string dev_name = argv[1];
    std::string dev_proj_name = argv[2];
    std::string fork_name = argv[3];
    Fork_Syncer::Sync(dev_name,dev_proj_name,fork_name);
}