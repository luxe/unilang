#include "utilities.hpp"
#include <string>
#include <boost/filesystem.hpp>
#include <fstream>
#include <sys/stat.h>
#include <iostream>
#include <cctype>
#include <gmpxx.h>

//general system stuff
std::string exec(std::string const& cmd){
	return exec(cmd.c_str());
}
std::string exec(const char* cmd) {
    FILE* pipe = popen(cmd, "r");
    if (!pipe) return "ERROR";
    char buffer[128];
    std::string result = "";
    while(!feof(pipe)) {
    	if(fgets(buffer, 128, pipe) != NULL)
    		result += buffer;
    }
    pclose(pipe);
		if (result.size() > 0){
	result.resize(result.size()-1);
	}
    return result;
}

//filesystem stuff
void Create_Path_If_It_Doesnt_Already_Exist(boost::filesystem::path const& path){

	if (!File_Exists(path.string())){
		system(("mkdir -p " + path.string()).c_str());
	}

	return;
}
std::string Current_Folder_Name(void){

	//there is probably a way to get just the current folder name, but i couldn't find it
	std::string full = boost::filesystem::current_path().string();
	std::string name;
	for (auto it = full.rbegin(); it != full.rend(); ++it){
		if (*it == '/'){
			break;
		}
		name+=*it;
	}

	std::reverse(name.begin(), name.end());
	return name;


}
void Step_Into_Folder(std::string const folder_name){

	//not sure if that "./" really needs to be there
	boost::filesystem::current_path("./" + folder_name);
	return;
}
void Step_Out_Of_Folder(void){

	//not sure if that "./" really needs to be there
	boost::filesystem::current_path(std::string("./") + std::string("../"));
	return;
}
bool File_Exists(std::string const& filename) {
    struct stat fileInfo;
    return stat(filename.c_str(), &fileInfo) == 0;
}
std::vector<std::string> Get_Dirs_Of_Path(std::string const& path){
	std::vector<std::string> dirs;
	std::string list = exec("find " + path + " -maxdepth 1 -type d 2>/dev/null; " + "find " + path + " -maxdepth 1 -type l 2>/dev/null;");
	std::string list2;

	bool done=false;
	for (auto it = list.begin(); it != list.end(); ++it){

		if (*it == '\n' && done == false){
			done = true;
			++it;
			if (it == list.end()){
				break;
			}
		}

		if (done){
			list2+=*it;
		}
	}

	std::string temp;
	for (auto it: list2){
		if (it == '/'){
			temp.clear();
		}else if (it == '\n'){
			dirs.push_back(temp);
			temp.clear();
		}else{
		temp+=it;
		}
	}
	if (!temp.empty()){
		dirs.push_back(temp);
	}

	return dirs;
}
std::vector<std::string> Get_Files_Of_Path(std::string const& path){
	std::vector<std::string> dirs;
	std::string list2 = exec("find " + path + " -maxdepth 1 -type f 2>/dev/null;");

	std::string temp;
	for (auto it: list2){
		if (it == '/'){
			temp.clear();
		}else if (it == '\n'){
			dirs.push_back(temp);
			temp.clear();
		}else{
		temp+=it;
		}
	}
	if (!temp.empty()){
		dirs.push_back(temp);
	}

	return dirs;
}
std::stack<std::string> Get_Files_Of_Path_As_Stack(std::string const& path){
	std::stack<std::string> dirs;
	std::string list2 = exec("find " + path + " -maxdepth 1 -type f 2>/dev/null;");

	std::string temp;
	for (auto it: list2){
		if (it == '/'){
			temp.clear();
		}else if (it == '\n'){
			dirs.push(temp);
			temp.clear();
		}else{
		temp+=it;
		}
	}
	if (!temp.empty()){
		dirs.push(temp);
	}

	return dirs;
}
	
