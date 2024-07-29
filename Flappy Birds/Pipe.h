#pragma once
#ifndef PIPE_H
#define PIPE_H

#include <SFML/Graphics.hpp>  //This includes the SFML graphics library which provides the functionality to handle graphics,windows and events
#include <vector>

class Pipe
{
public: //These are functions that are publicy accessible
	Pipe(float startX);	//The constructer, which initializes a new instance of the 'Pipe' class. It takes a float para which will be used to set the inital horizontal position of the pipe
	void update();		//A function to update the pipe's state
	void draw(sf::RenderWindow& window) const;	//A function to draw the pipes on the window
	sf::FloatRect getBounds() const;	//This declares the getBounds method, which will return the bounding rectangle of the pipe

	//These functions will handle with the pipes being displayed
	static void addPipe(float startX);
	static void updatePipes();
	static void drawPipes(sf::RenderWindow& window);

	//Static getter function for pipes
	static const std::vector<Pipe>& getPipes();

private:  //These are functions that are not publicy accessible
	sf::Sprite sprite;	//An object to represent the pipe
	sf::Texture texture;	// An object to hold the image for the bird
	float speed = 0.3f;		//This declares a float variable speed and initializes it to 2.0. This represents the speed at which the pipe moves horizontally across the screen
	
	//A vector for pipes
	static std::vector<Pipe> pipes;
};


#endif // !PIPE_H
