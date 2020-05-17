//general system stuff

// exec
std::string exec(std::string const& cmd){
	return exec(cmd.c_str());
}
std::string exec(const char* cmd) {
    FILE* pipe = popen(cmd, "r");
    if (!pipe) return "ERROR";
    char buffer[128];
    std::string result = "";
    while(!feof(pipe)) {
    	if(fgets(buffer, 128, pipe) != NULL)
    		result += buffer;
    }
    pclose(pipe);
		if (result.size() > 0){
	result.resize(result.size()-1);
	}
    return result;
}
std::string exec_quietly(std::string const& cmd) {
	return exec((cmd + " > /dev/null 2>&1").c_str());
}
std::string exec_quietly(const char* cmd) {
	return exec(std::string(cmd) + " > /dev/null 2>&1");
}

// execute
std::string execute(std::string const& cmd) {
	return exec(cmd.c_str());
}
std::string execute(const char* cmd) {
	return exec(cmd);
}
std::string execute_quietly(std::string const& cmd) {
	return exec_quietly(cmd.c_str());
}
std::string execute_quietly(const char* cmd) {
	return exec_quietly(cmd);
}

// system
void system(std::string const& cmd) {
	system(cmd.c_str());
}
