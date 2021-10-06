//STD Libraries
#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <cstdlib>

namespace {

//functions
std::string Get_GCC_Version(void);

//utility
std::string exec(const char* cmd);
}

int main(){
	
	std::cout << Get_GCC_Version() << std::endl;
	

	return EXIT_SUCCESS;
}

namespace {


//functions
std::string Get_GCC_Version(void){
	std::string command{"gcc -dumpversion"};
	std::string version{exec(command.c_str())};
	std::string version2;
	for (auto it = version.begin(); it != version.end(); ++it){
		if (it == version.end()-1 && *it == '\n'){
		}else{version2 += *it;}
	}
	
	return version2;
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
}

