
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

private:

public:

    Jogador_1(sf::Vector2f position, sf::Vector2f size, bool active, float speed, float jump_height, sf::Keyboard::Key right,
                                    sf::Keyboard::Key left, sf::Keyboard::Key jump);
    Jogador_1();
    ~Jogador_1();
    void inicializaJogador_1(sf::Vector2f position, sf::Vector2f size, bool active, float speed, float jump_height, sf::Keyboard::Key right,
                                    sf::Keyboard::Key left, sf::Keyboard::Key jump);
    void calculaMovimento(const float deltaTempo);

};
