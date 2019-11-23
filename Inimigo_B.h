
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 11/11/19.
//Implementado por:
    //Coradassi - 90%
    //Simao - 10%
#pragma once
//--------------------------------------------------------------------------------------------------------------------//
//Herança de Inimigo

//--------------------------------------------------------------------------------------------------------------------//
//Header//
#include "Inimigo.h"
#include "Projetil.h"

//--------------------------------------------------------------------------------------------------------------------//
//Classe Inimigo_B//
class Inimigo_B : public Inimigo{

private:
    Projetil* projetil;
    bool projetilCriado;
    bool passou10segundos;
    static const int id;

public:
    static sf::Clock clock;

public:
    Inimigo_B(Vector2f position = POSICAO_PADRAO, Vector2f size = TAMANHO_PADRAO, float speed = VELOCIDADE_PADRAO);
    ~Inimigo_B();

    void inicializar(Vector2f position, Projetil* projetil);
    void calculaMovimento(const float deltaTime);
    bool getPassou10Segundos() {return passou10segundos;}
    void setPassou10Segundos(bool pds){passou10segundos = pds; }
    void setProjetil(Projetil* projetil) {this->projetil = projetil; projetilCriado = true;}

};
