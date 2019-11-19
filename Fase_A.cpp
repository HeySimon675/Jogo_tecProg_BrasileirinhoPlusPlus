
//--------------------------------------------------------------------------------------------------------------------//
// Created by simao on 11/11/2019.

#include "Fase_A.h"
#include <iostream>
#include <string>
#include <cstring>





//--------------------------------------------------------------------------------------------------------------------//
//Construção
Fase_A::Fase_A(ListaEntidades* lista) : Fase(lista) {
    inicializa();
}

Fase_A::~Fase_A() {

}
//--------------------------------------------------------------------------------------------------------------------//



void Fase_A::criaJogador(){
    Jogador_1 *j1;
    j1 = new Jogador_1();
    j1->inicializaJogador_1(Vector2f(0.0f, 0.0f), Vector2f(100.0f, 100.0f),true,
                            100.0f, 50.0f,Keyboard::Right, Keyboard::Left, Keyboard::Up);
    listaEntidades->incluir((static_cast<Entidade*>(j1)));

}

void Fase_A::criaInimigoA() {
    Inimigo_A *nA;
    nA = new Inimigo_A();
    nA->inicializaInimigo_A(Vector2f(10.0f,10.0f),Vector2f(50,50), true,100.0f,50.0f);
    listaEntidades->incluir(static_cast<Entidade*>(nA));
}

void Fase_A::criaEntidade(char aux) {

    switch (aux){
        //Alterar ja que fases não iram criar Jogadores
        case '1' :
            //case somente para teste de construção
            criaJogador();
            break;
        case 'A':   //Inimigo_A
            criaInimigoA();
        default:
            break;
    }
}

void Fase_A::inicializa()  {
    char* charFaseFile = new char[FASE_FILE.getSize()];
    std::copy(FASE_FILE.begin(),FASE_FILE.end(),charFaseFile);
    charFaseFile[FASE_FILE.getSize()]  = '\0';
    arqFase = new std::ifstream(charFaseFile,std::ios::in);
    //arqFase = fopen(charFaseFile,"rt");
    if(!(*arqFase)){
        printf("Arquivo %s não foi aberto \n",charFaseFile);
    }

    constroiMatriz();
    printaMatriz();
}

//--------------------------------------------------------------------------------------------------------------------//
//Constantes//

const String Fase_A::FASE_FILE = "../" + FASES_DIR + "FaseTest.txt";
const int Fase_A::FASE_WIDTH = 10;
const int Fase_A::FASE_HEIGHT = 10;

