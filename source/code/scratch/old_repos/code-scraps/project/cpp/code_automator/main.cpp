/*
	This is the main module of the code base's code automater.
	Basically, you NEED to use this tool for almost everything except editing files.
	This program will be an essential component to using and working in the code base.
	Since the command line options may be a bit verbose and difficult to remember, I
	expect this program to be called by a front-end interface- preferably a browser's
	CGI program.
	
	This program will be capable of (ALL ARE STILL IN PROGRESS):
		- Creating New Projects
		- Creating New Main Modules
		- Creating New Classes
		- Customizing/Creating A Program Options Class
		- Customizing/Creating New Enum Classes
		- Automatically Maintaining Class Dependencies
		- Automatically Linking Libraries Based On Include Files
		- Available To Export Code Base In Various Ways
		
			* I understand the initial format of the code base
			* is not very standard or understood.  It also contains
			* a lot of directories and files. This is done in order 
			* to separate complexity, make some things automated, and 
			* to provide a better static analysis.

Sometimes This program does need additional input, such as: "Are you sure you want to overwrite this file?"
I'm not sure how to prompt the user's browser, have them respond, and then continue off in the program.

*/

//STD Libraries
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <vector>
#include <utility>
#include <limits>

//system library
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

//My Classes
#include "classes/program_options/program_options.hpp"
#include "classes/project_maker/project_maker.hpp"
#include "classes/class_maker/class_maker.hpp"
#include "classes/enum_maker/enum_maker.hpp"
#include "classes/enum_updater/enum_updater.hpp"
#include "classes/main_maker/main_maker.hpp"
#include "classes/command_line_validator/command_line_validator.hpp"
#include "classes/path_validator/path_validator.hpp"
#include "classes/run_location_info/run_location_info.hpp"
#include "classes/project_maintainer/project_maintainer.hpp"

namespace{
//=================================================================
namespace constants{
}
//functions
void Decide_What_To_Do_Based_On_Program_Options(Program_Options const& program_options);

	//Project Tasks
	void Perform_MK_Project(std::string const& str_project_names, std::string const& str_main_module_names);

	//Main Tasks
	void Perform_MK_Main(std::string const& str_main_names);
	
	void Perform_RM_Main(std::string const& str_main_names);
		void Warn_About_Missing_Modules_Specified_For_Deletion(std::vector<std::string> const& folder_names);
		
	void Perform_RN_Main(std::string const& str_main_names);
		bool Avoid_Renaming_A_Main_Module(std::pair<std::string,std::string> const& main_module_pair);
		void Update_Main_Module_Rules_From_RN(std::pair<std::string,std::string> const& main_module_pair);
		
	void Perform_CP_Main(std::string const& str_main_names);
		bool Avoid_Copying_A_Main_Module(std::pair<std::string,std::string> const& main_module_pair);

	//Class Tasks
	void Perform_MK_Class(std::string const& str_class_names);
	void Perform_RM_Class(std::string const& str_class_names);
	void Perform_RN_Class(std::string const& str_class_names);
	void Perform_CP_Class(std::string const& str_class_names);
	void Perform_MV_Class(std::string const& str_class_names);

	//Enum Class Tasks
	void Perform_MK_Enum_Class(std::string const& str_class_names);
	void Perform_RM_Enum_Class(std::string const& str_class_names);
	void Perform_RN_Enum_Class(std::string const& str_class_names);
	void Perform_CP_Enum_Class(std::string const& str_class_names);
	void Perform_MV_Enum_Class(std::string const& str_class_names);

//utility
void Avoid_Overwriting_Projects(std::vector<std::string> & folder_names);
void Avoid_Overwriting_Main_Modules(std::vector<std::string> & folder_names);
void Avoid_Overwriting_Classes(std::vector<std::string> & folder_names);
std::string Get_Back_Track_To_Code_Root(void);
std::string pwd_back(std::string const& path);
std::string exec(const char* cmd);
std::string pwd(std::string to_get_path="pwd");
bool File_Exists(std::string const& filename);
template <typename T> void Sort_And_Remove_Duplicates(std::vector<T>& vec);
std::vector<std::string> Extract_Names(std::string const& str);
std::vector<std::pair<std::string,std::string>> Extract_Paired_Names(std::string const& str);
//=================================================================
}

