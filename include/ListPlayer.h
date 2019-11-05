#pragma once
#include"Player.h"
#include"ListT.h"

class ListPlayer
{
public:
	ListPlayer();
	~ListPlayer();
	void include(Player* player);
	void draw(sf::RenderWindow* window);
	void update(const float deltaTime);
	void checkCollision(Character* other, const float push);
	void checkCollision(Player* other, const float push);
	ListT<Player*>::Element<Player*>* getFirst() { return players.getpFirst(); }

private:
	ListT<Player*> players;

};
