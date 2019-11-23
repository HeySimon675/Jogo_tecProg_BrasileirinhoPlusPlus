
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
#include "GerenciadorDeColisoes.h"
#include "Fase_A.h" //teste
#include "Inimigo_B.h"
#include "Inimigo_A.h"
#include "GameState.h"
#include "MenuPrincipal.h"
#include "MenuPause.h"
#include "MenuNovoJogo.h"


//--------------------------------------------------------------------------------------------------------------------//
//Classe Jogo//

class Jogo {
private:
    friend class GameState;
//atributos//
    static Jogo* _instance;     //instancia

    GameState* pState;
//--------------------------------------------------------------------------------------------------------------------//
// TESTE
    Jogador_1* p1;
    ListaEntidades* lEntidades;  //Lista Principal de Entidades
    //Inimigo_A inimigoA;
    //Inimigo_B inimigoB;
    //Projetil_Tipo_1 projetil;
    //Obstaculo plataforma;
    //Fase_A* faseA;
    int pontos;
    MenuNovoJogo menuPrincipal;
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

    //TODO teste
    bool podeDarUpdate;
    GerenciadorDeColisoes collider;
    Inimigo_A* inimigoA;
    Inimigo_B* inimigoB;
    Projetil* projetil;
    Projetil* projetilBoss;
    Obstaculo_Plataforma* plataforma;
    Obstaculo_Movel* caixa;
    Obstaculo_Espinho* espinho;
    Fase_A* faseA;



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
};

