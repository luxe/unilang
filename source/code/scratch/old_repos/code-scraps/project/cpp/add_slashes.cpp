#include <iostream>
#include <string>
#include <cstdlib>
#include "utilities.hpp"
#include <unistd.h>
#include <stdlib.h>

std::string Add_Slashes(std::string const& new_path) {
	std::string str;
	for (auto const& it: new_path) {
		if (it == ' ' || it == '(' || it == ')'){
			str+= ("\\" + it);
		}else{
			str+= it;
		}
	}
	
	
	return str;

}
int main() {
	
	//make the new folder for notes today
	auto number_of_directories = Get_Number_Of_Directories_In_Directory();
	auto new_folder_name = "Day " + std::to_string(number_of_directories+1) + " - " + exec("date +\"%A (%m-%d-%Y)\"");
	exec("mkdir " + std::string("\"") + new_folder_name + std::string("\""));
	
	//step into that directory
	Step_Into_Folder(new_folder_name);
	auto new_path = std::string("\"") + exec("pwd") + std::string("\"");
	
	//NOTE: I don't know how to stay in a directory when the program ends.
	//instead,  I'll make an alias inside a .bashrc file.
	std::cout <<  Add_Slashes(new_path) <<  std::endl;
	//exec("PWD=" + new_path);
	
	
	
	return EXIT_SUCCESS;
}