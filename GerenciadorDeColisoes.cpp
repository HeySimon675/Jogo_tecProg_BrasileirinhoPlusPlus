
//--------------------------------------------------------------------------------------------------------------------//
#include "GerenciadorDeColisoes.h"
#include <iostream>
#include <vector>
#include <iterator>

GerenciadorDeColisoes::GerenciadorDeColisoes(){

}

GerenciadorDeColisoes::~GerenciadorDeColisoes() {
    li.desativar();
    lo.desativar();
    lp.desativar();
}

void GerenciadorDeColisoes::executar()
{
    for(int itr = 0 ; itr != li.getContador() ;itr++) {
        Inimigo *ptrI = li.getInimigo(itr);
        if (ptrI->isActive())
            checkCollision(ptrI, j1);
        if (ptrI->isActive() && p2) //TODO TESTAR
            checkCollision(ptrI, j2);
    }

    for(int itr = 0; itr != lo.getContador(); itr++)
    {
        Obstaculo* ptrO = lo.getObstaculo(itr);
        if(ptrO->isActive())
        {
            sf::Vector2f direction;
            checkCollision(ptrO, j1, direction, ptrO->getPush());
            j1->emColisao(direction);
        }
        if(ptrO->isActive() && p2){
            sf::Vector2f direction;
            checkCollision(ptrO, j2, direction, ptrO->getPush());
            j2->emColisao(direction);
        }
    }

    for(int itr = 0; itr != lp.getContador(); itr++)
    {
        Projetil* ptrP = lp.getProjetil(itr);

        sf::Vector2f direction;
        checkCollision(ptrP, j1);
        j1->emColisao(direction);

        if(p2)
        {
            sf::Vector2f direction;
            checkCollision(ptrP, j2);
            j2->emColisao(direction);
        }
    }
}

bool GerenciadorDeColisoes::checkCollision(Obstaculo* parada, Personagem* movimentavel, sf::Vector2f& direction, float push) {
    sf::Vector2f otherPosition = movimentavel->getPosition();
    sf::Vector2f otherHalfSize = movimentavel->getHalfSize();
    sf::Vector2f thisPosition = parada->getPosition();
    sf::Vector2f thisHalfSize = parada->getHalfSize();
    //pegando as informações sobre os cubos de colisão

    float deltaX = otherPosition.x - thisPosition.x;
    float deltaY = otherPosition.y - thisPosition.y;

    float intersecX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
    float intersecY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

    if(!parada->getCanHurt() && !parada->getCanMove())
    {
        if(intersecX < 0.0f && intersecY < 0.0f){
            push = std::min(std::max(push, 0.0f),1.0f);
            // push vai receber o menor valor entre 1.0f e max(push, 0.0f) que é o maior valor entre push e zero
            //logo push vai ser um valor entre 0 e 1
            if( intersecX > intersecY){

                if(deltaX>0.0f){
                    direction.x =-1.0f;
                    direction.y =0.0f;

                    parada->move(intersecX* (1.0f- push),0.0f);
                    movimentavel->move((-intersecX * push),0.0f);
                }else {
                    direction.x =1.0f;
                    direction.y =0.0f;

                    parada->move(-intersecX* (1.0f-push),0.0f);
                    movimentavel->move((intersecX * push),0.0f);
                }
            }else{
                if(deltaY>0.0f){
                    direction.x =0.0f;
                    direction.y =-1.0f;

                    parada->move(0.0f,intersecY* (1.0f-push));
                    movimentavel->move(0.0f ,-intersecY *  push);
                }else{
                    direction.x =0.0f;
                    direction.y =1.0f;

                    parada->move(0.0f,-intersecY* ((1.0f-push)));
                    movimentavel->move(0.0f,intersecY *  push);

                }
            }
            return true;
        }
        return false;
    }

    if(parada->getCanHurt() && !parada->getCanMove())
    {
        if(intersecX < 0.0f && intersecY < 0.0f){
            float push = 1;
            sf::Vector2f direction;
            push = std::min(std::max(push, 0.0f),1.0f);
            // push vai receber o menor valor entre 1.0f e max(push, 0.0f) que é o maior valor entre push e zero
            //logo push vai ser um valor entre 0 e 1
            if( intersecX > intersecY){

                if(deltaX>0.0f){
                    direction.x =-1.0f;
                    direction.y =0.0f;

                    parada->move(intersecX* (1.0f- push),0.0f);
                    movimentavel->move((-intersecX * push),0.0f);
                    //movimentavel->desativarEntidade();
                }else {
                    direction.x =1.0f;
                    direction.y =0.0f;

                    parada->move(-intersecX* (1.0f-push),0.0f);
                    movimentavel->move((intersecX * push),0.0f);
                    //movimentavel->desativarEntidade();
                }
            }else{
                if(deltaY>0.0f){
                    direction.x =0.0f;
                    direction.y =-1.0f;

                    parada->move(0.0f,intersecY* (1.0f-push));
                    movimentavel->move(0.0f ,-intersecY *  push);
                }else{
                    direction.x =0.0f;
                    direction.y =1.0f;

                    //parada.move(0.0f,-intersecY* ((1.0f-push)));
                    movimentavel->move(0.0f,intersecY *  push);
                    movimentavel->desativar();

                }
            }
            return true;
        }
        return false;
    }

    if(!parada->getCanHurt() && parada->getCanMove())
    {
        if(intersecX < 0.0f && intersecY < 0.0f){
            push = std::min(std::max(push, 0.0f),1.0f);
            // push vai receber o menor valor entre 1.0f e max(push, 0.0f) que é o maior valor entre push e zero
            //logo push vai ser um valor entre 0 e 1
            if( intersecX > intersecY){

                if(deltaX>0.0f){
                    direction.x =-1.0f;
                    direction.y =0.0f;

                    parada->move(intersecX* (1.0f- push),0.0f);
                    movimentavel->move((-intersecX * push),0.0f);
                }else {
                    direction.x =1.0f;
                    direction.y =0.0f;

                    parada->move(-intersecX* (1.0f-push),0.0f);
                    movimentavel->move((intersecX * push),0.0f);
                }
            }else{
                if(deltaY>0.0f){
                    direction.x =0.0f;
                    direction.y =-1.0f;

                    parada->move(0.0f,intersecY* (1.0f-push));
                    movimentavel->move(0.0f ,-intersecY *  push);
                }else{
                    direction.x =0.0f;
                    direction.y =1.0f;

                    parada->move(0.0f,0.0f);
                    movimentavel->move(0.0f,intersecY );

                }
            }
            return true;
        }
        return false;
    }

}

