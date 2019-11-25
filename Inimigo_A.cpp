
//--------------------------------------------------------------------------------------------------------------------//


#include "Inimigo_A.h"

//--------------------------------------------------------------------------------------------------------------------//
//constantes
const int Inimigo_A::id = 2;

//--------------------------------------------------------------------------------------------------------------------//

Inimigo_A::Inimigo_A(Vector2f position, Vector2f size, float speed) : Inimigo(position, size, speed)
{
    goingLeft = true;
    position_X_inicial = position.x *50.0f;
    associaTextura();
}

Inimigo_A::~Inimigo_A()
{

}

void Inimigo_A::draw() {
    gerenciadorGrafico->draw(body);
}

void Inimigo_A::inicializar(Vector2f position)
{
    setPosition(position);
    position_X_inicial = position.x*50.0f;
    corrigePosicao();

}

void Inimigo_A::calculaMovimento(const float deltaTime)
{
    vel.x = 0;
       if(goingLeft)
       {
           if(!(body.getPosition().x <= (position_X_inicial - 123.0f) && body.getPosition().x >= (position_X_inicial - 127.0f)))
           {
               vel.x -= speed;
           }
           else
           {
               goingLeft = false;
              // vel.x = 0;
           }
       }

    else{

        if(!(body.getPosition().x >= (position_X_inicial - 23.0f) && body.getPosition().x <= position_X_inicial +27.0f))
        {
            vel.x += speed;
        }
        else
        {
            goingLeft = true;
              // vel.x = 0;
        }
    }

       //std::cout<<vel.x<<std::endl;
}
