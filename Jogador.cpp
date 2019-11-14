
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 09/11/19.

#include "Jogador.h"

//--------------------------------------------------------------------------------------------------------------------//

Jogador::Jogador(sf::Vector2f position, sf::Vector2f size, bool active, float speed, float jump_height,
                                 sf::Keyboard::Key right,  sf::Keyboard::Key left, sf::Keyboard::Key jump)
{
    inicializaJogador(position, size, active, speed, jump_height, right, left, jump);
}

Jogador::Jogador()
{

}

Jogador::~Jogador()
{

}


void Jogador::inicializaJogador(sf::Vector2f position, sf::Vector2f size, bool active, float speed, float jump_height,
                                 sf::Keyboard::Key right,  sf::Keyboard::Key left, sf::Keyboard::Key jump)
{
    inicializaPersonagem(position, size, active, speed, jump_height);

    KeyRight = right,
    KeyLeft = left;
    KeyJump = jump;

}



