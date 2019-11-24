
//--------------------------------------------------------------------------------------------------------------------//
//Implementado por:
    //coradassi - 100%
#pragma once
//--------------------------------------------------------------------------------------------------------------------//
//Herança de Jogador

//--------------------------------------------------------------------------------------------------------------------//
//Header//
#include "Jogador.h"

//--------------------------------------------------------------------------------------------------------------------//
//Classe Jogador//
class Jogador_2 : public Jogador{
public:
    ~Jogador_2();
    Jogador_2(Vector2f position = POSICAO_PADRAO);
    void inicializar(Vector2f position);
    void calculaMovimento(const float deltaTempo);
private:
    static const int id;
    const int getID(){return id;}
};
