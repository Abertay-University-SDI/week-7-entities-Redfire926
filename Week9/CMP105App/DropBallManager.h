#pragma once
#include "Ball.h"
#include <math.h>
#include <vector>

class DropBallManager
{
public:
	DropBallManager();
	~DropBallManager();

	void spawn();
	void update(float dt);
	void setWindow(sf::RenderWindow* hwnd);
	void deathCheck();
	void render();
	void setPressed(bool pressed) {
		buttonPressed = pressed;
	}
	bool getPressed() { return buttonPressed; }

private:
	std::vector<Ball> balls;
	sf::Vector2f spawnPoint;
	sf::Texture texture;
	sf::RenderWindow* window;
	int aliveBallCount;
	sf::Text countMessage;
	sf::Font textFont;
	bool buttonPressed;
};
