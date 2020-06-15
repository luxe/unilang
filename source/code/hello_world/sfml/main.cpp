#include <string>
#include <iostream>
#include <SFML/System/String.hpp>
#include <SFML/Graphics.hpp>
//#include <locale.h>
//#include <locale>

int main()
{
    //setlocale(LC_ALL, "C");
    //std::locale::global(std::locale("en_US.UTF-8"));
    //std::locale::global(std::locale("en_US.UTF-8"));
    //std::locale::global(std::locale("en_US.UTF-8"));
    //std::cout.imbue(std::locale("en_US.utf8"));
    
    sf::String str;
    str = "hello";
    auto video_mode = sf::VideoMode(200, 200); 
    sf::RenderWindow window(video_mode,"hello");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
