
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 11/11/19.
//Last Update 11/11 12hrs
#pragma once
#include <iostream>
//--------------------------------------------------------------------------------------------------------------------//
//Herança de Personagem

//Deriva as Classes:
    //Inimigo_A
    //Inimigo_B
    //Inimigo_Boss


//--------------------------------------------------------------------------------------------------------------------//
//Header//
#include "Personagem.h"

//--------------------------------------------------------------------------------------------------------------------//
//Classe Inimigo//
class Inimigo : public Personagem{

protected:

private:

public:
    Inimigo(sf::Vector2f position, sf::Vector2f size, bool active, float speed, float jump_height);
    Inimigo();
    ~Inimigo();

    void inicializaInimigo(sf::Vector2f position, sf::Vector2f size, bool active, float speed, float jump_height);
    void calculaMovimento(const float deltaTempo){
        //std::cout<<"calculando..."<<std::endl;
    }


};

