
//--------------------------------------------------------------------------------------------------------------------//
// Created by simao on 11/11/2019.

#include "Fase_A.h"
#include <iostream>
#include <string>
#include <cstring>



//--------------------------------------------------------------------------------------------------------------------//
//Construção
Fase_A::Fase_A() : Fase() {
    inicializa();
}

Fase_A::~Fase_A() {

}

//função para printar a matriz, podendo assim verificar a
void Fase_A::printaMatriz() {
    for(ROW = 0; ROW < FASE_HEIGHT; ROW++){
        for (COL = 0; COL < FASE_WIDTH; COL++) {
            printf("%c ",matrizFase[ROW][COL]);
        }
        printf("\n");
    }
}

void Fase_A::constroiMatriz() {
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
        (*arqFase) >> aux;
        if (COL == FASE_WIDTH-1){
            ROW++;
            COL = 0;
        } else{
            COL++;
        }
    }

    /*
    char aux;
    matrizFase = new char*[FASE_HEIGHT];
    for (int row = 0; row < FASE_WIDTH; row++){
        matrizFase[row] = new char[FASE_WIDTH];
    }
    fscanf(arqFase,"%c",&aux);
    ROW = 0;
    COL = 0;
    while (aux != EOF){
        matrizFase[ROW][COL] = aux;
        fscanf(arqFase,"%c ",&aux);
        if (aux == '\n'){
            ROW++;
            COL = 0;
        } else{
            COL++;
        }
    }
    */
}


void Fase_A::inicializa() {
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

