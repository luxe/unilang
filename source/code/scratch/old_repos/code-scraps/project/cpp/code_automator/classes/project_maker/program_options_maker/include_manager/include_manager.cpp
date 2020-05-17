#include "include_manager.hpp"
#include <string>
#include <vector>
#include <sys/stat.h>
#include <fstream>


bool Include_Manager::Turn_On_Header(std::string const& include_parts_folder, std::string const& header_file){
	bool changed = false;
	std::vector<std::string> header_containing_files = Get_Files_Containing_Headers(include_parts_folder);
	for (auto it = header_containing_files.begin(); it != header_containing_files.end() and !changed; ++it){
		changed = Attempt_Turn_On(*it,header_file);
	}
	
	return changed;
}
bool Include_Manager::Turn_Off_Header(std::string const& include_parts_folder, std::string const& header_file){
	bool changed = false;
	std::vector<std::string> header_containing_files = Get_Files_Containing_Headers(include_parts_folder);
	for (auto it = header_containing_files.begin(); it != header_containing_files.end() and !changed; ++it){
		changed = Attempt_Turn_Off(*it,header_file);
	}
	
	return changed;
}
std::vector<std::string> Include_Manager::Get_Files_Containing_Headers(std::string const& include_parts_folder){
	
	std::vector<std::string> header_containing_files;
	std::string str = exec(("ls " + include_parts_folder).c_str());
	std::string temp;
	for (auto it: str){
		if (it != '\n'){
			temp+=it;
		}else{
			if (temp.size() > 0){
				header_containing_files.push_back(include_parts_folder + temp);
				temp.clear();
			}
		}
	}
	if (temp.size() > 0){
		header_containing_files.push_back(include_parts_folder + temp);
		temp.clear();
	}
	
	return header_containing_files;
}
bool Include_Manager::Attempt_Turn_On(std::string const& full_path_file, std::string const& header_name){
	
	//i'm just going to assume the format of the headers are clean
	bool changed = false;
	std::string all;
	std::string line;
	std::ifstream infile(full_path_file);
	
	std::getline(infile,line);
	while (infile){
		//decide what the line is
		if (line.size() >= 3){
			
			//its a header and its off (SO WE WILL TURN IT ON)
			if (line[0] == '/' && line[1] == '/' && line[2] == '#'){
				if (line == "//#include " + header_name){
					line.erase(0,2);
					changed = true;
				}
			}
		}
		
		
		all += line + '\n';
		std::getline(infile,line);
	}
	infile.close();
	//trim of the last newline
	if (all.size() > 0){
	all.erase(all.size() - 1);
	}
	
	std::ofstream outfile(full_path_file);
	outfile << all;
	outfile.close();
	
	return changed;
}
bool Include_Manager::Attempt_Turn_Off(std::string const& full_path_file, std::string const& header_name){
	
	//i'm just going to assume the format of the headers are clean
	bool changed = false;
	std::string all;
	std::string line;
	std::ifstream infile(full_path_file);
	
	std::getline(infile,line);
	while (infile){
		std::cout << line << std::endl;
		//decide what the line is
		if (line.size() >= 3){
			
			//its a header and its off (SO WE WILL TURN IT ON)
			if (line[0] == '#' && line[1] == 'i' && line[2] == 'n'){
				if (line == "#include " + header_name){
					line = "//" + line;
					changed = true;
				}
			}
		}
		
		
		all += line + '\n';
		std::getline(infile,line);
	}
	infile.close();
	//trim of the last newline
	if (all.size() > 0){
	all.erase(all.size() - 1);
	}
	
	std::ofstream outfile(full_path_file);
	outfile << all;
	outfile.close();
	
	return changed;
}


std::string Include_Manager::exec(const char* cmd) {
    FILE* pipe = popen(cmd, "r");
    if (!pipe) return "ERROR";
    char buffer[128];
    std::string result = "";
    while(!feof(pipe)) {
    	if(fgets(buffer, 128, pipe) != NULL)
    		result += buffer;
    }
    pclose(pipe);
    return result;
}

