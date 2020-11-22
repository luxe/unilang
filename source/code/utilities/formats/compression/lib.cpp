#include "code/utilities/formats/compression/lib.hpp"
#include "code/utilities/program/call/lib.hpp"
#include "code/utilities/types/strings/observers/columns/lib.hpp"
#include "code/utilities/program/call/process_spawn/process_spawner.hpp"

void Make_Tar_GZ_File(std::string const& directory_name){
  
  std::string command = "tar -zcvf " + directory_name + ".tar.gz " + directory_name;
  //std::cout << command << std::endl;
  auto results = Process_Spawner::Execute_And_Get_Back_Results(command);
  std::cout << results.stderr << std::endl;
}
void Make_TGZ_File(std::string const& directory_name){
  
  auto results = Process_Spawner::Execute_And_Get_Back_Results("tar -zcvf " + directory_name + ".tgz " + directory_name);
  std::cout << results.stderr << std::endl;
}
void Make_TGZ_File(std::string const& location, std::vector<std::string> const& files, std::string const& out_name){
    
    std::string command = "tar -zcvf " + out_name + ".tgz ";
    command += " -C " + location + " ";
    for (auto const& file: files){
        command += file + " ";
    }
    
  //std::cout << command << std::endl;
  auto results = Process_Spawner::Execute_And_Get_Back_Results(command);
  std::cout << results.stderr << std::endl;
}
  
void Make_Zip_File(std::string const& directory_name){
  auto results = Process_Spawner::Execute_And_Get_Back_Results("zip -r " + directory_name + ".zip " + directory_name);
}

void Extract(std::string const& from, std::string const& into){
    std::string command = "tar -xvzf " + from + " -C " + into;
    //std::cout << command << std::endl;
    auto results = Process_Spawner::Execute_And_Get_Back_Results(command);
    std::cout << results.stderr << std::endl;
}

std::string Sha256sum_Of_Url_Artifact(std::string const& url)
{
    //TODO(thickey) we can get the raw data directly from wget and pipe it into sha256sum
    
    //decide where to put the downloaded artifact
    std::string path = "/tmp/";
    
    //decide the full name of the file
    path += "should_be_guid";
    
    //download the file to a temp directory
    std::string command = "wget " + url + " -O " + path;
    execute_quietly(command);
    
    //calculate the sum
    command = "sha256sum " + path;
    auto results = execute(command);
    auto answer = Get_1st_Column(results);
    
    //todo: delete the file
    
    return answer;
}