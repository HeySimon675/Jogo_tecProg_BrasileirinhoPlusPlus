
//--------------------------------------------------------------------------------------------------------------------//
// Created by simao on 11/11/2019.
//

#include "Projetil_Tipo_1.h"
#include <iostream>

Projetil_Tipo_1::Projetil_Tipo_1(sf::Vector2f position, sf::Vector2f size, bool active, float speed)
{
    inicializaProjetilTipo1(position, size, active, speed);
}

Projetil_Tipo_1::Projetil_Tipo_1()
{

}

Projetil_Tipo_1::~Projetil_Tipo_1()
{

}

void Projetil_Tipo_1::inicializaProjetilTipo1(sf::Vector2f position, sf::Vector2f size, bool active, float speed)
{
    inicializaProjetil(position, size, active, speed);
    posicao_X_inicial = position.x;
    dead = false;
}

void Projetil_Tipo_1::calculaMovimento()
{
    vel.x = 0;

        if(!(body.getPosition().x <= (posicao_X_inicial - 258.0f) && body.getPosition().x >= (posicao_X_inicial - 262.0f)))
        {
            vel.x -= speed;
        }
        else
        {
            vel.x = 0;
            dead = true;
        }
}
