
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
    bool _active;
    static GerenciadorGrafico* gerenciadorGrafico;

public:
    Entidade(float posX = 0.0f, float posY = 0.0f, bool active = false);
    Entidade(Vector2f posicao);
    ~Entidade();
    void ativarEntidade();
    void desativarEntidade();

//Metodos de loop//
    virtual void update();
    virtual void draw();
};
