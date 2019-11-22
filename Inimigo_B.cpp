
//--------------------------------------------------------------------------------------------------------------------//
// Created by simao on 11/11/2019.

#include "Inimigo_B.h"

Inimigo_B::Inimigo_B( Vector2f position, Vector2f size, float speed ) : Inimigo(position, size, speed)
{
    passou10segundos = false;
    projetilCriado = false;
}

Inimigo_B::~Inimigo_B()
{
}

void Inimigo_B::inicializar(Vector2f position, Projetil* projetil)
{
    setPosition(position);
    setProjetil(projetil);
}

void Inimigo_B::calculaMovimento(const float deltaTime)
{
    if(!projetilCriado)
    {
        projetil->setPosicao(sf::Vector2f(body.getPosition().x, body.getPosition().y - (body.getSize().y/4.0f)));
        projetilCriado = true;
    }
    projetil->setDead(false);
}
