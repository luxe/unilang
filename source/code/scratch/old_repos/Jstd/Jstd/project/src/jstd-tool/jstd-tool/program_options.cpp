#include "program_options.hpp"
const std::string Program_Options::VERSION_NUMBER = "4.0.0";
//WARNING: /\ this constant has to be on the second line.
//The release tool in the developer portion of the library,
//will change this constant. If you move it, there
//will be build problems for the exported project.

#include "global.hpp"

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
    options_description desc("The exporter will convert the jstd pseudo library code into the real jstd library code");

    //Program Flags
    desc.add_options()

	//+----------------------------------------------------------+
	//| SCAN                                                     |
	//+----------------------------------------------------------+
	("scan","scan the pseudo library for issues. [will not scan by default]")
	("warn_amount",value<int>(),"The amount of warnings to output before quiting. -1 is infinity, i.e. output every error that is not critical enough to end the application. [-1 by default]")
	("unresolve_warnings","don't automatically fix warnings. [warnings will be fixed by default.]")
	("prompt_automatic_warning_fixes","ask the user if they would like to fix each warning one at a time. [by default, warnings are fixed automatically.]")

	//+----------------------------------------------------------+
	//| Optimize                                                 |
	//+----------------------------------------------------------+
	("optimize","optimize the pseudo library. [will not optimize by default]\n")

	//+----------------------------------------------------------+
	//| EXPORT                                                   |
	//+----------------------------------------------------------+
	("export","export the library. [will not export by default]")
	("cases",value<std::string>(),"a string of 1s and 0s representing what cases should be on/off.  All cases are on by default.  The case order is:  lowercase underscore, uppercase underscore, lowercase camelCase, uppercase camelCase")
	("all_functions","export the synonym functions(not just the base functions). [by default, only the base functions will be exported.  Side note: don't use this flag.  Never use this flag on the Jstd.  It will run forever, and you will run out of hard drive space.]")
	("inclusion_guards","use inclusion guards in the library code. [will not be used by default]")
	("no_pragma_once","use pragma once in the library code. [will be used by default]\n")

	//+----------------------------------------------------------+
	//| BUILD                                                    |
	//+----------------------------------------------------------+
	("build","build any libraries or pre-compiled headers. [will not build these by default.  Note: individual build tasks may be specified off though.]")
	("no_keep_objects", "don't keep the objects after they are built i.e. delete them after libraries have been made. [objects are kept by default]")
	("no_header_only","don't output the single file that contains all of the code. [the header only file is created by default]")
	("no_pre_compiled_header","don't create a pre-compiled header containing all of the \"compiled\" header code. [the pre-compiled header is created by default]")
	("no_static","don't export a static library implementation. [will build a static library by default]")
	("no_dynamic","don't export a dynamic library implementation. [will build a dynamic library by default]")
	("no_windows","don't create a windows version of anything specified to be built. [windows creation is on by default]")
	("no_linux","don't create a linux version of anything specified to be built. [linux creation is on by default]")

	//+----------------------------------------------------------+
	//| DOCUMENTATION                                            |
	//+----------------------------------------------------------+
	("documentation","create documentation. [documentation not created by default]\n")

	//+----------------------------------------------------------+
	//| STATS                                                    |
	//+----------------------------------------------------------+
	("stats","don't create library stats. [stats are not created by default]\n")

	//+----------------------------------------------------------+
	//| DATABASE                                                 |
	//+----------------------------------------------------------+
	("database","dump database information. [database information is not dumped by default]\n")

	//+----------------------------------------------------------+
	//| PROGRAM CUSTOMIZATION                                    |
	//+----------------------------------------------------------+
	("no_progress","don't show progress of tasks. [progress is shown by default]")
	("simple_progress","show progress, but do it in a less sophisticated way. [simple progress is not used by default]")
	("no_colors","don't use colors in the command line. [colors are used by default]\n")

	//+----------------------------------------------------------+
	//| OBLIGATORY                                               |
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
        std::cout << "\nThis is version " << VERSION_NUMBER << " of the Jstd Exporting Tool.\n\n";
        exit(EXIT_SUCCESS);
    }
    else if (vm.count("help")){
        std::cout << '\n' << desc << '\n';
        exit(EXIT_SUCCESS);
    }

    return;
}

//+----------------------------------------------------------+
//| SCAN                                                     |
//+----------------------------------------------------------+
bool Program_Options::Scan(void) const{
	return vm.count("scan");
}
int Program_Options::Warn_Amount(void) const{
	int data{-1};
    if (vm.count("warn_amount")){
        data = vm["warn_amount"].as<int>();
    }
	return data;
}
bool Program_Options::Fix_Warnings(void) const{
	return !vm.count("unresolve_warnings");
}
bool Program_Options::Prompt_Automatic_Warning_Fixes(void) const{
	return vm.count("prompt_automatic_warning_fixes");
}

//+----------------------------------------------------------+
//| Optimize                                                 |
//+----------------------------------------------------------+
bool Program_Options::Optimize(void) const{
	return vm.count("optimize");
}

//+----------------------------------------------------------+
//| EXPORT                                                   |
//+----------------------------------------------------------+
bool Program_Options::Export(void) const{
	return vm.count("export");
}
std::string Program_Options::Cases(void) const{
	std::string data;
    if (vm.count("cases")){
        data = vm["cases"].as<std::string>();
    }

    if(data.empty()){
		for (unsigned short i = 0; i < constant::NUMBER_OF_AVAILABLE_FUNCTION_CASES; ++i){
			data += "1";
		}
	}

	return data;
}
bool Program_Options::Base_Functions_Only(void) const{
	return !vm.count("all_functions");
}
bool Program_Options::Inclusion_Guards(void) const{
	return vm.count("inclusion_guards");
}
bool Program_Options::Pragma_Once(void) const{
	return !vm.count("no_pragma_once");
}
//+----------------------------------------------------------+
//| BUILD                                                    |
//+----------------------------------------------------------+
bool Program_Options::Build(void) const{
	return vm.count("build");
}
bool Program_Options::Keep_Object_Files(void) const{
	return !vm.count("no_keep_objects");
}
bool Program_Options::Header_Only(void) const{
	return !vm.count("no_header_only");
}
bool Program_Options::Pre_Compiled_Header(void) const{
	return !vm.count("no_pre_compiled_header");
}
bool Program_Options::Static_Library(void) const{
	return !vm.count("no_static");
}
bool Program_Options::Dynamic_Library(void) const{
	return !vm.count("no_dynamic");
}
bool Program_Options::Windows(void) const{
	return !vm.count("no_windows");
}
bool Program_Options::Linux(void) const{
	return !vm.count("no_linux");
}
//+----------------------------------------------------------+
//| DOCUMENTATION                                            |
//+----------------------------------------------------------+
bool Program_Options::Documentation(void) const{
	return vm.count("documentation");
}
//+----------------------------------------------------------+
//| STATS                                                    |
//+----------------------------------------------------------+
bool Program_Options::Stats(void) const{
	return vm.count("stats");
}
//+----------------------------------------------------------+
//| DATABASE                                                 |
//+----------------------------------------------------------+
bool Program_Options::Database(void) const{
	return vm.count("database");
}
//+----------------------------------------------------------+
//| PROGRAM CUSTOMIZATION                                    |
//+----------------------------------------------------------+
bool Program_Options::Show_Progress(void) const{
	return !vm.count("no_progress");
}
bool Program_Options::Simple_Progress(void) const{
	return vm.count("simple_progress");
}
bool Program_Options::Colors(void) const{
	return !vm.count("no_colors");
}




