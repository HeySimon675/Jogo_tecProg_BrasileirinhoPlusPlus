
//--------------------------------------------------------------------------------------------------------------------//
// Created by simao on 27/05/19.
// Update 27/05

#include "Collider.h"

Collider::Collider(sf::RectangleShape* body):
body(*body)
{

}

Collider::~Collider() {

}

bool Collider::checkCollision(Collider* other,sf::Vector2f& direction, float push) {
    sf::Vector2f otherPosition = other->getPosition();
    sf::Vector2f otherHalfSize = other->getHalfSize();
    sf::Vector2f thisPosition = getPosition();
    sf::Vector2f thisHalfSize = getHalfSize();
    //pegando as informações sobre os cubos de colisão

    float deltaX = otherPosition.x - thisPosition.x ;
    float deltaY =  otherPosition.y - thisPosition.y;
    //pegando as distancias entre os objetos

    float intersecX = (deltaX>0)? deltaX - (otherHalfSize.x + thisHalfSize.x) : -deltaX - (otherHalfSize.x + thisHalfSize.x);
    float intersecY = (deltaY>0)? deltaY - (otherHalfSize.y + thisHalfSize.y) : -deltaY - (otherHalfSize.y + thisHalfSize.y);

    if(intersecX < 0.0f && intersecY < 0.0f){
        push = std::min(std::max(push, 0.0f),1.0f);
        // push vai receber o menor valor entre 1.0f e max(push, 0.0f) que é o maior valor entre push e zero
        //logo push vai ser um valor entre 0 e 1
        if( intersecX > intersecY){

            if(deltaX>0.0f){
                direction.x =1.0f;
                direction.y =0.0f;

                move(intersecX* (1.0f- push),0.0f);
                other->move(-intersecX * (1.0f - push),0.0f);
            }else {
                direction.x =-1.0f;
                direction.y =0.0f;

                move(-intersecX* (1.0f-push),0.0f);
                other->move(intersecX * (1.0f - push),0.0f);
            }
        }else{
            if(deltaY>0.0f){
                direction.x =0.0f;
                direction.y =1.0f;

                move(0.0f,intersecY* (1.0f-push));
                other->move(0.0f,-intersecY * (1.0f - push));
            }else{
                direction.x =0.0f;
                direction.y =-1.0f;

                move(0.0f,-intersecY* ((1.0f-push)));
                other->move(0.0f,intersecY * (1.0f - push));

                }
            }
        return true;
    }
    return false;
}
