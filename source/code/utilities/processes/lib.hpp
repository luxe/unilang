#pragma once
#include <string>

bool Process_Is_Running(std::string const& process_name);
std::string Pid_Of(std::string const& process_name);
std::string Wait_Until_We_Have_A_Pid_Of(std::string const& process_name);
void Send_Ctrl_C_To_Pid(std::string const& pid);
//void Send_Ctrl_C_To_Program(std::string const& program_name);

