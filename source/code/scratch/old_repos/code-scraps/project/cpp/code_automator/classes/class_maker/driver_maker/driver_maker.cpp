#include <fstream>
#include "driver_maker.hpp"
#include "code_paster/code_paster.hpp"
#include "make_putter/make_putter.hpp"
#include "namespace_generator/namespace_generator.hpp"
#include "project_maintainer/project_maintainer.hpp"
void Driver_Maker::Create_Main_Folder(std::string const& main_folder,std::string const& main_module_name){
	
	//---------------------//
	// ROOT OF MAIN MODULE //
	//---------------------//
		//put the main module folder
		system(("mkdir -p " + main_folder + "main/main_parts/includes_part").c_str());
		
		//build README folder
		system(("mkdir -p " + main_folder + "README/version/").c_str());
		std::ofstream outfile;
		
		system(("touch " + main_folder + "README/version/MAJOR").c_str());
		outfile.open(main_folder + "README/version/MAJOR");
		outfile << "0"; outfile.close();
		
		system(("touch " + main_folder + "README/version/MINOR").c_str());
		outfile.open(main_folder + "README/version/MINOR");
		outfile << "0"; outfile.close();
		
		system(("touch " + main_folder + "README/version/PATCH").c_str());
		outfile.open(main_folder + "README/version/PATCH");
		outfile << "0"; outfile.close();
		
		//add the Rules and Makefile
		Code_Paster::Put_Main_Module_Root_Rules_File(main_folder +".Rules.mk");
		Make_Putter::Hard_Link_The_Makefile(main_folder);
		
	//-------------//
	// MAIN FOLDER //
	//-------------//
		//direct relationships
		system(("mkdir -p " + main_folder + "main/direct_relationships").c_str());
		system(("touch " + main_folder + "main/direct_relationships/not_using").c_str());
		Code_Paster::Put_Main_Driver_DR_Rules_File(main_folder +"main/direct_relationships/.Rules.mk");
		
		//build main cpp parts
		Code_Paster::Put_Main_File(main_folder + "main/" + main_module_name + ".cpp");
		system(("touch " + main_folder + "main/main_parts/constants.hpp").c_str());
		system(("touch " + main_folder + "main/main_parts/function_declerations.hpp").c_str());
		system(("touch " + main_folder + "main/main_parts/function_definitions.hpp").c_str());
		Code_Paster::Put_Main_Driver_Function_File(main_folder + "main/main_parts/main_function.hpp");
		
		//build main include portion
		Code_Paster::Put_Includes_File(main_folder + "main/main_parts/includes.hpp");
		Code_Paster::Put_C_Include_File(main_folder + "main/main_parts/includes_part/c.hpp");
		Code_Paster::Put_CPP_Include_File(main_folder + "main/main_parts/includes_part/c++.hpp");
		Code_Paster::Put_3rd_Party_Include_File(main_folder + "main/main_parts/includes_part/3rd_party.hpp");
		Code_Paster::Put_Project_Include_File(main_folder + "main/main_parts/includes_part/project.hpp");
		
		//add the Rules and Makefile
		Code_Paster::Put_Main_Driver_Rules_File(main_folder +"main/.Rules.mk",main_module_name);
		Make_Putter::Hard_Link_The_Makefile(main_folder + "main/");
		
		
		//OTHER STUFF
		//Project_Maintainer::Update_All_Main_Driver_Direct_Relationships(main_folder+"../../../");
		Project_Maintainer::Update_All_Main_Driver_Headers(main_folder+"../../../");
		Project_Maintainer::Update_All_Main_Driver_Namespaces(main_folder+"../../../");
		//Project_Maintainer::Update_All_Main_Driver_Dependencies();
		
		
	return;
}
void Driver_Maker::Build_Include_Portion(std::string const& path, std::string const& includes_file){
	Code_Paster::Put_Includes_File(includes_file);
	Code_Paster::Put_C_Include_File(path + "c.hpp");
	Code_Paster::Put_CPP_Include_File(path + "c++.hpp");
	Code_Paster::Put_3rd_Party_Include_File(path + "3rd_party.hpp");
	Code_Paster::Put_Project_Include_File(path + "project.hpp");
	return;
}