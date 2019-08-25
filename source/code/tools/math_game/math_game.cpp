#include <string>
#include <iostream>
#include <vector>
#include <SFML/Window/Joystick.hpp>
#include <SFML/Window.hpp>
#include "code/utilities/keyboard/joycons/joycon_state_getter.hpp"
#include "code/utilities/json/functions/lib.hpp"

//jstest-gtk to toy visually
void Main_Logic(sf::Clock const& clock){
    //std::cout << "sdfsdf" << std::endl;
        // auto joys = Joycon_State_Getter::Get();
        // std::cout << As_JSON_String(joys) << std::endl;
    
    if (clock.getElapsedTime().asSeconds() > 10){
        exit(0);
    }
}


void Print_All_Video_Modes(){
    // Display the list of all the video modes available for fullscreen
    std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
    for (std::size_t i = 0; i < modes.size(); ++i)
    {
        sf::VideoMode mode = modes[i];
        std::cout << "Mode #" << i << ": "
                  << mode.width << "x" << mode.height << " - "
                  << mode.bitsPerPixel << " bpp" << std::endl;
    }
}


int main()
{
    //Print_All_Video_Modes();
    //exit(0);
    
    //create window
    sf::Window window(sf::VideoMode::getDesktopMode(), "My window"/*,sf::Style::Fullscreen*/);
    
    //avoid graphics tearing
    window.setVerticalSyncEnabled(true);
    
    sf::Clock clock;

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            
            switch(event.type){
               // window closed
                case sf::Event::Closed:
                    window.close();
                    break;

                // key pressed
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Escape){
                        std::cout << "leaving" << std::endl;
                        window.close();
                    }
                    break;

                // we don't process other types of events
                default:
                    break;
            }
        }
        
        Main_Logic(clock);
    }

    return 0;
}