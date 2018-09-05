#include <iostream>
#include <string>
#include "code/self-transfer/repo_transferer.hpp"


//this was an attempt to transfer one repo (from one machine), into the repo on another machine
//due to incompatibilities between the repos, the ideas was abandoned
//my desire was later met by getting bazel to work locally on the destination machine (outside the repo's version of bazel)
int main(int argc, char** argv){
    Repo_Transferer::Transfer();
}