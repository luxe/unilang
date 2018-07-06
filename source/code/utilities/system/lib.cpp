#include "lib.hpp"
#include "code/utilities/shell/lib.hpp"

std::string whoami(){
	return execute("whoami");
}