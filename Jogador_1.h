
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 11/11/19.
//Implementado por:
    //Coradassi - 90%
    //Simão 10%

#pragma once
//--------------------------------------------------------------------------------------------------------------------//
//Herança de Jogador


//--------------------------------------------------------------------------------------------------------------------//
//Header//
#include "Jogador.h"

#include <iostream>
#include <math.h>

//--------------------------------------------------------------------------------------------------------------------//
//Classe Jogador//
class Jogador_1 : public Jogador{

//--------------------------------------------------------------------------------------------------------------------//
//construção
private:
    //constante
    static const int id;
public:
    Jogador_1(Vector2f position = POSICAO_PADRAO);

    void inicializar(Vector2f position);
    ~Jogador_1();

    const int getID();

//--------------------------------------------------------------------------------------------------------------------//
//movimento
public:
    void calculaMovimento(const float deltaTempo);

};
