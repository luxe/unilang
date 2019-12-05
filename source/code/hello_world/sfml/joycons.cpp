#include <string>
#include <iostream>
#include <SFML/Window/Joystick.hpp>
#include "code/utilities/keyboard/joycons/joycon_state_getter.hpp"
#include "code/utilities/json/functions/lib.hpp"


//setting up the joycons are stupid.
//you have to run this jcdriver program
//https://github.com/riking/joycon
//git clone git@github.com:riking/joycon.git
//might be in: /home/laptop/go/bin/jcdriver
//then type sync
//the go your bluetooth devices and search for devices
//find the device and try to pair it.
//it might say there are errors and stuff in ubuntu, but it will usually work
//you can run this program to verify.

//jstest-gtk to toy with visually
int main()
{
    while (true){
        auto joys = Joycon_State_Getter::Get();
        std::cout << As_JSON_String(joys) << std::endl;
    }

    return 0;
}