
//--------------------------------------------------------------------------------------------------------------------//

#include "Obstaculo.h"

//--------------------------------------------------------------------------------------------------------------------//
//constantes
const Vector2f Obstaculo::TAMANHO_PADRAO = Vector2f(50.0f,50.0f);
const Vector2f Obstaculo::POSICAO_PADRAO = Vector2f(50.0f,50.0f);

//--------------------------------------------------------------------------------------------------------------------//
Obstaculo::Obstaculo(Vector2f position, Vector2f size) : Entidade()
{
    setPosition(position);
    body.setSize(size);
}


Obstaculo::~Obstaculo()
{

}

//--------------------------------------------------------------------------------------------------------------------//
//Ferramentas para fase
void Obstaculo::setPosition(Vector2f position){
    Vector2f pos(0,0);
    if(position != POSICAO_PADRAO){
        pos.x = POSICAO_PADRAO.x * position.x;
        pos.y = POSICAO_PADRAO.y * position.y;
    }else{
        pos = position;
    }
    body.setPosition(pos);
}
//--------------------------------------------------------------------------------------------------------------------//

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
//--------------------------------------------------------------------------------------------------------------------//
void Obstaculo::draw()
{
    gerenciadorGrafico->draw(body);

}
