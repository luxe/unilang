#pragma once
#include <string>

bool Make_Tar_GZ_File(std::string const& directory_name);
bool Make_Zip_File(std::string const& directory_name);

std::string Sha256sum_Of_Url_Artifact(std::string const& url);
