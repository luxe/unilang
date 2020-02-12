#include <string>
#include <iostream>
#include <SFML/Window/Joystick.hpp>
#include "code/utilities/peripheral/keyboard/F310_gamepad/functions/f310_gamepads_state_getter.hpp"
#include "code/utilities/formats/json/functions/lib.hpp"

int main()
{
    while (true){
        auto controllers = F310_Gamepads_State_Getter::Get();
        std::cout << As_JSON_String(controllers) << std::endl;
    }

    return 0;
}