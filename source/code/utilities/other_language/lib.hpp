#pragma once
#include <string>
#include <vector>

//C++ header parsing
bool Is_Header_Include_Line(std::string line);
bool Is_Local_Header_Include_Line(std::string line);
bool Is_System_Header_Include_Line(std::string line);
std::vector<size_t> Get_All_Indexes_Of_Lines_That_Are_Header_Includes(std::vector<std::string> const& lines);
