#include "program_options.hpp"
#include "global.hpp"
#include <iostream>
const std::string Program_Options::VERSION_NUMBER = "1.0.0";

Program_Options::Program_Options(int const& argc, char** const& argv){
	using namespace boost::program_options;

	//build all the possible flags and add description.
    options_description desc (Get_Options_Description());

	//set positional arguments
	positional_options_description pod;
	//pod.add("something",-1);

	//build variable map
	Build_Variable_Map(argc,argv,desc,pod);
	Process_Immediate_Options(desc);
}
boost::program_options::options_description Program_Options::Get_Options_Description(void){
    using namespace boost::program_options;

    //Program Description
    options_description desc("will create a program_options object to used by another program");

    //Program Flags
    desc.add_options()

    //+----------------------------------------------------------+
	//| ACTUAL PROGRAM FLAGS                                     |
	//+----------------------------------------------------------+
    // flag data
	("flag",value<std::vector<std::string>>(), "a flag to add to the generated program_options object")

	//meta data
	("author",value<std::string>(), "the author or authors of the program")
	("description",value<std::string>(), "what the program does")
	("website",value<std::string>(), "where the code or project information can be found")
	("email_address",value<std::string>(), "who to contact about in regards to the program")
	("tool_name",value<std::string>(), "the name of the program")
	("version_number",value<std::string>(), "the version number of the program")
    ("license",value<std::string>(), "the license that the software is under")
    ("allow-json","allow the program options object to accept its parameters through a json flag")

    ("check_code",value<std::string>(), "custom code to run against the program_options object")

	//+----------------------------------------------------------+
	//| OBLIGATORY FLAGS                                         |
	//+----------------------------------------------------------+
	("help,h","produce this help message")
    ("version,v","display version");

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
        std::cout << "\nThis is version " << VERSION_NUMBER << " of the Program Options Maker.\n\n";
        exit(EXIT_SUCCESS);
    }
    else if (vm.count("help")){
        std::cout << '\n' << desc << '\n';
        exit(EXIT_SUCCESS);
    }

    return;
}

std::string Program_Options::Author() const{
	std::string data;
    if (vm.count("author")){
        data = vm["author"].as<std::string>();
    }

	return data;
}
std::string Program_Options::Description() const{
	std::string data;
    if (vm.count("description")){
        data = vm["description"].as<std::string>();
    }

	return data;
}
std::string Program_Options::Website() const{
	std::string data;
    if (vm.count("website")){
        data = vm["website"].as<std::string>();
    }
	return data;
}
std::string Program_Options::Email_Address() const{
	std::string data;
    if (vm.count("email_address")){
        data = vm["email_address"].as<std::string>();
    }

	return data;
}
std::string Program_Options::Tool_Name() const{
	std::string data;
    if (vm.count("tool_name")){
        data = vm["tool_name"].as<std::string>();
    }

	return data;
}
std::string Program_Options::Version_Number() const{
	std::string data;
    if (vm.count("version_number")){
        data = vm["version_number"].as<std::string>();
    }
	return data;
}
std::string Program_Options::License() const{
    std::string data;
    if (vm.count("license")){
        data = vm["license"].as<std::string>();
    }
    return data;
}
std::string Program_Options::Check_Code() const{
    std::string data;
    if (vm.count("check_code")){
        data = vm["check_code"].as<std::string>();
    }
    return data;
}
bool Program_Options::Allow_JSON() const{
    if (vm.count("allow-json")){
        return true;
    }

    return false;
}
std::vector<std::string> Program_Options::Flags() const{
	std::vector<std::string> flags;
    if (vm.count("flag")){
        flags = vm["flag"].as<std::vector<std::string>>();
    }

    return flags;
}
