
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 27/10/19.
#pragma once
//--------------------------------------------------------------------------------------------------------------------//
//Header//
#include "GerenciadorGrafico.h"

//--------------------------------------------------------------------------------------------------------------------//
//Namespace's
using namespace sf;

//--------------------------------------------------------------------------------------------------------------------//
//Classe Entidade//

class Entidade {
protected:
    Vector2f posicao;
    bool _active;
    static GerenciadorGrafico* gerenciadorGrafico;
    virtual const String getID();

public:
    Entidade(float posX = 0.0f, float posY = 0.0f, bool active = false);
    Entidade(Vector2f posicao);

//--------------------------------------------------------------------------------------------------------------------//
//NECESSARIO??
    //Entidade(sf::Vector2f position, sf::Vector2f size, float speed, float jump_height, sf::Keyboard::Key right,
    //                                sf::Keyboard::Key left, sf::Keyboard::Key jump);

//--------------------------------------------------------------------------------------------------------------------//
    virtual ~Entidade();
    void ativarEntidade();
    void desativarEntidade();
    void inicializaEntidade(sf::Vector2f position, sf::Vector2f size, bool active);

//Metodos de loop//
    virtual void update();
    virtual void draw();
};
