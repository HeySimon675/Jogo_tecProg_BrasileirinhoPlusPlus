
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 09/11/19.

#include "Jogador_1.h"
#include <iostream>
#include <math.h>

//--------------------------------------------------------------------------------------------------------------------//
//constantes
const int Jogador_1::id = 0;


//--------------------------------------------------------------------------------------------------------------------//
//construção

Jogador_1::Jogador_1(Vector2f position) : Jogador(position)
{
    //deixar static assim que possivel
    setPosition(position);
    KeyLeft = Keyboard::Left;
    KeyRight = Keyboard::Right;
    KeyJump = Keyboard::Up;
}

Jogador_1::~Jogador_1(){}

void Jogador_1::inicializaJogador_1(Vector2f position)
{
    setPosition(position);
}

const int Jogador_1::getID() {
    return id;
}

//--------------------------------------------------------------------------------------------------------------------//
//Atualização
void Jogador_1::calculaMovimento(const float deltaTime)
{
    vel.x = 0.0f;

		if (Keyboard::isKeyPressed(KeyLeft)){
			vel.x -= speed;
		}
		if (Keyboard::isKeyPressed(KeyRight))
			vel.x += speed;
		if (Keyboard::isKeyPressed(KeyJump) && canJump)
		{
			canJump = false;
			vel.y = -sqrtf(2.0f * 981.0f * jump_height);
		}

		//std::cout<<body.getPosition().x<<std::endl;

		//vel.y += 981.0f * deltaTime;

}
//--------------------------------------------------------------------------------------------------------------------//

