
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 11/11/19.
//Implementado por:
    //Coradassi - 60%
    //Simão -   40%
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

public:
    Inimigo(Vector2f position = POSICAO_PADRAO, Vector2f size = TAMANHO_PADRAO, float speed = VELOCIDADE_PADRAO);

    ~Inimigo();


};

