
//--------------------------------------------------------------------------------------------------------------------//
//Implementado por:
    //Coradassi - 65%
    //Simão -   35%
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
#include "Projetil.h"

//--------------------------------------------------------------------------------------------------------------------//
//Classe Inimigo//
class Inimigo : public Personagem{

protected:
    //Para desativar o projetil
    bool inimigoB;
public:
    Inimigo(Vector2f position = POSICAO_PADRAO, Vector2f size = TAMANHO_PADRAO, float speed = VELOCIDADE_PADRAO);
    virtual Projetil* getProjetil() {}
    bool getInimigoB(){return inimigoB;}
    ~Inimigo();


};

