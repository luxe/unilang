#pragma once
#include "repository.hpp"

class Root_Repo_Getter{








public: static void Get_Root_Repo(bool const& get_dependencies, std::string const& url, bool const& allow_nested_git_repos);

private: static void Download_Root_Repo(Repository const& repo);};