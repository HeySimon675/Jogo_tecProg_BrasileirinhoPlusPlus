
//--------------------------------------------------------------------------------------------------------------------//
// Created by simao on 11/11/2019.

#include "Inimigo_A.h"
#include <iostream>

Inimigo_A::Inimigo_A(sf::Vector2f position, sf::Vector2f size, bool active, float speed, float jump_height)
{
    inicializaInimigo_A(position, size, active, speed, jump_height);
}

Inimigo_A::Inimigo_A()
{

}

Inimigo_A::~Inimigo_A()
{

}

void Inimigo_A::draw() {
    body.setFillColor(Color::Green);
    gerenciadorGrafico->draw(body);
}

void Inimigo_A::inicializaInimigo_A(sf::Vector2f position, sf::Vector2f size, bool active, float speed, float jump_height)
{
    Vector2f pos;
    if(position != POSICAO_PADRAO){
        pos.x = POSICAO_PADRAO.x * position.x;
        pos.y = POSICAO_PADRAO.y * position.y;
    }else{
        pos = position;
    }
    inicializaInimigo(pos, size, active, speed, jump_height);
    position_X_inicial = position.x;
    goingLeft = true;
}

void Inimigo_A::calculaMovimento(const float deltaTime)
{
    vel.x = 0;
       if(goingLeft)
       {
           if(!(body.getPosition().x <= (position_X_inicial - 508.0f) && body.getPosition().x >= (position_X_inicial - 512.0f)))
           {
               vel.x -= speed;
           }
           else
           {
               goingLeft = false;
              // vel.x = 0;
           }
       }

    else{

        if(!(body.getPosition().x >= (position_X_inicial - 2.0f) && body.getPosition().x <= position_X_inicial +2.0f))
        {
            vel.x += speed;
        }
        else
        {
            goingLeft = true;
              // vel.x = 0;
        }
    }

       //std::cout<<vel.x<<std::endl;
}
