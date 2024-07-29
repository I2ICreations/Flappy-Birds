#include "Pipe.h"
#include <iostream>

Pipe::Pipe(float StartX) {		//This line defines the constructor for the pipe class. The startx para specifies the inital position of the pipe
	if (!texture.loadFromFile("assets/pipe.png")) {
		std::cerr << "Error loading pipe.png" << std::endl;
	}
	else {
		std::cout << "Successfully loaded pipe.png" << std::endl;
	}

	sprite.setTexture(texture);		//This sets the texture of the sprite to the loaded texture
	sprite.setPosition(StartX, rand() % 400);		//This line sets the initial position of the sprite to coordinates (startX, rand() % 400) on the screen. The x-coordinate is startX, and the y-coordinate is a random value between 0 and 399. This randomizes the vertical position of the pipe.
}

void Pipe::update() {
	sprite.move(-speed, 0);		// This line moves the sprite by (-speed, 0) units. Since the x-component is -speed, the pipe moves to the left. The speed is determined by the speed variable.
}

void Pipe::draw(sf::RenderWindow& window) const {
	window.draw(sprite);	//This line defines the draw method, which draws the pipe on the given SFML render window.
}

sf::FloatRect Pipe::getBounds() const {		//Get Bounds Method Definition: This line defines the getBounds method, which returns the bounding rectangle of the pipe. The const keyword indicates that this method does not modify the state of the object.
	return sprite.getGlobalBounds();
}