#include "utilities.hpp"
#include "program_options_creator.hpp"
#include <iostream>
#include <fstream>
#include <string>

namespace constant{


const std::string RESET_WITH_PATH = R"foo(
void File_System_Traverser::Reset(std::string const& path) {

	//empty stack and go back to the starting directory
	while (!traverse_stack.empty()){traverse_stack.pop();}
	just_started = true;
	Set_Path(path);
	return;
}
)foo";

const std::string RESET = R"foo(
void File_System_Traverser::Reset() {

	//empty stack and go back to the starting directory
	while (!traverse_stack.empty()){traverse_stack.pop();}
	just_started = true;
	Set_Path(start_directory);
	return;
}
)foo";

const std::string SET_DIR = R"foo(
void File_System_Traverser::Set_Starting_Directory(std::string const& path) {

	if (path == ".") {
		start_directory = getenv ("PWD");
	}else{
		start_directory = path;
		Set_Path(path);
	}

	return;
}
)foo";

const std::string POSSIBLE_CYCLE_IMPL = R"foo(
bool File_System_Traverser::Possible_Cycle() {
	if (cycle) {Reset();}
	return cycle;
}
)foo";

const std::string CYCLE_IMPL = R"foo(
bool File_System_Traverser::Cycle() {
	Reset();
	return true;
}
)foo";

const std::string GET_DIR_IMPL = R"foo(
std::vector<std::string> File_System_Traverser::Get_Dirs_Of_Current_Directory_Possibly_Filtered() {
	auto all = Get_Dirs_Of_Path(".");
	std::sort(all.begin(), all.end());

	std::vector<std::string> difference;
	std::set_difference(
		all.begin(), all.end(),
		avoid_dirs.begin(), avoid_dirs.end(),
		std::back_inserter(difference)
	);

	return difference;
}
)foo";


const std::string CALL_WHEN_CYCLE_ON = "Cycle()";
const std::string CALL_WHEN_CYCLE_OFF = "false";
const std::string CALL_WHEN_CYCLE_OPTIONAL = "Possible_Cycle()";

const std::string CALL_WHEN_DIR_FILTER_ON = "Get_Dirs_Of_Current_Directory_Possibly_Filtered()";
const std::string CALL_WHEN_DIR_FILTER_OFF = "Get_Dirs_Of_Path(\".\")";



}

// create the .hpp and .cpp
void Create_Header(Program_Options const& program_options);
void Create_Source(Program_Options const& program_options);

	//header stuff
	void Create_Header_Constructor(std::ofstream & outfile, Program_Options const& program_options);
	void Create_Header_Move_Into_Next_Directory(std::ofstream & outfile, Program_Options const& program_options);
		void BFS_Comment(std::ofstream & outfile);
		void In_Order_Comment(std::ofstream & outfile);
		void Pre_Order_Comment(std::ofstream & outfile);
		void Post_Order_Comment(std::ofstream & outfile);
		void Optional_Comment(std::ofstream & outfile);
	void Create_Header_Reset(std::ofstream & outfile, Program_Options const& program_options);
	void Create_Header_Private_Section(std::ofstream & outfile, Program_Options const& program_options);

	//source stuff
	void Create_Source_Constructor(std::ofstream & outfile, Program_Options const& program_options);
	void Create_Source_Move_Into_Next_Directory(std::ofstream & outfile, Program_Options const& program_options);
		void BFS_Impl(std::ofstream & outfile);
		void In_Order_Impl(std::ofstream & outfile);
		void Pre_Order_Impl(std::ofstream & outfile, Program_Options const& program_options);
		void Post_Order_Impl(std::ofstream & outfile);
		void Optional_Impl(std::ofstream & outfile);
	void Create_Source_Reset(std::ofstream & outfile, Program_Options const& program_options);
	void Create_Source_Private_Section(std::ofstream & outfile, Program_Options const& program_options);

	//utility
	void Possible_Cycle(std::ofstream & outfile,  Program_Options const& program_options);
	void Possible_Dir_Filter(std::ofstream & outfile,  Program_Options const& program_options);

int main(int const argc, char** const argv) {

	auto program_options = Program_Options_Creator::Create(argc, argv);
	Create_Header(program_options);
	Create_Source(program_options);

	return EXIT_SUCCESS;
}

// create the .hpp and .cpp
void Create_Header(Program_Options const& program_options) {
	std::ofstream outfile("file_system_traverser.hpp");

	Create_Header_Constructor(outfile, program_options);
	Create_Header_Move_Into_Next_Directory(outfile, program_options);
	Create_Header_Reset(outfile, program_options);
	Create_Header_Private_Section(outfile, program_options);
	return;

}
void Create_Source(Program_Options const& program_options) {
	std::ofstream outfile("file_system_traverser.cpp");

	Create_Source_Constructor(outfile, program_options);
	Create_Source_Move_Into_Next_Directory(outfile, program_options);
	Create_Source_Reset(outfile, program_options);
	Create_Source_Private_Section(outfile, program_options);

	return;
}

