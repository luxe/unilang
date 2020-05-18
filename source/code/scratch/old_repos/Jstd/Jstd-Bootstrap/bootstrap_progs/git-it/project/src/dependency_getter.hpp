#pragma once
#include <string>
#include <vector>

class Dependency_Getter{








public:

public: static void Get_Dependencies(unsigned int depth, int percent_current, int percent_total);

public: static void Perform_Pulls(std::vector<std::string> const& paths_that_have_pulls, unsigned int depth, int percent_current, int percent_total);

private: static void Perform_Directory_Pull(std::string const& path, int & percent_current, int percent_total, unsigned int depth);


private: static void Record_Path_If_It_Contains_A_Pull_Directory(std::vector<std::string> const& current_directories, std::vector<std::string> & paths_that_have_pulls);
};