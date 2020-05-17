#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <fstream>

void Create_Folder(std::string const& version);
void Change_Version_In_Code(std::string const& version);
void Clean_Project(std::string const& version);
void Move_Project_To_Release_Folder(std::string const& version);
void Create_Compressed_File(std::string const& version);

int main(){
	
	std::string version;
	std::cout << "version number -> ";
	std::getline(std::cin,version);
	
	Create_Folder(version);
	Change_Version_In_Code(version);
	Clean_Project(version);
	Move_Project_To_Release_Folder(version);
	Create_Compressed_File(version);
	
	return 0;
}

void Create_Folder(std::string const& version){
	system(("mkdir jstd-releases/jstd-" + version).c_str());
	return;
}
void Change_Version_In_Code(std::string const& version){
	
	std::vector<std::string> vec;
	std::string str;
	std::ifstream infile("current/exporter/program_options.cpp");
	std::getline(infile,str);
	while(infile){
		vec.push_back(str);
		std::getline(infile,str);
	}
	infile.close();
	
	
	std::ofstream outfile("current/exporter/program_options.cpp");
	int i = 1;
	for (auto it: vec){
		if (i == 2){
			outfile << "const std::string Program_Options::VERSION_NUMBER = \"" << version << "\";\n";
		}else{
			outfile << it << '\n';
		}
		++i;
	}
	outfile.close();
	
	
	return;
}
void Clean_Project(std::string const& version){
	system("cd current; make clean;");
	return;
}

void Move_Project_To_Release_Folder(std::string const& version){
	system(("cp -r current jstd-releases/jstd-" + version + "/jstd-"+version).c_str());
	return;
}
void Create_Compressed_File(std::string const& version){
	system(("cd jstd-releases/jstd-" + version + "; tar -zcvf jstd-"+version+".tar.gz " + "jstd-"+version+ " > /dev/null 2>&1").c_str());
	system(("cd jstd-releases/jstd-" + version + "; zip -r    jstd-"+version+".zip " + "jstd-"+version+ " > /dev/null 2>&1").c_str());
	
	return;
}

//pro bono