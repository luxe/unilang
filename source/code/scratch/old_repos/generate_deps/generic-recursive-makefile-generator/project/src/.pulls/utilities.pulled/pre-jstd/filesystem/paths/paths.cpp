#include <sys/stat.h>
#include <sys/types.h>
#include <string>
#include <boost/range/adaptor/reversed.hpp>

//+---------------------------------------+
//| changing path / traversing filesystem |
//+---------------------------------------+
//THESE FUNCTIONS WILL CHANGE THE STATE OF THE CURRENT WORKING DIRECTORY
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
void Move_Back_Directories_Until_Directory_Exists(std::string root_directory_name){
	while (!File_Exists(root_directory_name)){
		Step_Out_Of_Folder();
	}
	return;
 }

//+-----------+
//| Observers |
//+-----------+

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
 
 std::vector<std::string> Recursively_Get_All_Directories_From_Path(std::string const& path){
 	return Get_Each_Line_Of_Shell_Command("find \"" + path + "\" -type d");
 }

//+---------------+
//| Getting Paths |
//+---------------+
std::vector<std::string> Current_Path_In_Parts(void){
	auto full = boost::filesystem::current_path().string();
	std::vector<std::string> parts;
	
	std::string part;
	for (auto const& c: full){
		if (c == '/'){
			parts.push_back(part);
			part.clear();
		}else{
			part+=c;
		}
	}

	if (!part.empty()){
		parts.push_back(part);
	}

	return parts;
 }
std::string Current_Path(void) {
	return boost::filesystem::current_path().string();
 }
 std::string Full_Path(void) {
	return boost::filesystem::current_path().string();
 }
std::string Get_Path_Of_Directory_Starting_From_Root_Directory_Name(std::string root_directory_name){
	std::string path;
	auto parts = Current_Path_In_Parts();
	for (auto const& it: boost::adaptors::reverse(parts)){
		if (it == root_directory_name){
			path=path+it + '/';
			break;
		}
		path=path+it + '/';
	}
	
	return path;
 }
std::string Get_Path_Of_Directory_Starting_From_One_Directory_Deeper_Than_Root_Directory_Name(std::string root_directory_name){
	std::string path;
	auto parts = Current_Path_In_Parts();
	for (auto const& it: boost::adaptors::reverse(parts)){
		if (it == root_directory_name){
			break;
		}
		path=path+it + '/';
	}
	
	return path;
 }

//+--------------------+
//| Checking Existence |
//+--------------------+
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
 
bool Directory_Exists(std::string path_to_dir){
  struct stat info;
  if(stat(path_to_dir.c_str(), &info) != 0 ){
    return false;
  }
  else if(info.st_mode & S_IFDIR){
    return true;
  }
  return false;
}

//+----------------------------------+
//| Get Numerical Data on Filesystem |
//+----------------------------------+
int Recursively_Get_Directory_Count(std::string const& path) {
	std::string str = exec("find " + path + " -type d | wc -l");

	return atoi(str.c_str());
 }
int Get_Number_Of_Files_In_Directory(std::string path) {
	struct dirent* entry;
	DIR* dp;
	int count = 0;
	
	//add slash to the end if wer need it since we append the path onto the filename when storing
	if (path[path.size()-1] != '/'){path+="/";}
	
	//open folder
	dp = opendir(path.c_str());
	if (dp == NULL){ return 0;}
	
	//loop and store
	while ((entry = readdir(dp))){
		if (Is_Regular_File(path + entry->d_name)){
			++count;
		}
	}
	closedir(dp);
	return count;
 }
unsigned int Number_Of_Directories_Deep_In_Root_Directory_Name(std::string root_directory_name){
	unsigned int depth = 0;
	auto parts = Current_Path_In_Parts();
	for (auto const& it: boost::adaptors::reverse(parts)){
		if (it == root_directory_name){
			break;
		}
		depth++;
	}

	return depth;
 }

//+--------------+
//| Transformers |
//+--------------+
 void Create_Path_If_It_Doesnt_Already_Exist(std::string const& path){

	if (!File_Exists(path)){
		execute_quietly(("mkdir -p " + path).c_str());
	}

	return;
 }

//+--------------------------------------------------------+
//| Transforming AND changing path / traversing filesystem |
//+--------------------------------------------------------+
void Create_Path_If_It_Doesnt_Already_Exist_And_Step_Into_It(std::string const& path){
	Create_Path_If_It_Doesnt_Already_Exist(path);
	Step_Into_Folder(path);
	return;
}
void Create_The_Path_Empty_And_Step_Into_It(std::string const& path){
	execute_quietly("rm -rf " + path);
	Create_Path_If_It_Doesnt_Already_Exist_And_Step_Into_It(path);
	return;
}

//utility
void Shortify_Path(boost::filesystem::path & path){
	path = boost::filesystem::canonical(path);
	return;
 }
