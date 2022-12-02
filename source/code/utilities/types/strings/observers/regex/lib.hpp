#pragma once

#include <string>
#include <regex>

bool Matches_Regex(std::string const& str, std::string const& regex);

bool Matches_Any_Regex(std::string const& str, std::vector<std::regex> const& regexes);

std::vector<std::smatch> Get_Regex_Matches(std::vector<std::string> lines, std::string const& regex);
