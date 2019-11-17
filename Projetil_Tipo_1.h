
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 11/11/19.
//Last Update 11/11 12hrs
#pragma once
//--------------------------------------------------------------------------------------------------------------------//
//Herança de Projetil


//--------------------------------------------------------------------------------------------------------------------//
//Header//
#include "Projetil.h"

//--------------------------------------------------------------------------------------------------------------------//
//Classe Projetil 1//
class Projetil_Tipo_1 : public Projetil {

private:
    float posicao_X_inicial;
    bool dead;

public:
    Projetil_Tipo_1(sf::Vector2f position, sf::Vector2f size, bool active, float speed);
    Projetil_Tipo_1();
    ~Projetil_Tipo_1();

    void inicializaProjetilTipo1(sf::Vector2f position, sf::Vector2f size, bool active, float speed);
    void calculaMovimento();
    bool getDead() {return dead;}
};

