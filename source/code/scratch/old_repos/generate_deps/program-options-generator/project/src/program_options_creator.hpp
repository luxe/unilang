#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "program_options.hpp"
#include "flag_line.hpp"

class Program_Options_Creator {

	public: static void Create_HPP(std::ofstream & outfile, Program_Options const& program_options, std::vector<Flag_Line> const& flag_files);
	public: static void Create_CPP(std::ofstream & outfile, Program_Options const& program_options, std::vector<Flag_Line> const& flag_files);

	private: static void Output_User_Flags(std::ofstream & outfile, Program_Options const& program_options, std::vector<Flag_Line> const& flag_files);
	private: static void Print_Checking_Code_For_Flag(std::ofstream & outfile, Flag_Line const& flag_line);

	//utility
	private: static std::string Split_Away_Flag_Name_Shorthand(std::string flag_name);
};
