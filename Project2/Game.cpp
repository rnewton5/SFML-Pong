#include "Game.h"

Game::Game() :
	window(sf::VideoMode(WIDTH, HEIGHT), TITLE, sf::Style::Titlebar | sf::Style::Close),
	leftPaddle(sf::Vector2f(10, HEIGHT / 2 - PADDLE_SIZE.y / 2), PADDLE_SIZE, sf::Color::Green),
	rightPaddle(sf::Vector2f(WIDTH - 10 - PADDLE_SIZE.x, HEIGHT / 2 - PADDLE_SIZE.y / 2), PADDLE_SIZE, sf::Color::Red),
	ball((float)BALL_RADIUS),
	clock()
{
	Keyboard::init();
}

void Game::start() {
	sf::Event event;
	clock.restart();
	long lastTime = clock.getElapsedTime().asMicroseconds();
	const double ms = 1000000.0 / 60;
	double delta = 0.0;
	int fps = 0, ups = 0;
	while (window.isOpen()) 
	{
		long now = clock.getElapsedTime().asMicroseconds();
		delta += (now - lastTime) / ms;
		lastTime = now;
		while (delta >= 1) {
			update();
			checkBallCollision();
			delta--;
			ups++;
		}
		while (window.pollEvent(event)) {
			processEvent(event);
		}
		
		draw();
		fps++;
		if (ups == 60) {
			window.setTitle(std::string(TITLE + " FPS: " + std::to_string(fps)));
			ups = 0;
			fps = 0;
		}
	}
}

void Game::update() {
	ball.move();
	Human_update(leftPaddle);
	AI_update(rightPaddle);
}

void Game::AI_update(Paddle& paddle) {
	if (ball.getPosition().y < paddle.getPosition().y + 10) {
		paddle.move(PADDLE_UP);
	}
	else if (ball.getPosition().y > paddle.getPosition().y + PADDLE_SIZE.y - 10) {
		paddle.move(PADDLE_DOWN);
	}
	else {
		paddle.move(PADDLE_STOP);
	}
}

void Game::Human_update(Paddle& paddle) {
	if (Keyboard::get(sf::Keyboard::Up)) {
		paddle.move(PADDLE_UP);
	}
	else if (Keyboard::get(sf::Keyboard::Down)) {
		paddle.move(PADDLE_DOWN);
	}
	else {
		paddle.move(PADDLE_STOP);
	}
}

void Game::draw() {
	window.clear();
	ball.draw(window);
	leftPaddle.draw(window);
	rightPaddle.draw(window);
	window.display();
}

void Game::checkBallCollision() {
	if (ball.getPosition().y - 10 < 0) {
		ball.positive_yVel();
	}
	else if (ball.getPosition().y + 10 > HEIGHT) {
		ball.negative_yVel();
	}
	if ((ball.getPosition().x - 10 < 10 + PADDLE_SIZE.x && ball.getPosition().x > 10)) {
		if (ball.getPosition().y > leftPaddle.getPosition().y && ball.getPosition().y < leftPaddle.getPosition().y + PADDLE_SIZE.y) {
			ball.random_positive_xVel();
			ball.increaseSpeed();
			ball.setCurveIntensity(leftPaddle.getYVel());
		}
	}
	else if (ball.getPosition().x + 10 > WIDTH - 10 - PADDLE_SIZE.x && ball.getPosition().x < WIDTH - 10) {
		if (ball.getPosition().y > rightPaddle.getPosition().y && ball.getPosition().y < rightPaddle.getPosition().y + PADDLE_SIZE.y) {
			ball.random_negative_xVel();
			ball.increaseSpeed();
			ball.setCurveIntensity(rightPaddle.getYVel());
		}
	}
	else if (ball.getPosition().x < 0) {
		ball.restart();
	}
	else if (ball.getPosition().x > WIDTH) {
		ball.restart();
	}
}

void Game::processEvent(sf::Event event) {
	if (event.type == sf::Event::Closed)
		window.close();
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Up) {
			Keyboard::keyPressed(sf::Keyboard::Up);
		}
		else if (event.key.code == sf::Keyboard::Down) {
			Keyboard::keyPressed(sf::Keyboard::Down);
		}
	}
	else if (event.type == sf::Event::KeyReleased) {
		if (event.key.code == sf::Keyboard::Up) {
			Keyboard::keyReleased(sf::Keyboard::Up);
		}
		else if (event.key.code == sf::Keyboard::Down) {
			Keyboard::keyReleased(sf::Keyboard::Down);
		}
	}
}