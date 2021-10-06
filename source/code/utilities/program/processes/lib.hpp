#pragma once
#include <string>

bool Process_Is_Running(std::string const& process_name);
std::string Pid_Of(std::string const& process_name);
std::string Wait_Until_We_Have_A_Pid_Of(std::string const& process_name);
void Send_Ctrl_C_To_Pid(std::string const& pid);

void Bring_Window_Name_Into_Forground(std::string const& name);
void Wait_Until_Window_Name_Is_Brought_Into_Forground(std::string const& name);

