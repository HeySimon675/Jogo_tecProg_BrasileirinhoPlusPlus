
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
#include "ListaInimigos.h"
#include "ListaObstaculos.h"
#include <fstream>

#include "Inimigo_B.h"
#include "Obstaculo.h"

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

    //listas
    ListaEntidades* listaEntidades;
    ListaInimigos listaInimigos;
    ListaObstaculos listaObstaculos;

public:
    Fase(ListaEntidades* lista = nullptr);
    ~Fase();
//--------------------------------------------------------------------------------------------------------------------//
//metodos de inicialização
protected:
//--------------------------------------------------------------------------------------------------------------------//
//Criando Entidades
    virtual void criaEntidade(char aux, Vector2f pos);
    void criaPlataforma();


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
