#include "code/utilities/processes/lib.hpp"
#include "code/utilities/shell/lib.hpp"

bool Process_Is_Running(std::string const& process_name){
  return Successful_Run_Of_Command("pgrep " + process_name);
}
std::string Pid_Of(std::string const& process_name){
    return execute("pidof " + process_name);
}
