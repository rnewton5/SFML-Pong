#pragma once
#include <SFML\Graphics.hpp>

#include "Paddle.h"
#include "Ball.h"
#include "GLOBALS.h"
#include "Keyboard.h"

class Game {
private:
	sf::RenderWindow window;
	Paddle leftPaddle;
	Paddle rightPaddle;
	Ball ball;
	sf::Clock clock;

	void update();
	void draw();
	void processEvent(sf::Event);
	void checkBallCollision();
	void AI_update(Paddle&);
	void Human_update(Paddle&);
public:
	Game();
	void start();

};