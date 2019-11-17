
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 11/11/19.
//Last Update 11/11 12hrs
#pragma once
//--------------------------------------------------------------------------------------------------------------------//
//Herança de Entidade

//Deriva as Classes:
//Projetil_Tipo_1
//Projetil_Tipo_2

//--------------------------------------------------------------------------------------------------------------------//
//Header//
#include "Entidade.h"

//--------------------------------------------------------------------------------------------------------------------//
//Classe Projetil//
class Projetil : Entidade {

protected:
    sf::RectangleShape body;
    sf::Vector2f vel;
    float speed;

private:

public:
    Projetil(sf::Vector2f position, sf::Vector2f size, bool active, float speed);
    Projetil();
    ~Projetil();
    void inicializaProjetil(sf::Vector2f position, sf::Vector2f size, bool active, float speed);
    void update(const float deltaTime);
    void draw();
    virtual void calculaMovimento() = 0;


};

