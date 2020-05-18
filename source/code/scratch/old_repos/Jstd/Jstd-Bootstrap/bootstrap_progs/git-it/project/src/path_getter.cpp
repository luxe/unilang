#include "path_getter.hpp"
#include "utilities.hpp"
#include "global.hpp"








 std::string Path_Getter::Get_Local_Path_Of_Repo(Repository const& repo){
	std::string home_path = execute("echo $HOME");
	return home_path + "/" + constant::LOCAL_GITHUB_ROOT_DIRECTORY + repo.User_Name() + "/" + repo.Repo_Name();
}