
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 11/11/19.
//Last Update 11/11 12hrs
#pragma once
//--------------------------------------------------------------------------------------------------------------------//
//Herança de Inimigo

//--------------------------------------------------------------------------------------------------------------------//
//Header//
#include "Inimigo.h"
#include "Projetil_Tipo_1.h"

//--------------------------------------------------------------------------------------------------------------------//
//Classe Inimigo_B//
class Inimigo_B : public Inimigo{

private:
    Projetil_Tipo_1* pt1;
    bool projetilCriado;

public:
    Inimigo_B(sf::Vector2f position, sf::Vector2f size, bool active, float speed, float jump_height);
    Inimigo_B();
    ~Inimigo_B();

    void inicializaInimigo_B(sf::Vector2f position, sf::Vector2f size, bool active, float speed, float jump_height);
    void calculaMovimento(const float deltaTime);

};
