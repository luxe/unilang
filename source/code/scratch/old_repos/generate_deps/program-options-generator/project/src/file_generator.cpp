#include "file_generator.hpp"
#include "flag_line.hpp"
#include "flag_extractor.hpp"
#include "global.hpp"
#include "program_options_creator.hpp"
#include "program_options_default_creator.hpp"
#include "program_options_checker_creator.hpp"
#include "program_options_creator_creator.hpp"

void File_Generator::Generate_Files(Program_Options const& program_options){

	auto flag_files = Flag_Extractor::Extract_Flags(program_options);

	//create the three object file source files
	Create_Program_Options_Default_HPP(program_options);
	Create_Program_Options_Default_CPP(program_options);

	Create_Program_Options_HPP(program_options, flag_files);
	Create_Program_Options_CPP(program_options, flag_files);

	Create_Program_Options_Checker_HPP(program_options);
	Create_Program_Options_Checker_CPP(program_options);

	Create_Program_Options_Creator_HPP(program_options);
	Create_Program_Options_Creator_CPP(program_options);

	Create_Program_Options_User_Check_Code_HPP(program_options);

	return;
}
void File_Generator::Create_Program_Options_Default_HPP(Program_Options const& program_options) {
	std::ofstream outfile(constant::PROGRAM_OPTIONS_DEFAULT_HPP);
	Program_Options_Default_Creator::Create_HPP(outfile, program_options);
	return;
}
void File_Generator::Create_Program_Options_Default_CPP(Program_Options const& program_options) {
	std::ofstream outfile(constant::PROGRAM_OPTIONS_DEFAULT_CPP);
	Program_Options_Default_Creator::Create_CPP(outfile, program_options);
	return;
}
void File_Generator::Create_Program_Options_HPP(Program_Options const& program_options, std::vector<Flag_Line> const& flag_files) {
	std::ofstream outfile(constant::PROGRAM_OPTIONS_HPP);
	Program_Options_Creator::Create_HPP(outfile, program_options, flag_files);
	return;
}
void File_Generator::Create_Program_Options_CPP(Program_Options const& program_options, std::vector<Flag_Line> const& flag_files) {
	std::ofstream outfile(constant::PROGRAM_OPTIONS_CPP);
	Program_Options_Creator::Create_CPP(outfile, program_options, flag_files);
	return;
}
void File_Generator::Create_Program_Options_Checker_HPP(Program_Options const& program_options) {
	std::ofstream outfile(constant::PROGRAM_OPTIONS_CHECKER_HPP);
	Program_Options_Checker_Creator::Create_HPP(outfile, program_options);
	return;
}
void File_Generator::Create_Program_Options_Checker_CPP(Program_Options const& program_options) {
	std::ofstream outfile(constant::PROGRAM_OPTIONS_CHECKER_CPP);
	Program_Options_Checker_Creator::Create_CPP(outfile, program_options);
	return;
}
void File_Generator::Create_Program_Options_Creator_HPP(Program_Options const& program_options) {
	std::ofstream outfile(constant::PROGRAM_OPTIONS_CREATOR_HPP);
	Program_Options_Creator_Creator::Create_HPP(outfile, program_options);
	return;
}
void File_Generator::Create_Program_Options_Creator_CPP(Program_Options const& program_options) {
	std::ofstream outfile(constant::PROGRAM_OPTIONS_CREATOR_CPP);
	Program_Options_Creator_Creator::Create_CPP(outfile, program_options);
	return;
}
void File_Generator::Create_Program_Options_User_Check_Code_HPP(Program_Options const& program_options) {
	std::ofstream outfile(constant::PROGRAM_OPTIONS_USER_CHECK_CODE_HPP);
	outfile << program_options.Check_Code();
	return;
}