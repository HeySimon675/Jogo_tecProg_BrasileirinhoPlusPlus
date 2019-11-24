
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 09/11/19.
#include "Personagem.h"

//--------------------------------------------------------------------------------------------------------------------//
//Constantes

const Vector2f Personagem::POSICAO_PADRAO = Vector2f(50,50);
const float Personagem::VELOCIDADE_PADRAO = 100;
const Vector2f Personagem::TAMANHO_PADRAO = Vector2f(50.0f,50.0f);
const float Personagem::PULO_PADRAO = 150.0f;

//--------------------------------------------------------------------------------------------------------------------//
//CONSTRUÇÃO

Personagem::Personagem(Vector2f position, Vector2f size, float speed): Entidade()
{
    inicializaPersonagem(position, size,speed);
}


Personagem::~Personagem()
{

}

void Personagem::inicializaPersonagem(Vector2f position, Vector2f size, float sd)
{
    setPosition(position);

    body.setSize(size);
    body.setOrigin(size/2.0f);
    this->speed = sd;
}

void Personagem::draw()
{
    gerenciadorGrafico->draw(body);
}

void Personagem::update(float deltaTime)
{
    //std::cout<<"Estou dando update?"<<std::endl;
    calculaMovimento(deltaTime);
    body.move(vel * deltaTime);

}

//--------------------------------------------------------------------------------------------------------------------//
//Ferramentas para fase
void Personagem::setPosition(Vector2f position){
    Vector2f pos;
    if(position != POSICAO_PADRAO){
        pos.x = POSICAO_PADRAO.x * position.x;
        pos.y = POSICAO_PADRAO.y * position.y;
    }else{
        pos = position;
    }
    body.setPosition(pos);
}


const bool Personagem::isDead()
{
    return dead;
}

void Personagem::setPositionx(const float positionx)
{
    body.setPosition(positionx, body.getPosition().y);
}

//--------------------------------------------------------------------------------------------------------------------//
//Ferramentas para Colisoes

void Personagem::emColisao(Vector2f direcao)
{
    if (direcao.x != 0)
    {
        if (direcao.x < 0.0f)
        {
            vel.x = 0.0f;
        }
        else if (direcao.x > 0.0f)
        {
            vel.x = 0.0f;
        }
    }
    if (direcao.y != 0)
    {
        if (direcao.y < 0.0f)
        {
            vel.y = 0.0f;
        }
        else if (direcao.y > 0.0f)
        {
            vel.y = 0.0f;
            canJump = true;
        }
    }
}

void Personagem::associaTextura() {
    body.setTexture(gerenciadorGrafico->getTexture(getID()));
}

