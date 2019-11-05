#pragma once
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Platform.h"
#include "ListT.h"
#include "ListEntity.h"
#include "Background.h"
#include "ListPlayer.h"
#include "ListEnemy.h"
#include "Boss.h"
#include "ListObstacles.h"
#include <vector>

class Level
{
public:
	Level();
	~Level();
	int Execute();
	void ResizeView();

	void InitializePlatforms();
	void Initialize();
	void setPlayer1(Player* player) { player1 = player; }
	void setPlayer2(Player* player) { player2 = player; }
    void setBoss(bool boss){this->boss = boss;}
	void includePlayer(Player*  player);
	void includeEnemy(Enemy* enemy) {  Enemies.include(enemy); }
	void includePlatform(sf::Vector2f position, sf::Vector2f size, const char* file);
	void includeBackground(Background* background) { Backgrounds.include(*background); }
    void includeObstacle(Obstacle* obstacle) {Obstacles.include(obstacle);}
    void includeObstacleFixos(Obstacle* obstacle) {ObstaclesFixos.include(obstacle);}
    void includeBoss(Boss* boss) {Enemies.include(boss);  pBoss = boss;}
	void checkCollisions();
	void setLevelEnd(const float lvlEnd) {LevelEnd = lvlEnd;}

private:
	//Macros
	const int WINDOW_WIDHT = 1366;
	const int WINDOW_HEIGHT = 768;
	const float VIEW_HEIGHT = 1000.0f;
	const char* PLAYER_TEXTURE_FILE = "Textures/Player1_Standing.png";
	const char* BACKGROUND_TEXTURE_FILE = "Textures/Background.png";
	const float PLAYERXPOSSCALE = 1.0f / 3.5f;

	sf::RenderWindow* window = NULL;
	sf::View view;
	sf::Texture playerText;
	sf::Sprite playerSprite;

	//Lists of the different Entities
	ListEntity Platforms;
	ListEntity Backgrounds;
	ListPlayer Players;
	ListEnemy Enemies;
    ListObstacles Obstacles;
    ListObstacles ObstaclesFixos;

	//std::vector<sf::Sprite> Background;

	Player* player1;
	Player* player2 = NULL;
	Boss* pBoss;

	bool FirstPlayer = true;
	bool P2 = false;
	bool fase1;
	bool boss;

    float LevelEnd;
    bool BackMove;
    bool Notpause;
	Background back;
};
