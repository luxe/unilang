#include "file_system_traverser.hpp"
#include "utilities.hpp"
#include <algorithm>

//constructors
File_System_Traverser::File_System_Traverser(std::string const& path, bool const& cycle_in)
:cycle(cycle_in)
{Set_Starting_Directory(path);}

File_System_Traverser::File_System_Traverser(bool const& cycle_in, std::string const& path)
:cycle(cycle_in)
{Set_Starting_Directory(path);}

File_System_Traverser::File_System_Traverser(std::vector<std::string> const& directory_names_not_to_step_into, std::string const& path, bool const& cycle_in)
:avoid_dirs(directory_names_not_to_step_into)
,cycle(cycle_in)
{
	Set_Starting_Directory(path);
	std::sort(avoid_dirs.begin(), avoid_dirs.end());
}

File_System_Traverser::File_System_Traverser(std::vector<std::string> const& directory_names_not_to_step_into, bool const& cycle_in, std::string const& path)
:avoid_dirs(directory_names_not_to_step_into)
,cycle(cycle_in)
{
	Set_Starting_Directory(path);
	std::sort(avoid_dirs.begin(), avoid_dirs.end());
}

//transformers
bool File_System_Traverser::Move_Into_Next_Directory() {

	//first time function is called
	if (traverse_stack.empty()) {
		if (just_started) {
			just_started = false;
			traverse_stack.push(std::pair<std::vector<std::string>, int>(Get_Dirs_Of_Current_Directory_Possibly_Filtered(), 0));

			// if there is a folder we can still step into, step into it
			if (traverse_stack.top().first.size() != traverse_stack.top().second) {
				Step_Into_Folder(traverse_stack.top().first[traverse_stack.top().second]);
				++traverse_stack.top().second;
				traverse_stack.push(std::pair<std::vector<std::string>, int>(Get_Dirs_Of_Current_Directory_Possibly_Filtered(), 0));

			//or you started in an empty folder in which case,  you're already done
			}else{return Possible_Cycle();}
		}

		//you called the function again, even though you're done
		else{return Possible_Cycle();}

	//all the other times (aka: each next step of the traversal)
	}else{


		bool new_folder_entered = false;
		while (!new_folder_entered) {

		//step into the next child directory
		if (traverse_stack.top().first.size() != traverse_stack.top().second) {
			Step_Into_Folder(traverse_stack.top().first[traverse_stack.top().second]);
			++traverse_stack.top().second;
			traverse_stack.push(std::pair<std::vector<std::string>, int>(Get_Dirs_Of_Current_Directory_Possibly_Filtered(), 0));
			new_folder_entered = true;

			//no more directories to visit at this level. Step out of the directory
			}else{
				traverse_stack.pop();
				if (traverse_stack.empty()) { return Possible_Cycle(); }
				Step_Out_Of_Folder();
			}
		}
	}

	return true;
}
void File_System_Traverser::Reset(std::string const& path) {

	//empty stack and go back to the starting directory
	while (!traverse_stack.empty()){traverse_stack.pop();}
	just_started = true;
	Set_Path(path);
	return;
}
void File_System_Traverser::Reset() {

	//empty stack and go back to the starting directory
	while (!traverse_stack.empty()){traverse_stack.pop();}
	just_started = true;
	Set_Path(start_directory);
	return;
}

void File_System_Traverser::Set_Starting_Directory(std::string const& path) {

	if (path == ".") {
		start_directory = getenv ("PWD");
	}else{
		start_directory = path;
		Set_Path(path);
	}

	return;
}
bool File_System_Traverser::Possible_Cycle() {
	if (cycle) {Reset();}
	return cycle;
}
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
