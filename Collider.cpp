
//--------------------------------------------------------------------------------------------------------------------//

#include "Collider.h"
#include <iostream>

Collider::Collider(){

}

Collider::~Collider() {

}

bool Collider::checkCollision(Obstaculo& parada, Personagem& movimentavel, sf::Vector2f& direction, float push) {
    sf::Vector2f otherPosition = movimentavel.getPosition();
    sf::Vector2f otherHalfSize = movimentavel.getHalfSize();
    sf::Vector2f thisPosition = parada.getPosition();
    sf::Vector2f thisHalfSize = parada.getHalfSize();
    //pegando as informações sobre os cubos de colisão

    //std::cout<< "Posicao do player .x : " << otherPosition.x <<std::endl;
    //std::cout<< "Posicao da plataforma .x : " << thisPosition.x <<std::endl;
    //std::cout<< "Posicao do player .y : " << otherPosition.y <<std::endl;
    //std::cout<< "Posicao da plataforma .y : " << thisPosition.y <<std::endl;

    float deltaX = otherPosition.x - thisPosition.x;
    float deltaY = otherPosition.y - thisPosition.y;

    float intersecX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
    float intersecY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

    if(intersecX < 0.0f && intersecY < 0.0f){
        push = std::min(std::max(push, 0.0f),1.0f);
        // push vai receber o menor valor entre 1.0f e max(push, 0.0f) que é o maior valor entre push e zero
        //logo push vai ser um valor entre 0 e 1
        if( intersecX > intersecY){

            if(deltaX>0.0f){
                direction.x =-1.0f;
                direction.y =0.0f;

                parada.move(intersecX* (1.0f- push),0.0f);
                movimentavel.move((-intersecX * push),0.0f);
            }else {
                direction.x =1.0f;
                direction.y =0.0f;

                parada.move(-intersecX* (1.0f-push),0.0f);
                movimentavel.move((intersecX * push),0.0f);
            }
        }else{
            if(deltaY>0.0f){
                direction.x =0.0f;
                direction.y =-1.0f;

                parada.move(0.0f,intersecY* (1.0f-push));
                movimentavel.move(0.0f ,-intersecY *  push);
            }else{
                direction.x =0.0f;
                direction.y =1.0f;

                parada.move(0.0f,-intersecY* ((1.0f-push)));
                movimentavel.move(0.0f,intersecY *  push);

            }
        }
        return true;
    }
    return false;
}

bool Collider::checkCollision(Personagem& parada, Personagem& movimentavel, sf::Vector2f& direction, float push) {
    sf::Vector2f otherPosition = movimentavel.getPosition();
    sf::Vector2f otherHalfSize = movimentavel.getHalfSize();
    sf::Vector2f thisPosition = parada.getPosition();
    sf::Vector2f thisHalfSize = parada.getHalfSize();
    //pegando as informações sobre os cubos de colisão

    float deltaX = otherPosition.x - thisPosition.x;
    float deltaY = otherPosition.y - thisPosition.y;

    float intersecX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
    float intersecY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

    if(intersecX < 0.0f && intersecY < 0.0f){
        push = std::min(std::max(push, 0.0f),1.0f);
        // push vai receber o menor valor entre 1.0f e max(push, 0.0f) que é o maior valor entre push e zero
        //logo push vai ser um valor entre 0 e 1
        if( intersecX > intersecY){

            if(deltaX>0.0f){
                direction.x =-1.0f;
                direction.y =0.0f;

                parada.move(intersecX* (1.0f- push),0.0f);
                movimentavel.move((-intersecX * push),0.0f);
            }else {
                direction.x =1.0f;
                direction.y =0.0f;

                parada.move(-intersecX* (1.0f-push),0.0f);
                movimentavel.move((intersecX * push),0.0f);
            }
        }else{
            if(deltaY>0.0f){
                direction.x =0.0f;
                direction.y =-1.0f;

                parada.move(0.0f,intersecY* (1.0f-push));
                movimentavel.move(0.0f ,-intersecY *  push);
            }else{
                direction.x =0.0f;
                direction.y =1.0f;

                parada.move(0.0f,-intersecY* ((1.0f-push)));
                movimentavel.move(0.0f,intersecY *  push);

            }
        }
        return true;
    }
    return false;
}

bool Collider::checkCollision(Obstaculo& parada, Obstaculo& movimentavel, sf::Vector2f& direction, float push) {
    sf::Vector2f otherPosition = movimentavel.getPosition();
    sf::Vector2f otherHalfSize = movimentavel.getHalfSize();
    sf::Vector2f thisPosition = parada.getPosition();
    sf::Vector2f thisHalfSize = parada.getHalfSize();
    //pegando as informações sobre os cubos de colisão


    float deltaX = otherPosition.x - thisPosition.x;
    float deltaY = otherPosition.y - thisPosition.y;

    float intersecX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
    float intersecY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

    if(intersecX < 0.0f && intersecY < 0.0f){
        push = std::min(std::max(push, 0.0f),1.0f);
        // push vai receber o menor valor entre 1.0f e max(push, 0.0f) que é o maior valor entre push e zero
        //logo push vai ser um valor entre 0 e 1
        if( intersecX > intersecY){

            if(deltaX>0.0f){
                direction.x =-1.0f;
                direction.y =0.0f;

                parada.move(intersecX* (1.0f- push),0.0f);
                movimentavel.move((-intersecX * push),0.0f);
            }else {
                direction.x =1.0f;
                direction.y =0.0f;

                parada.move(-intersecX* (1.0f-push),0.0f);
                movimentavel.move((intersecX * push),0.0f);
            }
        }else{
            if(deltaY>0.0f){
                direction.x =0.0f;
                direction.y =-1.0f;

                parada.move(0.0f,intersecY* (1.0f-push));
                movimentavel.move(0.0f ,-intersecY *  push);
            }else{
                direction.x =0.0f;
                direction.y =1.0f;

                parada.move(0.0f,-intersecY* ((1.0f-push)));
                movimentavel.move(0.0f,intersecY *  push);

            }
        }
        return true;
    }
    return false;
}
