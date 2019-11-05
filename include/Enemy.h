#pragma once
#include "Character.h"

class Enemy : public Character
{
public:
	Enemy(const char* textureFile = NULL, float speed = 0, float jumpHeight = 0);
	~Enemy();
	void InitializeEnemy(sf::Vector2f position, sf::Vector2f size, const char* textureFile, sf::Vector2u imgCount, float speed, float jumpHeight);
	virtual void calcMovement(const float deltaTime, sf::Vector2f position1, sf::Vector2f position2) {std::cout<<"1"<<std::endl;}
	virtual void calcMovement(const float deltaTime, sf::Vector2f position1) {std::cout<<"1"<<std::endl;}
	virtual void Update(float deltaTime, sf::Vector2f position1, sf::Vector2f position2);
	virtual void Update(float deltaTime, sf::Vector2f position1);
	virtual void draw(sf::RenderWindow& window);
	void setKillPoints(unsigned int points) { killPoints = points; }
	const unsigned int getKillPoints() { return killPoints; }

private:
	unsigned int killPoints = 0;

};
