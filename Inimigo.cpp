

//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 11/11/19.

#include "Inimigo.h"

Inimigo::Inimigo(Vector2f position, Vector2f size, float speed) : Personagem(position,size,speed)
{
    inimigoB = false;
}


Inimigo::~Inimigo()
{

}
