#include "ListObstacles.h"



ListObstacles::ListObstacles()
{
}


ListObstacles::~ListObstacles()
{
	obstacles.clear();
}

void ListObstacles::include(Obstacle * obstacle)
{
	if (obstacle != NULL)
		obstacles.include(obstacle);
}

void ListObstacles::Draw(sf::RenderWindow * window)
{
	ListT<Obstacle*>::Element<Obstacle*>* pAux = obstacles.getpFirst();

	while (pAux != NULL)
	{

        pAux->getInf()->Draw(window);
		pAux = pAux->getNext();
	}

}


void ListObstacles::Update(const float deltaTime)
{
	ListT<Obstacle*>::Element<Obstacle*>* pAux = obstacles.getpFirst();

	while (pAux != NULL)
	{
			pAux->getInf()->Update(deltaTime);
		pAux = pAux->getNext();
	}

}

void ListObstacles::CheckCollision(Character * other, const float push)
{
	ListT<Obstacle*>::Element <Obstacle*>* pAux = obstacles.getpFirst();

	sf::Vector2f direction;

	while (pAux != NULL)
	{

			direction.x = 0.f;
			direction.y = 0.f;

			pAux->getInf()->checkCollision(*other, direction, push);
			other->onCollision(direction);
            pAux = pAux->getNext();
	}
}

void ListObstacles::CheckCollisionObstacle(Obstacle * other, const float push)
{
	ListT<Obstacle*>::Element <Obstacle*>* pAux = obstacles.getpFirst();

	sf::Vector2f direction;

	while (pAux != NULL)
	{

			direction.x = 0.f;
			direction.y = 0.f;

			if(pAux->getInf() != other)
            {
                pAux->getInf()->checkCollision(*other, direction, push);
                other->onCollision(direction);
            }
            pAux = pAux->getNext();
	}
}
