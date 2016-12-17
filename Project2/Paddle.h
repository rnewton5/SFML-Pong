#pragma once
#include <SFML\Graphics.hpp>
#include "Keyboard.h"

class Paddle {
protected:
	sf::RectangleShape paddle;
	double yVel;

public:
	Paddle(sf::Vector2f position, sf::Vector2f size, sf::Color color);
	sf::Vector2f getPosition();
	void move(int);
	void draw(sf::RenderWindow&);
	double getYVel();
};