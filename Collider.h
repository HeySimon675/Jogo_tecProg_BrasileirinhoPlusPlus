
//--------------------------------------------------------------------------------------------------------------------//
// Implementado por:
    //Coradassi - 100%
//todo Classe ainda não otimizada para o projeto

#pragma once

#include <SFML/Graphics.hpp>
#include "Obstaculo.h"
#include "Personagem.h"
#pragma once
class Collider {
private:
    //sf::RectangleShape body;
public:
    Collider();
    ~Collider();

    // void move (float dx, float dy){body.move(dx,dy);}

    // void setBody(sf::RectangleShape& body);

    bool checkCollision(Obstaculo& parada, Personagem& movimentavel,sf::Vector2f& direction, float push);
    bool checkCollision(Personagem& parada, Personagem& movimentavel, sf::Vector2f& direction, float push);
    bool checkCollision(Obstaculo& parada, Obstaculo& movimentavel, sf::Vector2f& direction, float push);
};
