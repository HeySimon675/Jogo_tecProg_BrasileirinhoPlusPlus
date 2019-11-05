#pragma once
#include "LevelBuilder.h"
#include "Player.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include "Boss.h"
#include "Platform.h"
#include "Obstacle.h"

class LevelBuilder2 :
	public LevelBuilder
{
public:
	LevelBuilder2();
	~LevelBuilder2();
	virtual void BuildLevel();
	virtual void BuildPlayer(sf::Vector2f position, sf::Vector2f size);
	virtual void BuildPlayer2(sf::Vector2f position, sf::Vector2f size);
	virtual void BuildEnemy1(sf::Vector2f position, sf::Vector2f size);
	virtual void BuildEnemy2(sf::Vector2f position, sf::Vector2f size);
	virtual void BuildBoss(sf::Vector2f position, sf::Vector2f size);
	virtual void BuildPlatform(sf::Vector2f position, sf::Vector2f size, const char* textureFile);
	virtual void BuildObstacle(sf::Vector2f position, sf::Vector2f size, const char* textureFile);
	virtual void BuildObstacleFixos(sf::Vector2f position, sf::Vector2f size, const char* textureFile);
	virtual void BuildBackground(sf::Vector2f position, sf::Vector2f size);
	virtual void BuildBackground_1(sf::Vector2f position, sf::Vector2f size, const char * textureFile, const float increment, const float incrementScale);
	virtual void BuildBackground_2(sf::Vector2f position, sf::Vector2f size, const char* textureFile);
	virtual Level* getLevel() { return currentLevel; }

private:
	Level* currentLevel;

	//Macros
	const float WINDOW_WIDHT = 1366.0f;
	const float WINDOW_HEIGHT = 768.0f;
};
