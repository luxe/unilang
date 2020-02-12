#include "code/utilities/streams/filestreams/lib.hpp"
#include "code/utilities/types/strings/observers/front_back/lib.hpp"
#include "code/utilities/types/strings/observers/converting/lib.hpp"
#include "code/utilities/types/converters/lib.hpp"
#include "code/utilities/types/general/lib.hpp"
#include <streambuf>

//file stream functions
void Write_Each_Line_Of_Vector_Into_File(std::vector<std::string> const& vec, std::string const& file){
	std::ofstream outfile(file);
	
	Call_Function_On_All_Elements_Except_Last_Element_Then_Call_Function_On_Last_Element(vec
	,[&](auto it){
		outfile << it << '\n';
	}
	,[&](auto it){
		outfile << it;
	});
}
std::vector<std::vector<std::string>> Continue_Getting_And_Parsing_Each_Line_Of_File(std::ifstream & infile) {

	std::string line;
	std::string part;
	std::vector<std::string> parts;
	std::vector<std::vector<std::string>> all_lines;
	std::getline(infile, line);
	while (infile) {

		//parse and store
		bool c_found = false;
		bool in_string = false;
		for (auto const& c: line) {

			//if we have a character or a space inside a string
			if (c != ' '  || in_string) {


				// record the start or end of a string
				if (c == '"') {
					if (in_string) {
						in_string = false;
					}else{
						in_string = true;
					}
				}else{

					//store the other non quote characters
					c_found = true;
					part += c;
				}

			}else{
				if (c_found) {
					parts.push_back(part);
					c_found = false;
					part.clear();
				}
			}
		}

		if (!part.empty()) {
			parts.push_back(part);
			c_found = false;
			part.clear();
		}

		all_lines.push_back(parts);
		parts.clear();


		std::getline(infile, line);
	}

	return all_lines;
}
std::string Get_Line(std::ifstream & infile, char const& delim){
	std::string str;
	std::getline(infile,str,delim);
	return str;
}
std::string Get_Rest_Of_File_As_String(std::ifstream & infile){
	std::string data;
	char temp = infile.get();
	while(infile){
		data+=temp;
		temp = infile.get();
	}

	return data;
}

std::string Get_First_Line_Of_File(std::string const& file){
	std::ifstream infile(file);
	std::string line;
	if (infile){
		std::getline(infile,line);
	}
	return line;
}
std::string Get_Last_Line_Of_File(std::string const& file){
	std::ifstream infile(file);
	std::string line;
	while (infile){
		std::getline(infile,line);
	}
	return line;
}

std::string Get_Nth_Line_Of_File(std::string const& file, unsigned int line_number){
	std::ifstream infile(file);
	std::string line;
	while(line_number > 0){
		std::getline(infile,line);
		--line_number;
	}
	return line;
}

//printing
void Print_To_Stream_With_Newline(std::wofstream & outfile, std::wstring const& str){
	outfile << str << L'\n';
}
void Print_To_Stream_With_Newline(std::wofstream & outfile, std::string const& str){
	outfile << as_wstring(str) << L'\n';
}
void Print_To_Stream_With_Newline(std::ofstream & outfile, std::string const& str){
	outfile << str << '\n';
}
void Print_To_Stream_With_Newline(std::ofstream & outfile, std::wstring const& str){
	outfile << as_string(str) << '\n';
}
void Print_To_Stream_With_Newline_Only_If_There_Is_Content(std::wofstream & outfile, std::wstring const& str){
	if (!str.empty()){Print_To_Stream_With_Newline(outfile,str);}
}
void Print_To_Stream_With_Newline_Only_If_There_Is_Content(std::wofstream & outfile, std::string const& str){
	if (!str.empty()){Print_To_Stream_With_Newline(outfile,str);}
}
void Print_To_Stream_With_Newline_Only_If_There_Is_Content(std::ofstream & outfile, std::string const& str){
	if (!str.empty()){Print_To_Stream_With_Newline(outfile,str);}
}
void Print_To_Stream_With_Newline_Only_If_There_Is_Content(std::ofstream & outfile, std::wstring const& str){
	if (!str.empty()){Print_To_Stream_With_Newline(outfile,str);}
}



void Print_Newline_To_Stream(std::wofstream & outfile){
	outfile << L'\n';
}
void Print_Newline_To_Stream(std::ofstream & outfile){
	outfile << '\n';
}

void Print_To_Stream(std::wofstream & outfile, std::wstring const& str){
	outfile << str;
}
void Print_To_Stream(std::wofstream & outfile, std::string const& str){
	outfile << as_wstring(str);
}
void Print_To_Stream(std::ofstream & outfile, std::string const& str){
	outfile << str;
}
void Print_To_Stream(std::ofstream & outfile, std::wstring const& str){
	outfile << as_string(str);
}

void Print_To_Stream_N_Times(std::wofstream & outfile, std::wstring const& str, unsigned int amount){
    while (amount > 0) {Print_To_Stream(outfile,str); amount -= 1;}
}
void Print_To_Stream_N_Times(std::wofstream & outfile, std::string const& str, unsigned int amount){
    while (amount > 0) {Print_To_Stream(outfile,str); amount -= 1;}
}
void Print_To_Stream_N_Times(std::ofstream & outfile, std::string const& str, unsigned int amount){
    while (amount > 0) {Print_To_Stream(outfile,str); amount -= 1;}
}
void Print_To_Stream_N_Times(std::ofstream & outfile, std::wstring const& str, unsigned int amount){
    while (amount > 0) {Print_To_Stream(outfile,str); amount -= 1;}
}

