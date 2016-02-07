#pragma once
#include "systems.hpp"
#include "utilities.hpp"
#include "structure.hpp"
#include "contributor.hpp"

class Export_Spawner{








//default constructor at file beginning
public: Export_Spawner(std::string const& exporter_name);

public: void Add(std::string const& exporter
                    ,std::function<void(Structure const&, std::vector<Contributor> const&, std::string const&, std::string const&)> const& spawn_to
                    ,std::function<std::vector<Contributor>()> const& contribs);


public: void Spawn_Exporter(std::string const& exporter, Structure const& structure, std::string const& language, std::string const& style);




private:
std::string exporter_name;
std::vector<std::tuple<std::string
  ,std::function<void(Structure const&, std::vector<Contributor> const&, std::string const&, std::string const&)>
  ,std::function<std::vector<Contributor>()>
  >> execute_paths;


};