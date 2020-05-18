#include "program_options_checker_creator.hpp"
#include "global.hpp"

void Program_Options_Checker_Creator::Create_HPP(std::ofstream & outfile, Program_Options const& program_options) {
	outfile <<
R"foo(
#include "program_options.hpp"

class Program_Options_Checker {

	//If there are any additional issues with the flags you would like to check for, that can be done here.
	//these checks should deal with logical issues of the flag values, and not how flag values were passed.
	//If there are no logic errors, then the function will return; else it will exit the program inside the function.
	//This function is called automatically by the Program_Options object.
	public: static void Check(Program_Options const& program_options);
		private: static void Validate_Through_Regular_Expressions(Program_Options const& program_options);
		private: static void Validate_Through_User_Injected_Code(Program_Options const& program_options);
};
)foo";
	return;
}
void Program_Options_Checker_Creator::Create_CPP(std::ofstream & outfile, Program_Options const& program_options) {


//The check function
outfile <<
R"foo(
#include "program_options_checker.hpp"

void Program_Options_Checker::Check(Program_Options const& program_options) {

	Validate_Through_Regular_Expressions(program_options);
	Validate_Through_User_Injected_Code(program_options);

	return;
}
)foo";

//the regular expression flag function
outfile << 
R"foo(
void Program_Options_Checker::Validate_Through_Regular_Expressions(Program_Options const& program_options) {
)foo";

//not implemented yet

outfile << R"foo(
	return;
}
)foo";

//the user injected flag function
outfile << 
R"foo(
void Program_Options_Checker::Validate_Through_User_Injected_Code(Program_Options const& program_options) {
)foo";

outfile << "\t#include \"" << constant::PROGRAM_OPTIONS_USER_CHECK_CODE_HPP << "\"\n";
outfile << R"foo(
	return;
}
)foo";
	return;
}
