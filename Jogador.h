
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 09/11/19.
//Implementado por:
    //Coradassi - 75%
    //Simão - 25%

#pragma once
//--------------------------------------------------------------------------------------------------------------------//
//Herança de Personagem

//Deriva as Classes:
//Jogador_1
//Jogador_2

//--------------------------------------------------------------------------------------------------------------------//
//Header//
#include "Personagem.h"

//--------------------------------------------------------------------------------------------------------------------//
//Classe Jogador//
class Jogador : public Personagem{

protected:
    Keyboard::Key KeyRight;
	Keyboard::Key KeyLeft;
	Keyboard::Key KeyJump;

public:
    Jogador(Vector2f position = POSICAO_PADRAO, float speed = VELOCIDADE_PADRAO * 1);
    virtual ~Jogador();

};

