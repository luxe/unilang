#pragma once
#include <iostream>
#include <vector>
#include "program_options/program_options.hpp"
/*

*/
class Command_Line_Validator{

	//Task
	public: static void Validate_Task_Flag(Program_Options const& program_options);
	
	//Project
	public: static void Validate_MK_Project_Flags(std::vector<std::string> const& project_names, std::vector<std::string> & main_module_names);
	
	//Main
	public: static void Validate_MK_Main_Flags(std::vector<std::string> & main_module_names);
	public: static void Validate_RM_Main_Flags(std::vector<std::string> & main_module_names);
	public: static void Validate_RN_Main_Flags(std::vector<std::pair<std::string,std::string>> & main_module_names);
	public: static void Validate_CP_Main_Flags(std::vector<std::pair<std::string,std::string>> & main_module_names);
	
	//Class
	public: static void Validate_MK_Class_Flags(std::vector<std::string> const& class_names);
	//static void Validate_Enum_Flags
	//static void Validate_Enun_Update_Flags



	protected:
	private:

};