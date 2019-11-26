
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 09/11/19.

#include "Jogador_1.h"

//--------------------------------------------------------------------------------------------------------------------//
//constantes
const int Jogador_1::id = 0;


//--------------------------------------------------------------------------------------------------------------------//
//construção

Jogador_1::Jogador_1(Vector2f position) : Jogador(position)
{
    //deixar static assim que possivel
    KeyLeft = Keyboard::Left;
    KeyRight = Keyboard::Right;
    KeyJump = Keyboard::Up;
    associaTextura();
}

Jogador_1::~Jogador_1(){}

void Jogador_1::inicializar(Vector2f position)
{
    setPosition(position);
    body.move(25,25);
}

const int Jogador_1::getID() {
    return id;
}

//--------------------------------------------------------------------------------------------------------------------//
//Atualização
void Jogador_1::calculaMovimento(const float deltaTime)
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

    //std::cout<<body.getPosition().x<<std::endl;

    vel.y += 981.0f * deltaTime;
}
//--------------------------------------------------------------------------------------------------------------------//

