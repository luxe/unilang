#include "program_options_creator.hpp"

void Program_Options_Creator::Create_HPP(std::ofstream & outfile, Program_Options const& program_options, std::vector<Flag_Line> const& flag_files) {
	outfile <<
R"foo(
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
)foo";

	//output all of the flag decelerations
	Output_User_Flags(outfile, program_options, flag_files);

	outfile << "bool No_Flags_Were_Passed() const;\n";

	outfile <<
R"foo(

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
)foo";


	return;
}
void Program_Options_Creator::Create_CPP(std::ofstream & outfile, Program_Options const& program_options, std::vector<Flag_Line> const& flag_files) {
	outfile <<
R"foo(
#include "program_options.hpp"
#include <string>
#include <iostream>

//constructor
Program_Options::Program_Options(int const& argc, char** const& argv){
	using namespace boost::program_options;

	//build all the possible flags and add description.
    options_description desc (Get_Options_Description());

	//set positional arguments
	positional_options_description pod;
)foo";

	//this is where we add positional flags
	for (auto const& flag: flag_files) {
		if (flag.positional == "true"){
			outfile << "pod.add(\"" << Split_Away_Flag_Name_Shorthand(flag.flag_name) << "\", -1);\n";
		}
	}


	outfile <<
R"foo(
	//build variable map
	Build_Variable_Map(argc,argv,desc,pod);

	//process immediate options
	Process_Immediate_Options(desc);

	//validate the mandatory flags
	Check_For_Mandatory_Flags_Not_Passed();
}
boost::program_options::options_description Program_Options::Get_Options_Description(void){
	using namespace boost::program_options;

	//Program Description
	options_description desc(DESCRIPTION);

	//Program Flags
	desc.add_options()

	//these are flag descriptions of that can be passed into the class.
	//the code inserted,  are the flags added by the user through the
	//program_options_maker flag interface
)foo";

	//this is where we add the non positional flags
	for (auto const& flag: flag_files) {
			outfile << "\t(\"" << flag.flag_name << "\"";
			if (flag.type != "bool") {
				outfile << ",value<" << flag.type << ">()";
			}

			if (flag.multitoken == "true"){
				outfile << "->multitoken()";
			}

			outfile << ",\"" << flag.description << "\")\n";
	}
	
	//add the function to accept a json string as a parameter
	if (program_options.Allow_JSON()){
		outfile << "(\"parameters-as-json\",value<std::string>(), \"send in a json file that represents the program's command line arguments\")\n";
	}

	outfile <<
R"foo(
	//+----------------------------------------------------------+
	//| Obligatory                                               |
	//+----------------------------------------------------------+
	("help,h","produce this help message")
	("version,v","display version")
	;

    return desc;
}
void Program_Options::Build_Variable_Map(int const& argc, char** const& argv, boost::program_options::options_description const& desc, boost::program_options::positional_options_description const& pod){
	using namespace boost::program_options;

	//store user flag data. crash elegantly if they pass incorrect flags.
	try{
		store(command_line_parser(argc, argv).options(desc).positional(pod).run(), vm);
		notify(vm);
	}
	catch(error& e){
		std::cerr << "ERROR: " << e.what() << std::endl;
		std::cerr << desc << std::endl;
		exit(EXIT_FAILURE);
	}

	return;
}
void Program_Options::Process_Immediate_Options( boost::program_options::options_description const& desc){

	//do not continue the program if the user wanted to see the version or help data
	if (vm.count("version")){
		std::cout << "\nThis is version " << VERSION_NUMBER << " of the " + TOOL_NAME + ".\n\n";
		exit(EXIT_SUCCESS);
	}
	else if (vm.count("help")){
		std::cout << '\n' << desc << '\n';
		exit(EXIT_SUCCESS);
	}

	return;
}

