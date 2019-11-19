
//--------------------------------------------------------------------------------------------------------------------//
// Created by simao on 11/11/2019.
//

#include "Obstaculo.h"
#include <iostream>



//--------------------------------------------------------------------------------------------------------------------//
//constantes
const Vector2f Obstaculo::TAMANHO_PADRAO = Vector2f(50.0f,50.0f);
const Vector2f Obstaculo::POSICAO_PADRAO = Vector2f(50.0f,50.0f);

Obstaculo::Obstaculo(Vector2f position,Vector2f size, bool active)
{
    Vector2f pos = POSICAO_PADRAO;
    if(pos != position){
    
    }
    inicializaObstaculo(position, size, active);
}

Obstaculo::Obstaculo()
{

}

Obstaculo::~Obstaculo()
{

}

void Obstaculo::inicializaObstaculo(sf::Vector2f position, sf::Vector2f size, bool active)
{

    body.setPosition(position);
    body.setSize(size);
    inicializaEntidade(position, size, active);
}

void Obstaculo::setCanHurt(bool ch)
{
    canHurt = ch;
}

bool Obstaculo::getCanHurt()
{
    return canHurt;
}

void Obstaculo::setCanMove(bool cm)
{
    canMove = cm;
}

bool Obstaculo::getCanMove()
{
    return canMove;
}

void Obstaculo::draw()
{
    /**Teste para botar uma cor no body**/
    body.setFillColor(sf::Color::White);
    //Draw do body em si
    gerenciadorGrafico->draw(body);

    std::cout<<"desenhou?"<<std::endl;
}
/**
Collider Obstaculo::GetCollider()
{
    return Collider(body);
}
**/
