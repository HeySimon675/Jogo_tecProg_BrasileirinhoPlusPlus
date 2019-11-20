
//--------------------------------------------------------------------------------------------------------------------//
// Created by simao on 11/11/2019.

#include "Fase.h"


//--------------------------------------------------------------------------------------------------------------------//
/*PREFIXO DO SISTEMA//
    "../"      -> LINUX
    ""         -> WINDOWS
*/
//const String Fase::SYSTEM_PREFIX = "../";


//--------------------------------------------------------------------------------------------------------------------//
//Constantes//

const String Fase::FASES_DIR = "Fases/";
const int Fase::FASE_HEIGHT = 10;
const int Fase::FASE_WIDTH = 10;

Fase::Fase(ListaEntidades* lista, Jogador_1* jogador1, Jogador_2* jogador2) : Entidade() {
    listaEntidades = lista;
    pJ1 = jogador1;
    pJ2 = jogador2;
}

Fase::~Fase() {

}
//--------------------------------------------------------------------------------------------------------------------//
//Criação de Entidadades
void Fase::criaPlataforma() {
    Obstaculo* obstaculo;
    obstaculo = new Obstaculo();
    obstaculo->inicializaObstaculo(Vector2f(200,200),Vector2f(50,50), true);
    listaEntidades->incluir(static_cast<Entidade*>(obstaculo));
}

void Fase::posicionaJogador(Vector2f pos){
    pJ1->setPosition(pos);
    if(pJ2){
        Vector2f pos2(pos.x+2, pos.y);
        pJ2->setPosition(pos2);
    }
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
        criaEntidade(aux,Vector2f(COL,ROW));
        (*arqFase) >> aux;
        if (COL == FASE_WIDTH-1){
            ROW++;
            COL = 0;
        } else{
            COL++;
        }
    }

}

void Fase::criaEntidade(char aux, Vector2f pos) {}

void Fase::carregaInimigo() {

}

void Fase::carregaObstaculo() {

}

void Fase::inicializa() {}
