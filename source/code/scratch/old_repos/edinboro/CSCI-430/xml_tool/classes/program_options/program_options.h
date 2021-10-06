#pragma once
#ifndef PROGRAM_OPTIONS_T_H
#define PROGRAM_OPTIONS_T_H

//STL Libraries
#include <string>
#include <vector>
#include <utility>

//Boost Libraries
#include <boost/program_options.hpp>

class Program_OptionsT{
public:

	//Constructor
	explicit Program_OptionsT(int const& argc, char** const& argv);
	
	//Observers
	std::vector<std::string> Get_Files(void);
	std::vector<std::string> Get_Tags(void);
	std::vector<std::pair<std::string,std::string>> Get_Finds(void);
	std::vector<std::pair<std::string,std::string>> Get_Subtrees(void);
	std::vector<std::pair<std::string,std::string>> Get_Attributes(void);
	unsigned int Get_Indent(void);
	bool Height(void);
	bool Print(void);
	
	bool Interactive(void);/*
	The program will be interactive if the only flag value(s) given are to the file option.
	*/
	
protected:
private:
	
	static const std::string VERSION_NUMBER;
	
	//command line data sent to the program
	std::vector<std::string> files;
	std::vector<std::string> tags;
	std::vector<std::pair<std::string,std::string>> find;
	std::vector<std::pair<std::string,std::string>> subtrees;
	std::vector<std::pair<std::string,std::string>> attributes;
	bool print, height;
	unsigned int indent;
	
	//These functions parse through the command line data entered by the user and stores them into the above private variables
	auto Get_Options_Description(void) -> boost::program_options::options_description;
	auto Get_Variable_Map(int const& argc, char** const& argv, boost::program_options::options_description const& desc, boost::program_options::positional_options_description const& pod) -> boost::program_options::variables_map;
	void Process_Immediate_Options(boost::program_options::variables_map const& vm, boost::program_options::options_description const& desc);
	void Store_Remaining_Options(boost::program_options::variables_map const& vm, boost::program_options::options_description const& desc);
	std::vector<std::pair<std::string,std::string>> Build_Pairs(std::vector<std::string> option_values, boost::program_options::options_description const& desc);
	bool Is_Odd(int num);
};
#endif