//header stuff
void Create_Header_Constructor(std::ofstream & outfile, Program_Options const& program_options) {
	outfile << "#include <iostream>" << '\n';
	outfile << "#include <string>" << '\n';
	outfile << "#include <utility>" << '\n';
	outfile << "#include <vector>" <<  '\n';
	outfile << "#include <stack>" << '\n';
	outfile << "\nclass  File_System_Traverser {" << '\n';
	outfile << "\tpublic:\n\t\n\t//constructor\n\t\n";

	//variable comments for the constructor
	outfile << "\t//path - what directory to start in\n";
	if (program_options.Cycle() == "optional") {
		outfile << "\t//cycle - whether the filesystem should automatically continue to cycle when it finishes the traversal\n";
	}

	if (program_options.Directory_Skipable() == "yes") {
		outfile << "\t//avoid_dirs - directory names that the file system traversal should not step into\n";
	}

	//chunk comment for the constructors
	outfile << "\t\n\t//start at a certain path relative to yours, put in an absolute path,\n";
	outfile << "\t//or put in nothing and start from the current working directory.\n";
	if (program_options.Cycle() == "optional") {
		outfile << "\t//if the cycle is set to false, the file system traversal will start returning false\n";
		outfile << "\t//when you ask it to step into the next directory.  If the cycle is set to true, it will\n";
		outfile << "\t//essentially begin traversing all over again,  and thus the method \"Move_Into_Next_Directory\",\n";
		outfile << "\t//will always return true.  By default,  it is set to false,  assuming that you would want to loop over\n";
		outfile << "\t//the filesystem only once,  and require a reset if you would like to do it again.\n";
	}

	//first set of actual constructor code
	if (program_options.Cycle() == "optional") {
		outfile << "\tFile_System_Traverser(std::string const& path=\".\", bool const& cycle = false);\n";
		outfile << "\tFile_System_Traverser(bool const& cycle, std::string const& path=\".\");\n";
	}else{
		outfile << "\tFile_System_Traverser(std::string const& path=\".\");\n";
	}

	outfile << "\t\n";

	//constructors that contain avoid_dirs
	if (program_options.Directory_Skipable() == "yes") {
		if (program_options.Cycle() == "optional") {
			outfile << "\tFile_System_Traverser(std::vector<std::string> const& avoid_dirs, std::string const& path=\".\", bool const& cycle = false);\n";
			outfile << "\tFile_System_Traverser(std::vector<std::string> const& avoid_dirs, bool const& cycle, std::string const& path=\".\");\n";
		}else{
			outfile << "\tFile_System_Traverser(std::vector<std::string> const& avoid_dirs, std::string const& path=\".\");\n";
		}
	}

	outfile << "\t\n";

	return;
}
void Create_Header_Move_Into_Next_Directory(std::ofstream & outfile, Program_Options const& program_options) {

	if (program_options.Traversal_Method() == "bfs") { BFS_Comment(outfile);}
	else if (program_options.Traversal_Method() == "in-order") {In_Order_Comment(outfile);}
	else if (program_options.Traversal_Method() == "pre-order") {Pre_Order_Comment(outfile);}
	else if (program_options.Traversal_Method() == "post-order") {Post_Order_Comment(outfile);}
	else if (program_options.Traversal_Method() == "optional") {Optional_Comment(outfile);}

	outfile << "\tbool Move_Into_Next_Directory();\n";
	return;
}
void BFS_Comment(std::ofstream & outfile){

	return;
}
void In_Order_Comment(std::ofstream & outfile){

	return;
}
void Pre_Order_Comment(std::ofstream & outfile){
	//
	return;
}
void Post_Order_Comment(std::ofstream & outfile){

	return;
}
void Optional_Comment(std::ofstream & outfile){

	return;
}
void Create_Header_Reset(std::ofstream & outfile, Program_Options const& program_options) {
	outfile << "\t//when you want to stop in the middle of your traversing,\n";
	outfile << "\t//or traversing has ended and you want to reset the state of the traversal back to the starting path.\n";
	outfile << "\tvoid Reset();\n";
	outfile << "\tvoid Reset(std::string const& path);\n";
	return;
}
void Create_Header_Private_Section(std::ofstream & outfile, Program_Options const& program_options) {
	outfile << "\tprivate:\n\n";
	outfile << "\t\t//the directory given at construction\n";
	outfile << "\t\t//place to start the traversal\n";
	outfile << "\t\tstd::string start_directory;\n\n";

	if (program_options.Directory_Skipable() == "yes") {
		outfile << "\t\t//directories to NOT step into during the traversal\n";
		outfile << "\t\tstd::vector<std::string> avoid_dirs;\n\n";
	}

	if (program_options.Cycle() == "optional") {
		outfile << "\t\t//whether to start the traversal again when the start directory is reached again.\n";
		outfile << "\t\t//if false,  the function \"Move_Into_Next_Directory\" will return false when the start_directory\n";
		outfile << "\t\t//is reached again\n";
		outfile << "\t\tbool cycle;\n\n";
	}

	outfile << "\t\t//a little flag needed to make sure we are just starting,\n";
	outfile << "\t\t//and not returning back to the original directory\n";
	outfile << "\t\tbool just_started = true;\n";
	outfile << "\t\t\n";
	outfile << "\t\t//a stack of each directory and what folder we had last stepped into\n";
	outfile << "\t\t//I wanted to avoid recursion, so instead of utilizing the function stack, here is an actual stack\n";
	outfile << "\t\tstd::stack<std::pair<std::vector<std::string>, int>> traverse_stack;\n";
	outfile << "\t\t\n";
	outfile << "\t\t//used in the constructor to expand instances of \".\" to the pwd\n";
	outfile << "\t\tvoid Set_Starting_Directory(std::string const& path);\n\n";

	if (program_options.Directory_Skipable() == "yes") {
		outfile << "\t\tstd::vector<std::string> Get_Dirs_Of_Current_Directory_Possibly_Filtered();\n\n";
	}

	if (program_options.Cycle() == "optional") {
		outfile << "\t\t//returns the value of cycle, but also handles some reset computation\n";
		outfile << "\t\tbool Possible_Cycle();\n\n";
	}

	outfile << "};";

	return;
}

