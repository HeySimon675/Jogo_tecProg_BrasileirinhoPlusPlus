
//--------------------------------------------------------------------------------------------------------------------//
// Created by simao on 11/11/2019.

#include "Inimigo_B.h"
#include <iostream>
//#include <windows.h>

Inimigo_B::Inimigo_B(sf::Vector2f position, sf::Vector2f size, bool active, float speed, float jump_height)
{
    inicializaInimigo_B(position, size, active, speed, jump_height);
    pt1 = nullptr;
}

Inimigo_B::Inimigo_B()
{

}

Inimigo_B::~Inimigo_B()
{
    delete pt1;
}

void Inimigo_B::inicializaInimigo_B(sf::Vector2f position, sf::Vector2f size, bool active, float speed, float jump_height)
{
    inicializaInimigo(position, size, active, speed, jump_height);
    projetilCriado = false;
}

void Inimigo_B::calculaMovimento(const float deltaTime)
{
    if(!projetilCriado)
    {
        pt1 = new Projetil_Tipo_1(sf::Vector2f(body.getPosition().x + 25.0f, body.getPosition().y + (body.getSize().y/4)),
                       sf::Vector2f(25.0f, 25.0f), true, 100.0f);
        projetilCriado = true;
    }

    pt1->update(deltaTime);

    pt1->draw();

    if(pt1->getDead())
    {
        delete pt1;
        projetilCriado = false;
        //deltaDeltaTempo = 0;
    }

}
