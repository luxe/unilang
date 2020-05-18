#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <stack>

class  File_System_Traverser {
	public:
	
	//constructor
	
	//path - what directory to start in
	
	//start at a certain path relative to yours, put in an absolute path,
	//or put in nothing and start from the current working directory.
	File_System_Traverser(std::string const& path=".");
	
	
	bool Move_Into_Next_Directory();
	//when you want to stop in the middle of your traversing,
	//or traversing has ended and you want to reset the state of the traversal back to the starting path.
	void Reset();
	void Reset(std::string const& path);
	private:

		//the directory given at construction
		//place to start the traversal
		std::string start_directory;

		//a little flag needed to make sure we are just starting,
		//and not returning back to the original directory
		bool just_started = true;
		
		//a stack of each directory and what folder we had last stepped into
		//I wanted to avoid recursion, so instead of utilizing the function stack, here is an actual stack
		std::stack<std::pair<std::vector<std::string>, int>> traverse_stack;
		
		//used in the constructor to expand instances of "." to the pwd
		void Set_Starting_Directory(std::string const& path);

};