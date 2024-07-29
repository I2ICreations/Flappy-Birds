#pragma once
#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SFML/Graphics.hpp>

class Background {
public:
    Background();
    void draw(sf::RenderWindow& window) const;

private:
    sf::Sprite sprite;
    sf::Texture texture;
};

#endif // BACKGROUND_H

