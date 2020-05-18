#include "include_category.hpp"

//constructor
Include_Category::Include_Category(std::string const& name_in,std::vector<std::string> const& lines_in)
: lines(lines_in)
, name(name_in)
{}

//observers
std::vector<std::string> Include_Category::Lines() const {return lines;}
std::string Include_Category::Name() const {return name;}
