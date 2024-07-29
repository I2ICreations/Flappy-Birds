#include "Background.h"
#include <iostream>

//Grab the background and load it as a texture
Background::Background() {
    if (!texture.loadFromFile("assets/background.png")) {
        std::cerr << "Error loading background.png" << std::endl;
    }
    else
        std::cout << "background.png successfully loaded" << std::endl;

    // Make the background a sprite and set the texture
    sprite.setTexture(texture);
    sprite.setPosition(0, 0); // Position at the top-left corner
}

void Background::draw(sf::RenderWindow& window) const {
    window.draw(sprite);
}
