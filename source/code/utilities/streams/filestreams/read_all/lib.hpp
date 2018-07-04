#pragma once
#include <string>
#include <vector>
#include <fstream>

//handling the whole file at once
std::string Read_Entire_File_Into_String(std::string const& file);
std::wstring Read_Entire_File_Into_WString(std::string const& file);
std::vector<std::string> Read_Each_Line_Of_File_Into_Vector(std::string const& file);
std::vector<std::vector<std::string>> Read_Each_Line_Of_File_Into_Vector_Split_Chunks_By_Empty_Line(std::string const& file);
std::vector<std::vector<std::string>> Get_And_Parse_Each_Line_Of_File(std::string const& file); //basically how cin works
std::vector<std::pair<char,int>> Get_Comma_Seperated_Values_From_File_Where_Each_Value_Is_A_Pair_Of_Char_Int(std::string const& file);