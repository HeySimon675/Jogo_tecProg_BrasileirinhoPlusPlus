
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 11/11/19.

#pragma once
//--------------------------------------------------------------------------------------------------------------------//
//Herança de Entidade

//Deriva as Classes:
//Fase_A
//Fase_B

//--------------------------------------------------------------------------------------------------------------------//
//Header//
#include "Entidade.h"
#include "ListaEntidades.h"
#include "Jogador_1.h"
#include "Jogador_2.h"
#include <fstream>
#include "time.h"

#include <iostream>
#include <string>   //testar remover string
#include <cstring>

#include "GerenciadorDeColisoes.h"

#include "Inimigo_B.h"
#include "Projetil.h"
#include "Obstaculo_Espinho.h"
#include "Obstaculo_Plataforma.h"


//--------------------------------------------------------------------------------------------------------------------//
//Classe Fase//
class Fase : public Entidade {
protected:
    //Matriz de construção da fase
    char** matrizFase;
    int ROW;
    int COL;
    GerenciadorDeColisoes gerenciadorDeColisoes;
    Vector2f posicaoPlayer;
    int numInimigos;
    int numEspinhos;
    int numCaixas;
    RectangleShape background;
    float finalPosition;

//--------------------------------------------------------------------------------------------------------------------//
    //Arquivo
    std::ifstream* arqFase;

    //lista
    ListaEntidades listaEntidades;

    //Jogadores
    Jogador_1* pJ1;
    Jogador_2* pJ2;

public:
    Fase(Jogador_1* jogador1 = nullptr, Jogador_2* jogador2 = nullptr);
    ~Fase();
protected:
//--------------------------------------------------------------------------------------------------------------------//
//Criando Entidades
    virtual void criaEntidade(char aux, Vector2f pos);

    void criaPlataforma(Vector2f pos);
    void criaEspinho(Vector2f pos);
    void criaProjetil_InimigoB(Vector2f pos);
    void criaInimigoB(Vector2f pos, Projetil* projetil);

//Armazena a posição do Player, que será posicionado quando receceber os ponteiros
    void armazenaPosicao(Vector2f position){posicaoPlayer = position;}
    void posicionaJogador(Vector2f pos);

//Matriz da fase
    virtual void constroiMatriz();
    void destroiMatriz();
    void printaMatriz();

//Randomiza numero de Obstaculos e Inimigos
    void randomizaEntidades();

//Verificador se a Fase Acabou
    bool checkFim();
    virtual void setFinalPosition(){}
//--------------------------------------------------------------------------------------------------------------------//
//metodos de inicialização
public:
    virtual void inicializa();  //deve ditar a prioridade de cada entidade que vai ser desenhada
    void draw(){gerenciadorGrafico->draw(background);}
    void update(float deltaTime);
    void setJogadores(Jogador_1* jogador1 = nullptr, Jogador_2* jogador2 = nullptr);
    //implementação de update, onde vai percorrer as listas verificando colisão

//--------------------------------------------------------------------------------------------------------------------//
//Constantes//
protected:
    static const String FASES_DIR;
    static const String SYSTEM_PREFIX;
    static const int FASE_HEIGHT;
    static const int FASE_WIDTH;

};
