#pragma once
#include <iostream>
#include <string>
#include "program_options.hpp"
#include "flag_line.hpp"

class File_Generator{

	public: static void Generate_Files(Program_Options const& program_options);
		private: static void Create_Program_Options_Default_HPP(Program_Options const& program_options);
		private: static void Create_Program_Options_Default_CPP(Program_Options const& program_options);
		private: static void Create_Program_Options_HPP(Program_Options const& program_options, std::vector<Flag_Line> const& flag_files);
		private: static void Create_Program_Options_CPP(Program_Options const& program_options, std::vector<Flag_Line> const& flag_files);
		private: static void Create_Program_Options_Checker_HPP(Program_Options const& program_options);
		private: static void Create_Program_Options_Checker_CPP(Program_Options const& program_options);
		private: static void Create_Program_Options_Creator_HPP(Program_Options const& program_options);
		private: static void Create_Program_Options_Creator_CPP(Program_Options const& program_options);
		private: static void Create_Program_Options_User_Check_Code_HPP(Program_Options const& program_options);
};