#include "program_options.hpp"
Program_Options::Program_Options(int const& argc, char** const& argv){
	using namespace boost::program_options;

	//build all the possible flags and add description.
    options_description desc (Get_Options_Description());

	//set positional arguments
	positional_options_description pod;
	pod.add("program-file",-1);

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
	("help,h","produce this help message")
    ("version,v","display version")
	("program-file",value<std::vector<std::string> >(),"program file(s) for the simulator to run");

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
std::vector<std::string> Program_Options::Files(void) const{
	std::vector<std::string> files;
	 if (vm.count("program-file")){
		 return vm["program-file"].as<std::vector<std::string> >();
	 }
	 return files;
}
void Program_Options::Process_Immediate_Options( boost::program_options::options_description const& desc){

    //do not continue the program if the user wanted to see the version or help data
    if (vm.count("version")){
        std::cout << "\nThis is version " << constants::VERSION_NUMBER << " of the Something Tool.\n\n";
        exit(EXIT_SUCCESS);
    }
    else if (vm.count("help")){
        std::cout << '\n' << desc << '\n';
        exit(EXIT_SUCCESS);
    }

    return;
}