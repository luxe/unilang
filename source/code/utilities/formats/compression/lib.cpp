#include "code/utilities/formats/compression/lib.hpp"
#include "code/utilities/program/call/lib.hpp"
#include "code/utilities/types/strings/observers/columns/lib.hpp"

bool Make_Tar_GZ_File(std::string const& directory_name){
  return Successful_Run_Of_Command("tar -zcvf " + directory_name + ".tar.gz " + directory_name);
}
bool Make_TGZ_File(std::string const& directory_name){
  return Successful_Run_Of_Command("tar -zcvf " + directory_name + ".tgz " + directory_name);
}
bool Make_TGZ_File(std::vector<std::string> const& files, std::string const& out_name){
    
    std::string command = "tar -zcvf " + out_name + ".tgz ";
    for (auto const& file: files){
        command += file + " ";
    }
  return Successful_Run_Of_Command(command);
}
  
bool Make_Zip_File(std::string const& directory_name){
  return Successful_Run_Of_Command("zip -r " + directory_name + ".zip " + directory_name);
}

bool Extract(std::string const& from, std::string const& into){
    return Successful_Run_Of_Command("tar -xvzf " + from + " -C " + into);
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