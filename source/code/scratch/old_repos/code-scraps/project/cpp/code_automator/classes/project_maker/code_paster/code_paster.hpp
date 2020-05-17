#pragma once
#include <iostream>
#include <vector>
/*

*/
class Code_Paster{

	public:
		
	//Main Module Code (Also Driver)
	static void Put_Main_File(std::string const& file_name);
		static void Put_Main_Function_File(std::string const& main_function_file);
		static void Put_Main_Driver_Function_File(std::string const& main_function_file);
		static void Put_Includes_File(std::string const& file_name);
			static void Put_C_Include_File(std::string const& file_name);
			static void Put_CPP_Include_File(std::string const& file_name);
			static void Put_3rd_Party_Include_File(std::string const& file_name);
			static void Put_Project_Include_File(std::string const& file_name);
	
	//Class
	static void Put_Class_Header(std::string const& file_name, std::string const& class_name);
	static void Put_Class_Source(std::string const& file_name, std::string const& class_name);
	static void Put_Class_Static_Part(std::string const& file_name);
	static void Put_Class_Object_Functions_Part(std::string const& file_name);
	
	//Program_Options
	static void Put_Program_Options_Decleration_Constructor(std::string const& file_name);
	static void Put_Program_Options_Definition_Constructor(std::string const& file_name);
	static void Put_Program_Options_Decleration_Transformer_Functions(std::string const& file_name);
	static void Put_Program_Options_Definition_Transformer_Functions(std::string const& file_name);
	static void Put_Program_Options_Decleration_Data(std::string const& file_name);
	static void Put_Program_Options_Definition_Data(std::string const& file_name);
	static void Put_Program_Options_Decleration_Static_Data(std::string const& file_name);
	static void Put_Program_Options_Definition_Static_Data(std::string const& file_name);
		
	//Rules Files Code
		//root
	static void Put_Root_Rules_File(std::string const& file_name);
	static void Put_Code_Root_Rules_File(std::string const& file_name);
		//main / driver
	static void Put_Main_Modules_Rules_File(std::string const& file_name, std::vector<std::string> const& main_module_names);
	static void Put_Main_Module_Rules_File(std::string const& file_name,std::string const& main_module_name);
	static void Put_Main_Driver_Rules_File(std::string const& file_name,std::string const& main_module_name);
	static void Put_Main_Module_Root_Rules_File(std::string const& file_name);
	static void Put_Main_Module_DR_Rules_File(std::string const& file_name);
	static void Put_Main_Driver_DR_Rules_File(std::string const& file_name);
	static void Put_Tests_Rule_File(std::string const& file_name);
	static void Put_Drivers_Rule_File(std::string const& file_name);
	
		//class
	static void Put_Class_Root_Rules_File(std::string const& file_name);
	static void Put_Class_Name_Rules_File(std::string const& file_name);
	static void Put_Class_Rules_File(std::string const& file_name, std::string const& class_name);
	

};