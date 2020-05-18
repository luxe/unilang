#pragma once
#include <string>
#include <vector>
#include <boost/filesystem.hpp>

namespace constant{

	//these could be changed if needed
	namespace file_base{
		const std::string PROGRAM_OPTIONS_DEFAULT = "program_options_default";
		const std::string PROGRAM_OPTIONS = "program_options";
		const std::string PROGRAM_OPTIONS_CHECKER = "program_options_checker";
		const std::string PROGRAM_OPTIONS_CREATOR = "program_options_creator";
		const std::string PROGRAM_OPTIONS_USER_CHECK_CODE = "program_options_user_check_code";
	}

	//these will most likely not need to be touched
	const std::string PROGRAM_OPTIONS_DEFAULT_HPP = file_base::PROGRAM_OPTIONS_DEFAULT + ".hpp";
	const std::string PROGRAM_OPTIONS_DEFAULT_CPP = file_base::PROGRAM_OPTIONS_DEFAULT + ".cpp";
	const std::string PROGRAM_OPTIONS_HPP         = file_base::PROGRAM_OPTIONS + ".hpp";
	const std::string PROGRAM_OPTIONS_CPP         = file_base::PROGRAM_OPTIONS + ".cpp";
	const std::string PROGRAM_OPTIONS_CHECKER_HPP = file_base::PROGRAM_OPTIONS_CHECKER + ".hpp";
	const std::string PROGRAM_OPTIONS_CHECKER_CPP = file_base::PROGRAM_OPTIONS_CHECKER + ".cpp";
	const std::string PROGRAM_OPTIONS_CREATOR_HPP = file_base::PROGRAM_OPTIONS_CREATOR + ".hpp";
	const std::string PROGRAM_OPTIONS_CREATOR_CPP = file_base::PROGRAM_OPTIONS_CREATOR + ".cpp";
	const std::string PROGRAM_OPTIONS_USER_CHECK_CODE_HPP = file_base::PROGRAM_OPTIONS_USER_CHECK_CODE + ".hpp";
}
