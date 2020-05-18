
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
pod.add("url", -1);

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
	("url",value<std::string>()->multitoken(),"the url of the repository to download")
	("no_deps","download the repository, but don't apply the symbolic pull-ins")
	("recursive","apply the symbolic pull-ins to the current directory and all sub directories")
	("all","apply the symbolic pull-ins to all parts of the repository")
	("symfile",value<std::vector<std::string>>(),"apply specified symbolic pull-in")
	("clean","perform a clean instead of an update")
	("no-ignore","stops git-it from creating a global .gitignore file")
	("wipe-local","deletes all of the locally downloaded repos")
	("allow-nested-git","allows downloading git repos inside git repos. Although not recomended, and generally attempted by acccident, it can be overridden for times when it needs to be done.")

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
	if (vm.count("url")){return false;}
	if (vm.count("no_deps")){return false;}
	if (vm.count("recursive")){return false;}
	if (vm.count("all")){return false;}
	if (vm.count("symfile")){return false;}
	if (vm.count("clean")){return false;}
	if (vm.count("no-ignore")){return false;}
	if (vm.count("wipe-local")){return false;}
	if (vm.count("allow-nested-git")){return false;}
   return true;
}
std::string Program_Options::URL() const{
	std::string data= "";
	if (vm.count("url")){
		data = vm["url"].as<std::string>();
	}

	return data;
}
bool Program_Options::Deps() const{
return !vm.count("no_deps");}
bool Program_Options::Recursive() const{
return vm.count("recursive");}
bool Program_Options::All() const{
return vm.count("all");}
std::vector<std::string> Program_Options::Symfiles() const{
	std::vector<std::string> data= std::vector<std::string>();
	if (vm.count("symfile")){
		data = vm["symfile"].as<std::vector<std::string>>();
	}

	return data;
}
bool Program_Options::Clean() const{
return vm.count("clean");}
bool Program_Options::Generate_Ignore() const{
return !vm.count("no-ignore");}
bool Program_Options::Clear_Local_Repo_Cache() const{
return vm.count("wipe-local");}
bool Program_Options::Allow_Nested_Git_Repos() const{
return vm.count("allow-nested-git");}
