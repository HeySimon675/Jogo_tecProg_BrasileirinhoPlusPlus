
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



#include "Inimigo_B.h"
#include "Obstaculo.h"  //remover assim que possivel

//#include "Obstaculo_Plataforma"


//--------------------------------------------------------------------------------------------------------------------//
//Classe Fase//
class Fase : public Entidade {
protected:
    //Matriz de construção da fase
    char** matrizFase;
    int ROW;
    int COL;

//--------------------------------------------------------------------------------------------------------------------//
    //Arquivo
    std::ifstream* arqFase;

    //lista
    ListaEntidades* listaEntidades;

    //Jogadores
    Jogador_1* pJ1;
    Jogador_2* pJ2;

public:
    Fase(ListaEntidades* lista = nullptr, Jogador_1* jogador1 = nullptr, Jogador_2* jogador2 = nullptr);
    ~Fase();
//--------------------------------------------------------------------------------------------------------------------//
//metodos de inicialização
protected:
//--------------------------------------------------------------------------------------------------------------------//
//Criando Entidades
    virtual void criaEntidade(char aux, Vector2f pos);
    void criaPlataforma();
    void posicionaJogador(Vector2f pos);

    void destroiMatriz();
    virtual void constroiMatriz();
    void printaMatriz();
    void carregaInimigo();
    void carregaObstaculo();
public:
    virtual void inicializa();  //deve ditar a prioridade de cada entidade que vai ser desenhada

    //implementação de update, onde vai percorrer as listas verificando colisão

//--------------------------------------------------------------------------------------------------------------------//
//Constantes//
protected:
    static const String FASES_DIR;
    //static const String SYSTEM_PREFIX;
    static const int FASE_HEIGHT;
    static const int FASE_WIDTH;

};
