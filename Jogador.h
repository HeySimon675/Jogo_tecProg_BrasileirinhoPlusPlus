
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 09/11/19.
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
    //TODO: Metodo Precisa ser alterado para seja menos dependente de paramentros.
    Jogador(Vector2f position = POSICAO_PADRAO);
    virtual ~Jogador();

    //void inicializaJogador(Vector2f position);



};

