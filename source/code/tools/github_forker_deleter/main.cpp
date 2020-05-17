#include <iostream>
#include "code/utilities/github/user_forked_repos_getter.hpp"

int main(){
    
    auto repos = User_Forked_Repos_Getter::Get("luxe");
    
    for (auto it: repos){
        std::cout << it["full_name"] << std::endl;
    }
    //std::cout << repos.dump(1) << std::endl;
}