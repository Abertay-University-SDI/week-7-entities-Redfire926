#include "Ball.h"

Ball::Ball()
{
	velocity = sf::Vector2f(0, 100);
}

Ball::~Ball()
{
}

void Ball::update(float dt)
{
	move(velocity * dt);
}
