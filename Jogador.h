
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 09/11/19.
//Last Update 09/11 13hrs
#pragma once
//--------------------------------------------------------------------------------------------------------------------//
//Herança de Personagem

//Deriva as Classes:
//Jogador_1
//Jogador_2

//--------------------------------------------------------------------------------------------------------------------//
//Header//
#include "Personagem.h"
#include <iostream>

//--------------------------------------------------------------------------------------------------------------------//
//Classe Jogador//
class Jogador : public Personagem{

protected:
    sf::Keyboard::Key KeyRight;
	sf::Keyboard::Key KeyLeft;
	sf::Keyboard::Key KeyJump;

public:
    Jogador(sf::Vector2f position, sf::Vector2f size, bool active, float speed, float jump_height,
                                 sf::Keyboard::Key right,  sf::Keyboard::Key left, sf::Keyboard::Key jump);
    Jogador();
    virtual ~Jogador();

    void inicializaJogador(sf::Vector2f position, sf::Vector2f size, bool active, float speed, float jump_height,
                                 sf::Keyboard::Key right,  sf::Keyboard::Key left, sf::Keyboard::Key jump);

    void calculaMovimento(const float deltaTempo){ std::cout<<"calculando..."<<std::endl;}


};