int main(int argc, char** argv){
	
	//read in command line parameters and make sure a valid task has been chosen
	Program_Options program_options(argc,argv);
	Command_Line_Validator::Validate_Task_Flag(program_options);
	
	//make sure the user is in an appropriate directory in regards to the task chosen
	Path_Validator::Make_Sure_Program_Is_Run_In_The_Correct_Directory(program_options);
	
	//perform the task specified (assume we are in the correct directory)
	Decide_What_To_Do_Based_On_Program_Options(program_options);
	
	return EXIT_SUCCESS;
}

namespace{
//=================================================================
//functions
void Decide_What_To_Do_Based_On_Program_Options(Program_Options const& program_options){
	
	//Project Tasks
	if (program_options.Task()     == "mk_project"       ){Perform_MK_Project(program_options.Project_Names(), program_options.Main_Module_Names());}
	
	//Main Tasks
	else if(program_options.Task() == "mk_main"          ){Perform_MK_Main(program_options.Main_Module_Names());}
	else if(program_options.Task() == "rm_main"          ){Perform_RM_Main(program_options.Main_Module_Names());}
	else if(program_options.Task() == "rn_main"          ){Perform_RN_Main(program_options.Main_Module_Names());}
	else if(program_options.Task() == "cp_main"          ){Perform_CP_Main(program_options.Main_Module_Names());}
	
	//Class Tasks
	else if(program_options.Task() == "mk_class"         ){Perform_MK_Class(program_options.Class_Names());}
	else if(program_options.Task() == "rm_class"         ){Perform_RM_Class(program_options.Class_Names());}
	else if(program_options.Task() == "rn_class"         ){Perform_RN_Class(program_options.Class_Names());}
	else if(program_options.Task() == "cp_class"         ){Perform_CP_Class(program_options.Class_Names());}
	else if(program_options.Task() == "mv_class"         ){Perform_MV_Class(program_options.Class_Names());}
	
	//Enum Class Tasks
	else if(program_options.Task() == "mk_enum_class"    ){Perform_MK_Enum_Class(program_options.Enum_Class_Names());}
	else if(program_options.Task() == "rm_enum_class"    ){Perform_RM_Enum_Class(program_options.Enum_Class_Names());}
	else if(program_options.Task() == "rn_enum_class"    ){Perform_RN_Enum_Class(program_options.Enum_Class_Names());}
	else if(program_options.Task() == "cp_enum_class"    ){Perform_CP_Enum_Class(program_options.Enum_Class_Names());}
	else if(program_options.Task() == "mv_enum_class"    ){Perform_MV_Enum_Class(program_options.Enum_Class_Names());}
	
	return;
}


//Project Tasks
void Perform_MK_Project(std::string const& str_project_names, std::string const& str_main_module_names){
	
	//turn the two strings from the command line into a vector of names so that they are easier to work with
	std::vector<std::string> project_names = Extract_Names(str_project_names);
	std::vector<std::string> main_module_names = Extract_Names(str_main_module_names);
	
	//error out if there are no project names
	//add "main" as a module name, if no module names have been specified
	Command_Line_Validator::Validate_MK_Project_Flags(project_names, main_module_names);
	
	//sort and remove duplicates
	Sort_And_Remove_Duplicates(project_names);
	Sort_And_Remove_Duplicates(main_module_names);
	
	//remove any projects the user doesn't want to overwrite
	Avoid_Overwriting_Projects(project_names);
	
	//create projects
	for (auto project: project_names){
		Project_Maker::Create_Project(project, main_module_names);
		Project_Maintainer::Update_All_Main_Module_Direct_Relationships(project+"/code");
		Project_Maintainer::Update_All_Main_Module_Headers(project+"/code");
		Project_Maintainer::Update_All_Main_Module_Namespaces(project+"/code");
	}
	
	return;
}

//Main Tasks
void Perform_MK_Main(std::string const& str_main_names){
	
	//turn the strings from the command line into a vector of names so that they are easier to work with
	std::vector<std::string> main_module_names = Extract_Names(str_main_names);
	
	//error out if there are no main module names specified
	Command_Line_Validator::Validate_MK_Main_Flags(main_module_names);
	
	//sort and remove duplicates
	Sort_And_Remove_Duplicates(main_module_names);
	
	//remove any main modules the user doesn't want to overwrite
	Avoid_Overwriting_Main_Modules(main_module_names);
	
	//create main modules
	for (auto main_module: main_module_names){
		Main_Maker::Create_Main_Folder("main_modules/" + main_module +"/",main_module);
		Project_Maintainer::Update_All_Main_Module_Direct_Relationships(".");
		Project_Maintainer::Update_All_Main_Module_Headers(".");
		Project_Maintainer::Update_All_Main_Module_Namespaces(".");
		Project_Maintainer::Update_Main_Modules_Root_Rules_File(".");
	}
	
	return;
}
void Perform_RM_Main(std::string const& str_main_names){
	
	//turn the strings from the command line into a vector of names so that they are easier to work with
	std::vector<std::string> main_module_names = Extract_Names(str_main_names);
	
	//error out if there are no main module names specified
	Command_Line_Validator::Validate_RM_Main_Flags(main_module_names);
	
	//sort and remove duplicates
	Sort_And_Remove_Duplicates(main_module_names);
	
	//If a folder isn't there, it obviously can't be deleted.  Warn them if it isn't there.
	Warn_About_Missing_Modules_Specified_For_Deletion(main_module_names);
	
	//delete main module
	for (auto main_module: main_module_names){
		system(("rm -rf main_modules/" + main_module).c_str());
		Project_Maintainer::Update_Main_Modules_Root_Rules_File(".");
	}
	
	return;
}
void Warn_About_Missing_Modules_Specified_For_Deletion(std::vector<std::string> const& folder_names){
	
	for (auto dir = folder_names.begin(); dir != folder_names.end(); ++dir){
		if (!File_Exists("main_modules/" + *dir)){
			std::cerr << "can't delete main module: " << *dir << " because it does not exist.\n";
		}
	}
	
	return;
}
void Perform_RN_Main(std::string const& str_main_names){
	
	//turn the strings from the command line into a vector of paired names so that they are easier to work with
	//Note: this function will warn if there is an odd number of main modules specified.
	std::vector<std::pair<std::string,std::string>> rename_list = Extract_Paired_Names(str_main_names);
	
	//error out if there are no main module names specified
	Command_Line_Validator::Validate_RN_Main_Flags(rename_list);
	
	//sort and remove duplicates
	Sort_And_Remove_Duplicates(rename_list);
	
	//rename main module
	for (auto main_module_pair: rename_list){
		if (main_module_pair.first != main_module_pair.second){
			if (File_Exists("main_modules/" + main_module_pair.first)){
				
				//avoid an overwite
				if (!Avoid_Renaming_A_Main_Module(main_module_pair)){
					/* rename folder */ system(("mv main_modules/" + main_module_pair.first + "/ main_modules/" + main_module_pair.second).c_str());
					/* rename cpp file */ system(("mv main_modules/" + main_module_pair.second + "/main/" + main_module_pair.first + ".cpp " + "main_modules/" + main_module_pair.second + "/main/"+ main_module_pair.second + ".cpp").c_str());
					/* update Rules file */ Update_Main_Module_Rules_From_RN(main_module_pair);
					Project_Maintainer::Update_All_Main_Module_Namespaces(".");
				}
			}
			else{
				std::cerr << "can't rename main module: " << main_module_pair.first << " to " << main_module_pair.second << " because it does not exist.\n";
			}
		}else{
			std::cerr << "can't rename main module: " << main_module_pair.first << " to itself.\n";
		}
	}
	Project_Maintainer::Update_Main_Modules_Root_Rules_File(".");
	
	return;
}
bool Avoid_Renaming_A_Main_Module(std::pair<std::string,std::string> const& main_module_pair){
	
	bool removed = false;
	if (File_Exists("main_modules/" + main_module_pair.second)){
		char input;
		std::cout << main_module_pair.second << " already exists. Overwrite it by renaming " << main_module_pair.first << "? (y/n) ";
		std::cin >> input;
		if (tolower(input) == 'y'){
			removed = true;
			system(("rm -rf main_modules/" + main_module_pair.second).c_str());
			using namespace std;
			cin.ignore( numeric_limits <streamsize> ::max(), '\n' );
		}
	}
	
	return removed;
}
void Update_Main_Module_Rules_From_RN(std::pair<std::string,std::string> const& main_module_pair){
	std::string all;
	std::string line;
	std::ifstream infile("main_modules/" + main_module_pair.second + "/main/.Rules.mk");
	std::getline(infile,line);
	while (infile){
		
		
		
		//fix TARGETS line
		if (line.substr(0, (std::string("TARGETS := ")).size()) == "TARGETS := "){
			all += "TARGETS := " + main_module_pair.second + '\n';
		}
		
		//fix main_DEPS
		else if(line.substr(0, (std::string(main_module_pair.first + "_DEPS = " + main_module_pair.first + ".o ")).size()) == std::string(main_module_pair.first + "_DEPS = " + main_module_pair.first + ".o ")){
			line.erase(0,std::string(main_module_pair.first + "_DEPS = " + main_module_pair.first + ".o ").size());
			line = std::string(main_module_pair.second + "_DEPS = " + main_module_pair.second + ".o ") + line + '\n';
			all += line;
		}
		
		//fix main_LIBS
		else if(line.substr(0, (std::string(main_module_pair.first + "_LIBS = ")).size()) == std::string(main_module_pair.first + "_LIBS = ")){
			line.erase(0,std::string(main_module_pair.first + "_LIBS = ").size());
			line = std::string(main_module_pair.second + "_LIBS = ") + line + '\n';
			all += line;
		}
		
		//all other lines
		else{
			all += line + '\n';
		}
		
		
		std::getline(infile,line);
	}
	
	infile.close();
	std::ofstream outfile("main_modules/" + main_module_pair.second + "/main/.Rules.mk");
	outfile << all;
	
	return;
}
void Perform_CP_Main(std::string const& str_main_names){
	
	//turn the strings from the command line into a vector of paired names so that they are easier to work with
	//Note: this function will warn if there is an odd number of main modules specified.
	std::vector<std::pair<std::string,std::string>> copy_list = Extract_Paired_Names(str_main_names);
	
	//error out if there are no main module names specified
	Command_Line_Validator::Validate_CP_Main_Flags(copy_list);
	
	//sort and remove duplicates
	Sort_And_Remove_Duplicates(copy_list);
	
	//copy main module
	for (auto main_module_pair: copy_list){
		if (main_module_pair.first != main_module_pair.second){
			if (File_Exists("main_modules/" + main_module_pair.first)){
				
				//avoid an overwite
				if (!Avoid_Copying_A_Main_Module(main_module_pair)){
					/* rename folder */ system(("cp -R main_modules/" + main_module_pair.first + "/ main_modules/" + main_module_pair.second).c_str());
					/* rename cpp file */ system(("mv main_modules/" + main_module_pair.second + "/main/" + main_module_pair.first + ".cpp " + "main_modules/" + main_module_pair.second + "/main/"+ main_module_pair.second + ".cpp").c_str());
					/* update Rules file */ Update_Main_Module_Rules_From_RN(main_module_pair);
					Project_Maintainer::Update_All_Main_Module_Namespaces(".");
				}
				
			}
			else{
				std::cerr << "can't copy main module: " << main_module_pair.first << " to " << main_module_pair.second << " because it does not exist.\n";
			}
			
		}else{
			std::cerr << "can't copy main module: " << main_module_pair.first << " to itself.\n";
		}
	}
	Project_Maintainer::Update_Main_Modules_Root_Rules_File(".");
	
	
	return;
}
bool Avoid_Copying_A_Main_Module(std::pair<std::string,std::string> const& main_module_pair){
	
	bool removed = false;
	if (File_Exists("main_modules/" + main_module_pair.second)){
		char input;
		std::cout << main_module_pair.second << " already exists. Overwrite it by coying " << main_module_pair.first << "? (y/n) ";
		std::cin >> input;
		if (tolower(input) == 'y'){
			removed = true;
			system(("rm -rf main_modules/" + main_module_pair.second).c_str());
			using namespace std;
			cin.ignore( numeric_limits <streamsize> ::max(), '\n' );
		}
	}
	
	return removed;
}

//Class Tasks
void Perform_MK_Class(std::string const& str_class_names){
	
	//turn the strings from the command line into a vector of names so that they are easier to work with
	std::vector<std::string> class_names = Extract_Names(str_class_names);
	
	//error out if there are no main module names specified
	Command_Line_Validator::Validate_MK_Class_Flags(class_names);
	
	//sort and remove duplicates
	Sort_And_Remove_Duplicates(class_names);
	
	//remove any main modules the user doesn't want to overwrite
	Avoid_Overwriting_Classes(class_names);
	
	
	std::string put_dir = "classes/";
	if (File_Exists(".class_root")){put_dir = "class/direct_relationships/";}
	
	std::string back_track = Get_Back_Track_To_Code_Root();
	
	//create classes
	for (auto class_name: class_names){
		Class_Maker::Make_Class(put_dir,class_name);
	}
	
	Project_Maintainer::Update_Class_Sub_Directory(put_dir);
	if (File_Exists(".code_root")){
		Project_Maintainer::Update_All_Main_Module_Direct_Relationships(back_track);
		Project_Maintainer::Update_All_Main_Module_Headers(back_track);
		Project_Maintainer::Update_All_Main_Module_Direct_Relationships_Rules_File(back_track);
		Project_Maintainer::Update_All_Main_Module_Namespaces(".");
	}
	
	//update main_module object dependencies
	Project_Maintainer::Update_All_Main_Module_Dependencies(back_track);
	
	//update driver object dependencies
	
	//update  main_module linked libraries (will have to look at header files and such)
	
	//update  driver linked libraries (will have to look at header files and such)
	
	return;
}
void Perform_RM_Class(std::string const& str_class_names){
	
	return;
}
void Perform_RN_Class(std::string const& str_class_names){
	
	return;
}
void Perform_CP_Class(std::string const& str_class_names){
	
	return;
}
void Perform_MV_Class(std::string const& str_class_names){
	
	return;
}

//Enum Class Tasks
void Perform_MK_Enum_Class(std::string const& str_class_names){
	
	return;
}
void Perform_RM_Enum_Class(std::string const& str_class_names){
	
	return;
}
void Perform_RN_Enum_Class(std::string const& str_class_names){
	
	return;
}
void Perform_CP_Enum_Class(std::string const& str_class_names){
	
	return;
}
void Perform_MV_Enum_Class(std::string const& str_class_names){
	
	return;
}

//utility
void Avoid_Overwriting_Projects(std::vector<std::string> & folder_names){
	
	char input;
	for (auto dir = folder_names.begin(); dir != folder_names.end();){
		if (File_Exists(*dir)){
			std::cout << *dir << " already exists. Overwrite? (y/n) ";
			std::cin >> input;
			if (tolower(input) != 'y'){
				folder_names.erase(dir);
			}else{
				system(("rm -rf " + *dir).c_str());
				++dir;
				using namespace std;
				cin.ignore( numeric_limits <streamsize> ::max(), '\n' );
			}
		}else{++dir;}
	}
	
	return;
}
void Avoid_Overwriting_Main_Modules(std::vector<std::string> & folder_names){
	
	char input;
	for (auto dir = folder_names.begin(); dir != folder_names.end();){
		if (File_Exists("main_modules/" + *dir)){
			std::cout << *dir << " already exists. Overwrite? (y/n) ";
			std::cin >> input;
			if (tolower(input) != 'y'){
				folder_names.erase(dir);
			}else{
				system(("rm -rf main_modules/" + *dir).c_str());
				++dir;
				using namespace std;
				cin.ignore( numeric_limits <streamsize> ::max(), '\n' );
			}
		}else{++dir;}
	}
	
	return;
}
void Avoid_Overwriting_Classes(std::vector<std::string> & folder_names){
	
	char input;
	std::string look_dir = "classes/";
	if (File_Exists(".class_root")){
		look_dir = "class/direct_relationships/";
	}
	
	for (auto dir = folder_names.begin(); dir != folder_names.end();){
		if (File_Exists(look_dir + *dir)){
			std::cout << *dir << " already exists. Overwrite? (y/n) ";
			std::cin >> input;
			if (tolower(input) != 'y'){
				folder_names.erase(dir);
			}else{
				system(("rm -rf " + look_dir + *dir).c_str());
				++dir;
				using namespace std;
				cin.ignore( numeric_limits <streamsize> ::max(), '\n' );
			}
		}else{++dir;}
	}
	
	return;
}
std::string Get_Back_Track_To_Code_Root(void){
	std::string bt = ".";
	if (!File_Exists(".code_root")){
		std::string p = pwd();
		bt = "../";
		p = pwd_back(p);
		while (!File_Exists(p + "/.code_root") && p != "/"){
			bt +="../";
			p = pwd_back(p);
		}
		
		if (p == "/"){
			std::cerr << "root of code was not found because no .code_root was located\n";
			exit(EXIT_FAILURE);
		}
	}
	
	return bt;
}
std::string pwd_back(std::string const& path){
	
	return pwd("cd " + path + "; cd ..; pwd");
}
std::string pwd(std::string to_get_path){
	std::string command{to_get_path};
	std::string pwd{exec(command.c_str())};
	std::string pwd2;
	for (auto it = pwd.begin(); it != pwd.end(); ++it){
		if (it == pwd.end()-1 && *it == '\n'){
		}else{pwd2 += *it;}
	}
	
	return pwd2;
}
std::string exec(const char* cmd) {
    FILE* pipe = popen(cmd, "r");
    if (!pipe) return "ERROR";
    char buffer[128];
    std::string result = "";
    while(!feof(pipe)) {
    	if(fgets(buffer, 128, pipe) != NULL)
    		result += buffer;
    }
    pclose(pipe);
    return result;
}
bool File_Exists(std::string const& filename) {
    struct stat fileInfo;
    return stat(filename.c_str(), &fileInfo) == 0;
}
template <typename T> void Sort_And_Remove_Duplicates(std::vector<T>& vec){
  std::sort(vec.begin(), vec.end());
  vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
}
std::vector<std::string> Extract_Names(std::string const& str){
	std::vector<std::string> vec;
		std::string temp;
		
	//extract names from the input str
	for (auto character: str){
		if (character == ' '){
			if (temp != ""){
				vec.push_back(temp);
			}
			temp.clear();
		}else{
			temp+=character;
		}
	}
	if (temp != ""){
		vec.push_back(temp);
	}
	
	return vec;
}
std::vector<std::pair<std::string,std::string>> Extract_Paired_Names(std::string const& str){
	std::vector<std::pair<std::string,std::string>> pairs;
	std::pair<std::string,std::string> pair_temp;
	std::string temp;
	bool second = false;
	
	//extract pairs from the input str
	for (auto character: str){
		if (character == ' '){
			if (temp != ""){
				if (!second){
					//fist pair
					pair_temp.first = temp;
					second = true;
				}
				else{
					//second pair
					pair_temp.second = temp;
					second = false;
					pairs.push_back(pair_temp);
					pair_temp.first = "";
					pair_temp.second = "";
				}
				temp.clear();
			}
		}else{
			temp+=character;
		}
	}
	
	if (temp != "" && pair_temp.first == ""){
		std::cerr << temp << " will be ignored because a new name for the main module was not provided.\n";
	}
	else if (pair_temp.first != ""){
		if (temp != ""){
			//good
			pair_temp.second = temp;
			pairs.push_back(pair_temp);
		}else{
			//bad
			std::cerr << pair_temp.first << " will be ignored because a new name for the main module was not provided.\n";
		}
	}
	
			
	
	
	
	return pairs;
}
//=================================================================
}




