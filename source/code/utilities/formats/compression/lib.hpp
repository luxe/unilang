#pragma once
#include <string>
#include <vector>
#include "code/utilities/filesystem/files/temp/existing_temp_file.hpp"
#include "code/utilities/filesystem/files/moving/lib.hpp"
#include "code/utilities/filesystem/files/creating/lib.hpp"
#include "code/utilities/filesystem/files/getting/lib.hpp"
#include "code/utilities/random/files/random_files.hpp"
#include "code/utilities/types/strings/observers/path/lib.hpp"
#include "code/utilities/filesystem/paths/lib.hpp"
#include "code/utilities/filesystem/files/getting/lib.hpp"

void Make_Tar_GZ_File(std::string const& directory_name);
void Make_TGZ_File(std::string const& directory_name);
void Make_TGZ_File(std::vector<std::string> const& files, std::string const& out_name);
void Make_Zip_File(std::string const& directory_name);

void Extract(std::string const& from, std::string const& into);

std::string Sha256sum_Of_Url_Artifact(std::string const& url);

template <typename Fun>
void Unzip_Do_Rezip_TGZ(std::string const& filename, Fun fun){
    
    auto base_name = Get_File_Name_Without_Extension(filename);
    std::cout << base_name << std::endl;
    
    //create a scope-lived /tmp/xxx
    auto tmp = Random_Files::Random_Tmp_Directory();
    Create_Path_If_It_Doesnt_Already_Exist(tmp);
    Existing_Temp_File x(tmp,true);
    std::cout << tmp << std::endl;
    
    //extract the data into the tmp folder
    std::cout << "extracting..." << std::endl;
    Extract(filename,tmp);
    
    //do the user provided changes to content
    fun(tmp);
    
    //where to re-create the zip
    auto tmp2 = Random_Files::Random_Tmp_Directory();
    Create_Path_If_It_Doesnt_Already_Exist(tmp2);
    Existing_Temp_File x2(tmp2,true);
    std::cout << tmp2 << std::endl;
    
    //rezip
    auto extracted_content = Get_Full_Paths_Of_Everything_At_Path(tmp);
    std::cout << "taring..." << std::endl;
    Make_TGZ_File(extracted_content,tmp2 + "/" + base_name);
    
    auto final_file = tmp2 + "/" + base_name + ".tgz";
    
    //rewrite
    execute("mv -f " + final_file + " " + filename + "_v2");
}
