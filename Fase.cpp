
//--------------------------------------------------------------------------------------------------------------------//
// Created by simao on 11/11/2019.

#include "Fase.h"


//--------------------------------------------------------------------------------------------------------------------//
/*PREFIXO DO SISTEMA//
    "../"      -> LINUX
    ""         -> WINDOWS
*/
//const String GerenciadorGrafico::SYSTEM_PREFIX = "../";


//--------------------------------------------------------------------------------------------------------------------//
//Constantes//

const String Fase::FASES_DIR = "Fases/";
const int Fase::FASE_HEIGHT = 10;
const int Fase::FASE_WIDTH = 10;

Fase::Fase(ListaEntidades* lista) : Entidade() {
    listaEntidades = lista;
}

Fase::~Fase() {

}

//função para printar a matriz, podendo assim verificar a integridade da matriz
void Fase::printaMatriz() {
    for(ROW = 0; ROW < FASE_HEIGHT; ROW++){
        for (COL = 0; COL < FASE_WIDTH; COL++) {
            printf("%c ",matrizFase[ROW][COL]);
        }
        printf("\n");
    }
}

void Fase::constroiMatriz() {
    char aux;
    matrizFase = new char*[FASE_HEIGHT];
    for (int row = 0; row < FASE_WIDTH; row++){
        matrizFase[row] = new char[FASE_WIDTH];
    }
    ROW = 0;
    COL = 0;
    (*arqFase) >> aux;
    while (!(*arqFase).eof()){
        matrizFase[ROW][COL] = aux;
        criaEntidade(aux);
        (*arqFase) >> aux;
        if (COL == FASE_WIDTH-1){
            ROW++;
            COL = 0;
        } else{
            COL++;
        }
    }

}

void Fase::criaEntidade(char aux) {}

void Fase::carregaInimigo() {

}

void Fase::carregaObstaculo() {

}

void Fase::inicializa() {}
