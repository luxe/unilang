#include <string>
#include <iostream>
#include <vector>
#include <SFML/Window/Joystick.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "code/utilities/keyboard/joycons/joycon_state_getter.hpp"
#include "code/utilities/json/functions/lib.hpp"
#include "code/tools/math_game/assets/assets_loader.hpp"

void Frame_Logic(sf::RenderWindow & window, Assets & assets){
    
    window.clear(sf::Color(50, 127, 168));
    
    // auto joys = Joycon_State_Getter::Get();
    // std::cout << As_JSON_String(joys) << std::endl;
    //texture.update(window,0,0);
    //window.draw(sprite);
    
    window.draw(assets.main_bg.sprite);
    window.draw(assets.title_text);
    
    window.display();
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

void Handle_Events(sf::RenderWindow & window){
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
                    window.close();
                }
                break;

            // we don't process other types of events
            default: break;
        }
    }
}


int main()
{
    
    //Create the main window.
    //note: if you do a bad (possibly unsupported resolution), it will go fullscreen but freeze
    //and then you have just a black screen and you have to restart the machine.
    //I don't even know if the application ends up exiting and my OS just never recovers.
    //But I can't even go to a different ubuntu session.  I couldn't figure out anything but
    //restarting the machine.  Not good.  Probably the best thing to do, is go with the desktop mode for now.
    //Another idea would be to make sure the desired resolution is supported by the machine.
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Math Game",sf::Style::Fullscreen);
    
    //avoid graphics tearing
    //Sometimes, when your application runs fast, you may notice visual artifacts such as tearing.
    //The reason is that your application's refresh rate is not synchronized with the vertical frequency of the monitor,
    //and as a result, the bottom of the previous frame is mixed with the top of the next one.
    //The solution to this problem is to activate vertical synchronization.
    //It is automatically handled by the graphics card,
    //and can easily be switched on and off with the setVerticalSyncEnabled function.
    //After this call, your application will run at the same frequency as the monitor's refresh rate.
    //Sometimes setVerticalSyncEnabled will have no effect:
    //this is most likely because vertical synchronization is forced to "off" in your graphics driver's settings.
    //It should be set to "controlled by application" instead.
    window.setVerticalSyncEnabled(true);
    
    auto assets = Assets_Loader::Load(window);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        Handle_Events(window);
        Frame_Logic(window,assets);
    }

    return 0;
}



















