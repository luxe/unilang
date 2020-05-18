#pragma once
#include "class_structure.hpp"

class Class_Compiler{





public:

static void Compile_HCP_File(Class_Structure const& structure, std::string const& hcp_file);

static void Print_Include_Files(std::wofstream & outfile, std::vector<std::pair<std::wstring,bool>> const& includes);

static void Dump_HPP(std::wofstream & outfile, Class_Structure const& structure, std::string const& hcp_file);

static std::string hack_fix(std::string hcp_file, bool do_bootstrap_hack);
private:
};