#include "project_maintainer.hpp"
#include "namespace_generator/namespace_generator.hpp"
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <utility>
#include <prettyprint.hpp>
#include <sys/stat.h>

void Project_Maintainer::Update_All_Main_Module_Headers(std::string const& project_name){
	
	std::vector<std::string> main_modules = Get_Dirs_Of_Path(project_name+"/main_modules/");
	
	for (auto main_module: main_modules){
		Update_Main_Module_Header(project_name+"/main_modules/"+main_module);
	}
	
	return;
}
void Project_Maintainer::Update_Main_Module_Header(std::string const& main_module){
	
	std::vector<std::string> used_classes = Get_Dirs_Of_Path(main_module+"/main/direct_relationships/");
	
	std::ofstream outfile(main_module+"/main/main_parts/includes_part/project.hpp");
	outfile << "///Root Project Classes\n";
	for (auto used_class: used_classes){
		outfile << "#include \"../../direct_relationships/" << used_class << "/class/" << used_class << ".hpp\"\n";
	}
	return;
}
void Project_Maintainer::Update_All_Main_Driver_Headers(std::string const& project_name){
	
	std::string hello = exec("cd " + project_name + "; pwd");
	
	std::string backward;
	bool found = false;
	for (auto it = hello.rbegin(); it != hello.rend() && !found; ++it){
		if (*it == '/'){
			found = true;
		}else{
			backward+=*it;
		}
	}
	std::string got_ya;
	for (auto it = backward.rbegin(); it != backward.rend(); ++it){
		got_ya+=*it;
	}
	
	std::vector<std::string> main_modules = Get_Dirs_Of_Path(project_name+"tests/drivers/");
	
	for (auto main_module: main_modules){
		Update_Main_Driver_Header(project_name+"tests/drivers/"+main_module,got_ya);
	}
	
	return;
}
void Project_Maintainer::Update_Main_Driver_Header(std::string const& main_module,std::string const& got_ya){
	
	std::vector<std::string> used_classes = Get_Dirs_Of_Path(main_module+"/main/direct_relationships/");
	
	std::ofstream outfile(main_module+"/main/main_parts/includes_part/project.hpp");
	outfile << "///Root Project Classes\n";
	for (auto used_class: used_classes){
		outfile << "#include \"../../direct_relationships/" << used_class << "/class/" << used_class << ".hpp\"\n";
	}
	
	outfile << "#include \"../../../../../../" << "class/" << got_ya << ".hpp\"\n";
	return;
}


void Project_Maintainer::Update_All_Main_Module_Dependencies(std::string folder_path){
	
	if (folder_path.size() == 1){
		folder_path += "/";
	}
	std::vector<std::string> main_modules = Get_Dirs_Of_Path(folder_path+"main_modules/");
	
	for (auto main_module: main_modules){
		Update_Main_Module_Dependencies(folder_path+"main_modules/"+main_module);
	}
	
	return;
}
void Project_Maintainer::Update_Main_Module_Dependencies(std::string const& main_module){
	
	//recursively get all the classes, related(directly or not) to the directly related classes of the main_modules
	//WE EXPECT TO FIND DUPLICATE OBJECTS REPRESENTED AS DIFFERENT DIRECTORIES
	//WE'LL RECORD THE I-NODES OF ALL THESE OBJECTS AND FILTER OUT THE DUPLICATES
	//INEFFICIENT? PROBABLY. I DON'T THINK IT WILL BE AN ISSUE THOUGH. IF IT BECOMES ONE, THE GATHER ALL/FILTER ALGORITHM
	//CAN BE REPLACED WITH A PICK CAREFULLY AS WE GO ALGORITHM.  I'M NOT SCREAMING, I JUST REALIZED THAT CAPS LOCK WAS ON OK.
	//ACTUALLY I'M GOING TO USE A MAP SO THEY DON'T EVEN GET PICKED UP- NO FILTERING NEEDED. SELF-FILTERING IF YOU WILL!
	std::map<long,std::string> objects;
	int erase_amount = std::string(main_module+"/main/").size();
	Recursive_Object_Pickup(objects,main_module+"/main/",erase_amount);
	
	//update the dependencies (we are ensured no duplicates
	std::ifstream infile(main_module+"/main/.Rules.mk");
	std::string str;
	std::string all;
	std::getline(infile,str);
	all+=str+'\n';
	std::getline(infile,str);
	all+=str+'\n';
	str.erase(0,11);
	all+=str+"_DEPS = " + str + ".o ";
	for (auto it: objects){
		all+= "$(TARGETS_$(d)/" + it.second + ") ";
	}
	std::getline(infile,str);
	std::getline(infile,str);
	all += '\n';
	all += str;
	infile.close();
	std::ofstream outfile(main_module+"/main/.Rules.mk");
	outfile << all;
	
	return;
}


