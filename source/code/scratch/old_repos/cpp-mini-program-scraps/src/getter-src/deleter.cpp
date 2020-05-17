#include "deleter.hpp"
#include "utilities.hpp"
#include "global.hpp"
#include <thread>

void Deleter::Start_Task() {
	
	std::vector<std::string> not_working_files;
	std::vector<std::string> not_interesting_files;
	while (true){
		
		std::cout << "starting delete process\n";
		not_working_files = Get_Files_Of_Path(constant::NOT_COMPILED_DIRECTORY);
		not_interesting_files = Get_Files_Of_Path(constant::NOT_INTERESTING_DIRECTORY);

		for (auto const& file: not_working_files){
			system(("rm -f " + constant::NOT_COMPILED_DIRECTORY + file).c_str());
			Increment_Number_In_File(constant::DELETED_NOT_BUILDABLE);
		}

		if (!File_Exists("if-this-file-is-here-not-interesting-files-WILL-NOT-be-rm")){
			for (auto const& file: not_interesting_files){
				system(("rm -f " + constant::NOT_INTERESTING_DIRECTORY + file).c_str());
				Increment_Number_In_File(constant::DELETED_NOT_INTERESTING);
			}
		}
		
		std::cout << "stoping delete process\n";
		//sleep a number of minutes
		std::this_thread::sleep_for(std::chrono::minutes(constant::DELAY_BETWEEN_DELETES));
	}
	
	return;
}
