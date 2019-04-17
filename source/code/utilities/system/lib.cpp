#include "lib.hpp"
#include "code/utilities/shell/lib.hpp"

std::string whoami(){
	return execute("whoami");
}
std::string hostname(){
    return execute("hostname");
}
std::string env(){
    return execute("env");
}