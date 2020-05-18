#include "repo_getter.hpp"
#include "path_getter.hpp"
#include "utilities.hpp"
#include "global.hpp"









 void Repo_Getter::Store_Repo_Locally_From_Github(Repository const& repo){

	// download the repository from github if needed and make sure it is up-to-date with the branch that it is on
	// we assume merge conflicts don't occur
	auto path_to_repo = Path_Getter::Get_Local_Path_Of_Repo(repo);

	//create the repo in .github if it doesn't exist
	if (!File_Exists(path_to_repo)) {
		execute_quietly("mkdir -p " + constant::LOCAL_GITHUB_ROOT_PATH + repo.User_Name());
		execute_quietly("cd " + constant::LOCAL_GITHUB_ROOT_PATH + repo.User_Name() +  "/; git clone " + repo.SSH_URL());
	}

    return;
}
