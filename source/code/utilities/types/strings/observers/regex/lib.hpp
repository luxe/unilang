#pragma once

#include <string>
#include <regex>

bool Matches_Regex(std::string const& str, std::string const& regex);

bool Matches_Any_Regex(std::string const& str, std::vector<std::regex> const& regexes);
