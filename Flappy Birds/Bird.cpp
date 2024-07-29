#include "Bird.h"	//includes the bird's header file
#include <iostream>

Bird::Bird() {
	if (!texture.loadFromFile("assets/bird.png")) {
		std::cerr << "Error loading bird.png" << std::endl;
	} 
	else {
		std::cout << "Successfully loaded bird.png" << std::endl;
	}

	sprite.setTexture(texture);		//This sets the sprite to a loaded texture 'texture'
	sprite.setPosition(100,500);	//Setting the intial position of the sprite
	sprite.scale(0.2,0.2);
	velocity = 0;	//Initalizing the bird's veloicty
}

void Bird::update() {
	velocity += gravity;	//The bird's velocity will increase by the gravity constant
	sprite.move(0, velocity);	//The bird only moves vertically as the x component is set to 0 and y is set to the velocity

	//Preventing the bird from falling off the screen
	if (sprite.getPosition().y > 1080) {
		sprite.setPosition(100, 0);
	}
	if (sprite.getPosition().y < 0) {
		sprite.setPosition(100, 1080);
	}
}

void Bird::draw(sf::RenderWindow& window) const { //Draw the bird on the window
	window.draw(sprite);
}

void Bird::flap() {
	velocity = flapStrength;	//This sets the bird's vertical velocity to 'flapStrength', which is a negative value
}

sf::FloatRect Bird::getBounds() const {
	return sprite.getGlobalBounds();
}