#include "code/utilities/formats/compression/lib.hpp"
#include "code/utilities/shell/lib.hpp"
#include "code/utilities/types/strings/observers/columns/lib.hpp"

bool Make_Tar_GZ_File(std::string const& directory_name){
  return Successful_Run_Of_Command("tar -zcvf " + directory_name + ".tar.gz " + directory_name);
}
  
bool Make_Zip_File(std::string const& directory_name){
  return Successful_Run_Of_Command("zip -r " + directory_name + ".zip " + directory_name);
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