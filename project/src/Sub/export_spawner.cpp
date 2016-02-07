#include "export_spawner.hpp"









//default constructor at file beginning
 Export_Spawner::Export_Spawner(std::string const& exporter_name)
              :exporter_name(exporter_name)
             {}

 void Export_Spawner::Add(std::string const& exporter
                    ,std::function<void(Structure const&, std::vector<Contributor> const&, std::string const&, std::string const&)> const& spawn_to
                    ,std::function<std::vector<Contributor>()> const& contribs){
    
    auto hi = std::make_tuple(exporter,spawn_to,contribs);
    execute_paths.push_back(hi);
}


 void Export_Spawner::Spawn_Exporter(std::string const& exporter, Structure const& structure, std::string const& language, std::string const& style){

  for (auto const& it: execute_paths){
    if (std::get<0>(it) == exporter){
      auto contribs = std::get<2>(it)();
      std::get<1>(it)(structure,contribs,language,style);
      return;
    }
  }

  throw "The " + exporter_name + " exporter does not exist.";
}





