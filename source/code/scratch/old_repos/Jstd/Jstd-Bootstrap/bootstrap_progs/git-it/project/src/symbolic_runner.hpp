#pragma once
#include "repository.hpp"

class Symbolic_Runner{





public: static void Run_Symbolic_Pullin_Program(std::string const& dependency_path, std::string const& flags, std::string const& path_to_file, Repository repo, size_t const& depth);
};