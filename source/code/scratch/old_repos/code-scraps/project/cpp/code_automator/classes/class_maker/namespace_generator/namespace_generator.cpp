#include "namespace_generator.hpp"
#include <fstream>
#include <sys/stat.h>

void Namespace_Generator::Generate_For_Class_Header(std::string const& file, std::string class_path){
	std::ofstream outfile(file);
	std::string generated_namespace = Generate_Namespace(class_path);
	outfile << "namespace " << generated_namespace << "{\n";
	outfile << "namespace " << generated_namespace << "_obj{\n";
	Use_The_Namespace_Of_Related_Classes_For_Class(outfile,class_path);
	outfile << "}\n";
	outfile << "namespace obj = " << generated_namespace << "_obj;";
	
	return;
}
void Namespace_Generator::Generate_For_Class_Source(std::string const& file, std::string class_path){
	
	std::ofstream outfile(file);
	std::string generated_namespace = Generate_Namespace(class_path);
	outfile << "namespace " << generated_namespace << "{\n";
	
	return;
}

void Namespace_Generator::Generate_For_Main_Module(std::string const& file, std::string main_path){
	std::string generated_namespace = Generate_Namespace(main_path + "main/main_parts/generated_namespace.hpp");
	
if (File_Exists(".code_root")){
		bool found = false;
		std::string temp;
		for (auto it = main_path.begin(); it != main_path.end() && !found; ++it){
			if (*it != '/'){
				temp+= *it;
			}else{
				found = true;
			}
		}
		main_path.erase(0,temp.size()+1);
	
			found = false;
			temp ="";
			for (auto it = main_path.begin(); it != main_path.end() && !found; ++it){
				if (*it != '/'){
					temp+= *it;
				}else{
					found = true;
				}
			}
			main_path.erase(0,temp.size()+1);
			//main_path="."+main_path;
}
			
	std::ofstream outfile(file);
	outfile << "namespace " << generated_namespace << "_obj{\n";
	Use_The_Namespace_Of_Related_Classes_For_Main(outfile,main_path);
	outfile << "}\n";
	outfile << "namespace obj = " << generated_namespace << "_obj;";
	
	return;
}
std::string Namespace_Generator::Generate_Namespace(std::string start_name){
	
	//remove the last underscore if there is one
	if (start_name[start_name.length()-1] == '_'){
		start_name.resize(start_name.size()-1);
	}
	
	//turn slashes into underscores
	//and lowercase the string
	std::string str;
	for (auto it: start_name){
		if (it == '/' || it == '.'){
			str+="__";
		}else{
			str+= tolower(it);
		}
	}
	
	return str;
}
void Namespace_Generator::Use_The_Namespace_Of_Related_Classes_For_Class(std::ofstream & outfile, std::string const& class_path){
	
	std::vector<std::string> dirs = Get_Dirs_Of_Path(class_path+"direct_relationship/");
	for (auto it: dirs){
		Use_Namespace_For_Class(outfile,class_path,it);
	}
	
	return;
}
void Namespace_Generator::Use_Namespace_For_Class(std::ofstream & outfile, std::string const& class_path, std::string const& class_name){
	
	std::ifstream infile(class_path+"direct_relationship/"+class_name+"/class/class_parts/deceleration/generated_namespace.hpp");
	std::string name;
	std::getline(infile,name);
	name.resize(name.size()-1);
	name.erase(0,10);
	outfile << "\tusing namespace " << name << ";\n";
	return;
}
void Namespace_Generator::Use_The_Namespace_Of_Related_Classes_For_Main(std::ofstream & outfile, std::string main_path){
	
	std::vector<std::string> dirs = Get_Dirs_Of_Path(main_path+"main/direct_relationships/");
	for (auto it: dirs){
		Use_Namespace_For_Main(outfile,main_path,it);
	}
	
	return;
}
void Namespace_Generator::Use_Namespace_For_Main(std::ofstream & outfile, std::string const& main_path, std::string const& class_name){
	
	std::ifstream infile(main_path+"main/direct_relationships/"+class_name+"/class/class_parts/deceleration/generated_namespace.hpp");
	std::string name;
	std::getline(infile,name);
	name.resize(name.size()-1);
	name.erase(0,10);
	outfile << "\tusing namespace " << name << ";\n";
	
	return;
}

void Namespace_Generator::Generate_For_Main_Driver(std::string const& file, std::string main_path){
	
	std::string generated_namespace = Generate_Namespace(main_path + "main/main_parts/generated_namespace.hpp");
	std::ofstream outfile(file);
	outfile << "namespace " << generated_namespace << "_obj{\n";
	Use_The_Namespace_Of_Related_Classes_For_Driver(outfile,main_path);
	outfile << "}\n";
	outfile << "namespace obj = " << generated_namespace << "_obj;";
	
	
	return;
}
void Namespace_Generator::Use_The_Namespace_Of_Related_Classes_For_Driver(std::ofstream & outfile, std::string main_path){
	
	std::vector<std::string> dirs = Get_Dirs_Of_Path(main_path+"main/direct_relationships/");
	for (auto it: dirs){
		Use_Namespace_For_Main(outfile,main_path,it);
	}
	//std::cout << main_path << std::endl;
	Use_The_Actual_Class(outfile,main_path);
	
	return;
}
void Namespace_Generator::Use_The_Actual_Class(std::ofstream & outfile, std::string const& main_path){
	
	std::string trim = main_path;
	//std::string trim = exec("cd " + main_path +"; pwd");
	std::string trim_reverse;
	for (auto it = trim.rbegin(); it != trim.rend(); ++it){
		trim_reverse += *it;
		
	}
	trim="";
	int c = 0;
	for (auto it = trim_reverse.begin(); it != trim_reverse.end() && c !=10; ++it){
		if (*it == '/'){++c;}
		trim+=*it;
	}
	
	trim_reverse.erase(0,trim.length());
	
	trim="";
	for (auto it = trim_reverse.rbegin(); it != trim_reverse.rend(); ++it){
		trim += *it;
		
	}
	trim+="/class/class_parts/deceleration/generated_namespace.hpp";
	
	//std::cout << trim << std::endl;
	std::ifstream infile(trim);
	std::string name;
	std::getline(infile,name);
	name.resize(name.size()-1);
	name.erase(0,10);
	outfile << "\tusing namespace " << name << ";\n";
	std::cout << name << std::endl;
	return;
}
void Namespace_Generator::Use_Namespace_For_Driver(std::ofstream & outfile, std::string const& main_path, std::string const& class_name){
	
	std::cout << main_path << "main/direct_relationships/" <<  class_name << "/class/class_parts/deceleration/generated_namespace.hpp" << std::endl;
	std::ifstream infile(main_path+"main/direct_relationships/"+class_name+"/class/class_parts/deceleration/generated_namespace.hpp");
	std::string name;
	std::getline(infile,name);
	name.resize(name.size()-1);
	name.erase(0,10);
	outfile << "\tusing namespace " << name << ";\n";
	
	return;
}


std::vector<std::string> Namespace_Generator::Get_Dirs_Of_Path(std::string const& path){
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
		if (it == '/' || it == '.'){
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
std::string Namespace_Generator::exec(std::string const& cmd){
	return exec(cmd.c_str());
}
std::string Namespace_Generator::exec(const char* cmd) {
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
bool Namespace_Generator::File_Exists(std::string const& filename){
    struct stat fileInfo;
    return stat(filename.c_str(), &fileInfo) == 0;
}


