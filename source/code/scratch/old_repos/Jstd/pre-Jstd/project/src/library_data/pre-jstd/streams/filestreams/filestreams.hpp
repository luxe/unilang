#include <string>
#include <vector>
#include <fstream>

//handling the whole file at once
std::string Read_Entire_File_Into_String(std::string const& file);
std::wstring Read_Entire_File_Into_WString(std::string const& file);
std::vector<std::string> Read_Each_Line_Of_File_Into_Vector(std::string const& file);
void Write_Each_Line_Of_Vector_Into_File(std::vector<std::string> const& vec, std::string const& file);
std::vector<std::vector<std::string>> Read_Each_Line_Of_File_Into_Vector_Split_Chunks_By_Empty_Line(std::string const& file);
std::vector<std::vector<std::string>> Get_And_Parse_Each_Line_Of_File(std::string const& file); //basically how cin works
std::vector<std::pair<char,int>> Get_Comma_Seperated_Values_From_File_Where_Each_Value_Is_A_Pair_Of_Char_Int(std::string const& file);



    //getting portions
    std::string Get_First_Line_Of_File(std::string const& file);
    std::string Get_Last_Line_Of_File(std::string const& file);
    std::string Get_Nth_Line_Of_File(std::string const& file, unsigned int line_number);


//handling parts of the filestream
std::vector<std::vector<std::string>> Continue_Getting_And_Parsing_Each_Line_Of_File(std::ifstream & infile);
std::string Get_Line(std::ifstream & infile, char const& delim = '\n');
std::string Get_Rest_Of_File_As_String(std::ifstream & infile);

//printing (handles conversions automatically)
void Print_To_Stream_With_Newline(std::wofstream & outfile, std::wstring const& str);
void Print_To_Stream_With_Newline(std::wofstream & outfile, std::string const& str);
void Print_To_Stream_With_Newline(std::ofstream & outfile, std::string const& str);
void Print_To_Stream_With_Newline(std::ofstream & outfile, std::wstring const& str);
void Print_To_Stream_With_Newline_Only_If_There_Is_Content(std::wofstream & outfile, std::wstring const& str);
void Print_To_Stream_With_Newline_Only_If_There_Is_Content(std::wofstream & outfile, std::string const& str);
void Print_To_Stream_With_Newline_Only_If_There_Is_Content(std::ofstream & outfile, std::string const& str);
void Print_To_Stream_With_Newline_Only_If_There_Is_Content(std::ofstream & outfile, std::wstring const& str);

void Print_To_Stream(std::wofstream & outfile, std::wstring const& str);
void Print_To_Stream(std::wofstream & outfile, std::string const& str);
void Print_To_Stream(std::ofstream & outfile, std::string const& str);
void Print_To_Stream(std::ofstream & outfile, std::wstring const& str);

void Print_Newline_To_Stream(std::wofstream & outfile);
void Print_Newline_To_Stream(std::ofstream & outfile);

void Print_To_Stream_N_Times(std::wofstream & outfile, std::wstring const& str, unsigned int amount);
void Print_To_Stream_N_Times(std::wofstream & outfile, std::string const& str, unsigned int amount);
void Print_To_Stream_N_Times(std::ofstream & outfile, std::string const& str, unsigned int amount);
void Print_To_Stream_N_Times(std::ofstream & outfile, std::wstring const& str, unsigned int amount);
