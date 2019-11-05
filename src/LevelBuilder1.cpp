#include "LevelBuilder1.h"



LevelBuilder1::LevelBuilder1()
{
	currentLevel = 0;
}


LevelBuilder1::~LevelBuilder1()
{
}

void LevelBuilder1::BuildLevel()
{
	currentLevel = new Level();
	currentLevel->setLevelEnd(5500.0f);
	currentLevel->setBoss(false);
}

void LevelBuilder1::BuildPlayer(sf::Vector2f position, sf::Vector2f size)
{
	Player* pAux = new Player();
	pAux->setLife(1000);
	pAux->InitializePlayer(position, size, "Textures/Player1_Standing.png", sf::Vector2u(8, 1), 200.0f, 200.0f);
	pAux->includeTextureVector((char*) "Textures/Player1_Standing.png");
	pAux->includeImgCountVector(8);
	pAux->includeTextureVector((char*) "Textures/Player1_Walking.png");
	pAux->includeImgCountVector(6);
	pAux->includeTextureVector((char*) "Textures/Player1_Jumping.png");
	pAux->includeImgCountVector(13);
	pAux->includeTextureVector((char*) "Textures/socando.png");
	pAux->includeImgCountVector(12);
	pAux->setKeyRight(sf::Keyboard::D);
	pAux->setKeyLeft(sf::Keyboard::A);
	pAux->setKeyJump(sf::Keyboard::W);
	pAux->setKeyAttack(sf::Keyboard::Space);
	pAux->setKeyRun(sf::Keyboard::LShift);
	pAux->setDamage(5);
	currentLevel->includePlayer(pAux);
}

void LevelBuilder1::BuildPlayer2(sf::Vector2f position, sf::Vector2f size)
{
	Player* pAux = new Player();
	pAux->setLife(1000);
	pAux->InitializePlayer(position, size, "Textures/Player2_Standing.png", sf::Vector2u(6,1), 200.0f, 200.0f);
	pAux->includeTextureVector((char*) "Textures/Player2_Standing.png");
	pAux->includeImgCountVector(6);
	pAux->includeTextureVector((char*) "Textures/Player2_Walking.png");
	pAux->includeImgCountVector(6);
	pAux->includeTextureVector((char*) "Textures/Player2_Jumping.png");
	pAux->includeImgCountVector(9);
	pAux->includeTextureVector((char*) "Textures/ramona.ataque.png");
	pAux->includeImgCountVector(8);
	pAux->setKeyRight(sf::Keyboard::Right);
	pAux->setKeyLeft(sf::Keyboard::Left);
	pAux->setKeyJump(sf::Keyboard::Up);
	pAux->setKeyAttack(sf::Keyboard::RShift);
	pAux->setKeyRun(sf::Keyboard::RAlt);
	pAux->setPlayer2();
	pAux->setDamage(5);
	currentLevel->includePlayer(pAux);
}

void LevelBuilder1::BuildEnemy1(sf::Vector2f position, sf::Vector2f size)
{
	Enemy1* pAux = new Enemy1();
	pAux->setLife(100);
	pAux->InitializeEnemy(position, size, "Textures/Enemy3.png", sf::Vector2u(8, 1), 180.0f, 200.0);
	pAux->includeTextureVector((char*) "Textures/Enemy3.png");
	pAux->includeImgCountVector(10);
	/*pAux->includeTextureVector((char*) "Textures/Player2_Standings.png");
	pAux->includeImgCountVector(6);
	pAux->includeTextureVector((char*) "Textures/Player2_Standings.png");
	pAux->includeImgCountVector(6);*/
	pAux->setDamage(10);
	pAux->setKillPoints(150);
	currentLevel->includeEnemy(pAux);

}

void LevelBuilder1::BuildEnemy2(sf::Vector2f position, sf::Vector2f size)
{
    Enemy2* pAux = new Enemy2();
	pAux->setLife(150);
	pAux->InitializeEnemy(position, size, "Textures/Enemy1.png", sf::Vector2u(8, 1), 300.0f, 200.0);
	pAux->includeTextureVector((char*) "Textures/Enemy1.png");
	pAux->includeImgCountVector(6);
	/*pAux->includeTextureVector((char*) "Textures/Player2_Standings.png");
	pAux->includeImgCountVector(6);
	pAux->includeTextureVector((char*) "Textures/Player2_Standings.png");
	pAux->includeImgCountVector(6);*/
	pAux->setDamage(15);
	pAux->setKillPoints(150);
	currentLevel->includeEnemy(pAux);
}

void LevelBuilder1::BuildPlatform(sf::Vector2f position, sf::Vector2f size, const char* textureFile)
{
	currentLevel->includePlatform(position, size, textureFile);
}


void LevelBuilder1::BuildBackground(sf::Vector2f position, sf::Vector2f size)
{
	Background* pAux = new Background;
	pAux->Initialize(position, size, "Textures/Background.png", 0.f, 1.f);
	currentLevel->includeBackground(pAux);
}

void LevelBuilder1::BuildBackground_1(sf::Vector2f position, sf::Vector2f size, const char * textureFile, const float increment, const float incrementScale)
{
	Background* pAux = new Background;
	pAux->Initialize(position, size, textureFile, increment, incrementScale);
	currentLevel->includeBackground(pAux);
}

void LevelBuilder1::BuildBackground_2(sf::Vector2f position, sf::Vector2f size, const char* textureFile)
{
	Background* pAux = new Background;
	pAux->Initialize(position, size, textureFile, 0.f, 1.f);
	pAux->Stand();
	currentLevel->includeBackground(pAux);
}

void LevelBuilder1::BuildObstacle(sf::Vector2f position, sf::Vector2f size, const char* textureFile)
{
    Obstacle* pAux = new Obstacle;
    pAux->InitializeObstacle(position, size, textureFile);
    currentLevel->includeObstacle(pAux);
}

void LevelBuilder1::BuildObstacleFixos(sf::Vector2f position, sf::Vector2f size, const char* textureFile)
{
    Obstacle* pAux = new Obstacle;
    pAux->InitializeObstacle(position, size, textureFile);
    currentLevel->includeObstacleFixos(pAux);
}
