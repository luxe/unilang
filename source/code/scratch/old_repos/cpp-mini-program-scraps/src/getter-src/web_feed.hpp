#pragma once
#include <string>
#include <cstdlib>
#include <vector>
#include "website.hpp"

//A web feed is a data structure that represents a webpage
//from a certain site, as well as how long to refresh the feed
struct Web_Feed {

	//constructor
	Web_Feed(std::string const& name_in, Website const& website_in, std::string const& url_in)
	  : name(name_in)
      , website(website_in)
	  , url(url_in)
	{}

	//data members
	std::string name; // what the website calls labels their feed as (example: cpp-qt) 
	Website website;  // enumerated type of web domain 
	std::string url;  // the full url to the web feed 
};
