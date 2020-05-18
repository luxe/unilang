bool Inside_Git_Repository(){
	return Directory_Exists_In_Current_Directory_Or_Any_Parents(".git");
}

bool Git_Repo_Dirty(){
	return Get_Return_Value_Of_Running("git diff-index --quiet HEAD --;");
}
bool Repo_Exists_On_Github(std::string const& user_name, std::string const& repo_name){
//return Successful_Run_Of_Command("wget -q --spider address https://github.com/" + user_name + "/" + repo_name);
return Successful_Run_Of_Command("curl -s --head https://github.com/" + user_name + "/" + repo_name + " | head -n 1 | grep \"HTTP/1.[01] [23]..\"");
}
void Create_Repo_On_Github(std::string const& user_name, std::string const& autorization, std::string const& project_name, std::string const& description){
exec_quietly("curl -u \"" + user_name + ":" + autorization + "\" https://api.github.com/user/repos -d '{\"name\": \"" + project_name + "\", " + "\"description\": \"" + description + "\"}'");
}
std::string Get_Path_Of_Directory_Starting_At_Git_Repo_Root(){
	return Get_Path_Of_Directory_Starting_From_Root_Directory_Name(".git");
}
void Go_To_Git_Repo_Root(){
	return Move_Back_Directories_Until_Directory_Exists(".git");
}
unsigned int Number_Of_Directories_Deep_In_Git_Repo(){
	return Number_Of_Directories_Deep_In_Root_Directory_Name(".git");
}
std::string Get_Project_Name(){
	return execute("basename `git rev-parse --show-toplevel`");
}
std::string Get_Project_URL(){
	return execute("git ls-remote --get-url");
}
std::string Current_Git_Branch_Name(){
	return execute("git rev-parse --abbrev-ref HEAD");
}
