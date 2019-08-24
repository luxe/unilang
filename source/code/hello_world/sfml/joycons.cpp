#include <string>
#include <iostream>
#include <SFML/Window/Joystick.hpp>
#include "code/utilities/keyboard/joycons/joycons.hpp"
#include "code/utilities/keyboard/joycons/joycon_state_getter.hpp"
#include "code/utilities/json/functions/lib.hpp"

//jstest-gtk to toy visually
int main(){
    
    Joycon_Horizontal_State state;
    
    while (true){
        
        auto joys = Joycon_State_Getter::Get();
        
        
        std::cout << As_JSON_String(joys) << std::endl;
        
        //std::cout << sf::Joystick::getAxisPosition(0, sf::Joystick::PovX) << std::endl;
        
        
    }
}