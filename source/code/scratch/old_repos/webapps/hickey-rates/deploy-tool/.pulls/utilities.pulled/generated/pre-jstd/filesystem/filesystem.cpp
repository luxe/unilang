#include <sys/stat.h>

//filesystem stuff
std::string Full_Path(void) {
	return boost::filesystem::current_path().string();
}
std::string Current_Path(void) {
	return boost::filesystem::current_path().string();
}
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
void Set_Path(std::string const& path) {
	boost::filesystem::current_path(path);
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
bool Directory_Exists_In_Current_Directory_Or_Any_Parents(std::string const& dir) {
	std::string full = boost::filesystem::current_path().string();
	while (Current_Folder_Name() !=  "") {
		if (File_Exists(dir)) {
			boost::filesystem::current_path(full);
			return true;
		}
		Step_Out_Of_Folder();
	}

	boost::filesystem::current_path(full);
	return false;
}
bool Inside_Git_Repository(){

	return Directory_Exists_In_Current_Directory_Or_Any_Parents(".git");
}
std::vector<std::string> Get_Dirs_Of_Path(std::string const& path){
	std::vector<std::string> dirs;
	std::string list = exec("find " + path + " -maxdepth 1 -type d 2>/dev/null;");
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
