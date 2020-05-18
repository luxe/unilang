
#pragma once
#include "program_options_default.hpp"

//Boost Libraries
#include <boost/program_options.hpp>

class Program_Options: public Program_Options_Default{

	public:

	//Constructor
	explicit Program_Options(int const& argc, char** const& argv);

	//These are functions for the client who uses the Program Options object.
	//They include all of the functions passed to the program_options_maker.
	//The options "help" and "version", do not need to be implemented by the user.
	//The "help" and "version" flags are always added automatically unless specified not to be.
	//+----------------------------------------------------------+
	//| USER FLAGS                                               |
	//+----------------------------------------------------------+
	/* "" */ std::string URL()const; //the url of the repository to download;
	/* true */ bool Deps()const; //download the repository, but don't apply the symbolic pull-ins;
	/* false */ bool Recursive()const; //apply the symbolic pull-ins to the current directory and all sub directories;
	/* false */ bool All()const; //apply the symbolic pull-ins to all parts of the repository;
	/* std::vector<std::string>() */ std::vector<std::string> Symfiles()const; //apply specified symbolic pull-in;
	/* false */ bool Clean()const; //perform a clean instead of an update;
	/* true */ bool Generate_Ignore()const; //stops git-it from creating a global .gitignore file;
	/* false */ bool Clear_Local_Repo_Cache()const; //deletes all of the locally downloaded repos;
	/* false */ bool Allow_Nested_Git_Repos()const; //allows downloading git repos inside git repos. Although not recomended, and generally attempted by acccident, it can be overridden for times when it needs to be done.;
bool No_Flags_Were_Passed() const;


	private:

	//functions used to parse, store, verify,  and immediately process SOME of the flags.
	//other verification of flag data is passed on as a responsibility of the Program_Options_Checker
	auto Get_Options_Description() -> boost::program_options::options_description;
	auto Build_Variable_Map(int const& argc, char** const& argv, boost::program_options::options_description const& desc, boost::program_options::positional_options_description const& pod) -> void;
	auto Process_Immediate_Options(boost::program_options::options_description const& desc) -> void;
	auto Check_For_Mandatory_Flags_Not_Passed() -> void;

	//Data Members
	//the variables map,  holds all of the flag data passed in through the constructor.
	boost::program_options::variables_map vm;
};
