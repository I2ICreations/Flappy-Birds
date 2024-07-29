//header files that define the bird class. They are responsible for the bird's behaviour and properties
#ifndef BIRD_H
#define BIRD_H

#include <SFML/Graphics.hpp> //This includes the SFML graphics library which provides the functionality to handle graphics,windows and events


class Bird {
public:		//These are functions that are publicy accessible
	Bird();		//The constructer, which initializes a new instance of the 'Bird' class
	void update();	//A function to update the bird's state
	void draw(sf::RenderWindow& window);	//A function to draw the bird on the window
	void flap();	//A function to make the bird flap - this then affects its velocity
	sf::FloatRect getBounds() const;

private:	//these are objects and functions that are not publicly accessible
	sf::Sprite sprite;	//An object to represent the bird
	sf::Texture texture;	// An object to hold the image for the bird
	float velocity;		// A float variable to store the velocity of the bird 
	const float gravity = 0.5f;	// A float value that represent the gravitational force applied to the bird (it remains constant)
	const float flapStrength = -10.0f;	// A float value that represents the upward force applied to the bird when it flaps 
};

#endif