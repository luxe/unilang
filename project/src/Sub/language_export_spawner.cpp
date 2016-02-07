#include "language_export_spawner.hpp"









//default constructor at file beginning
 Language_Export_Spawner::Language_Export_Spawner(std::string const& exporter_name)
              :exporter_name(exporter_name)
             {}

 void Language_Export_Spawner::Add(std::string const& language, std::function<void(const Structure&, const std::vector<Contributor> &, const std::string &)> const& func){
    
  execute_paths.emplace_back(language,func);
}


 void Language_Export_Spawner::Spawn_Language_Exporter(Structure const& structure, std::vector<Contributor> const& contributors, std::string const& language, std::string const& style){

  for (auto const& it: execute_paths){
    if (it.first == language){
      it.second(structure,contributors,style);
      return;
    }
  }

  throw "The " + exporter_name + " exporter does not support the following language: " + language;
}





