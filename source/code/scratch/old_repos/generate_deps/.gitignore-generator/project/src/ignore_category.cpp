#include "ignore_category.hpp"

//constructor
Ignore_Category::Ignore_Category(std::string const& name_in,std::vector<std::string> const& lines_in)
: lines(lines_in)
, name(name_in)
{}

//observers
std::vector<std::string> Ignore_Category::Lines() const {return lines;}
std::string Ignore_Category::Name() const {return name;}
