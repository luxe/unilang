#include <string>
#include <iostream>
#include <SFML/Window/Joystick.hpp>
#include "code/utilities/keyboard/joycons/joycon_state_getter.hpp"
#include "code/utilities/json/functions/lib.hpp"

//jstest-gtk to toy visually
int main()
{
    while (true){
        auto joys = Joycon_State_Getter::Get();
        std::cout << As_JSON_String(joys) << std::endl;
    }

    return 0;
}