#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h>



//utility
std::string exec(std::string const& cmd);
std::string exec(const char* cmd);
std::string do_readlink(std::string const& path);
std::string get_selfpath();

int main(int argc, char** argv)
{
  std::cout << argv[0] << std::endl;
  std::string selfpath = get_selfpath();
  std::cout << exec("cd " + selfpath + "; pwd") << std::endl;
  std::cout << selfpath << std::endl;
  return 0;
}

//utility
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
    return result;
}
std::string do_readlink(std::string const& path) {
    char buff[1024];
    ssize_t len = ::readlink(path.c_str(), buff, sizeof(buff)-1);
    if (len != -1) {
      buff[len] = '\0';
      return std::string(buff);
    } else {
     /* handle error condition */
    }
}
std::string get_selfpath() {
    char buff[1024];
    ssize_t len = ::readlink("/proc/self/exe", buff, sizeof(buff)-1);
    if (len != -1) {
      buff[len] = '\0';
      return std::string(buff);
    } else {
     /* handle error condition */
    }
}