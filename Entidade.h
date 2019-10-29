
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
private:
    Vector2f posicao;
    static const GerenciadorGrafico* gerenciadorGrafico;


public:
    Entidade(float posX = 0.0f, float posY = 0.0f);
    Entidade(Vector2f posicao);
    ~Entidade();

//Metodos de loop//
    virtual void update();
    virtual void draw();
};
