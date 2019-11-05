#pragma once
#include "Character.h"
#include<string>

class Player : public Character
{
public:
	Player(const char* textureFile = NULL, float speed = 0, float jumpHeight = 0);
	~Player();
	void InitializePlayer(sf::Vector2f position, sf::Vector2f size, const char* textureFile, sf::Vector2u imgCount, float speed, float jumpHeight);
	void calcMovement(const float deltaTime);
	void setKeyRight(sf::Keyboard::Key right) { KeyRight = right; }
	void setKeyLeft(sf::Keyboard::Key left) { KeyLeft = left; }
	void setKeyJump(sf::Keyboard::Key jump) { KeyJump = jump; }
	void setKeyAttack(sf::Keyboard::Key attack) { KeyAttack = attack; }
	void setKeyRun(sf::Keyboard::Key run) {KeyRun = run;}
	float getSpeed() { return velocity.x; }
	void setPlayer2() { player2 = true; }
	virtual void draw(sf::RenderWindow& window);
	void operator+=(unsigned int points) {	this->points += points; }
	const bool attacking() { return Attacking; }
	void atacando();

private:
	sf::Keyboard::Key KeyRight;
	sf::Keyboard::Key KeyLeft;
	sf::Keyboard::Key KeyJump;
	sf::Keyboard::Key KeyAttack;
	sf::Keyboard::Key KeyRun;
	unsigned int points = 0;
	bool player2 = false;
	bool Attacking = false;
};
