
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

void Fase_A::constroiMatriz() {

}


void Fase_A::inicializa() {
    char* charFaseFile = new char[FASE_FILE.getSize()];
    std::copy(FASE_FILE.begin(),FASE_FILE.end(),charFaseFile);
    charFaseFile[FASE_FILE.getSize()]  = '\0';
    arqFase = fopen(charFaseFile,"rt");
    if(!arqFase){
        printf("Arquivo %s não foi aberto \n",charFaseFile);


    }
    constroiMatriz();

}

//--------------------------------------------------------------------------------------------------------------------//
//Constantes//

const String Fase_A::FASE_FILE = "../" + FASES_DIR + "FaseTest.txt";


