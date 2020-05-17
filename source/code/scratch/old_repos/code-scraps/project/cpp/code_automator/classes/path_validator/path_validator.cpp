#include "path_validator.hpp"
#include <string>
#include <sys/stat.h>


const std::string Path_Validator::TOP_RULES_FILE = ".Rules.top";
const std::string Path_Validator::TOP_CODE_FILE = ".code_root";
const std::string Path_Validator::BUILD_SYSTEM_FOLDER = "build_system";
const std::string Path_Validator::MAKEFILE_NAME = "Makefile";
const std::string Path_Validator::PATH_TO_MAKEFILE_FROM_BUILD_SYSTEM_FOLDER{BUILD_SYSTEM_FOLDER + "/" + MAKEFILE_NAME};
const std::string Path_Validator::PATH_TO_MAKEFILE_FROM_BUILD_SYSTEM_FOLDER2{BUILD_SYSTEM_FOLDER};
	
void Path_Validator::Make_Sure_Program_Is_Run_In_The_Correct_Directory(Program_Options const& program_options){
	
	//make sure build system is present
	Ensure_Build_System_Is_Present();
	
	
	//---------//
	// PROJECT //
	//---------//
	//if putting a new project, make sure they are not currently in a project
	if (program_options.Task() == "mk_project"){
		if (Is_Top()){
			std::cerr << "You can't build a project inside an already existing project.\n";
			exit(EXIT_FAILURE);
		}
	}
	
	//-------------//
	// OTHER TASKS //
	//-------------//
	else {
		Ensure_Rules_Top_File_Is_Present();
		
		//------//
		// MAIN //
		//------//
		if (program_options.Task() == "mk_main"){      Test_Directory_Of_Task({TOP_CODE_FILE},"You need to be at the root of the code in order to create another main module.");}
		else if (program_options.Task() == "rm_main"){ Test_Directory_Of_Task({TOP_CODE_FILE},"You need to be at the root of the code in order to remove a main module.");}
		else if (program_options.Task() == "rn_main"){ Test_Directory_Of_Task({TOP_CODE_FILE},"You need to be at the root of the code in order to re-name a main module.");}
		else if (program_options.Task() == "cp_main"){ Test_Directory_Of_Task({TOP_CODE_FILE},"You need to be at the root of the code in order to copy a main module.");}
		
		//-------//
		// CLASS //
		//-------//
		else if (program_options.Task() == "mk_class"){Test_Directory_Of_Task({".class_root",TOP_CODE_FILE},"You need to be at the root of a class or the root of the code in order to create another class.");}
		else if (program_options.Task() == "rm_class"){Test_Directory_Of_Task({".class_root",TOP_CODE_FILE},"You need to be at the root of a class or the root of the code in order to remove another class.");}
		else if (program_options.Task() == "rn_class"){Test_Directory_Of_Task({".class_root",TOP_CODE_FILE},"You need to be at the root of a class or the root of the code in order to re-name another class.");}
		else if (program_options.Task() == "cp_class"){Test_Directory_Of_Task({".class_root",TOP_CODE_FILE},"You need to be at the root of a class or the root of the code in order to copy another class.");}
		else if (program_options.Task() == "mv_class"){Test_Directory_Of_Task({".class_root",TOP_CODE_FILE},"You need to be at the root of a class or the root of the code in order to move another class.");}
		
		//------------//
		// ENUM CLASS //
		//------------//
		else if (program_options.Task() == "mk_enum_class"){Test_Directory_Of_Task({".class_root",TOP_CODE_FILE},"You need to be at the root of a class or the root of the code in order to create another enum class.");}
		else if (program_options.Task() == "rm_enum_class"){Test_Directory_Of_Task({".class_root",TOP_CODE_FILE},"You need to be at the root of a class or the root of the code in order to remove another enum class.");}
		else if (program_options.Task() == "rn_enum_class"){Test_Directory_Of_Task({".class_root",TOP_CODE_FILE},"You need to be at the root of a class or the root of the code in order to re-name another enum class.");}
		else if (program_options.Task() == "cp_enum_class"){Test_Directory_Of_Task({".class_root",TOP_CODE_FILE},"You need to be at the root of a class or the root of the code in order to copy another enum class.");}
		else if (program_options.Task() == "mv_enum_class"){Test_Directory_Of_Task({".class_root",TOP_CODE_FILE},"You need to be at the root of a class or the root of the code in order to move another enum class.");}
		
		
	}
	
	return;
}
void Path_Validator::Test_Directory_Of_Task(std::vector<std::string> const& files, std::string const& error_message){
	
	std::string path{pwd()};
	bool found = false;
	for (auto it = files.begin(); it != files.end() && !found; ++it){
		if (File_Exists(path + "/" + *it)){
			found = true;
		}
	}
	
	if (!found){
		std::cerr << error_message << std::endl;
		std::exit(EXIT_FAILURE);
	}
	
	return;
}

bool Path_Validator::Is_Top(){
	bool is_top = true;
	
	std::string path{pwd()};
	while (!File_Exists(path + "/" + TOP_RULES_FILE) && path != "/"){
		path = pwd_back(path);
	}
	
	if (!File_Exists(path + "/" + TOP_RULES_FILE) && path == "/"){
		is_top = false;
	}
	
	return is_top;
}
void Path_Validator::Ensure_Build_System_Is_Present(){
	build_dir();
	return;
}
void Path_Validator::Ensure_Rules_Top_File_Is_Present(){
	top();
	return;
}

//utility
std::string Path_Validator::pwd_back(std::string const& path){
	
	return pwd("cd " + path + "; cd ..; pwd");
}
std::string Path_Validator::pwd(std::string to_get_path){
	std::string command{to_get_path};
	std::string pwd{exec(command.c_str())};
	std::string pwd2;
	for (auto it = pwd.begin(); it != pwd.end(); ++it){
		if (it == pwd.end()-1 && *it == '\n'){
		}else{pwd2 += *it;}
	}
	
	return pwd2;
}
std::string Path_Validator::top(){
	std::string path{pwd()};
	while (!File_Exists(path + "/" + TOP_RULES_FILE) && path != "/"){
		path = pwd_back(path);
	}
	
	if (!File_Exists(path + "/" + TOP_RULES_FILE) && path == "/"){
		std::cerr << "No " << TOP_RULES_FILE << " file found in the project.  Are you sure you are in a project?" << std::endl;
		exit(EXIT_FAILURE);
	}
	
	return path;
}
std::string Path_Validator::build_dir(){
	std::string path{pwd()};
	while (!File_Exists(path + "/" + PATH_TO_MAKEFILE_FROM_BUILD_SYSTEM_FOLDER)  && path != "/"){
		path = pwd_back(path);
	}
	
	if (!File_Exists(path + "/" + PATH_TO_MAKEFILE_FROM_BUILD_SYSTEM_FOLDER) && path == "/"){
		std::cerr << "Could not find the " + BUILD_SYSTEM_FOLDER + " folder." << std::endl;
		exit(EXIT_FAILURE);
	}
	
	path += "/" + PATH_TO_MAKEFILE_FROM_BUILD_SYSTEM_FOLDER2;
	return path;
}
std::string Path_Validator::exec(const char* cmd) {
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
bool Path_Validator::File_Exists(std::string const& filename) {
    struct stat fileInfo;
    return stat(filename.c_str(), &fileInfo) == 0;
}