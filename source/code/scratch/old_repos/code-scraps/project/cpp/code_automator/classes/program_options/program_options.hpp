#pragma once

//Boost Libraries
#include <boost/program_options.hpp>

/*

*/
class Program_Options{

	public:

	//Constructors
	explicit Program_Options(int const& argc, char** const& argv);

	//Observers
	
	//What task is being performed
	std::string Task(void) const;
		//Put Project
		//Put Main
		//Put Class
		//Put Enum_Class
	
	
		std::string Project_Names(void) const;
		std::string Main_Module_Names(void) const;
		std::string Class_Names(void) const;
		std::string Enum_Class_Names(void) const;


	protected:
	private:

	//functions
	auto Get_Options_Description(void) -> boost::program_options::options_description;
	auto Build_Variable_Map(int const& argc, char** const& argv, boost::program_options::options_description const& desc, boost::program_options::positional_options_description const& pod) -> void;
	auto Process_Immediate_Options(boost::program_options::options_description const& desc) -> void;

	//data members
	boost::program_options::variables_map vm;
	static const std::string VERSION_NUMBER;

};