//source stuff
void Create_Source_Constructor(std::ofstream & outfile, Program_Options const& program_options) {

	outfile << "#include \"file_system_traverser.hpp\"\n";
	outfile << "#include \"utilities.hpp\"\n";
	outfile << "#include <algorithm>\n";
	outfile << "\n";
	outfile << "//constructors\n";


	//first set of actual constructor code
	if (program_options.Cycle() == "optional") {
		outfile << "File_System_Traverser::File_System_Traverser(std::string const& path, bool const& cycle_in)\n";
		outfile << ":cycle(cycle_in)\n";
		outfile << "{Set_Starting_Directory(path);}\n";

		outfile << "File_System_Traverser::File_System_Traverser(bool const& cycle_in, std::string const& path)\n";
		outfile << ":cycle(cycle_in)\n";
		outfile << "{Set_Starting_Directory(path);}\n";

	}else{
		outfile << "File_System_Traverser::File_System_Traverser(std::string const& path)\n";
		outfile << "{Set_Starting_Directory(path);}\n";
	}

	outfile << "\n";

	//constructors that contain avoid_dirs
	if (program_options.Directory_Skipable() == "yes") {
		if (program_options.Cycle() == "optional") {
			outfile << "File_System_Traverser::File_System_Traverser(std::vector<std::string> const& avoid_dirs_in, std::string const& path, bool const& cycle_in)\n";
			outfile << ":avoid_dirs(avoid_dirs_in)\n";
			outfile << ",cycle(cycle_in)\n";
			outfile << "{\n";
			outfile << "\tSet_Starting_Directory(path);\n";
			outfile << "\tstd::sort(avoid_dirs.begin(), avoid_dirs.end());\n";
			outfile << "}\n";
			outfile << "\n";
			outfile << "File_System_Traverser::File_System_Traverser(std::vector<std::string> const& avoid_dirs_in, bool const& cycle_in, std::string const& path)\n";
			outfile << ":avoid_dirs(avoid_dirs_in)\n";
			outfile << ",cycle(cycle_in)\n";
			outfile << "{\n";
			outfile << "\tSet_Starting_Directory(path);\n";
			outfile << "\tstd::sort(avoid_dirs.begin(), avoid_dirs.end());\n";
			outfile << "}\n";
		}else{
			outfile << "File_System_Traverser::File_System_Traverser(std::vector<std::string> const& avoid_dirs_in, std::string const& path)\n";
			outfile << ":avoid_dirs(avoid_dirs_in)\n";
			outfile << "{\n";
			outfile << "\tSet_Starting_Directory(path);\n";
			outfile << "\tstd::sort(avoid_dirs.begin(), avoid_dirs.end());\n";
			outfile << "}\n";
		}

			outfile << "\n";
	}

	return;
}
void Create_Source_Move_Into_Next_Directory(std::ofstream & outfile, Program_Options const& program_options)  {

	outfile << "//transformers\n";
	outfile << "bool File_System_Traverser::Move_Into_Next_Directory() {\n";

	if (program_options.Traversal_Method() == "bfs") { BFS_Impl(outfile);}
	else if (program_options.Traversal_Method() == "in-order") {In_Order_Impl(outfile);}
	else if (program_options.Traversal_Method() == "pre-order") {Pre_Order_Impl(outfile, program_options);}
	else if (program_options.Traversal_Method() == "post-order") {Post_Order_Impl(outfile);}
	else if (program_options.Traversal_Method() == "optional") {Optional_Impl(outfile);}

	return;
}
void BFS_Impl(std::ofstream & outfile) {

	return;
}
void In_Order_Impl(std::ofstream & outfile){

	return;
}
void Pre_Order_Impl(std::ofstream & outfile, Program_Options const& program_options){

outfile << R"foo(
	//first time function is called
	if (traverse_stack.empty()) {
		if (just_started) {
			just_started = false;
			traverse_stack.push(std::pair<std::vector<std::string>, int>()foo";
Possible_Dir_Filter(outfile,program_options);

outfile << R"foo(, 0));

			// if there is a folder we can still step into, step into it
			if (traverse_stack.top().first.size() != traverse_stack.top().second) {
				Step_Into_Folder(traverse_stack.top().first[traverse_stack.top().second]);
				++traverse_stack.top().second;
				traverse_stack.push(std::pair<std::vector<std::string>, int>()foo";
Possible_Dir_Filter(outfile,program_options);
outfile << R"foo(, 0));

			//or you started in an empty folder in which case, you're already done
			}else{return )foo";
Possible_Cycle(outfile,program_options);
outfile << R"foo(;}
		}

		//you called the function again, even though you're done
		else{return )foo";
Possible_Cycle(outfile,program_options);
outfile << R"foo(;}

	//all the other times (aka: each next step of the traversal)
	}else{


		bool new_folder_entered = false;
		while (!new_folder_entered) {

		//step into the next child directory
		if (traverse_stack.top().first.size() != traverse_stack.top().second) {
			Step_Into_Folder(traverse_stack.top().first[traverse_stack.top().second]);
			++traverse_stack.top().second;
			traverse_stack.push(std::pair<std::vector<std::string>, int>()foo";
Possible_Dir_Filter(outfile,program_options);
outfile << R"foo(, 0));
			new_folder_entered = true;

			//no more directories to visit at this level. Step out of the directory
			}else{
				traverse_stack.pop();
				if (traverse_stack.empty()) { return )foo";
Possible_Cycle(outfile,program_options);
outfile << R"foo(;}
				Step_Out_Of_Folder();
			}
		}
	}

	return true;
}
)foo";

	return;
}
void Post_Order_Impl(std::ofstream & outfile){

	return;
}
void Optional_Impl(std::ofstream & outfile){

	return;
}
void Create_Source_Reset(std::ofstream & outfile, Program_Options const& program_options) {

	return;
}
void Create_Source_Private_Section(std::ofstream & outfile, Program_Options const& program_options) {

	//functions always needed
	outfile << constant::RESET_WITH_PATH;
	outfile << constant::RESET;
	outfile << constant::SET_DIR;

	//cycle function used (might be none, and instead the traverse function will return false)
	if (program_options.Cycle() == "optional"){
		outfile << constant::POSSIBLE_CYCLE_IMPL;
	}else if (program_options.Cycle() == "yes"){
		outfile << constant::CYCLE_IMPL;
	}

	//decide to filter (and if not use a function from the pre-jstd)
	if (program_options.Directory_Skipable() == "yes"){
		outfile << constant::GET_DIR_IMPL;
	}

	return;
}

//utility
void Possible_Cycle(std::ofstream & outfile,  Program_Options const& program_options) {
	if (program_options.Cycle() == "optional"){
		outfile << constant::CALL_WHEN_CYCLE_OPTIONAL;
	}else if (program_options.Cycle() == "yes"){
		outfile << constant::CALL_WHEN_CYCLE_ON;
	}else if (program_options.Cycle() == "no"){
		outfile << constant::CALL_WHEN_CYCLE_OFF;
	}
	return;
}
void Possible_Dir_Filter(std::ofstream & outfile,  Program_Options const& program_options) {

	if (program_options.Directory_Skipable() == "yes"){
		outfile << constant::CALL_WHEN_DIR_FILTER_ON;
	}else{
		outfile << constant::CALL_WHEN_DIR_FILTER_OFF;
	}

	return;
}
