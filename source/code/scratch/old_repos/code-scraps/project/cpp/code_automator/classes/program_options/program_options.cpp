#include "program_options.hpp"
const std::string Program_Options::VERSION_NUMBER = "1";
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
    options_description desc("This program does something");

    //Program Flags
    desc.add_options()
	("task",value<std::string>(),"the name of the task you would like the code_automator to perform. Only one task can be chosen per run.  Each task may require additional parameters to be set.")
	
	("project_names",value<std::string>(),"a list of project names to be created")
	("main_module_names",value<std::string>(),"a list of main module names to be created in the project")
	("class_names",value<std::string>(),"a list of class names to be created")
	("enum_class_names",value<std::string>(),"a list of class names to be created")
	
	("help,h","produce this help message")
    ("version,v","display version");

    return desc;
}
void Program_Options::Build_Variable_Map(int const& argc, char** const& argv, boost::program_options::options_description const& desc, boost::program_options::positional_options_description const& pod){
	using namespace boost::program_options;

	//store user flag data.  crash elegantly if they pass incorrect flags.
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
        std::cout << "\nThis is version " << VERSION_NUMBER << " of the Code Automating Tool.\n\n";
        exit(EXIT_SUCCESS);
    }
    else if (vm.count("help")){
        std::cout << '\n' << desc << '\n';
        exit(EXIT_SUCCESS);
    }

    return;
}

std::string Program_Options::Task(void) const{
	std::string data;
    if (vm.count("task")){
        data = vm["task"].as<std::string>();
    }
	return data;
}
std::string Program_Options::Project_Names(void) const{
	std::string data;
    if (vm.count("project_names")){
        data = vm["project_names"].as<std::string>();
    }
	return data;
}
std::string Program_Options::Main_Module_Names(void) const{
	std::string data;
    if (vm.count("main_module_names")){
        data = vm["main_module_names"].as<std::string>();
    }
	return data;
}
std::string Program_Options::Class_Names(void) const{
	std::string data;
    if (vm.count("class_names")){
        data = vm["class_names"].as<std::string>();
    }
	return data;
}
std::string Program_Options::Enum_Class_Names(void) const{
	std::string data;
    if (vm.count("enum_class_names")){
        data = vm["enum_class_names"].as<std::string>();
    }
	return data;
}