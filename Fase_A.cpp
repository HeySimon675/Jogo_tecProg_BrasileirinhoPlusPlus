
//--------------------------------------------------------------------------------------------------------------------//
// Created by simao on 11/11/2019.

#include "Fase_A.h"
#include <iostream>
#include <string>
#include <cstring>





//--------------------------------------------------------------------------------------------------------------------//
//Construção
Fase_A::Fase_A(ListaEntidades* lista, Jogador_1* jogador1, Jogador_2* jogador2) : Fase(lista, jogador1, jogador2) {
    inicializa();
}

Fase_A::~Fase_A() {

}
//--------------------------------------------------------------------------------------------------------------------//





void Fase_A::criaInimigoA(Vector2f pos) {
    Inimigo_A *nA;
    nA = new Inimigo_A();
    nA->inicializaInimigo_A(pos);
    listaEntidades->incluir(static_cast<Entidade*>(nA));
}

void Fase_A::criaEntidade(char aux, Vector2f pos) {

    switch (aux){
        //Alterar ja que fases não iram criar Jogadores
        case 'J' :
            //modificar nome da função, pois a função posiciona o jogador
            posicionaJogador(pos);
            break;
        case 'A':   //Inimigo_A
            criaInimigoA(pos);
            break;
        case 'P':
            criaPlataforma();
            break;
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

