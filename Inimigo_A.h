
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 11/11/19.
//Last Update 11/11 12hrs
#pragma once
//--------------------------------------------------------------------------------------------------------------------//
//Herança de Inimigo

//--------------------------------------------------------------------------------------------------------------------//
//Header//
#include "Inimigo.h"

//--------------------------------------------------------------------------------------------------------------------//
//Classe Inimigo_A//
class Inimigo_A : public Inimigo{

public:
    Inimigo_A(sf::Vector2f position, sf::Vector2f size, bool active, float speed, float jump_height);
    Inimigo_A();
    ~Inimigo_A();

    void inicializaInimigo_A(sf::Vector2f position, sf::Vector2f size, bool active, float speed, float jump_height);
    void calculaMovimento(const float deltaTime);
    void draw();

private:
    float position_X_inicial;
    bool goingLeft;
    float delta_X;

};

