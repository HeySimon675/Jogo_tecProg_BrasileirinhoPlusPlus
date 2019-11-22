
//--------------------------------------------------------------------------------------------------------------------//
// Created by simao on 11/11/2019.
//

#include "Projetil.h"
#include <iostream>


Projetil::Projetil(Vector2f size, float speed) : Entidade()
{
    this->speed = speed;
    dead = false;
    left = true;
    vel = Vector2f(0,0);
    inicializaProjetil(size);
}



Projetil::~Projetil()
{

}

void Projetil::inicializaProjetil(Vector2f size)
{
    body.setSize(size);
    body.setOrigin(size/2.0f);
}

void Projetil::update(const float deltaTime)
{
    calculaMovimento();
    body.move(vel * deltaTime);
}

void Projetil::draw()
{
    /**Teste para botar uma cor no body**/
    body.setFillColor(Color::Yellow);
    //Draw do body em si
    gerenciadorGrafico->draw(body);
}

void Projetil::calculaMovimento()
{
    if(!dead)
    {
        vel.x = 0;
        if(left)
        {
            if(!(body.getPosition().x <= (posicao_X_inicial - 258.0f) && body.getPosition().x >= (posicao_X_inicial - 262.0f)))
            {
                vel.x -= speed;
            }
            else
            {
                vel.x = 0;
                body.setPosition(Vector2f(posicao_X_inicial, posicao_Y_inicial));
                dead = true;
            }
        }
        else
        {
            if(!(body.getPosition().x >= (posicao_X_inicial + 258.0f) && body.getPosition().x <= (posicao_X_inicial + 262.0f)))
            {
                vel.x += speed;
            }
            else
            {
                vel.x = 0;
                body.setPosition(Vector2f(posicao_X_inicial, posicao_Y_inicial));
                dead = true;
            }
        }
    }
}

void Projetil::setPosicao(Vector2f posicao)
{
    body.setPosition(posicao);
    posicao_X_inicial = posicao.x;
    posicao_Y_inicial = posicao.y;
}
