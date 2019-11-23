#include "Obstaculo_Espinho.h"

const int Obstaculo_Espinho::id = 5;

Obstaculo_Espinho::Obstaculo_Espinho(Vector2f position) : Obstaculo(position)
{
    canHurt = true;
    canMove = false;
    push = 1.0;
}

Obstaculo_Espinho::~Obstaculo_Espinho()
{
    //dtor
}
