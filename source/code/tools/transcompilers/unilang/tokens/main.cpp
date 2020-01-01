#include "code/tools/transcompilers/unilang/tokens/task_executer.hpp"
#include <string>

int main(int arc, char** argv){
	std::string output_directory = argv[1];
	Task_Executer::Execute_Needed_Tasks(output_directory);
}