
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 11/11/19.
//Last Update 11/11 12hrs
#pragma once
//--------------------------------------------------------------------------------------------------------------------//
//Herança de Jogador


//--------------------------------------------------------------------------------------------------------------------//
//Header//
#include "Jogador.h"

//--------------------------------------------------------------------------------------------------------------------//
//Classe Jogador//
class Jogador_1 : public Jogador{

//--------------------------------------------------------------------------------------------------------------------//
//construção
private:
    static const String ID;
public:
    Jogador_1(Vector2f position, Vector2f size, bool active, float speed, float jump_height, Keyboard::Key right,
                                    Keyboard::Key left, Keyboard::Key jump);

    void inicializaJogador_1(Vector2f position, Vector2f size, bool active, float speed, float jump_height,
                             Keyboard::Key right, Keyboard::Key left, Keyboard::Key jump);
    Jogador_1();
    ~Jogador_1();

    const String getID();

//--------------------------------------------------------------------------------------------------------------------//
//movimento
public:
    void calculaMovimento(const float deltaTempo);

};