std::vector<std::string> Recursively_Get_All_Source_File_Paths_Of_Path(std::string const& path){
	std::vector<std::string> dirs;
	std::string list = exec("find " + path + " -type f -name \\*.cpp 2>/dev/null;");
	std::string list2;

	bool done=false;
	for (auto it = list.begin(); it != list.end(); ++it){

		if (*it == '\n' && done == false){
			done = true;
			++it;
			if (it == list.end()){
				break;
			}
		}

		if (done){
			list2+=*it;
		}
	}

	std::string temp;
	for (auto it: list2){
		if (it == '\n'){
			dirs.push_back(temp);
			temp.clear();
		}else{
		temp+=it;
		}
	}
	if (!temp.empty()){
		dirs.push_back(temp);
	}

	return dirs;
}
int Recursively_Get_Directory_Count(std::string const& path) {
	std::string str = exec("find " + path + " -type d | wc -l");

	return atoi(str.c_str());
}
int Get_Number_Of_Files_In_Directory(std::string const& path) {
	std::string str = exec("ls -1 " + path + " | wc -l");
	return atoi(str.c_str());
}
void Shortify_Path(boost::filesystem::path & path){
	path = boost::filesystem::canonical(path);
	return;
}
unsigned int Get_Unsigned_Int_From_File(std::string const& file_name) {
	std::ifstream infile(file_name);
	std::string str;
	std::getline(infile, str);
	return std::atoll(str.c_str());
}

void Append_Text_To_The_Top_Of_File(std::string const& file_name, std::string const& append_text) {
	auto original_file = Get_All_Lines_of_File(file_name);
	std::ofstream outfile(file_name);
	outfile << append_text;
	for (auto const& line: original_file) {
		outfile <<  line <<  "\n";
	}
	
	return;
}

void Download_And_Save_HTML_File(std::string const& url, std::string const& file) {

	system((std::string("wget ") + url + " -N --tries=0 --output-document=" + file + " >> /dev/null 2>&1").c_str());

	return;
}

std::string Get_Whole_File_As_String(std::string const& file_name){
	std::ifstream t(file_name);
	return std::string((std::istreambuf_iterator<char>(t)),
                 std::istreambuf_iterator<char>());
}

//string functions
std::string &ltrim(std::string &s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
        return s;
}
std::string &rtrim(std::string &s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
        return s;
}
std::string &trim(std::string &s) {
        return ltrim(rtrim(s));
}
std::string& Squeeze_Away_Spaces(std::string &s){
	std::string::iterator new_end = std::unique(s.begin(), s.end(), [](char lhs, char rhs) { return (lhs == rhs) && (lhs == ' '); });
	s.erase(new_end, s.end());
	return s;
}
std::string Make_Capital_And_Underscored_In_User_Type_Format(std::string s) {

	trim(s);
	Squeeze_Away_Spaces(s);

	//turn spaces into underscores and capitalize each word
	bool was_space = true; // <- capitalize the first character every time
	for (auto & it: s){
		if (it == ' ' /*|| it == '.'*/){
			it ='_';
			was_space = true;
		}else{
			if (was_space){
				it = static_cast<char>(toupper(it));
				was_space = false;
			}
		}
	}

	return s;
}

std::string Make_Lowercased_And_Underscored_In_User_Type_Format(std::string s) {

	trim(s);
	Squeeze_Away_Spaces(s);

	//turn spaces into underscores and capitalize each word
	bool was_space = true; // <- capitalize the first character every time
	for (auto & it: s){
		if (it == ' ' /*|| it == '.'*/){
			it ='_';
			was_space = true;
		}else{
			if (was_space){
				it = static_cast<char>(tolower(it));
				was_space = false;
			}
		}
	}

	return s;
}
bool Space_At_The_Beginning(std::string const& s) {

	if (s.empty()) {return false;}
	if (s[0] ==  ' ') {
		return true;
	}

	return false;
 }
