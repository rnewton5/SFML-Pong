#include "Paddle.h"
#include "GLOBALS.h"

Paddle::Paddle(sf::Vector2f position, sf::Vector2f size, sf::Color color) {
	paddle = sf::RectangleShape(size);
	paddle.setPosition(position);
	paddle.setFillColor(color);
	paddle.setOutlineThickness(2);
	paddle.setOutlineColor(sf::Color::White);

	yVel = 0;
}

sf::Vector2f Paddle::getPosition() {
	return paddle.getPosition();
}

void Paddle::move(int direction) {
	if (direction == PADDLE_UP) {
		yVel -= 1;
	}
	else if (direction == PADDLE_DOWN) {
		yVel += 1;
	}
	else {
		yVel *= MOMENTUM;
	}

	if (yVel < -10) {
		yVel = -10;
	}
	else if (yVel > 10) {
		yVel = 10;
	}
	if (getPosition().y < 0) {
		yVel = 1; // abs(yVel);
	}
	else if (getPosition().y + PADDLE_SIZE.y > HEIGHT) {
		yVel = -1; // -abs(yVel);
	}

	paddle.setPosition(getPosition().x, getPosition().y + yVel);
}

void Paddle::draw(sf::RenderWindow& window) {
	window.draw(paddle);
}

double Paddle::getYVel() {
	return yVel;
}