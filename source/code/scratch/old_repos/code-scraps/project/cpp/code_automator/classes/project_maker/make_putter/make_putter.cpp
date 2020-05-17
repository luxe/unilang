#include "make_putter.hpp"
#include <string>
#include <sys/stat.h>

const std::string Make_Putter::TOP_RULES_FILE = ".Rules.top";
const std::string Make_Putter::BUILD_SYSTEM_FOLDER = "build_system";
const std::string Make_Putter::MAKEFILE_NAME = "Makefile";
const std::string Make_Putter::PATH_TO_MAKEFILE_FROM_BUILD_SYSTEM_FOLDER{BUILD_SYSTEM_FOLDER + "/" + MAKEFILE_NAME};
const std::string Make_Putter::PATH_TO_MAKEFILE_FROM_BUILD_SYSTEM_FOLDER2{BUILD_SYSTEM_FOLDER};

void Make_Putter::Hard_Link_The_Makefile(std::string const& path){
	
	std::string bdir = build_dir();
	std::string path2 = pwd() +"/"+ path;
	Make_Hard_Link(bdir,path2);
	
	return;
}
void Make_Putter::Make_Hard_Link(std::string const& build_dir, std::string const& run_dir){
	system(("cd " + build_dir + "; ln -P " + MAKEFILE_NAME + " " + run_dir).c_str());
	return;
}

//utility
std::string Make_Putter::pwd_back(std::string const& path){
	
	return pwd("cd " + path + "; cd ..; pwd");
}
std::string Make_Putter::pwd(std::string to_get_path){
	std::string command{to_get_path};
	std::string pwd{exec(command.c_str())};
	std::string pwd2;
	for (auto it = pwd.begin(); it != pwd.end(); ++it){
		if (it == pwd.end()-1 && *it == '\n'){
		}else{pwd2 += *it;}
	}
	
	return pwd2;
}
std::string Make_Putter::top(){
	std::string path{pwd()};
	while (!File_Exists(path + "/" + TOP_RULES_FILE) && path != "/"){
		path = pwd_back(path);
	}
	
	if (!File_Exists(path + "/" + TOP_RULES_FILE) && path == "/"){
		std::cerr << "No " << TOP_RULES_FILE << " file found in the project." << std::endl;
		exit(EXIT_FAILURE);
	}
	
	return path;
}
std::string Make_Putter::build_dir(){
	//std::string path{top()};
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
std::string Make_Putter::exec(const char* cmd) {
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
bool Make_Putter::File_Exists(std::string const& filename) {
    struct stat fileInfo;
    return stat(filename.c_str(), &fileInfo) == 0;
}