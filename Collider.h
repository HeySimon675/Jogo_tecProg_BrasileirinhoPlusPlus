
//--------------------------------------------------------------------------------------------------------------------//
// Created by simao on 27/05/19.
// Update 27/05
//todo Classe ainda não otimizada para o projeto

#pragma once

#include <SFML/Graphics.hpp>
#pragma once
class Collider {
private:
    sf::RectangleShape& body;
public:
    Collider(sf::RectangleShape* body);
    ~Collider();

    void move (float dx, float dy){body.move(dx,dy);}

    bool checkCollision(Collider* other,sf::Vector2f& direction, float push);
    sf::Vector2f getPosition(){ return body.getPosition();}
    sf::Vector2f getHalfSize(){ return (body.getSize()/2.0f);}
};
