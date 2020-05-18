
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
	("all","add all important system headers")
	("std","add all important std library headers")
	("boost","add all important boost library headers")
	("qt","add all important Qt library headers")
	("ncurses","add all important ncurses library headers")
	("adds",value<std::vector<std::string>>()->multitoken(),"add additional include statements")
	("removes",value<std::vector<std::string>>()->multitoken(),"add additional include statements to NOT include")

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

	if (!flags_not_passed.empty()){
		std::cerr << "you need to pass the following flags still:\n";
		for (auto it: flags_not_passed){
			std::cerr << '\t' << it << '\n';
		}
		exit(EXIT_FAILURE);
	}
	return;
}
bool Program_Options::No_Flags_Were_Passed() const{
	if (vm.count("all")){return false;}
	if (vm.count("std")){return false;}
	if (vm.count("boost")){return false;}
	if (vm.count("qt")){return false;}
	if (vm.count("ncurses")){return false;}
	if (vm.count("adds")){return false;}
	if (vm.count("removes")){return false;}
   return true;
}
bool Program_Options::All() const{
return vm.count("all");}
bool Program_Options::Std() const{
return vm.count("std");}
bool Program_Options::Boost() const{
return vm.count("boost");}
bool Program_Options::Qt() const{
return vm.count("qt");}
bool Program_Options::Ncurses() const{
return vm.count("ncurses");}
std::vector<std::string> Program_Options::Adds() const{
	std::vector<std::string> data;
	if (vm.count("adds")){
		data = vm["adds"].as<std::vector<std::string>>();
	}

	return data;
}
std::vector<std::string> Program_Options::Removes() const{
	std::vector<std::string> data;
	if (vm.count("removes")){
		data = vm["removes"].as<std::vector<std::string>>();
	}

	return data;
}
