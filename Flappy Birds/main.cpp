#include <iostream>
#include "Bird.h"
#include "Pipe.h"
#include "Background.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <cstdlib>


#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

int main()
{
    //Initialize a random seed
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Flappy Bird!");

    //Declaring the background, bird and pipe objects
    Background background;
    Bird bird;

    //Add the inital pipes
    Pipe::addPipe(SCREEN_WIDTH);

    // Start the game loop
    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
                bird.flap();
        }

        //Update the bird
        bird.update();
        
        //Update the pipes
        Pipe::updatePipes();

        //Check for collisions
        for (const auto& pipe : Pipe::getPipes()) {
            if (bird.getBounds().intersects(pipe.getBounds())) {
                std::cout << "Collision detected!" << std::endl;
                window.close();
            }
        }

        // Clear screen
        window.clear();

        // Update and render the game objects here
        //Render background
        background.draw(window);

        //Render bird
        bird.draw(window);

        //Render pipes
        Pipe::drawPipes(window);

        // Update the window
          window.display();
    }

	return 0;
}