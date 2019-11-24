
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
private:
    friend class GameState;
//atributos//
    static Jogo* _instance;     //instancia
    bool firstUse;
    GameState* pState;
//--------------------------------------------------------------------------------------------------------------------//
// TESTE
    Jogador_1* p1;
    Jogador_2* p2;
    //ListaEntidades* lEntidades;  //Lista Principal de Entidades
    //Fase_A* faseA;
    int pontos;
    //MenuNovoJogo menuPrincipal;
//--------------------------------------------------------------------------------------------------------------------//
//Metodos do State
//TODO: testar

    //considerando que cada função muda de State, não precisaria diretamente de um metodo changeState
    void inicializarState(); //Inicializa com o primeiro State, função para ser chamada fora do loop, basicamente chama
    //changeState com MenuPrincipal.
    void executarState();    //inicia o state novo jogo e a partir dele, chama state fase
    void pausarState();      //chamado a partir de fase, e retorna a fase
    //void changeState(GameState* pState);

//--------------------------------------------------------------------------------------------------------------------//
    //gerenciadores//
    GerenciadorGrafico* g;
    float deltaTime;
    Menu menu;

    //TODO teste
    bool podeDarUpdate;
    Fase_A* faseA;
    int menuOp;
    bool pause;
    bool player2;


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
    void update(float deltaTime, float elapsed);
    void draw();
    //Metodos de Menu//
    void criaFase1player1();
    void criaFase1player2();
    void criaFase2player1();
    void criaFase2player2();
};