bool Space_At_The_End(std::string const& s) {

	if (s.empty()) {return false;}
	if (s[s.size()-1] ==  ' ') {
		return true;
	}

	return false;
 }
bool Consecutive_Space_In_The_Middle(std::string s) {

	trim(s);
	bool found = false;
	for (auto const& it: s) {
		if (it == ' ') {
			if (found) {
				return true;
			}
			found = true;
		}
		else{
			found = false;
		}
	}
	return false;
}
bool Contains_Capital_Letters(std::string const& s) {

	for (auto const& it: s) {
		if (std::isupper(it)) {
			return true;
		}
	}

	return false;
}

std::string& Remove_File_Extension(std::string & file_name) {
	
	while (file_name[file_name.size()-1] != '.') {
		file_name = file_name.substr(0, file_name.size()-1);
	}
	file_name = file_name.substr(0, file_name.size()-1);
	
	return file_name;
}
std::string Without_File_Extension(std::string file_name) {
	
	while (file_name[file_name.size()-1] != '.') {
		file_name = file_name.substr(0, file_name.size()-1);
	}
	file_name = file_name.substr(0, file_name.size()-1);
	
	return file_name;
}

bool String_Starts_With_String(std::string const& looking_in, std::string const& looking_for){
	return (looking_in.substr(0, looking_for.size()) == looking_for);
}
bool String_Ends_With_String(std::string const& looking_in, std::string const& looking_for){
	
	if (looking_in.size() < looking_for.size()){ return false;}
	return (looking_in.substr(looking_in.size()-looking_for.size(), looking_for.size()) == looking_for);
}
bool Is_All_Whitespace(std::string const& str){
	for (auto const& it: str){
		if (!std::isspace(it)){
			return false;
		}
	}
	return true;
}

void Remove_First_N_Characters(std::string & str,int const& amount){
	str.erase(0,amount);
}
void Remove_Last_N_Characters(std::string & str,int const& amount){
	str.erase(str.size()-amount,str.size());
}

//vector functions
bool String_In_Vector(std::vector<std::string> const& vec,  std::string const& str){
	return std::find(vec.begin(), vec.end(), str) != vec.end();
}
//color functions
std::string colorize(std::string const& message, int const& background, int const& forground) {
	return std::string("\x1b[38;5;" + std::to_string(forground) + ";48;5;" + std::to_string(background) + "m" + message + "\x1b[0m");
}
std::string colorize_forground(std::string const& message, int const& background) {
	return std::string("\x1b[38;5;" + std::to_string(background) + "m" + message + "\x1b[0m");
}
std::string colorize_background(std::string const& message, int const& forground) {
	return std::string("\x1b[48;5;" + std::to_string(forground) + "m" + message + "\x1b[0m");
}
void Green_Message(std::string const& str){

	std::cout << colorize_forground(str, 118);
	return;
}
void Red_Message(std::string const& str){

	std::cerr << colorize_forground(str, 1);
	return;
}
void Exit_With_Error_Message(std::string const& str){
	Red_Message(str);
	exit(EXIT_SUCCESS);
	return;
}

//file stream functions
std::vector<std::vector<std::string>> Get_And_Parse_Each_Line_Of_File(std::string const& file) {

	std::ifstream infile(file);
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

std::vector<std::string> Get_All_Lines_of_File(std::string const& file) {
	
	std::vector<std::string> lines;
	std::string line;
	std::ifstream infile(file);
	std::getline(infile, line);
	while (infile) {
		lines.push_back(line);
		std::getline(infile, line);
	}
	
	return lines;
}

//gmp function wrapper
mpf_class add_all_elements(std::vector<mpf_class> nums) {
	mpf_class num("0");
	for (auto const& it: nums) {
		num += it;
	}

	return num;
}
void Increment_Number_In_File(std::string const& file_name){
	mpz_class number(Get_Whole_File_As_String(file_name));
	number += mpf_class("1");
	std::ofstream outfile(file_name);
	outfile << number;
}



