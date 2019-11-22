
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 11/11/19.
//Implementado por:
    //Coradassi - 80%
    //Simão -   20%

#pragma once
//--------------------------------------------------------------------------------------------------------------------//
//Herança de Inimigo

//--------------------------------------------------------------------------------------------------------------------//
//Header//
#include "Inimigo.h"

//--------------------------------------------------------------------------------------------------------------------//
//Classe Inimigo_A//
class Inimigo_A : public Inimigo{

public:
    Inimigo_A(Vector2f position = POSICAO_PADRAO, Vector2f size = TAMANHO_PADRAO, float speed = VELOCIDADE_PADRAO);
    ~Inimigo_A();

    void inicializar(Vector2f position);
    void calculaMovimento(const float deltaTime);
    void draw();
    const int getID(){return id;}

private:
    static const int id;
    float position_X_inicial;
    bool goingLeft;
    float delta_X;

};

