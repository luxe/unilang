#include "dependency_getter.hpp"
#include "file_system_traverser.hpp"
#include "symbolic_puller.hpp"
#include "utilities.hpp"











 void Dependency_Getter::Get_Dependencies(unsigned int depth, int percent_current, int percent_total){

	File_System_Traverser file_traverser;
	std::vector<std::string> paths_that_have_pulls;

	//store the path if it contains a pull folder
	auto current_directories = Get_Dirs_Of_Path(".");
	Record_Path_If_It_Contains_A_Pull_Directory(current_directories, paths_that_have_pulls);

	//recursively check all of the other directories and record
	//any other paths that contain a pull folder
	//(we don't step into pull folders to look for more)
	while (file_traverser.Move_Into_Next_Directory()) {
		current_directories = Get_Dirs_Of_Path(".");
		Record_Path_If_It_Contains_A_Pull_Directory(current_directories, paths_that_have_pulls);
	}

	//sort the list of pull directory locations by depth
	//we do this, because some symbolic pull-ins may generate .sympull files further up the tree
	std::sort(paths_that_have_pulls.begin(), paths_that_have_pulls.end(),
		[](std::string const& s1, std::string const& s2) -> bool{

			//this way of getting path depth assumes the path is not sumbolic and doesn't have any backwards steps (i.e. ../ )
			//The strings we are getting are full paths that start with a root slash and end without a slash.
			//therefore, just counting the slashes gives us the right depth
			return Count_Instances_Of_Character(s1, '/') > Count_Instances_Of_Character(s2, '/');
		});

	//we jump to all the directories that require symbolic pull-ins
	Perform_Pulls(paths_that_have_pulls,depth,percent_current,percent_total);

	return;
}

 void Dependency_Getter::Perform_Pulls(std::vector<std::string> const& paths_that_have_pulls, unsigned int depth, int percent_current, int percent_total){

	//save the current path, so that we can reset it
	//after jumping around pulling in dependencies
	auto current_path = Current_Path();
    
    //(only happens once at root)
    if (depth == 0){
        
        //get total root dependencies
        for (auto const& it: paths_that_have_pulls){
            percent_total += Get_Number_Of_Files_In_Directory(it + "/.pulls/");
        }
        
        //show that amount
        if (percent_total > 0){
            Output_And_Flush("\nGenerating content from " + std::to_string(percent_total) + " Dependencies:\n");
        }else{
            Output_And_Flush("\nNo Dependencies.\n");
        }
    }


	for (auto const& it: paths_that_have_pulls) {
		//perform pulls on each directory that requires it
		Perform_Directory_Pull(it,percent_current,percent_total,depth);
	}

	//reset the path back to where we were originally now
	//we are done pulling in the dependencies
	Set_Path(current_path);

	return;
}

 void Dependency_Getter::Perform_Directory_Pull(std::string const& path, int & percent_current, int percent_total, unsigned int depth){
	Set_Path(path +"/.pulls");
	auto pull_files = Get_Regular_Files_Of_Path();
    for (size_t i = 0; i < pull_files.size(); ++i) {
        if (depth == 0) { ++percent_current;}
		Symbolic_Puller::Pull_File(pull_files[i],depth,percent_current,percent_total);
	}

	return;
}


 void Dependency_Getter::Record_Path_If_It_Contains_A_Pull_Directory(std::vector<std::string> const& current_directories, std::vector<std::string> & paths_that_have_pulls){
	for (auto const& it: current_directories) {
		if (it == ".pulls") {
			paths_that_have_pulls.push_back(Full_Path());
			return;
		}
	}
	return;
}
