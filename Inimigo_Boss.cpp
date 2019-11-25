
//--------------------------------------------------------------------------------------------------------------------//
#include "Inimigo_Boss.h"

const int Inimigo_Boss::id = 9;

Inimigo_Boss::Inimigo_Boss(Vector2f position, Vector2f size, float speed) : Inimigo(position,size,speed)
{
    position_X_inicial = position.x;
    goingLeft = true;
    canMove = true;
    projetilCriado = false;
    associaTextura();
}

Inimigo_Boss::~Inimigo_Boss()
{

}

void Inimigo_Boss::inicializarBoss(Vector2f position)
{
    setPosition(position);
    corrigePosicao();
    position_X_inicial = position.x*50.0f;
}

void Inimigo_Boss::calculaMovimento(const float deltaTime)
{
    if(!projetilCriado)
    {
        projetil->setPosicao(Vector2f(body.getPosition().x, body.getPosition().y - (body.getSize().y/4.0f)));
        projetilCriado = true;
    }

    if(projetil->getDead() && canMove)
    {
        projetil->setPosicao(Vector2f(body.getPosition().x, body.getPosition().y - (body.getSize().y/4.0f)));
        vel.x = 0;
        if(goingLeft)
        {
            if(!(body.getPosition().x <= (position_X_inicial - 173.0f) && body.getPosition().x >= (position_X_inicial - 177.0f)))
            {
                vel.x -= speed;
            }
            else
            {
                goingLeft = false;
                //canMove = false;
                projetil->setDead(false);
                projetil->setLeft(false);
                // vel.x = 0;
            }
        }

        else{

            if(!(body.getPosition().x >= (position_X_inicial - 48.0f) && body.getPosition().x <= position_X_inicial +52.0f))
            {
                vel.x += speed;
            }
            else
            {
                goingLeft = true;
                projetil->setDead(false);
                projetil->setLeft(true);
                // vel.x = 0;
            }
        }
    }
}

