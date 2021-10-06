#include "utilities.hpp"
#include "global.hpp"
#include <string>
#include <boost/filesystem.hpp>
#include <sys/stat.h>
#include <iostream>
#include <cctype>

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
		if (it == ' '){
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


//vector functions
bool String_In_Vector(std::vector<std::string> const& vec,  std::string const& str){
	return std::find(vec.begin(), vec.end(), str) != vec.end();
}
//color functions
std::string colorize(std::string const& message, int const& background, int const& forground) {
	if (global::COLORS_ENABLED) {
		return std::string("\e[38;5;" + std::to_string(forground) + ";48;5;" + std::to_string(background) + "m" + message + "\x1b[0m");
	}
	return message;
}
std::string colorize_forground(std::string const& message, int const& background) {
	if (global::COLORS_ENABLED) {
		return std::string("\e[38;5;" + std::to_string(background) + "m" + message + "\x1b[0m");
	}
	return message;
}
std::string colorize_background(std::string const& message, int const& forground) {
	if (global::COLORS_ENABLED) {
		return std::string("\e[48;5;" + std::to_string(forground) + "m" + message + "\x1b[0m");
	}
	return message;
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