void Project_Maintainer::Recursive_Object_Pickup(std::map<long,std::string> & objects,std::string const& object_path, int const& erase_amount){
	
	std::vector<std::string> class_folders = Get_Dirs_Of_Path(object_path+"direct_relationships/");
	for (auto class_folder: class_folders){
		objects.insert(std::pair<long,std::string>(Get_I_Node_Number(object_path+"direct_relationships/"+class_folder+"/class"),std::string(object_path+"direct_relationships/"+class_folder+"/class").erase(0,erase_amount)));
		Recursive_Object_Pickup(objects,object_path+"direct_relationships/"+class_folder+"/class/",erase_amount);
	}
	
	return;
}
void Project_Maintainer::Update_All_Main_Module_Namespaces(std::string const& project_name){
	
	std::string real_proj_name = exec("cd " + project_name +"; pwd");
	std::string temp2;
	
	
	
	if (!File_Exists(".code_root")){
		temp2 = Skim_String2(real_proj_name);
	}else{
		real_proj_name = exec("cd " + project_name +"/../; pwd");
		temp2 = Skim_String(real_proj_name);
	}
	
	
	std::vector<std::string> main_modules = Get_Dirs_Of_Path(project_name+"/main_modules/");

	for (auto main_module: main_modules){
		Namespace_Generator::Generate_For_Main_Module(project_name+"/main_modules/"+main_module+"/main/main_parts/generated_namespace.hpp",temp2+"/code/main_modules/"+main_module+"/");
	}
	
	return;
}
void Project_Maintainer::Update_All_Main_Driver_Namespaces(std::string const& project_name){
	
	std::string real_proj_name = exec("cd " + project_name +"; pwd");
	std::string temp2;
	
	
	temp2 = project_name;
	/*if (!File_Exists(".code_root")){
		temp2 = Skim_String3(real_proj_name);
	}else{
		real_proj_name = exec("cd " + project_name +"../; pwd");
		temp2 = Skim_String(real_proj_name);
	}*/
	//std::cout << "[" << temp2 << "]" << std::endl;
	
	
	
	std::vector<std::string> main_modules = Get_Dirs_Of_Path(project_name+"tests/drivers/");
	for (auto main_module: main_modules){
		Namespace_Generator::Generate_For_Main_Driver(project_name+"tests/drivers/"+main_module+"/main/main_parts/generated_namespace.hpp",temp2+"tests/drivers/"+main_module+"/");
	}
	return;
}


void Project_Maintainer::Update_All_Main_Module_Direct_Relationships(std::string const& project_name){
	
	std::vector<std::string> root_classes = Get_Dirs_Of_Path(project_name+"/classes/");
	std::vector<std::string> main_modules = Get_Dirs_Of_Path(project_name+"/main_modules/");
	for (auto main_module: main_modules){
		Update_Main_Module_Direct_Relationships(project_name+"/main_modules/"+main_module+"/main/",root_classes);
	}
	
	return;
}
void Project_Maintainer::Update_Main_Module_Direct_Relationships(std::string const& main_module, std::vector<std::string> root_classes){
	
	//a root class may have been removed from the classes folder, or perhaps a name was added to the not_using link, which is currently
	//linked to the module.  In any case, I'm just going to wipe all the connections, and rebuild them.
	std::vector<std::string> current_connections = Get_Dirs_Of_Path(main_module + "direct_relationships/");
	for (auto it: current_connections){
		system(("rm -rf " + main_module + "direct_relationships/" + it + "/").c_str());
	}
	
	//read in the list of root classes that the main module is NOT using.
	//whatever is NOT listed in that file, we assume is being used.
	std::vector<std::string> not_using;
	std::ifstream infile(main_module+"direct_relationships/not_using");
	std::string temp;
	std::getline(infile,temp);
	while (infile){
		not_using.push_back(temp);
		std::getline(infile,temp);
	}
	
	//don't consider ones that are not being used
	for (auto it: not_using){
		root_classes.erase(std::remove(root_classes.begin(), root_classes.end(), it), root_classes.end());
	}
	
	//symbolically link what is being used
	for (auto it: root_classes){
		system(("ln --symbolic --force --target-directory=" + main_module + "direct_relationships/ ../../../../classes/" + it + "/").c_str());
	}
	
	return;
}
void Project_Maintainer::Update_All_Main_Driver_Direct_Relationships(std::string const& project_name){
	
	//std::cout << project_name << std::endl;
	std::vector<std::string> root_classes = Get_Dirs_Of_Path(project_name+"class/direct_relationships/");
	std::vector<std::string> main_modules = Get_Dirs_Of_Path(project_name+"tests/drivers/");
	for (auto main_module: main_modules){
		Update_Main_Driver_Direct_Relationships(project_name+"tests/drivers/"+main_module+"/main/",root_classes);
	}
	
	return;
}
void Project_Maintainer::Update_Main_Driver_Direct_Relationships(std::string const& main_module, std::vector<std::string> root_classes){
	
	//a root class may have been removed from the classes folder, or perhaps a name was added to the not_using link, which is currently
	//linked to the module.  In any case, I'm just going to wipe all the connections, and rebuild them.
	std::vector<std::string> current_connections = Get_Dirs_Of_Path(main_module + "direct_relationships/");
	for (auto it: current_connections){
		system(("rm -rf " + main_module + "direct_relationships/" + it + "/").c_str());
	}
	
	//symbolically link what is being used
	for (auto it: root_classes){
		system(("ln --symbolic --force --target-directory=" + main_module + "direct_relationships/ ../../../../class/direct_relationships/" + it + "/").c_str());
		std::cout << ("ln --symbolic --force --target-directory=" + main_module + "direct_relationships/ ../../../../class/direct_relationships/" + it + "/").c_str() << std::endl;
	}
	
	return;
}

