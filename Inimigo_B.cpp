
//--------------------------------------------------------------------------------------------------------------------//
// Created by simao on 11/11/2019.

#include "Inimigo_B.h"

const int Inimigo_B::id = 2;    //TODO arrumar
//const int Inimigo_B::id = 7;

Inimigo_B::Inimigo_B( Vector2f position, Vector2f size, float speed ) : Inimigo(position, size, speed)
{
    passou10segundos = false;
    projetilCriado = false;
    associaTextura();
}

Inimigo_B::~Inimigo_B()
{
}

void Inimigo_B::inicializar(Vector2f position, Projetil* projetil)
{
    setPosition(position);
    setProjetil(projetil);
    projetilCriado = false;
    body.move(25,25);
}

void Inimigo_B::calculaMovimento(const float deltaTime)
{
    if(!projetilCriado)
    {
        projetil->setPosicao(sf::Vector2f(body.getPosition().x, body.getPosition().y + (body.getSize().y/16.0f)));
        projetilCriado = true;
    }
    projetil->setDead(false);
}
