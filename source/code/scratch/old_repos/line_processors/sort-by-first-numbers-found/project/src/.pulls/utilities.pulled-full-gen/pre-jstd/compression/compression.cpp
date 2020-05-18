bool Make_Tar_GZ_File(std::string const& directory_name){
  return Successful_Run_Of_Command("tar -zcvf " + directory_name + ".tar.gz " + directory_name);
}
  
bool Make_Zip_File(std::string const& directory_name){
  return Successful_Run_Of_Command("zip -r " + directory_name + ".zip " + directory_name);
}
