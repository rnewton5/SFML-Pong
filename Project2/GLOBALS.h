#pragma once
#include <string>

const int WIDTH  = 1000;
const int HEIGHT = 600;
const float MOMENTUM = 0.86f;
const int BALL_RADIUS = 10;
const sf::Vector2f PADDLE_SIZE(15, 75);
const std::string TITLE = "PONG!";


const enum {
	PADDLE_DOWN = -1,
	PADDLE_UP = 1,
	PADDLE_STOP = 0
};