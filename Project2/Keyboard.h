#pragma once

class Keyboard {
private:
	static bool keyHeld[1024];
	Keyboard() {}
public:
	static void init() {
		for (int i = 0; i < 1024; i++) {
			Keyboard::keyHeld[i] = false;
		}
	}

	static void keyPressed(int keyCode) {
		Keyboard::keyHeld[keyCode] = true;
	}

	static void keyReleased(int keyCode) {
		Keyboard::keyHeld[keyCode] = false;
	}

	static bool get(int keyCode) {
		return Keyboard::keyHeld[keyCode];
	}
};