#include <iostream>
#include "Bird.h"
#include "Pipe.h"
#include <SFML/Graphics.hpp>


#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Flappy Bird!");

    //Grab the background and load it as a texture
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("assets/background.png"))
        std::cerr << "Error loading background.png" << std::endl;
    else
        std::cout << "background.png successfully loaded" << std::endl;

    // Make the background a sprite and set the texture
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);

    // Start the game loop
    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {

            }
          
        }

        // Clear screen
        window.clear();

        // Update and render the game objects here

        //Render background
        window.draw(backgroundSprite);

        //Render bird

        //Render pipes

        // Update the window
        window.display();
    }


	return 0;
}