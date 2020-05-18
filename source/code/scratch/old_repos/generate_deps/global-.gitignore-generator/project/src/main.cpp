#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "program_options_creator.hpp"
#include "global_git_ignore_file_generator.hpp"

//this is where we expect git-it to place the repo
const std::string DEPENDENCY_DIRECTORY = "~/.github/generative-dependencies/global_.gitignore_generator/project/src/";

int main(int const argc, char** const argv) {

    //get program options from command line
    auto program_options = Program_Options_Creator::Create(argc, argv);

    //generate global git ignore file
    //Global_Git_Ignore_File_Generator::Generate_Ignore_File_At_Project_Root();
    //
    system(("cp " + DEPENDENCY_DIRECTORY + "global_git_ignore_file_generator.hpp .").c_str());
    system(("cp " + DEPENDENCY_DIRECTORY + "global_git_ignore_file_generator.cpp .").c_str());

    return EXIT_SUCCESS;
}
