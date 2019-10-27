
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 27/10/19.
#pragma once

//--------------------------------------------------------------------------------------------------------------------//
//Header//
#include "GerenciadorGrafico.h"


//--------------------------------------------------------------------------------------------------------------------//
//Classe Jogo//

class Jogo {
private:
    //instancia//
    static Jogo* _instance;
    //gerenciadores//
    GerenciadorGrafico* g;

    //delta//
    float deltaTime;
    //Players

    //construtora privada//
    Jogo();

    //inicializadores//
    void inicializa();
public:
    //singleton//
    static Jogo* getJogo();
    //destrutora//
    ~Jogo();

    //metodos principais//
    void executar();
    void update();
    void draw();
};

