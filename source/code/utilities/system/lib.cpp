#include "lib.hpp"
#include "code/utilities/program/call/lib.hpp"
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


static void print_missing_program_error(std::string const& prog){
	std::cerr << "program does not exist: " << prog << std::endl;
	return;
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
		print_missing_program_error(prog);
	}
}
void Exit_With_Error_Message_If_Program_Does_Not_Exist(std::string const& prog)
{
	if (!Does_Program_Exist(prog)){
		print_missing_program_error(prog);
		exit(EXIT_FAILURE);
	}
}