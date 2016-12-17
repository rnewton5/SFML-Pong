#pragma once
#include <SFML\Graphics.hpp>

class Ball {
private:
	sf::CircleShape ball;
	int xVel;
	int yVel;
	int speed;
	double curveIntensity;

	int generateRandomNumber();
	sf::Clock clock;

public:
	Ball(float);

	void setxVel(int);
	int getxVel();
	void setyVel(int);
	int getyVel();
	void negative_yVel();
	void positive_yVel();
	void random_positive_xVel();
	void random_negative_xVel();
	void restart();
	void increaseSpeed();
	void setCurveIntensity(double);

	sf::Vector2f getPosition();
	void move();

	void draw(sf::RenderWindow&);
};
