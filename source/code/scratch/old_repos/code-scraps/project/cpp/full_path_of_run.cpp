#include <iostream>
#include <string>
#include <cstdlib>
#include <sys/stat.h>

std::string exec(const char* cmd);
bool File_Exists(std::string const& filename);
std::string Full_Path_Of_Run_Directory(std::string to_get_path="pwd");

int main(int a, char ** b){
	
	std::cout << Full_Path_Of_Run_Directory() << std::endl;
	std::cout << b[0] << std::endl;
	
	return EXIT_SUCCESS;
}

std::string Full_Path_Of_Run_Directory(std::string to_get_path){
	std::string command{to_get_path};
	std::string pwd{exec(command.c_str())};
	std::string pwd2;
	for (auto it = pwd.begin(); it != pwd.end(); ++it){
		if (it == pwd.end()-1 && *it == '\n'){
		}else{pwd2 += *it;}
	}
	
	return pwd2;
}

//utility
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