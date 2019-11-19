
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 11/11/19.
//Last Update 11/11 12hrs
#pragma once
//--------------------------------------------------------------------------------------------------------------------//
//Herança de Fase_A

//--------------------------------------------------------------------------------------------------------------------//
//Header//
#include <stdio.h>
#include "Fase.h"

//--------------------------------------------------------------------------------------------------------------------//
//ENTIDADES QUE A FASE CONNHECE
//todo fases não criam nem agregam o(s) jogador(es) foi incluido somente para testar a construção da fase, remover
// assim que a fase estiver criando Inimigos e Obstaculos
#include "Jogador_1.h"

#include "Inimigo_A.h"


//--------------------------------------------------------------------------------------------------------------------//
//Classe Fase_A//
class Fase_A : public Fase{

//--------------------------------------------------------------------------------------------------------------------//
//construção
private:

//--------------------------------------------------------------------------------------------------------------------//
//Criação de Entidades
    void criaJogador(); //teste
    void criaEntidade(char aux);
    void criaInimigoA();


    //para teste//

public:
    Fase_A(ListaEntidades* lista = nullptr);
    ~Fase_A();
    void inicializa();
//--------------------------------------------------------------------------------------------------------------------//
//variaveis para fase


//--------------------------------------------------------------------------------------------------------------------//
//Constantes
private:
    static const String FASE_FILE;
    //static const char* charFaseFile;
    static const int FASE_WIDTH;
    static const int FASE_HEIGHT;
};
