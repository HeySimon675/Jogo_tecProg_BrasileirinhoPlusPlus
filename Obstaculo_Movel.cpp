

#include "Obstaculo_Movel.h"

const int Obstaculo_Movel::id = 4;

Obstaculo_Movel::Obstaculo_Movel(Vector2f position): Obstaculo(position)
{
    canHurt = false;
    canMove = true;
    push = 0.0;
    associaTextura();
}

Obstaculo_Movel::~Obstaculo_Movel()
{
    //dtor
}
