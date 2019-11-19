
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 27/10/19.
#pragma once

//--------------------------------------------------------------------------------------------------------------------//
//Header//
#include "GerenciadorGrafico.h"
#include "ListaEntidades.h"
#include "Personagem.h" //teste
#include "Jogador_1.h"
#include <cmath>   //temporario
#include "Collider.h"//temporario
#include "Fase_A.h" //teste
#include "Inimigo_B.h"
#include "Inimigo_A.h"


//--------------------------------------------------------------------------------------------------------------------//
//Classe Jogo//

class Jogo {
private:
//atributos//
    static Jogo* _instance;     //instancia
    ListaEntidades* lEntidades;  //Lista Principal de Entidades

//--------------------------------------------------------------------------------------------------------------------//
// TESTE
    //Jogador_1 p1;
    //Inimigo_A inimigoA;
    //Inimigo_B inimigoB;
    //Projetil_Tipo_1 projetil;
    //Obstaculo plataforma;
    Fase_A* faseA;
//--------------------------------------------------------------------------------------------------------------------//


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

