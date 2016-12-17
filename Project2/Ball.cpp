#include "Ball.h"
#include "GLOBALS.h"
#include <stdio.h>
#include <time.h>

Ball::Ball(float size) {
	ball = sf::CircleShape(size-2);//creating a new ball of the size size
	ball.setOutlineThickness(2);
	ball.setOutlineColor(sf::Color::White);
	ball.setOrigin(sf::Vector2f(size, size)); //setting the origin of the ball to the center of the ball
	ball.setPosition(sf::Vector2f(WIDTH / 2, HEIGHT / 2)); //placing the ball in the center of the screen
	ball.setFillColor(sf::Color::Yellow); //coloring the ball yellow
	srand(time(NULL));
	speed = 10;
	curveIntensity = 0.0;
	xVel = generateRandomNumber();
	yVel = generateRandomNumber();
	clock = sf::Clock();
}

void Ball::setxVel(int xVel) {
	this->xVel = xVel;
}

int Ball::getxVel() {
	return xVel;
}

void Ball::negative_yVel() {
	yVel = -(abs(yVel));
}

void Ball::positive_yVel() {
	yVel = abs(yVel);
}

void Ball::setyVel(int yVel) {
	this->yVel = yVel;
}

int Ball::getyVel() {
	return yVel;
}

sf::Vector2f Ball::getPosition() {
	return ball.getPosition();
}

void Ball::move() {
	if (clock.getElapsedTime().asMilliseconds() > 1000) {
		/*if (curveIntensity > 1 || curveIntensity < -1) {
			++xVel;
			yVel = speed - xVel;
		}*/
		ball.setPosition(sf::Vector2f(ball.getPosition().x + xVel, ball.getPosition().y + yVel));
	}
}

void Ball::restart() {
	ball.setPosition(sf::Vector2f(WIDTH / 2, HEIGHT / 2));
	speed = 10;
	xVel = generateRandomNumber();
	yVel = generateRandomNumber();
	clock.restart();
	curveIntensity = 0;
	if (curveIntensity > 1 || curveIntensity < -1) {//fix curveture
		xVel = 1;
	}
}

void Ball::draw(sf::RenderWindow& window) {
	window.draw(ball);
}

void Ball::random_positive_xVel() {
	xVel = abs(generateRandomNumber());
	if (yVel < 0) {
		yVel = -(speed - xVel);
	}
	else {
		yVel = speed - xVel;
	}
}

void Ball::random_negative_xVel() {
	xVel = -abs(generateRandomNumber());
	if (yVel < 0) {
		yVel = -(speed + xVel);
	}
	else {
		yVel = speed + xVel;
	}
}

int Ball::generateRandomNumber() {
	int randomNumber = 0;
	while (randomNumber < 2 && randomNumber > -2) {
		randomNumber = (rand() % speed * 2) - speed;
	}
	return randomNumber;
}

void Ball::increaseSpeed() {
	++speed;
}

void Ball::setCurveIntensity(double intensity) {
	curveIntensity = intensity;
}