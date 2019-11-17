
//--------------------------------------------------------------------------------------------------------------------//
// Created by simao on 11/11/2019.
//

#include "Projetil.h"
#include <iostream>

Projetil::Projetil(sf::Vector2f position, sf::Vector2f size, bool active, float speed)
{
    inicializaProjetil(position, size, active, speed);
}

Projetil::Projetil()
{

}

Projetil::~Projetil()
{

}

void Projetil::inicializaProjetil(sf::Vector2f position, sf::Vector2f size, bool active, float spd)
{
    inicializaEntidade(position, size, active);
    body.setPosition(position);
    body.setSize(size);
    speed = spd;
}

void Projetil::update(const float deltaTime)
{
    calculaMovimento();
    body.move(vel * deltaTime);
}

void Projetil::draw()
{
    /**Teste para botar uma cor no body**/
    body.setFillColor(sf::Color::Yellow);
    //Draw do body em si
    gerenciadorGrafico->draw(body);
}
