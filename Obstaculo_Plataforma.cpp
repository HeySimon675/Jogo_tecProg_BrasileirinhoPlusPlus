

#include "Obstaculo_Plataforma.h"

Obstaculo_Plataforma::Obstaculo_Plataforma(Vector2f position) : Obstaculo(position)
{
    canHurt = false;
    canMove = false;
    push = 1.0;
    setPosition(position);
}


Obstaculo_Plataforma::~Obstaculo_Plataforma()
{
    //dtor
}
