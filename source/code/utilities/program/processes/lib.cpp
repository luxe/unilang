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

void Bring_Window_Name_Into_Forground(std::string const& name)
{
    auto id = execute("xdotool search --onlyvisible --name '" + name + "'");
    if (!id.empty()){
        execute("xdotool windowactivate " + id);
    }
}

void Wait_Until_Window_Name_Is_Brought_Into_Forground(std::string const& name)
{
    std::string id;
    while (id.empty()){
        id = execute("xdotool search --onlyvisible --name '" + name + "'");
    }
    
    execute("xdotool windowactivate " + id);
}