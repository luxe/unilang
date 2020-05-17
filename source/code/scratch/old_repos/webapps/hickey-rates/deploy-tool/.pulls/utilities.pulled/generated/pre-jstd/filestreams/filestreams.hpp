#pragma once
#include <string>
#include <vector>
#include <fstream>

//file stream functions
std::vector<std::vector<std::string>> Get_And_Parse_Each_Line_Of_File(std::string const& file);
std::vector<std::vector<std::string>> Continue_Getting_And_Parsing_Each_Line_Of_File(std::ifstream & infile);