void Project_Maintainer::Update_Main_Modules_Root_Rules_File(std::string const& project_name){
	
	std::vector<std::string> main_modules = Get_Dirs_Of_Path(project_name+"/main_modules/");
	
	std::ofstream outfile(project_name+"/main_modules/.Rules.mk");
	outfile << "SUBDIRS := ";
	for (auto main_module: main_modules){
		outfile << main_module << " ";
	}
	
	return;
}
void Project_Maintainer::Update_Class_Sub_Directory(std::string const& folder_path){
	std::vector<std::string> classes = Get_Dirs_Of_Path(folder_path);
	std::ofstream outfile(folder_path+"/.Rules.mk");
	outfile << "SUBDIRS := ";
	for (auto c: classes){
		outfile << c << " ";
	}
	
	return;
}
void Project_Maintainer::Update_All_Main_Module_Direct_Relationships_Rules_File(std::string const& folder_path){
	
	std::vector<std::string> main_modules = Get_Dirs_Of_Path(folder_path+"/main_modules/");
	std::vector<std::string> direct_classes;
	std::ofstream outfile;
	for (auto main_module: main_modules){
			direct_classes = Get_Dirs_Of_Path(folder_path+"/main_modules/" + main_module +"/main/direct_relationships/");
			// open
			outfile.open(folder_path+"/main_modules/" + main_module +"/main/direct_relationships/.Rules.mk");
			outfile << "SUBDIRS := ";
			for (auto direct_class: direct_classes){
				outfile << direct_class << " ";
			}
			//close
			outfile.close();
	}
	
	return;
}
std::vector<std::string> Project_Maintainer::Get_Dirs_Of_Path(std::string const& path){
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
std::string Project_Maintainer::exec(std::string const& cmd){
	return exec(cmd.c_str());
}
std::string Project_Maintainer::exec(const char* cmd) {
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
long Project_Maintainer::Get_I_Node_Number(std::string const& filename) {
    struct stat fileInfo;
    stat(filename.c_str(), &fileInfo);
	return fileInfo.st_ino;
}

std::string Project_Maintainer::Skim_String(std::string str){
	std::string temp;
	
	bool found = false;
	for (auto it = str.rbegin(); it != str.rend() && !found; ++it){
		if (*it == '/'){
			found = true;
		}else{
		temp+=*it;
		}
	}
	std::string temp2;
	for (auto it = temp.rbegin(); it != temp.rend(); ++it){
		temp2+=*it;
	}
	
	return temp2;
}
std::string Project_Maintainer::Skim_String2(std::string str){
	std::string temp;
	
	int c = 0;
	for (auto it = str.rbegin(); it != str.rend() && c != 2; ++it){
		if (*it == '/'){
			++c;
			if (c != 2){
			temp="";
			}
		}else{
		temp+=*it;
		}
	}
	std::string temp2;
	for (auto it = temp.rbegin(); it != temp.rend(); ++it){
		temp2+=*it;
	}
	
	return temp2;
}
std::string Project_Maintainer::Skim_String3(std::string str){
	std::string temp;
	
	int c = 0;
	for (auto it = str.rbegin(); it != str.rend() && c != 3; ++it){
		if (*it == '/'){
			++c;
			if (c != 3){
			temp="";
			}
		}else{
		temp+=*it;
		}
	}
	std::string temp2;
	for (auto it = temp.rbegin(); it != temp.rend(); ++it){
		temp2+=*it;
	}
	
	return temp2;
}
bool Project_Maintainer::File_Exists(std::string const& filename) {
    struct stat fileInfo;
    return stat(filename.c_str(), &fileInfo) == 0;
}



