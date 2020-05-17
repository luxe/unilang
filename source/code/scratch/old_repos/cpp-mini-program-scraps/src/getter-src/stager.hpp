#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "utilities.hpp"
#include "compile_method.hpp"

class Stager {

public: static void Start_Task();
	private: static void Attempt_To_Stage(std::string const& source_file);
		private: static void Append_Results_To_The_Bottom_Of_The_File(std::string const& source_file, bool const& valid_code, std::vector<Compile_Method> const& methods);
			private: static void Add_Success_Message(std::string & top_message,  std::vector<Compile_Method> const& methods);
			private: static void Add_Fail_Message(std::string & top_message,  std::vector<Compile_Method> const& methods);
	private: static void Move_File_To_Deleted(std::string const& source_file);
	private: static void Move_File_To_Staged(std::string const& source_file);
};
