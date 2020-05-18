#pragma once
#include <string>

//Boost Libraries
#include <boost/program_options.hpp>

class Program_Options{

	public:

	//Constructor
	explicit Program_Options(int const& argc, char** const& argv);


	//+----------------------------------------------------------+
	//| SCAN                                                     |
	//+----------------------------------------------------------+
	/*[false]*/ bool Scan                           ()const;   //will we do the following tasks?
	/*[0    ]*/ int  Warn_Amount                    ()const;   //how many warnings to show before crashing (0 = infinity)
	/*[true ]*/ bool Fix_Warnings                   ()const;   //should we attempt to fix the warnings at all?
	/*[false]*/ bool Prompt_Automatic_Warning_Fixes ()const;   //if we are going to fix warnings,  should prompt for each one?

	//+----------------------------------------------------------+
	//| Optimize                                                 |
	//+----------------------------------------------------------+
	/*[false]*/ bool Optimize                       ()const;

	//+----------------------------------------------------------+
	//| EXPORT                                                   |
	//+----------------------------------------------------------+
	/*[false]*/ bool Export                         ()const;
	/*[0000 ]*/ std::string Cases                   ()const;
	/*[true ]*/ bool Base_Functions_Only            ()const;
	/*[false]*/ bool Inclusion_Guards               ()const; /* \                                            */
	/*[true ]*/ bool Pragma_Once                    ()const; /* / You need at least one of these to be true. */

	//+----------------------------------------------------------+
	//| BUILD                                                    |
	//+----------------------------------------------------------+
	/*[false]*/ bool Build                          ()const;
	/*[true ]*/ bool Keep_Object_Files              ()const;
	/*[true ]*/ bool Header_Only                    ()const;
	/*[true ]*/ bool Pre_Compiled_Header            ()const;
	/*[true ]*/ bool Static_Library                 ()const;
	/*[true ]*/ bool Dynamic_Library                ()const;
	/*[true ]*/ bool Windows                        ()const;
	/*[true ]*/ bool Linux                          ()const;

	//+----------------------------------------------------------+
	//| DOCUMENTATION                                            |
	//+----------------------------------------------------------+
	/*[false]*/ bool Documentation                  ()const;

	//+----------------------------------------------------------+
	//| STATS                                                    |
	//+----------------------------------------------------------+
	/*[false]*/ bool Stats                          ()const;

	//+----------------------------------------------------------+
	//| DATABASE                                                 |
	//+----------------------------------------------------------+
	/*[false]*/ bool Database                       ()const;

	//+----------------------------------------------------------+
	//| PROGRAM CUSTOMIZATION                                    |
	//+----------------------------------------------------------+
	/*[true ]*/ bool Show_Progress                  ()const;
	/*[false]*/ bool Simple_Progress                ()const;
	/*[true ]*/ bool Colors                         ()const;



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
