#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	dropManager.setWindow(hwnd);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isLeftMousePressed())
	{
		ballManager.spawn();
	}

	if ((input->isKeyDown(sf::Keyboard::Space)) && (dropManager.getPressed() == false))
	{
		dropManager.spawn();
		dropManager.setPressed(true);
	}
	if (!input->isKeyDown(sf::Keyboard::Space))
	{
		dropManager.setPressed(false);
	}
}

// Update game objects
void Level::update(float dt)
{
	ballManager.update(dt);
	dropManager.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	ballManager.render(window);
	dropManager.render();
	endDraw();
}
