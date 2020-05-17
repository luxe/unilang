#include "project_maker.hpp"
#include "make_putter/make_putter.hpp"
#include "code_paster/code_paster.hpp"
#include "main_maker/main_maker.hpp"
#include "program_options_maker/program_options_maker.hpp"
#include "license_maker/license_maker.hpp"
#include <fstream>

void Project_Maker::Create_Project(std::string const& project_name, std::vector<std::string> const& main_module_names){
	
	  //////////////////////////
	 // ROOT DIRECTORY STUFF //
	//////////////////////////
	
	//build the root folder
	system(("mkdir -p " + project_name+"/code/").c_str());
	system(("touch " + project_name+"/code/.code_root").c_str());
	
	//build the class and main modules folders
	Build_Main_Modules_Directory(project_name,main_module_names);
	Build_Classes_Directory(project_name);
	
	//build the README folder
	system(("mkdir -p " + project_name + "/README/version/").c_str());
	
		std::ofstream outfile;
		system(("touch " + project_name + "/README/version/MAJOR").c_str());
		outfile.open( project_name + "/README/version/MAJOR");
		outfile << "0"; outfile.close();
		
		system(("touch " + project_name + "/README/version/MINOR").c_str());
		outfile.open(project_name + "/README/version/MINOR");
		outfile << "0"; outfile.close();
		
		system(("touch " + project_name + "/README/version/PATCH").c_str());
		outfile.open(project_name + "/README/version/PATCH");
		outfile << "0"; outfile.close();
		
		system(("touch " + project_name + "/README/LICENSE").c_str());
		License_Maker::Artistic_License_2(project_name + "/README/LICENSE","2013","Trevor Hickey");
		
	
	//add the Rules and Makefile
	Code_Paster::Put_Root_Rules_File(project_name +"/.Rules.top");
	Make_Putter::Hard_Link_The_Makefile(project_name+"/");
	
	Code_Paster::Put_Code_Root_Rules_File(project_name +"/code/.Rules.mk");
	Make_Putter::Hard_Link_The_Makefile(project_name+"/code/");
	
	return;
}

void Project_Maker::Build_Main_Modules_Directory(std::string const& project_name, std::vector<std::string> const& main_module_names){
	
	//create the main modules directory
	system(("mkdir -p " + project_name+"/code/main_modules/").c_str());
	
	//make all the main modules
	for (auto main_module_name: main_module_names){
		Main_Maker::Create_Main_Folder(project_name+"/code/main_modules/"+main_module_name+"/",main_module_name);
	}
	
	//add the Rules and Makefile
	Code_Paster::Put_Main_Modules_Rules_File(project_name+"/code/main_modules/.Rules.mk",main_module_names);
	Make_Putter::Hard_Link_The_Makefile(project_name+"/code/main_modules/");
	
	return;
}
	
void Project_Maker::Build_Classes_Directory(std::string const& project_name){
	
	//create the class modules directory
	system(("mkdir -p " + project_name + "/code/classes/").c_str());
	
	//create program_options class
	Create_Program_Options_Class(project_name + "/code/classes/");
	
	//add the Rules and Makefile
	Code_Paster::Put_Class_Root_Rules_File(project_name + "/code/classes/.Rules.mk");
	Make_Putter::Hard_Link_The_Makefile(project_name + "/code/classes/");
	
	return;
}
void Project_Maker::Create_Program_Options_Class(std::string const& path){
	
	Program_Options_Maker::Make(path, "program_options");
	
	
	return;
}
