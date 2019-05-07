#include "lib.hpp"
#include "code/utilities/shell/lib.hpp"
#include <iostream>

std::string whoami(){
	return execute("whoami");
}
std::string hostname(){
    return execute("hostname");
}
std::string env(){
    return execute("env");
}

bool Does_Program_Exist(std::string const& prog)
{
	std::string command = "hash " + prog;
	if (Silence_Output_And_Get_Return_Value_Of_Running(command) == 0){
		return true;
	}
	return false;
}
void Print_Error_If_Program_Does_Not_Exist(std::string const& prog)
{
	if (!Does_Program_Exist(prog)){
		std::cout << "program does not exist: " << prog << std::endl;
	}
}