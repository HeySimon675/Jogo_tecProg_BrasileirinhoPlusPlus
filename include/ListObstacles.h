#pragma once
#include"ListT.h"
#include"Obstacle.h"
#include"Character.h"
#include<SFML/Graphics.hpp>
#include <iostream>

class ListObstacles
{
public:
	ListObstacles();
	~ListObstacles();
	void include(Obstacle* obstacle);
	void Draw(sf::RenderWindow* window);
	void Update(const float deltaTime);
	void CheckCollision(Character* other, const float push);
	void CheckCollisionObstacle(Obstacle* other, const float push);
	ListT<Obstacle*>::Element<Obstacle*>* getFirst() { return obstacles.getpFirst(); }

private:
	ListT<Obstacle*> obstacles;

};
