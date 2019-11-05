#pragma once
#include "Enemy.h"

class Boss : public Enemy
{
public:
	Boss(const char* textureFile = NULL, float speed = 0, float jumpHeight = 0);
	~Boss();
	void InitializeBoss(sf::Vector2f position, sf::Vector2f size, const char* textureFile, sf::Vector2u imgCount, float speed, float jumpHeight);
	void calcMovement(const float deltaTime, sf::Vector2f position1);
	void calcMovement(const float deltaTime, sf::Vector2f position1, sf::Vector2f position2);

private:
    float totalTime = 0;
    bool canMove = false;
};
