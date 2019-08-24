#include <string>
#include <iostream>
#include <SFML/Window/Joystick.hpp>
#include "code/utilities/keyboard/joycons/joycon_horizontal_state.hpp"
#include "code/utilities/json/functions/lib.hpp"

//jstest-gtk to toy visually
int main(){
    
    Joycon_Horizontal_State state;
    
    while (true){
        
        sf::Joystick::update();
        
        state.down = sf::Joystick::isButtonPressed(0, 0);
        state.right = sf::Joystick::isButtonPressed(0, 1);
        state.left = sf::Joystick::isButtonPressed(0, 2);
        state.up = sf::Joystick::isButtonPressed(0, 3);
        state.sl = sf::Joystick::isButtonPressed(0, 4);
        state.sr = sf::Joystick::isButtonPressed(0, 5);
        std::cout << As_JSON_String(state) << std::endl;
        
        
    }
}