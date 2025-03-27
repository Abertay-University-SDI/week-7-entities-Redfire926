#include "DropBallManager.h"
#include <string>

DropBallManager::DropBallManager()
{
	spawnPoint = sf::Vector2f(0, 0);
	texture.loadFromFile("gfx/Beach_Ball.png");

	for (int i = 0; i < 40; i++)
	{
		balls.push_back(Ball());
		balls[i].setAlive(false);
		balls[i].setTexture(&texture);
		balls[i].setSize(sf::Vector2f(100, 100));
	}
	aliveBallCount = 0;
	textFont.loadFromFile("font/arial.ttf");
	countMessage.setFont(textFont);
	countMessage.setFillColor(sf::Color::Red);
	countMessage.setPosition(500, 0);
	countMessage.setCharacterSize(20);
	countMessage.setString("Balls");
}

DropBallManager::~DropBallManager()
{
}

void DropBallManager::spawn()
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (!balls[i].isAlive())
		{
			balls[i].setAlive(true);
			balls[i].setVelocity(0, 200);
			spawnPoint.x = rand() % (int)(window->getSize().x - balls[i].getSize().x);
			balls[i].setPosition(spawnPoint);
			aliveBallCount++;
			return;
		}
	}
}

void DropBallManager::update(float dt)
{
	// call update on all ALIVE balls
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			balls[i].update(dt);
		}
	}
	deathCheck();
	countMessage.setString("Alive dropped balls: " + std::to_string(aliveBallCount));
}

void DropBallManager::setWindow(sf::RenderWindow* hwnd)
{
	window = hwnd;
}

void DropBallManager::deathCheck()
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			if (balls[i].getPosition().y > window->getSize().y)
			{
				balls[i].setAlive(false);
				aliveBallCount--;
			}
		}
	}
}

void DropBallManager::render()
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			window->draw(balls[i]);
		}
	}
	window->draw(countMessage);
}
