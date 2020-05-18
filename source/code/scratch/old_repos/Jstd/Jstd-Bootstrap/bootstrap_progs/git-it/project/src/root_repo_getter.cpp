#include "root_repo_getter.hpp"
#include "dependency_getter.hpp"
#include "path_getter.hpp"
#include "repo_getter.hpp"
#include "utilities.hpp"









 void Root_Repo_Getter::Get_Root_Repo(bool const& get_dependencies, std::string const& url, bool const& allow_nested_git_repos){

	//first make sure that we are not already in a git repository (unless we allow that by a special flag being passed)
	if (Inside_Git_Repository()){
		if (!allow_nested_git_repos){
			Exit_With_Red_Error("You shouldn't put a git repo inside a git repo!\n");
		}
	}

	//create a repo type based on the url passed in
    //and quickly validate it before using it
	auto repo = Repository{url};
    if (!repo.Valid_URL()){ Exit_With_Red_Error("Invalid URL: " + url); }
    //if (!repo.Valid()){ Exit_With_Red_Error("Repo not found at: " + url); }

	//if we didn't quit the program from the above if statements,
	//download the repository off of github (or download it from the local .github)
	Download_Root_Repo(repo);

	//also, update all of the dependencies (i.e. perform the symbolic pulling and generate the dependencies)
	if (get_dependencies){
        int percent_current = 0;
        int percent_total = 0;
        Dependency_Getter::Get_Dependencies(0,percent_current,percent_total);
    }

	return;
}

 void Root_Repo_Getter::Download_Root_Repo(Repository const& repo){

    //make sure the repo exists in the local github.
    //if it's not there, it will be cloned there.
    //if it is there, it will updated to the most recent commit
	Repo_Getter::Store_Repo_Locally_From_Github(repo);

	if (!File_Exists(Current_Path() + "/" + repo.Repo_Name())) {
		execute_quietly("ln -s " + Path_Getter::Get_Local_Path_Of_Repo(repo) + " " + Current_Path());
	}

	Step_Into_Folder(repo.Repo_Name());

	return;
}
