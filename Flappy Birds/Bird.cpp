#include "Bird.h"	//includes the bird's header file

Bird::Bird() {
	if (!texture.loadFromFile("assests/bird.png")) {
		//Handle loading error
	}
	sprite.setTexture(texture);		//This sets the sprite to a loaded texture 'texture'
	sprite.setPosition(100,300);	//Setting the intial position of the sprite
	velocity = 0;	//Initalizing the bird's veloicty
}

void Bird::update() {
	velocity += gravity;	//The bird's velocity will increase by the gravity constant
	sprite.move(0, velocity);	//The bird only moves vertically as the x component is set to 0 and y is set to the velocity

	//Preventing the bird from falling off the screen
	if (sprite.getPosition().y > 600) {
		sprite.setPosition(100, 600);
		velocity = 0;
	}
}

void Bird::draw(sf::RenderWindow& window) { //Draw the bird on the window
	window.draw(sprite);
}

void Bird::flap() {
	velocity = flapStrength;	//This sets the bird's vertical velocity to 'flapStrength', which is a negative value
}