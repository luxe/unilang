#pragma once
#include <string>
#include <vector>
#include <fstream>

//handling the whole file at once
std::string Read_Entire_File_Into_String(std::string const& file);
std::vector<std::string> Read_Each_Line_Of_File_Into_Vector(std::string const& file);
std::vector<std::vector<std::string>> Read_Each_Line_Of_File_Into_Vector_Split_Chunks_By_Empty_Line(std::string const& file);
std::vector<std::vector<std::string>> Get_And_Parse_Each_Line_Of_File(std::string const& file); //basically how cin works


    //getting portions
    std::string Get_First_Line_Of_File(std::string const& file);
    std::string Get_Last_Line_Of_File(std::string const& file);
    std::string Get_Nth_Line_Of_File(std::string const& file, unsigned int line_number);


//handling parts of the filestream
std::vector<std::vector<std::string>> Continue_Getting_And_Parsing_Each_Line_Of_File(std::ifstream & infile);
std::string Get_Line(std::ifstream & infile, char const& delim = '\n');
std::string Get_Rest_Of_File_As_String(std::ifstream & infile);
