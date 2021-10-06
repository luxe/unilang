#include "compile_method.hpp"

//constructor
Compile_Method::Compile_Method(std::string const& language_standard_in)
 : language_standard(language_standard_in)
 , success(false)
{}
	
//transformers

//try to build the file with the particular language standard.
//We check to see if the binary exists to know whether it was built or not.
//if it was, we ensure that asking for success will remain true.
//Don't worry, we delete the binary aftwerwards too
void Compile_Method::Attempt_To_Get_Successful_Build(std::string source_file) {
	
	std::string compile_statement = "g++ --std=" + language_standard + " -o " + Without_File_Extension(source_file) + " " + source_file + " >> /dev/null 2>&1;";
	system(compile_statement.c_str());
	
	if (File_Exists(Without_File_Extension(source_file))){
		success = true;
		
		std::string delete_statement = "rm -f " + Without_File_Extension(source_file);
		system(delete_statement.c_str());
	}
	
	
	return;
}

//observers
bool Compile_Method::Was_Successful() {
	return success;
}
	