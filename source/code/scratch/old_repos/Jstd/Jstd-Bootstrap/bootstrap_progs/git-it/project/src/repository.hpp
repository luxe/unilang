#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

class Repository{









private:
    bool valid_url=false;  //the url is well-formatted
    bool valid_repo=false; //the url actually points to an existing repo that is downloadable
    bool cached = false;
    std::string user_name;
    std::string repo_name;


public:
//construct a repo object based on either an ssh url or an http url
Repository(std::string const& url);
Repository(std::string const& user_name_in, std::string const& repo_name_in)
;

//getters
std::string User_Name() const;
std::string Repo_Name()const ;
std::string Title()const;
std::string Web_URL()const ;
std::string HTTPS_URL()const ;
std::string SSH_URL()const ;
bool Valid_URL()const ;
bool Valid() ;

private:
void Prase_HTTPS_Url(std::string const& url);
void Prase_SSH_Url(std::string const& url);
void Prase_Web_Url(std::string const& url);
	};