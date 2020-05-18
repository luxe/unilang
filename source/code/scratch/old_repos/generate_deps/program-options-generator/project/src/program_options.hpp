#pragma once
#include <string>
#include <vector>

//Boost Libraries
#include <boost/program_options.hpp>

class Program_Options{

	public:

	//Constructor
	explicit Program_Options(int const& argc, char** const& argv);

	//flags for the program
	std::vector<std::string> Flags() const;

		//necessary meta data
		std::string Author() const;
		std::string Description() const;
		std::string Website() const;
		std::string Email_Address() const;
		std::string Tool_Name() const;
		std::string Version_Number() const;
		std::string License() const;
		bool Allow_JSON() const;

		std::string Check_Code() const;

	protected:
	private:

	//functions
	auto Get_Options_Description() -> boost::program_options::options_description;
	auto Build_Variable_Map(int const& argc, char** const& argv, boost::program_options::options_description const& desc, boost::program_options::positional_options_description const& pod) -> void;
	auto Process_Immediate_Options(boost::program_options::options_description const& desc) -> void;

	//data members
	boost::program_options::variables_map vm;
	static const std::string VERSION_NUMBER;

};
