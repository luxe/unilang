#include "code/utilities/program/processes/lib.hpp"
#include "code/utilities/program/call/lib.hpp"

bool Process_Is_Running(std::string const& process_name){
  return Successful_Run_Of_Command("pgrep " + process_name);
}
std::string Pid_Of(std::string const& process_name){
    return execute("pidof " + process_name);
}
std::string Wait_Until_We_Have_A_Pid_Of(std::string const& process_name)
{
    bool found = false;
    std::string pid;
    while(!found){
        pid = Pid_Of(process_name);
        if (!pid.empty()){
            found = true;
        }
    }
    
    return pid;
}
void Send_Ctrl_C_To_Pid(std::string const& pid)
{
    execute("sudo kill -SIGINT " + pid);
}

//xdotool search --onlyvisible --name zenity
//xdotool windowactivate 58734224