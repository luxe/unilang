#include "program_options_creator_creator.hpp"

void Program_Options_Creator_Creator::Create_HPP(std::ofstream & outfile, Program_Options const& program_options) {
	outfile <<
R"foo(#pragma once
#include "program_options.hpp"
#include "program_options_checker.hpp"

class Program_Options_Creator{

	public: static Program_Options Create(int const argc, char** const argv);
};

)foo";
	return;
}
void Program_Options_Creator_Creator::Create_CPP(std::ofstream & outfile, Program_Options const& program_options) {
	outfile <<
R"foo(#include "program_options_creator.hpp"

Program_Options Program_Options_Creator::Create(int const argc, char** const argv){
	Program_Options program_options(argc, argv);
	Program_Options_Checker::Check(program_options);
	return program_options;
}
)foo";
	return;
}
