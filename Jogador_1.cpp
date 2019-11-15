
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 09/11/19.

#include "Jogador_1.h"
#include <iostream>
#include <math.h>

Jogador_1::Jogador_1(sf::Vector2f position, sf::Vector2f size, bool active, float speed, float jump_height, sf::Keyboard::Key right,
                                    sf::Keyboard::Key left, sf::Keyboard::Key jump)
{
    inicializaJogador_1(position, size, active, speed, jump_height, right, left, jump);
}

Jogador_1::Jogador_1()
{

}

Jogador_1::~Jogador_1()
{

}

void Jogador_1::inicializaJogador_1(sf::Vector2f position, sf::Vector2f size, bool active, float speed, float jump_height,
                         sf::Keyboard::Key right, sf::Keyboard::Key left, sf::Keyboard::Key jump)
{
    inicializaJogador(position, size, active, speed, jump_height, right, left, jump);
}

void Jogador_1::calculaMovimento(const float deltaTime)
{
    vel.x = 0.0f;

		if (sf::Keyboard::isKeyPressed(KeyLeft)){
			vel.x -= speed;
		}
		if (sf::Keyboard::isKeyPressed(KeyRight))
			vel.x += speed;
		if (sf::Keyboard::isKeyPressed(KeyJump) && canJump)
		{
			canJump = false;
			vel.y = -sqrtf(2.0f * 981.0f * jump_height);
		}

		//std::cout<<body.getPosition().x<<std::endl;

		//vel.y += 981.0f * deltaTime;

}