void Program_Options::Check_For_Mandatory_Flags_Not_Passed(){
	std::vector<std::string> flags_not_passed;
)foo";

	//loop over the flags and provide mandatory checking code for the ones that need it
	for (auto const& it: flag_files){
		if (it.mandatory == "true"){
			Print_Checking_Code_For_Flag(outfile,it);
		}
	}

outfile << R"foo(
	if (!flags_not_passed.empty()){
		std::cerr << "you need to pass the following flags still:\n";
		for (auto it: flags_not_passed){
			std::cerr << '\t' << it << '\n';
		}
		exit(EXIT_FAILURE);
	}
	return;
}
)foo";

outfile << "bool Program_Options::No_Flags_Were_Passed() const{\n";

for (auto const& flag: flag_files) {
	outfile << '\t' << "if (vm.count(" <<  "\"" << Split_Away_Flag_Name_Shorthand(flag.flag_name) << "\"" << ")){return false;}\n";
}
outfile << "   return true;\n";
outfile << "}\n";


//this is where we add the non positional flag definitions
for (auto const& flag: flag_files) {
	outfile << flag.type << " Program_Options::" << flag.function_name << "() const{\n";

	//output the bool function
	if (flag.type == "bool") {
		outfile <<  "return ";
		if (flag.default_value != "false") {
			outfile << "!";
		}
		outfile << "vm.count(\"" <<  Split_Away_Flag_Name_Shorthand(flag.flag_name) << "\");}\n";
	}

	//output a non bool function
	else{
		outfile << '\t' << flag.type << " data";

		if (!flag.default_value.empty()){outfile << "= " << flag.default_value;}
		outfile << ";\n";
		
		outfile << '\t' << "if (vm.count(" <<  "\"" << Split_Away_Flag_Name_Shorthand(flag.flag_name) << "\"" << ")){\n";
		outfile << "\t\t" << "data = vm[\"" << Split_Away_Flag_Name_Shorthand(flag.flag_name) << "\"].as<" << flag.type << ">();\n";
		outfile << '\t' << "}\n\n";
		outfile << "\treturn data;\n}\n";
	}
}

	//possibly output the json retrieval function
	if (program_options.Allow_JSON()){
		outfile << "std::string Program_Options::Parameters_As_JSON() const{\n";
		outfile << '\t' << "std::string" << " data;\n";
		
		outfile << '\t' << "if (vm.count(" <<  "\"" << "parameters-as-json" << "\"" << ")){\n";
		outfile << "\t\t" << "data = vm[\"" << "parameters-as-json" << "\"].as<" << "std::string" << ">();\n";
		outfile << '\t' << "}\n\n";
		outfile << "\treturn data;\n}\n";
	}

	return;
}
void Program_Options_Creator::Output_User_Flags(std::ofstream & outfile, Program_Options const& program_options, std::vector<Flag_Line> const& flag_files) {

	outfile << "\t//+----------------------------------------------------------+\n";
	outfile << "\t//| USER FLAGS                                               |\n";
	outfile << "\t//+----------------------------------------------------------+\n";
	for (auto const& flag: flag_files) {
		outfile << "\t/* " <<  flag.default_value << " */ ";
		outfile << flag.type <<  " " << flag.function_name << "()const; //" << flag.comment << ";\n";
	}
  
  if (program_options.Allow_JSON()){
    outfile << "std::string Parameters_As_JSON() const;\n";
    
  }

	return;
}

void Program_Options_Creator::Print_Checking_Code_For_Flag(std::ofstream & outfile, Flag_Line const& flag_line){
	outfile << "\tif(!vm.count(\"" << Split_Away_Flag_Name_Shorthand(flag_line.flag_name) << "\")){flags_not_passed.push_back(\"" << flag_line.flag_name << "\");}\n";
	return;
}
std::string Program_Options_Creator::Split_Away_Flag_Name_Shorthand(std::string flag_name){

	std::string new_flag_name;
	for (auto const& it: flag_name){
		if (it == ','){
			break;
		}else{
			new_flag_name += it;
		}
	}

	return new_flag_name;
}
