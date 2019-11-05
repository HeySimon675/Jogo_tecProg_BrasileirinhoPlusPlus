#include "Obstacle.h"



Obstacle::Obstacle(const char* textureFile)
{
	sf::Vector2f position;
	position.x = 0.0f;
	position.y = 0.0f;

	sf::Vector2f size;
	size.x = 0.0f;
	size.y = 0.0f;

	InitializeObstacle(position, size, textureFile);
}


Obstacle::~Obstacle()
{
}

void Obstacle::InitializeObstacle(sf::Vector2f position, sf::Vector2f size, const char * textureFile)
{
	InitializeEnt(position, size, textureFile);
}

void Obstacle::calcMovement(const float deltaTime)
{
    velocity.x = 0.0f;
   velocity.y += 981.0f * deltaTime;
}

void Obstacle::Update(float deltaTime)
{
    calcMovement(deltaTime);
    base.move(velocity * deltaTime);
}

void Obstacle::onCollision(sf::Vector2f direction)
{
	if (direction.x != 0)
	{
		if (direction.x < 0.0f)
		{
			velocity.x = 0.0f;
		}
		else if (direction.x > 0.0f)
		{
			velocity.x = 0.0f;
		}
	}
	if (direction.y != 0)
	{
		if (direction.y < 0.0f)
		{
			velocity.y = 0.0f;
		}
		else if (direction.y > 0.0f)
		{
			velocity.y = 0.0f;
		}
	}
}
