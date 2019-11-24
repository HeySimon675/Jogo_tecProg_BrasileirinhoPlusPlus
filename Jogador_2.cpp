
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 11/11/19.


#include "Jogador_2.h"

const int Jogador_2::id = 1;

//--------------------------------------------------------------------------------------------------------------------//
//construção

Jogador_2::Jogador_2(Vector2f position) : Jogador(position)
{
    //deixar static assim que possivel
    KeyLeft = Keyboard::Left;
    KeyRight = Keyboard::Right;
    KeyJump = Keyboard::Up;
    associaTextura();
}

Jogador_2::~Jogador_2(){}

void Jogador_2::inicializar(Vector2f position)
{
    setPosition(position);
}


//--------------------------------------------------------------------------------------------------------------------//
//Atualização
void Jogador_2::calculaMovimento(const float deltaTime)
{
    vel.x = 0.0f;
    // vel.y = 0.0f;

    if (Keyboard::isKeyPressed(sf::Keyboard::Left)){
        vel.x -= speed;
    }
    if (Keyboard::isKeyPressed(sf::Keyboard::Right))
        vel.x += speed;
    if (Keyboard::isKeyPressed(sf::Keyboard::Up) && canJump)
    {
        canJump = false;
        //vel.y -= speed;
        vel.y = -sqrtf(2.0f * 981.0f * PULO_PADRAO);
    }


    vel.y += 981.0f * deltaTime;
}
//--------------------------------------------------------------------------------------------------------------------//

