#include "class_maker.hpp"
#include "code_paster/code_paster.hpp"
#include "make_putter/make_putter.hpp"
#include "namespace_generator/namespace_generator.hpp"
#include "driver_maker/driver_maker.hpp"
#include <sys/stat.h>

void Class_Maker::Make_Class(std::string const& path, std::string const& name){
	
	//build tests directory
	system(("mkdir -p " + path + Lowercase(name) + "/tests/drivers/").c_str());
	Code_Paster::Put_Tests_Rule_File(path + Lowercase(name) + "/tests/.Rules.mk");
	Make_Putter::Hard_Link_The_Makefile(path + Lowercase(name) + "/tests/");
	
	
	//build README directory
	system(("mkdir -p " + path + Lowercase(name) + "/README/version/").c_str());
	
		std::ofstream outfile;
		
		system(("touch " + path + Lowercase(name) + "/README/version/MAJOR").c_str());
		outfile.open(path + Lowercase(name) + "/README/version/MAJOR");
		outfile << "0"; outfile.close();
		
		system(("touch " + path + Lowercase(name) + "/README/version/MINOR").c_str());
		outfile.open(path + Lowercase(name) + "/README/version/MINOR");
		outfile << "0"; outfile.close();
		
		system(("touch " + path + Lowercase(name) + "/README/version/PATCH").c_str());
		outfile.open(path + Lowercase(name) + "/README/version/PATCH");
		outfile << "0"; outfile.close();
	
	//build class root file
	system(("touch " + path + Lowercase(name) + "/.class_root").c_str());
	
	
	//build class directories
	system(("mkdir -p " + path + Lowercase(name) + "/class/class_parts/deceleration/includes_part").c_str());
	system(("mkdir -p " + path + Lowercase(name) + "/class/class_parts/deceleration/object_functions_part").c_str());
	system(("mkdir -p " + path + Lowercase(name) + "/class/class_parts/deceleration/static_part").c_str());
	system(("mkdir -p " + path + Lowercase(name) + "/class/class_parts/definition/includes_part").c_str());
	system(("mkdir -p " + path + Lowercase(name) + "/class/class_parts/definition/object_functions_part").c_str());
	system(("mkdir -p " + path + Lowercase(name) + "/class/class_parts/definition/static_part").c_str());
	system(("mkdir -p " + path + Lowercase(name) + "/class/direct_relationships").c_str());
	system(("touch " + path + Lowercase(name) + "/class/direct_relationships/.Rules.mk").c_str());
	
	//create source and header file
	Code_Paster::Put_Class_Header(path + Lowercase(name) + "/class/"+Lowercase(name)+".hpp",Uppercase(name));
	Code_Paster::Put_Class_Source(path + Lowercase(name) + "/class/"+Lowercase(name)+".cpp",Lowercase(name));
	
	
	std::string temp2;
	if (File_Exists(".Rules.top")){
		std::string real_proj_name = exec("pwd");
			std::string temp;
	bool found = false;
	for (auto it = real_proj_name.rbegin(); it != real_proj_name.rend() && !found; ++it){
		if (*it == '/'){
			found = true;
		}else{
		temp+=*it;
		}
	}
	for (auto it = temp.rbegin(); it != temp.rend(); ++it){
		temp2+=*it;
	}
	temp2+="/";
	}
	
	//create deceleration parts
	system(("touch " + path + Lowercase(name) + "/class/class_parts/deceleration/data.hpp").c_str());
	Namespace_Generator::Generate_For_Class_Header(path + Lowercase(name) + "/class/class_parts/deceleration/generated_namespace.hpp",temp2+path+Lowercase(name));
	Code_Paster::Put_Includes_File(path + Lowercase(name) + "/class/class_parts/deceleration/includes.hpp");
	system(("touch " + path + Lowercase(name) + "/class/class_parts/deceleration/object_functions.hpp").c_str());
	system(("touch " + path + Lowercase(name) + "/class/class_parts/deceleration/templated.hpp").c_str());
	system(("touch " + path + Lowercase(name) + "/class/class_parts/deceleration/parents.hpp").c_str());
	system(("touch " + path + Lowercase(name) + "/class/class_parts/deceleration/static.hpp").c_str());
	system(("touch " + path + Lowercase(name) + "/class/class_parts/deceleration/friend.hpp").c_str());
	
	system(("touch " + path + Lowercase(name) + "/class/class_parts/deceleration/object_functions_part/constructors.hpp").c_str());
	system(("touch " + path + Lowercase(name) + "/class/class_parts/deceleration/object_functions_part/observers.hpp").c_str());
	system(("touch " + path + Lowercase(name) + "/class/class_parts/deceleration/object_functions_part/transformers.hpp").c_str());
	system(("touch " + path + Lowercase(name) + "/class/class_parts/deceleration/object_functions_part/overloaded_operators.hpp").c_str());
	system(("touch " + path + Lowercase(name) + "/class/class_parts/deceleration/object_functions_part/casts.hpp").c_str());
	system(("touch " + path + Lowercase(name) + "/class/class_parts/deceleration/object_functions_part/destructor.hpp").c_str());
	
	system(("touch " + path + Lowercase(name) + "/class/class_parts/deceleration/static_part/data.hpp").c_str());
	system(("touch " + path + Lowercase(name) + "/class/class_parts/deceleration/static_part/functions.hpp").c_str());
	
	Code_Paster::Put_C_Include_File(path + Lowercase(name) + "/class/class_parts/deceleration/includes_part/c.hpp");
	Code_Paster::Put_CPP_Include_File(path + Lowercase(name) + "/class/class_parts/deceleration/includes_part/c++.hpp");
	Code_Paster::Put_3rd_Party_Include_File(path + Lowercase(name) + "/class/class_parts/deceleration/includes_part/3rd_party.hpp");
	Code_Paster::Put_Project_Include_File(path + Lowercase(name) + "/class/class_parts/deceleration/includes_part/project.hpp");
	
	Code_Paster::Put_Class_Static_Part(path + Lowercase(name) + "/class/class_parts/deceleration/static.hpp");
	Code_Paster::Put_Class_Object_Functions_Part(path + Lowercase(name) + "/class/class_parts/deceleration/object_functions.hpp");
	
	//create definition parts
	Namespace_Generator::Generate_For_Class_Source(path + Lowercase(name) + "/class/class_parts/definition/generated_namespace.hpp",temp2+path+Lowercase(name));
	Code_Paster::Put_Includes_File(path + Lowercase(name) + "/class/class_parts/definition/includes.hpp");
	system(("touch " + path + Lowercase(name) + "/class/class_parts/definition/object_functions.hpp").c_str());
	system(("touch " + path + Lowercase(name) + "/class/class_parts/definition/static.hpp").c_str());
	system(("touch " + path + Lowercase(name) + "/class/class_parts/definition/friend.hpp").c_str());
	system(("touch " + path + Lowercase(name) + "/class/class_parts/definition/templates.hpp").c_str());
	
	system(("touch " + path + Lowercase(name) + "/class/class_parts/definition/object_functions_part/constructors.hpp").c_str());
	system(("touch " + path + Lowercase(name) + "/class/class_parts/definition/object_functions_part/observers.hpp").c_str());
	system(("touch " + path + Lowercase(name) + "/class/class_parts/definition/object_functions_part/transformers.hpp").c_str());
	system(("touch " + path + Lowercase(name) + "/class/class_parts/definition/object_functions_part/overloaded_operators.hpp").c_str());
	system(("touch " + path + Lowercase(name) + "/class/class_parts/definition/object_functions_part/casts.hpp").c_str());
	system(("touch " + path + Lowercase(name) + "/class/class_parts/definition/object_functions_part/destructor.hpp").c_str());
	
	system(("touch " + path + Lowercase(name) + "/class/class_parts/definition/static_part/data.hpp").c_str());
	system(("touch " + path + Lowercase(name) + "/class/class_parts/definition/static_part/functions.hpp").c_str());
	
	Code_Paster::Put_C_Include_File(path + Lowercase(name) + "/class/class_parts/definition/includes_part/c.hpp");
	Code_Paster::Put_CPP_Include_File(path + Lowercase(name) + "/class/class_parts/definition/includes_part/c++.hpp");
	Code_Paster::Put_3rd_Party_Include_File(path + Lowercase(name) + "/class/class_parts/definition/includes_part/3rd_party.hpp");
	Code_Paster::Put_Project_Include_File(path + Lowercase(name) + "/class/class_parts/definition/includes_part/project.hpp");
	
	Code_Paster::Put_Class_Static_Part(path + Lowercase(name) + "/class/class_parts/definition/static.hpp");
	Code_Paster::Put_Class_Object_Functions_Part(path + Lowercase(name) + "/class/class_parts/definition/object_functions.hpp");
	
	//some files that should be included when coding to make re-naming the class easier
	system(("touch " + path + Lowercase(name) + "/class/class_parts/definition/object_functions_part/.scope_function.hpp").c_str());
	outfile.open(path + Lowercase(name) + "/class/class_parts/definition/object_functions_part/.scope_function.hpp");
	outfile << "auto " << Uppercase(name) << "::"; outfile.close();
	
	system(("touch " + path + Lowercase(name) + "/class/class_parts/definition/static_part/.scope_function.hpp").c_str());
	outfile.open(path + Lowercase(name) + "/class/class_parts/definition/static_part/.scope_function.hpp");
	outfile << "auto " << Uppercase(name) << "::"; outfile.close();
	
	system(("touch " + path + Lowercase(name) + "/class/class_parts/definition/.scope_function.hpp").c_str());
	outfile.open(path + Lowercase(name) + "/class/class_parts/definition/.scope_function.hpp");
	outfile << "auto " << Uppercase(name) << "::"; outfile.close();
	
	system(("touch " + path + Lowercase(name) + "/class/class_parts/definition/object_functions_part/.scope_data.hpp").c_str());
	outfile.open(path + Lowercase(name) + "/class/class_parts/definition/object_functions_part/.scope_data.hpp");
	outfile << Uppercase(name) << "::"; outfile.close();
	
	system(("touch " + path + Lowercase(name) + "/class/class_parts/definition/static_part/.scope_data.hpp").c_str());
	outfile.open(path + Lowercase(name) + "/class/class_parts/definition/static_part/.scope_data.hpp");
	outfile << Uppercase(name) << "::"; outfile.close();
	
	system(("touch " + path + Lowercase(name) + "/class/class_parts/definition/.scope_data.hpp").c_str());
	outfile.open(path + Lowercase(name) + "/class/class_parts/definition/.scope_data.hpp");
	outfile << Uppercase(name) << "::"; outfile.close();
	
	system(("touch " + path + Lowercase(name) + "/class/class_parts/definition/object_functions_part/.scope_constructor.hpp").c_str());
	outfile.open(path + Lowercase(name) + "/class/class_parts/definition/object_functions_part/.scope_constructor.hpp");
	outfile << Uppercase(name) << "::" << Uppercase(name); outfile.close();
	
	system(("touch " + path + Lowercase(name) + "/class/class_parts/definition/object_functions_part/.scope_destructor.hpp").c_str());
	outfile.open(path + Lowercase(name) + "/class/class_parts/definition/object_functions_part/.scope_destructor.hpp");
	outfile << Uppercase(name) << "::~" << Uppercase(name) << "()"; outfile.close();
	
	
	
	
	//add the Rules and Makefile
	Code_Paster::Put_Class_Name_Rules_File(path + Lowercase(name) + "/.Rules.mk");
	Code_Paster::Put_Class_Rules_File(path + Lowercase(name) + "/class/.Rules.mk",Lowercase(name));
	Make_Putter::Hard_Link_The_Makefile(path + Lowercase(name) + "/");
	Make_Putter::Hard_Link_The_Makefile(path + Lowercase(name) + "/class/");
	
		Driver_Maker::Create_Main_Folder(path + Lowercase(name) + "/tests/drivers/driver0/","driver0");
	Code_Paster::Put_Drivers_Rule_File(path + Lowercase(name) + "/tests/drivers/.Rules.mk");
	Make_Putter::Hard_Link_The_Makefile(path + Lowercase(name) + "/tests/drivers/");
	return;
}

std::string Class_Maker::Uppercase(std::string str){
	char letter = str[0];
	str.erase(0,1);
	letter = (char)static_cast<char>(toupper(letter));
	str = letter + str;

	for (auto it = str.begin(); it != str.end(); ++it){
		if ((it - 1) > str.begin()){
			if (*(it - 1) == '_'){
				*it = toupper(*it);
			}
		}
	}

	return str;

}
std::string Class_Maker::Lowercase(std::string str){
	char letter = str[0];
	str.erase(0,1);
	letter = (char)static_cast<char>(tolower(letter));
	str = letter + str;

	for (auto it = str.begin(); it != str.end(); ++it){
		if ((it - 1) > str.begin()){
			if (*(it - 1) == '_'){
				*it = tolower(*it);
			}
		}
	}

	return str;
}
bool Class_Maker::File_Exists(std::string const& filename){
    struct stat fileInfo;
    return stat(filename.c_str(), &fileInfo) == 0;
}
std::string Class_Maker::exec(std::string const& cmd){
	return exec(cmd.c_str());
}
std::string Class_Maker::exec(const char* cmd) {
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