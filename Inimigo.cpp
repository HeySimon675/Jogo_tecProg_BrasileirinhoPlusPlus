

//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 11/11/19.

#include "Inimigo.h"

Inimigo::Inimigo(sf::Vector2f position, sf::Vector2f size, bool active, float speed, float jump_height)
{
    inicializaInimigo(position, size, active, speed, jump_height);
}

Inimigo::Inimigo()
{

}

Inimigo::~Inimigo()
{

}

void Inimigo::inicializaInimigo(sf::Vector2f position, sf::Vector2f size, bool active, float speed, float jump_height)
{
    inicializaPersonagem(position, size, active, speed, jump_height);
}
