#include "symbolic_puller.hpp"
#include "dependency_getter.hpp"
#include "path_getter.hpp"
#include "repo_getter.hpp"
#include "symbolic_runner.hpp"
#include "utilities.hpp"










 void Symbolic_Puller::Pull_File(std::string const& path_to_file, unsigned int depth, int percent_current, int percent_total){


	if (depth > 15){ Exit_With_Error("I THINK WE'VE GONE TOO DEEP.  YOU MIGHT BE STUCK!"); }
    
	std::ifstream infile(path_to_file);

	//get repo name and flag values
    std::string line = Get_Line(infile);
	Repository repo(line);
    if (!repo.Valid_URL()){ Exit_With_Red_Error("Invalid URL: " + line); }
    //if (!repo.Valid()){ Exit_With_Red_Error("Repo not found at: " + line); }
	auto flags = Get_Rest_Of_File_As_String(infile);

    if (depth == 0){
        std::cout << "[" << percent_current << "/" << percent_total << "] " << repo.Title() << std::endl;
    }
	Repo_Getter::Store_Repo_Locally_From_Github(repo);

	//save the current path, so that we can reset it
	//after jumping around pulling in dependencies
	auto current_path = Current_Path();

	auto dependency_path = Path_Getter::Get_Local_Path_Of_Repo(repo);

	//step into the dependency
	Set_Path(dependency_path);

	//get all of its dependencies
	Dependency_Getter::Get_Dependencies(depth+1,percent_current,percent_total);

	//reset the path back to where we were originally now
	//we are done pulling in the dependencies
	Set_Path(current_path);

	//run the symbolic pull-in now that it's dependencies have been gotten
	Symbolic_Runner::Run_Symbolic_Pullin_Program(dependency_path,flags,path_to_file,repo,depth);

    return;
}
