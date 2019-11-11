#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <SFML/Window/Joystick.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include "code/utilities/keyboard/joycons/joycon_state_getter.hpp"
#include "code/utilities/json/functions/lib.hpp"
#include "code/tools/math_game/assets/assets_loader.hpp"
#include "code/tools/math_game/state/game_state.hpp"
#include "code/tools/math_game/state/game_state_getter.hpp"
#include "code/tools/math_game/core/frame_renderer.hpp"
#include "code/tools/math_game/core/state_updater.hpp"
#include "code/utilities/graphics/sfml/game_loop.hpp"

void Handle_Events(sf::RenderWindow & window){
    
    // check all the window's events that were triggered since the last iteration of the loop
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch(event.type){
            
            
           // window closed (probably not relevant for fullscreen)
            case sf::Event::Closed:
                window.close();
                break;

            // window closed because of a key press
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

std::unique_ptr<sf::RenderWindow> Create_Render_Window(std::string const& name){
    
    //Create the main window.
    //note: if you do a bad (possibly unsupported resolution), it will go fullscreen but freeze
    //and then you have just a black screen and you have to restart the machine.
    //I don't even know if the application ends up exiting and my OS just never recovers.
    //But I can't even go to a different ubuntu session.  I couldn't figure out anything but
    //restarting the machine.  Not good.  Probably the best thing to do, is go with the desktop mode for now.
    //Another idea would be to make sure the desired resolution is supported by the machine.
    auto window = std::make_unique<sf::RenderWindow>(sf::VideoMode::getDesktopMode(),name,sf::Style::Fullscreen);
    
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
    window->setVerticalSyncEnabled(true);
    
    //WARNING: setVerticalSync and set FrameLimit SHOULD NOT be mixed.
    //window.setFramerateLimit(60);
    
    return window;
}

int main()
{
    
    //get the rendering window
    auto window = Create_Render_Window("Math Game");
    
    //get all the assets and game state
    auto assets = Assets_Loader::Load(*window);
    Game_State state = Game_State_Getter::Get();
    
    Game_Loop::Run(
    [&](){
        return window->isOpen();
    },
    [&](sf::Time const& TimePerFrame){
        Handle_Events(*window);
        State_Updater::Run_Frame_Logic(*window,TimePerFrame,state,assets);
    },
    [&](){
        Frame_Renderer::Run_Frame_Render(*window,state,assets);
    });

    return 0;
}


