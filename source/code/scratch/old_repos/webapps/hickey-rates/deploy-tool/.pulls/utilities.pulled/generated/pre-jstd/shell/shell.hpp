#pragma once
#include <string>

//general system calling
std::string exec(std::string const& cmd);
std::string exec(const char* cmd);
std::string execute(std::string const& cmd);
std::string execute(const char* cmd);
std::string exec_quietly(std::string const& cmd);
std::string exec_quietly(const char* cmd);
std::string execute_quietly(std::string const& cmd);
std::string execute_quietly(const char* cmd);
void system(std::string const& cmd);
