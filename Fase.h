
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 11/11/19.
//Last Update 11/11 12hrs
#pragma once
//--------------------------------------------------------------------------------------------------------------------//
//Herança de Entidade

//Deriva as Classes:
//Fase_A
//Fase_B

//--------------------------------------------------------------------------------------------------------------------//
//Header//
#include "Entidade.h"


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
    FILE* arqFase;

    //listas


public:
    Fase();
    ~Fase();
//--------------------------------------------------------------------------------------------------------------------//
//metodos de inicialização
private:
    virtual void constroiMatriz();
    void inicializaLista();
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

};
