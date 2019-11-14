
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 27/10/19.
#pragma once

//--------------------------------------------------------------------------------------------------------------------//
//Header//
#include "GerenciadorGrafico.h"
#include "ListaEntidades.h"
#include "Personagem.h"
#include "Jogador_1.h"


//--------------------------------------------------------------------------------------------------------------------//
//Classe Jogo//

class Jogo {
private:
//atributos//
    static Jogo* _instance;     //instancia
    ListaEntidades lEntidades;  //Lista Principal de Entidades
    Jogador_1 p1;

    //gerenciadores//
    GerenciadorGrafico* g;



    //delta//
    float deltaTime;
    //Players

//metodos//
    //construtora privada//
    Jogo();

    //inicializadores//
    void inicializa();
public:
//metodos//
    //singleton//
    static Jogo* getJogo();
    //destrutora//
    ~Jogo();

    //metodos principais//
    void executar();
    void update(float deltaTime);
    void draw();
};