bool GerenciadorDeColisoes::checkCollision(Inimigo* parada, Jogador* movimentavel) {
    sf::Vector2f otherPosition = movimentavel->getPosition();
    sf::Vector2f otherHalfSize = movimentavel->getHalfSize();
    sf::Vector2f thisPosition = parada->getPosition();
    sf::Vector2f thisHalfSize = parada->getHalfSize();
    //pegando as informações sobre os cubos de colisão

    float deltaX = otherPosition.x - thisPosition.x;
    float deltaY = otherPosition.y - thisPosition.y;

    float intersecX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
    float intersecY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

    if(intersecX < 0.0f && intersecY < 0.0f){
        float push = 0;
        sf::Vector2f direction;
        push = std::min(std::max(push, 0.0f),1.0f);
        // push vai receber o menor valor entre 1.0f e max(push, 0.0f) que é o maior valor entre push e zero
        //logo push vai ser um valor entre 0 e 1
        if( intersecX > intersecY){

            if(deltaX>0.0f){
                direction.x =-1.0f;
                direction.y =0.0f;

                parada->move(intersecX* (1.0f- push),0.0f);
                movimentavel->move((-intersecX * push),0.0f);
                movimentavel->desativar();
            }else {
                direction.x =1.0f;
                direction.y =0.0f;

                parada->move(-intersecX* (1.0f-push),0.0f);
                //movimentavel.move((intersecX * push),0.0f);
                movimentavel->desativar();
            }
        }else{
            if(deltaY>0.0f){
                direction.x =0.0f;
                direction.y =-1.0f;

                parada->move(0.0f,intersecY* (1.0f-push));
                movimentavel->move(0.0f ,-intersecY *  push);
            }else{
                direction.x =0.0f;
                direction.y =1.0f;

                //parada.move(0.0f,-intersecY* ((1.0f-push)));
                movimentavel->move(0.0f,intersecY *  push);
                parada->desativar();
                //Para desativar o projetil
                if(parada->getInimigoB())
                {
                    parada->getProjetil()->desativar();
                }

            }
        }
        return true;
    }
    return false;
}

bool GerenciadorDeColisoes::checkCollision(Projetil* parada, Jogador* movimentavel) {
    sf::Vector2f otherPosition = movimentavel->getPosition();
    sf::Vector2f otherHalfSize = movimentavel->getHalfSize();
    sf::Vector2f thisPosition = parada->getPosition();
    sf::Vector2f thisHalfSize = parada->getHalfSize();
    //pegando as informações sobre os cubos de colisão

    float deltaX = otherPosition.x - thisPosition.x;
    float deltaY = otherPosition.y - thisPosition.y;

    float intersecX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
    float intersecY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

    if(intersecX < 0.0f && intersecY < 0.0f){
        float push = 0;
        sf::Vector2f direction;
        push = std::min(std::max(push, 0.0f),1.0f);
        // push vai receber o menor valor entre 1.0f e max(push, 0.0f) que é o maior valor entre push e zero
        //logo push vai ser um valor entre 0 e 1
        if( intersecX > intersecY){

            if(deltaX>0.0f){
                direction.x =-1.0f;
                direction.y =0.0f;

                // parada->move(intersecX* (1.0f- push),0.0f);
                //movimentavel->move((-intersecX * push),0.0f);
                movimentavel->desativar();
            }else {
                direction.x =1.0f;
                direction.y =0.0f;

                // parada->move(-intersecX* (1.0f-push),0.0f);
                //movimentavel.move((intersecX * push),0.0f);
                movimentavel->desativar();
            }
        }else{
            if(deltaY>0.0f){
                direction.x =0.0f;
                direction.y =-1.0f;

                // parada->move(0.0f,intersecY* (1.0f-push));
                // movimentavel->move(0.0f ,-intersecY *  push);
                movimentavel->desativar();
            }else{
                direction.x =0.0f;
                direction.y =1.0f;

                //parada.move(0.0f,-intersecY* ((1.0f-push)));
                //  movimentavel->move(0.0f,intersecY *  push);
                //   parada->desativarEntidade();
                movimentavel->desativar();
            }
        }
        return true;
    }
    return false;
}
