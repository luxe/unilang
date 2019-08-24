#include <string>
#include <iostream>
#include <SFML/Window/Joystick.hpp>
#include <SFML/Window.hpp>
#include "code/utilities/keyboard/joycons/joycon_state_getter.hpp"
#include "code/utilities/json/functions/lib.hpp"

//jstest-gtk to toy visually
void Main_Logic(){
    std::cout << "sdfsdf" << std::endl;
        // auto joys = Joycon_State_Getter::Get();
        // std::cout << As_JSON_String(joys) << std::endl;
}


int main()
{
    sf::Window window(sf::VideoMode(800, 600), "My window");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
         Main_Logic();
    }

    return 0;
}