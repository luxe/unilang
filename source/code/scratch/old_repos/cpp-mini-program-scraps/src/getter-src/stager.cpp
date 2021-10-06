#include "stager.hpp"
#include "global.hpp"
#include "compile_method.hpp"
#include <thread>
#include <chrono>

void Stager::Start_Task() {


	//loop through all source files in the testing area and attempt to stage them.
	//attempting to stage them,  will either move them into the "Staged" folder,  or into the "Deleted" folder
	std::vector<std::string> source_files;
	
	while(true){
		
		std::cout << "doing staging code" << std::endl;
		source_files = Recursively_Get_All_Source_File_Paths_Of_Path(constant::TESTING_DIRECTORY);
		for (auto const& source_file: source_files) {
			std::cout << "stage a file" <<std::endl;
			Attempt_To_Stage(source_file);
		}

		std::cout << "stoping staging code" << std::endl;
		std::this_thread::sleep_for(std::chrono::minutes(constant::DELAY_BETWEEN_STAGES));
	}


	return;
}

void Stager::Attempt_To_Stage(std::string const& source_file) {


	//when staging files,
	//a list of language standards and libraries are used to find successful compiles.
	//If the code compiles,  we will post a comment at the top of the file that shows how we got a successful build.
    //There is likely more than one way to get a successful build.  We strive to show all of the standards,
	//and whether or not they are valid for the code. We also try to ONLY SHOW the extra
	//libraries that are actually needed.


	//create a list of compile methods.
	//compile methods are just a different language standards to compile against
	//one compile method(say, c++11), will be used against a combination of libraries until a successful build is discovered,
	//or until all library combinations have been exausted
	std::vector<Compile_Method> methods;
	for (auto const& it: constant::language_standards) {
		methods.push_back(Compile_Method(it));
	}

	//now we try to compile the same piece of code through all of these "compile methods"
	for (auto & it: methods) { it.Attempt_To_Get_Successful_Build(source_file); }

	//did any of these compile methods work?
	bool valid_code = false;
	for (auto & it: methods) {if (it.Was_Successful()) {valid_code = true; break;}}

	//post a C comment at the bottom of the file explaining how the testing process went
	//Append_Results_To_The_Bottom_Of_The_File(source_file, valid_code, methods);

	//move the file into a new area
	if (valid_code) {Move_File_To_Staged(source_file);}
	else{Move_File_To_Deleted(source_file);}

	return;
};

void Stager::Append_Results_To_The_Bottom_Of_The_File(std::string const& source_file, bool const& valid_code, std::vector<Compile_Method> const& methods) {

	//create a comment block to append at the top of the source code file
	std::string top_message = "/*\n";

	//add either a success or failure message
	if (valid_code) {
		top_message += "CODE SUCCESSFULLY BUILT\n";
		Add_Success_Message(top_message, methods);
	}
	else {
		top_message += "CODE FAILED TO BUILD\n";
		Add_Fail_Message(top_message, methods);
	}


	top_message += "*/\n";
	return;
}
void Stager::Add_Success_Message(std::string & top_message,  std::vector<Compile_Method> const& methods) {

	return;
}
void Stager::Add_Fail_Message(std::string & top_message,  std::vector<Compile_Method> const& methods) {

	return;
}

void Stager::Move_File_To_Deleted(std::string const& source_file) {
	std::cout << "bad-deleting" <<std::endl;
	system(("mv " + source_file + " " + constant::NOT_COMPILED_DIRECTORY).c_str());
	return;
}
void Stager::Move_File_To_Staged(std::string const& source_file) {
	std::cout << "good-staging" <<std::endl;
	system(("mv " + source_file + " " + constant::STAGED_DIRECTORY).c_str());
	return;
}
