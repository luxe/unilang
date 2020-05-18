#include "repository.hpp"
#include "utilities.hpp"












//construct a repo object based on either an ssh url or an http url
Repository::Repository(std::string const& url){

    if (Begins_With(url,"https://github.com/")){
        
        //handle the url if it's https
        if (Ends_With(url,".git")){
            Prase_HTTPS_Url(url);
        }
        
        //handle the url if it's web url
        else{
            Prase_Web_Url(url);
        }
    }
    
    //handle the url if it's ssh
    else if(Begins_With(url,"git@github.com:") and Ends_With(url,".git")){
        Prase_SSH_Url(url);
    }
    
    //if none of the parse functions are hit, the repo remains in an invalid state
    //noted by the boolean member values
}
Repository::Repository(std::string const& user_name_in, std::string const& repo_name_in)
            : valid_url(true)
            , user_name(user_name_in)
            , repo_name(repo_name_in)
            
{}

//getters
std::string Repository::User_Name() const{
    return user_name;
}
std::string Repository::Repo_Name()const {
    return repo_name;
}
std::string Repository::Title()const{
    return user_name + '/' + repo_name;
}
std::string Repository::Web_URL()const {
    return "https://github.com/" + user_name + "/" + repo_name;
}
std::string Repository::HTTPS_URL()const {
    return "https://github.com/" + user_name + "/" + repo_name + ".git";
}
std::string Repository::SSH_URL()const {
    return "git@github.com:" + user_name + "/" + repo_name + ".git";
}
bool Repository::Valid_URL()const {
    return valid_url;
}
bool Repository::Valid() {
    
    if (valid_url){
        //test url location for repo
        if (!cached){
            valid_repo = Repo_Exists_On_Github(user_name,repo_name);
            cached = true;
        }
    }
        
    return valid_repo;
}


void Repository::Prase_HTTPS_Url(std::string const& url){
    valid_url = true;
    auto it = Split_By_Char(url.substr(19),'/');
    user_name = it.first;
    repo_name = As_Removed_Suffix(it.second);
}
void Repository::Prase_SSH_Url(std::string const& url){
    valid_url = true;
    auto it = Split_By_Char(url.substr(15),'/');
    user_name = it.first;
    repo_name = As_Removed_Suffix(it.second);
}
void Repository::Prase_Web_Url(std::string const& url){
    valid_url = true;
    auto it = Split_By_Char(url.substr(19),'/');
    user_name = it.first;
    repo_name = it.second;
}
	