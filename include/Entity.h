#pragma once
#include"SFML/Graphics.hpp"

class Entity
{
public:
	Entity(const char * textureFile = NULL);
	~Entity();
	void InitializeEnt(sf::Vector2f position, sf::Vector2f size, const char* textureFile);
	virtual void Draw(sf::RenderWindow* window);
	virtual void setTexture(const char* textureFile);
	virtual void Update(float deltaTime) {}
	sf::Vector2f getPosition() { return base.getPosition(); }
	sf::Vector2f getHalfPosition() { return base.getSize() / 2.0f; }
	virtual void move(float dx, float dy) { base.move(dx, dy); }
	virtual void move(sf::Vector2f position, float speed) {}
	virtual bool checkCollision(Entity& other, sf::Vector2f& direction, float push);

protected:
	sf::RectangleShape base;
	sf::Texture texture;

};