#include "LevelBuilder2.h"



LevelBuilder2::LevelBuilder2()
{
	currentLevel = 0;
}


LevelBuilder2::~LevelBuilder2()
{

}

void LevelBuilder2::BuildLevel()
{
	currentLevel = new Level();
	currentLevel->setLevelEnd(5500.0f);
	currentLevel->setBoss(true);
}

void LevelBuilder2::BuildPlayer(sf::Vector2f position, sf::Vector2f size)
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

void LevelBuilder2::BuildPlayer2(sf::Vector2f position, sf::Vector2f size)
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
	pAux->includeTextureVector((char*) "Textures/ramona.atacando.png");
	pAux->includeImgCountVector(8);
	pAux->setKeyRight(sf::Keyboard::Right);
	pAux->setKeyLeft(sf::Keyboard::Left);
	pAux->setKeyJump(sf::Keyboard::Up);
	pAux->setKeyAttack(sf::Keyboard::RShift);
	pAux->setKeyRun(sf::Keyboard::RShift);
	pAux->setPlayer2();
	pAux->setDamage(5);
	currentLevel->includePlayer(pAux);
}

void LevelBuilder2::BuildEnemy1(sf::Vector2f position, sf::Vector2f size)
{
	Enemy1* pAux = new Enemy1();
	pAux->setLife(100);
	pAux->InitializeEnemy(position, size, "Textures/Enemy1.png", sf::Vector2u(8, 1), 400.0f, 200.0);
	pAux->includeTextureVector((char*) "Textures/Enemy1.png");
	pAux->includeImgCountVector(6);
	/*pAux->includeTextureVector((char*) "Textures/Player2_Standings.png");
	pAux->includeImgCountVector(6);
	pAux->includeTextureVector((char*) "Textures/Player2_Standings.png");
	pAux->includeImgCountVector(6);*/
	pAux->setDamage(10);
	pAux->setKillPoints(150);
	currentLevel->includeEnemy(pAux);
}

void LevelBuilder2::BuildEnemy2(sf::Vector2f position, sf::Vector2f size)
{
    Enemy2* pAux = new Enemy2();
	pAux->setLife(150);
	pAux->InitializeEnemy(position, size, "Textures/Enemy3.png", sf::Vector2u(8, 1), 300.0f, 200.0);
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

void LevelBuilder2::BuildBoss(sf::Vector2f position, sf::Vector2f size)
{
    Boss* pAux = new Boss();
    pAux->setLife(10000);
	pAux->InitializeEnemy(position, size, "Textures/BossParado.png", sf::Vector2u(4, 1), 300.0f, 200.0);
	pAux->includeTextureVector((char*) "Textures/BossParado.png");
	pAux->includeImgCountVector(4);
	pAux->includeTextureVector((char*) "Textures/BossAtaque.png");
	pAux->includeImgCountVector(11);
	/*pAux->includeTextureVector((char*) "Textures/Player2_Standings.png");
	pAux->includeImgCountVector(6);
	pAux->includeTextureVector((char*) "Textures/Player2_Standings.png");
	pAux->includeImgCountVector(6);*/
	pAux->setDamage(30);
	pAux->setKillPoints(1000);
	currentLevel->includeBoss(pAux);
}

void LevelBuilder2::BuildPlatform(sf::Vector2f position, sf::Vector2f size, const char* textureFile)
{
	currentLevel->includePlatform(position, size, textureFile);
}

void LevelBuilder2::BuildObstacle(sf::Vector2f position, sf::Vector2f size, const char* textureFile)
{
    Obstacle* pAux = new Obstacle;
    pAux->InitializeObstacle(position, size, textureFile);
    currentLevel->includeObstacle(pAux);
}

void LevelBuilder2::BuildObstacleFixos(sf::Vector2f position, sf::Vector2f size, const char* textureFile)
{
    Obstacle* pAux = new Obstacle;
    pAux->InitializeObstacle(position, size, textureFile);
    currentLevel->includeObstacleFixos(pAux);
}

void LevelBuilder2::BuildBackground(sf::Vector2f position, sf::Vector2f size)
{
	Background* pAux = new Background;
	pAux->Initialize(position, size, "Textures/BackgroundFase2.png", 0.f, 1.f);
	currentLevel->includeBackground(pAux);
}

void LevelBuilder2::BuildBackground_1(sf::Vector2f position, sf::Vector2f size, const char * textureFile, const float increment, const float incrementScale)
{
	Background* pAux = new Background;
	pAux->Initialize(position, size, textureFile, increment, incrementScale);
	currentLevel->includeBackground(pAux);
}

void LevelBuilder2::BuildBackground_2(sf::Vector2f position, sf::Vector2f size, const char* textureFile)
{
	Background* pAux = new Background;
	pAux->Initialize(position, size, textureFile, 0.f, 1.f);
	pAux->Stand();
	currentLevel->includeBackground(pAux);
}
