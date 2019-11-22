

#include "Obstaculo_Movel.h"

Obstaculo_Movel::Obstaculo_Movel(Vector2f position): Obstaculo(position)
{
    canHurt = false;
    canMove = true;
    push = 0.0;
}

Obstaculo_Movel::~Obstaculo_Movel()
{
    //dtor
}
