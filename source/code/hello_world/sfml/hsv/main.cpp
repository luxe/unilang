

int main(int argc, char **argv) {
    // Setup a render window
    sf::RenderWindow window(sf::VideoMode(256, 256), "Color Picker");

    // We're using a clock to change the hue dynamically.
    sf::Clock timer;

    // This vertex array is going to be used for drawing.
    // It includes one vertex/point/pixel per color.
    sf::VertexArray colors(sf::Points, 256 * 256);
    for (unsigned int y = 0; y <= 255; ++y) {
        for (unsigned int x = 0; x <= 255; ++x) {
            sf::Vertex &vertex(colors[y * 256 + x]);

            // Note that I "flip" the displayed texture here, by subtracting
            // x/y from 255 rather than just using x/y, but that's really just
            // to get the same orientation that you have.
            vertex.position.x = 255 - x;
            vertex.position.y = 255 - y;
        }
    }

    while (window.isOpen()) {
        sf::Event event;
        // Your typical event loop
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }

        // Update our colors based on the time passed.
        // I want to cycle all hues in 5 seconds, so dividing the timer.
        modulate(colors, timer.getElapsedTime().asSeconds() / 5);

        // Draw and display our colors
        window.clear();
        window.draw(colors);
        window.display();
    }

