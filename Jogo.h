
//--------------------------------------------------------------------------------------------------------------------//
//Implementado por:
    //Simão     - 80%
    //Coradassi - 20%
#pragma once

//--------------------------------------------------------------------------------------------------------------------//
//Header//
#include "GerenciadorGrafico.h"
#include "ListaEntidades.h"
#include "Personagem.h" //teste
#include "Jogador_1.h"
#include <cmath>   //temporario
#include "GerenciadorDeColisoes.h"
#include "Fase_A.h" //teste
#include "Inimigo_B.h"
#include "Inimigo_A.h"
#include "GameState.h"
#include "Menu.h"

//--------------------------------------------------------------------------------------------------------------------//
//Classe Jogo//

class Jogo {
//--------------------------------------------------------------------------------------------------------------------//
private:
//ATRIBUTOS//
    static Jogo* _instance;     //instancia
    int pontos;
    float deltaTime;
//Menu
    bool firstUse;
    bool podeDarUpdate;
    int menuOp;
    bool pause;
    bool player2;
//Jogadores
    Jogador_1* p1;
    Jogador_2* p2;
//Fases
    Fase_A* faseA;

//gerenciadores//
    GerenciadorGrafico* g;
    Menu menu;

//--------------------------------------------------------------------------------------------------------------------//
//METODOS//
private:
    Jogo();
    void inicializa();
    void executarMenu();
    //Metodos de Menu//
    void criaFase1player1();
    void criaFase1player2();
    void criaFase2player1();
    void criaFase2player2();
public:
    static Jogo* getJogo(); //singleton
    ~Jogo();
    void executar();
};

