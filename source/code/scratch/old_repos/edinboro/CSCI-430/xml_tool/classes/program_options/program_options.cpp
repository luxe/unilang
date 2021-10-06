#include "program_options.h"

const std::string Program_OptionsT::VERSION_NUMBER = "1";

//These functions parse through the command line data entered by the user and store that data into appropriate containers
Program_OptionsT::Program_OptionsT(int const& argc, char** const& argv): indent{4}
{
    using namespace boost::program_options;
    
    //build all the possible flags and add description.
    //file is a possitional argument
    options_description desc (Get_Options_Description());
    positional_options_description pod;
    pod.add("file",-1);
    
    //process all of the user flag data and store it appropriately
    variables_map vm (Get_Variable_Map(argc, argv, desc, pod));
    Process_Immediate_Options(vm,desc);
    Store_Remaining_Options(vm,desc);
}
boost::program_options::options_description Program_OptionsT::Get_Options_Description(void){
    using namespace boost::program_options;
    
    //Program Description
    options_description desc("This program can read an xml file into memory and perform queries on the data.\n\nUsage: xml_tool [Options] [FILE ...]\n\nOptions");
    
    //Program Flags
    desc.add_options()
    ( "file,f",value<std::vector<std::string>>()->multitoken(),"name of the xml file(s) to parse")
    ("print,p","print the entire tree, including attributes")
    ("height","print the height of the tree")
    ("printtag,t",value<std::vector<std::string>>()->multitoken(),"find all occurrences of given tag and print the corresponding data values.")
    ("find,x",value<std::vector<std::string>>()->multitoken(),"print a message stating if the given tag and value pair exist.")
    ("printsubtree,s",value<std::vector<std::string>>()->multitoken(),"Starting at a tag with the associated data value, print the first occurrence of the tag-value pair")
    ("printattributes,a",value<std::vector<std::string>>()->multitoken(),"Print all attributes for a given tag-value pair")
    ("indent,i",value<unsigned int>(),"Set the indent level of the tree")
	("help,h","produce this help message")
    ("version,v","display the xml reader version");

    return desc;
}
boost::program_options::variables_map Program_OptionsT::Get_Variable_Map(int const& argc, char** const& argv, boost::program_options::options_description const& desc, boost::program_options::positional_options_description const& pod){
    using namespace boost::program_options;
    
    //store user flag data.  crash elegantly if they pass incorrect flags.
    variables_map vm;
    try{
        store(command_line_parser(argc, argv).options(desc).positional(pod).run(), vm);
        notify(vm);
    }
    catch(error& e){
        std::cerr << "ERROR: " << e.what() << std::endl; 
        std::cerr << desc << std::endl; 
        exit(EXIT_FAILURE);
    }

    return vm;
}
void Program_OptionsT::Process_Immediate_Options(boost::program_options::variables_map const& vm, boost::program_options::options_description const& desc){

    //do not continue the program if the user wanted to see the version or help data
    if (vm.count("version")){
        std::cout << "\nThis is version " << VERSION_NUMBER << " of the XML Tool.\n\n";
        exit(EXIT_SUCCESS);
    }
    else if (vm.count("help") || !vm.count("file")){
        std::cout << '\n' << desc << '\n';
        exit(EXIT_SUCCESS);
    }
    
    return;
}
void Program_OptionsT::Store_Remaining_Options(boost::program_options::variables_map const& vm, boost::program_options::options_description const& desc){
    
    //take program option data out of the boost variable map and store them in appropriate containers
    //TODO: everything should stay in the boost variable map.. just have the observer functions extract them
    if (vm.count("file")){
        files = vm["file"].as<std::vector<std::string>>();
    }
    if (vm.count("print")){
        print = true;
    }
    if (vm.count("height")){
        height = true;
    }
    if (vm.count("printtag")){
        tags = vm["printtag"].as<std::vector<std::string>>();
    }
    if (vm.count("find")){
        find = Build_Pairs(vm["find"].as<std::vector<std::string>>(),desc);
    }
    if (vm.count("printsubtree")){
        subtrees = Build_Pairs(vm["printsubtree"].as<std::vector<std::string>>(),desc);
    }
    if (vm.count("printattributes")){
        attributes = Build_Pairs(vm["printattributes"].as<std::vector<std::string>>(),desc);
    }
    if (vm.count("indent")){
		indent = vm["indent"].as<unsigned int>();
	}
    
    return;
}
std::vector<std::pair<std::string,std::string>> Program_OptionsT::Build_Pairs(std::vector<std::string> option_values, boost::program_options::options_description const& desc){
    
    //store paired data. crash elegantly on missing pair values.
    std::vector<std::pair<std::string,std::string>> paired_list;
    
    if (Is_Odd(option_values.size())){
        std::cerr << '\n' << "Malformed Flag! " << option_values[option_values.size()-1] << " is missing a corresponding value.\n\n" << desc << '\n';
        exit(EXIT_FAILURE);
    }
    for (auto it = option_values.begin(); it != option_values.end(); ++it){
        
        std::string first{*it};
        ++it;
        std::string second{*it};
        
        paired_list.push_back(std::make_pair(first, second));
    }
    
    return paired_list;
}
bool Program_OptionsT::Is_Odd(int num){
    return (num % 2);
}

//Obervers
std::vector<std::string> Program_OptionsT::Program_OptionsT::Get_Files(void){
    return files;
}
std::vector<std::string> Program_OptionsT::Get_Tags(void){
    return tags;
}
std::vector<std::pair<std::string,std::string>> Program_OptionsT::Get_Finds(void){
    return find;
}
std::vector<std::pair<std::string,std::string>> Program_OptionsT::Get_Subtrees(void){
    return subtrees;
}
std::vector<std::pair<std::string,std::string>> Program_OptionsT::Get_Attributes(void){
    return attributes;
}
bool Program_OptionsT::Interactive(void){
    
   //interactive mode is on when the file flag is the only option given a value.
    bool interactive{false};
    if (tags.empty() && find.empty() && subtrees.empty() && attributes.empty() && !print &!height){
        interactive = true;
    }
    
    return interactive;
}
unsigned int Program_OptionsT::Get_Indent(void){
	return indent;
}
bool Program_OptionsT::Height(void){
	return height;
}
bool Program_OptionsT::Print(void){
	return print;
}
