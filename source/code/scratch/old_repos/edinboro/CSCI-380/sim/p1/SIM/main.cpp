/*

*/

//system
#include <iostream>
#include <string>
#include <cstdlib>

//relative
#include "classes/program_options/program_options.hpp"
#include "classes/SIM/SIM.hpp"
#include "classes/shut_down_code/shut_down_code.hpp"

namespace{
//=================================================================
//FUNCTIONS

//set up locale for Unicode support
void Set_Locale(void);

//every operating system that you want to boot and run 
//must be default construct-able and have a Run function.
template<class operating_system>
auto Boot_And_Run_Operating_System(Program_Options const& program_options) -> Shut_Down_Code;

//when the operating shuts down, it sends a message back to
//the hardware. the hardware will handle this message here. 
void Handle_Operating_System_Shutdown(Shut_Down_Code const& shut_down_code, bool & reboot);
//=================================================================
}

//this represents the boot process.
//we will boot and load an operating system.
int main(int argc, char** argv/*, char **envp, char **apple*/){
	
	//parse the command line options so that the
	//simulation can be run according to specific parameters.
	Program_Options program_options(argc,argv);
	
	//unicode support [english]
	Set_Locale();
	
	//boot and run a particular operating system.
	//we might run it multiple times if reboots are triggered
	bool reboot{false};
	do{
		
		//boot and run
		//capture the reason for operating system's shutdown
		auto shut_down_code (Boot_And_Run_Operating_System<SIM>(program_options));
		
		//the operating system has shut down(..or crashed).
		//handle the information it sent to the hardware here.
		Handle_Operating_System_Shutdown(shut_down_code,reboot);
		
	} while(reboot);
	
	//can a simulation fail? NO!
	//but the simulation OF THE OPERATING SYSTEM can.
	//if so, it is handled before the closing of this program.
	return EXIT_SUCCESS;
}

namespace{
// //=================================================================
//FUNCTIONS
void Set_Locale(void){
	char* locale = setlocale(LC_ALL, "");
    setlocale(LC_ALL, locale);
	return;
}
template<class operating_system>
auto Boot_And_Run_Operating_System(Program_Options const& program_options) -> Shut_Down_Code{
	SIM sim;
	sim.Setup(program_options.Files());
	return sim.Run();
}
void Handle_Operating_System_Shutdown(Shut_Down_Code const& shut_down_code, bool & reboot){
	reboot = false;
	return;
}
//=================================================================
}
