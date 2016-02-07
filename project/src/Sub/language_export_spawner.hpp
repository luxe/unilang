#pragma once
#include "systems.hpp"
#include "utilities.hpp"
#include "structure.hpp"
#include "contributor.hpp"

class Language_Export_Spawner{








//default constructor at file beginning
public: Language_Export_Spawner(std::string const& exporter_name);

public: void Add(std::string const& language, std::function<void(const Structure&, const std::vector<Contributor> &, const std::string &)> const& func);


public: void Spawn_Language_Exporter(Structure const& structure, std::vector<Contributor> const& contributors, std::string const& language, std::string const& style);




private:
std::string exporter_name;
std::vector<std::pair<std::string,std::function<void(const Structure&, const std::vector<Contributor> &, const std::string &)>>> execute_paths;


};