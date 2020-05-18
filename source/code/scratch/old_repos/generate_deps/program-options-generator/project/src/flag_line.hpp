#pragma once
#include <iostream>
#include <string>
#include <vector>

struct Flag_Line {

	Flag_Line(std::string const& in_type, std::string const& in_default_value, std::string const& in_function_name,
			  std::string const& in_flag_name, std::string const& in_comment, std::string const& in_description, 
			  std::string const& in_mandatory, std::string const& in_positional, std::string const& in_multitoken)
				: type(in_type)
				, default_value(in_default_value)
				, function_name(in_function_name)
				, flag_name(in_flag_name)
				, comment(in_comment)
				, description(in_description)
				, mandatory(in_mandatory)
				, positional(in_positional)
				, multitoken(in_multitoken)

				{}

	std::string type;
	std::string default_value;
	std::string function_name;
	std::string flag_name;
	std::string comment;
	std::string description;
	std::string mandatory;
	std::string positional;
	std::string multitoken;
};
