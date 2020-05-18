//this hpp and cpp are here just for reference

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <stack>

// TODO:
//  allow different traversals:
//   - BFS [NOT IMPLEMENTED]
//   - DFS
// 		 - In-Order Traversal [NOT IMPLEMENTED]
// 		 - Pre-Order Traversal [CURRENTLY IMPLEMENTED]
// 		 - Post-Order Traversal [NOT IMPLEMENTED]

// option for lexicographical order and reversed lexicographical order

class File_System_Traverser {

	public:

	//constructor

	//- directories to ignore
	//- what directory to start in
	//- whether or not to cycle

	//start at a certain path relative to yours, put in an absolute path,
	//or put in nothing and start from the current working directory.
	//if the cycle is set to false, the file system traversal will start returning false
	//when you ask it to step into the next directory.  If the cycle is set to true, it will
	//essentially begin traversing all over again,  and thus the method "Move_Into_Next_Directory",
	//will always return true.  By default,  it is set to false,  assuming that you would want to loop over
	//the filesystem only once,  and require a reset if you would like to do it again.
	File_System_Traverser(std::string const& path=".", bool const& cycle = false);
	File_System_Traverser(bool const& cycle, std::string const& path=".");

	//provide a list of directory names for the file traverser to skip over
	File_System_Traverser(std::vector<std::string> const& directory_names_not_to_step_into, std::string const& path=".", bool const& cycle = false);
	File_System_Traverser(std::vector<std::string> const& directory_names_not_to_step_into, bool const& cycle, std::string const& path=".");

	//moves to next directory (returns false when all sub files have been traversed and you attempt to go to the next one)
	//so for example,  given a file directory like this in which you are at the root:
	//.
	//|-- 1
	//|   |-- 2
	//|   `-- 3
	//|-- 4
	//|   `-- 5
	//|       `-- 6
	//`-- 7
	//
	//will allow you to call the "Move_Into_Next_Directory" function 7 times,  and during the 8th time,  it will be back at
	//the root and will return false.  If you had set cycle to true in the constructor however,  then it would still return true.
	//therefore if cycle is set to true and this method is put into some kind of loop control structure,  then it would loop forever,
	//and cycle again and again through the directories.
	bool Move_Into_Next_Directory();

	//when you want to stop in the middle of your traversing and start over at a certain path
	//starting directory, if nothing is passed in
	void Reset();
	void Reset(std::string const& path);

	private:

		//the directory given at construction
		//place to start the traversal
		std::string start_directory;

		//directories to NOT step into during the traversal
		std::vector<std::string> avoid_dirs;

		//whether to start the traversal again when the start directory is reached again.
		//if false,  the function "Move_Into_Next_Directory" will return false when the start_directory
		//is reached again
		bool cycle;

		//a little flag needed to make sure we are just starting,
		//and not returning back to the original directory
		bool just_started = true;

		//a stack of each directory and what folder we had last stepped into
		//I wanted to avoid recursion, so instead of utilizing the function stack, here is an actual stack
		std::stack<std::pair<std::vector<std::string>, int>> traverse_stack;

		//used in the constructor to expand instances of "." to the pwd
		void Set_Starting_Directory(std::string const& path);

		//returns the value of cycle, but also handles some reset computation
		bool Possible_Cycle();

		std::vector<std::string> Get_Dirs_Of_Current_Directory_Possibly_Filtered();
};
