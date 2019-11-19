
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 09/11/19.
//Last Update 09/11 12hrs

#include "Personagem.h"
#include <iostream>


//--------------------------------------------------------------------------------------------------------------------//
//Constantes
    const Vector2f Personagem::TAMANHO_PADRAO = Vector2f(50.0f,50.0f);
    const Vector2f Personagem::POSICAO_PADRAO = Vector2f(0,0);

//--------------------------------------------------------------------------------------------------------------------//
//
Personagem::Personagem(sf::Vector2f position, sf::Vector2f size, bool active, float speed, float jump_height)
{
    inicializaPersonagem(position, size, active, speed, jump_height);
}

Personagem::Personagem()
{

}

Personagem::~Personagem()
{

}

void Personagem::inicializaPersonagem(sf::Vector2f position = POSICAO_PADRAO, sf::Vector2f size = TAMANHO_PADRAO, bool active = true, float sp = 100.0f, float jh = 50.0f)
{
    inicializaEntidade(position, size, active);

    body.setPosition(position);
    body.setSize(size);
    speed = sp;
    jump_height = jh;
}

void Personagem::draw()
{
    /**Teste para botar uma cor no body**/
    body.setFillColor(sf::Color::Cyan);
    //Draw do body em si
    gerenciadorGrafico->draw(body);
}

void Personagem::update(float deltaTime)
{
    //std::cout<<"Estou dando update?"<<std::endl;
    calculaMovimento(deltaTime);
    body.move(vel * deltaTime);

}

const bool Personagem::isDead()
{
    return dead;
}

void Personagem::setPositionx(const float positionx)
{
    body.setPosition(positionx, body.getPosition().y);
}
