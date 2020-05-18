#pragma once
#include "class_structure.hpp"

class Global_Optimizer{






public:

//use the optimizer to print the new version of the hcp file
//also has to call make to make sure the changes are valid, so it also compiles the hcp as well as the c++ to create a .o
static void Optimize_HCP_File(Class_Structure structure, std::string const& hcp_file);

static void Initial_Test(Class_Structure const& structure, std::string const& hcp_file);
static void Sort_And_Remove_Duplicates_Test(Class_Structure & structure, std::string const& hcp_file);
static void Remove_Sources_Based_On_Headers_Test(Class_Structure & structure, std::string const& hcp_file);
static void Move_As_Many_Includes_From_Header_To_Source_Test(Class_Structure & structure, std::string const& hcp_file);
static void Try_Raw_Deletes(std::vector<std::pair<std::wstring,bool>> & includes, Class_Structure & structure, std::string const& hcp_file);
static void Reprint_Hcp_File(Class_Structure const& structure, std::string const& hcp_file);

static bool Compiles(Class_Structure const& structure, std::string hcp_file);


friend std::ostream& operator<<( std::ostream & out, Global_Optimizer const& self){
	return out;
}




};