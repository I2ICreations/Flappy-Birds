#include <iostream>
#include <SFML/Graphics.hpp>


#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Flappy Bird!");

    // Start the game loop
    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear screen
        window.clear();

        // Update and render the game objects here

        // Update the window
        window.display();
    }


	return 0;
}