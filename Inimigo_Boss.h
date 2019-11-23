
//--------------------------------------------------------------------------------------------------------------------//
//Implementado por:
//Coradassi - 90%
//Simao     - 10%

#pragma once
//--------------------------------------------------------------------------------------------------------------------//
//Herança de Inimigo

//--------------------------------------------------------------------------------------------------------------------//
//Header//
#include "Inimigo.h"
#include "Projetil.h"

//--------------------------------------------------------------------------------------------------------------------//
//Classe Inimigo_Boss//
class Inimigo_Boss : public Inimigo{
public:
    Inimigo_Boss(Vector2f position = POSICAO_PADRAO, Vector2f size = TAMANHO_PADRAO,  float speed = VELOCIDADE_PADRAO);
    ~Inimigo_Boss();

    void inicializarBoss(Vector2f position);
    void calculaMovimento(const float deltaTime);
    void setProjetil(Projetil* projetil){this->projetil = projetil;}

private:
    Projetil* projetil;
    float position_X_inicial;
    bool goingLeft;
    bool canMove;
    float delta_X;
    bool projetilCriado;
    static const int id;
};
