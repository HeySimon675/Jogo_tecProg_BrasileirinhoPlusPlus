
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
const int Fase::FASE_HEIGHT = 12;
const int Fase::FASE_WIDTH = 16;

Fase::Fase(ListaEntidades* lista, Jogador_1* jogador1, Jogador_2* jogador2) : Entidade() {
    listaEntidades = lista;
    pJ1 = jogador1;
    pJ2 = jogador2;
}

Fase::~Fase() {
    destroiMatriz();
    pJ1 = nullptr;
    pJ2 = nullptr;
    listaEntidades = nullptr;
    arqFase = nullptr;

}
//--------------------------------------------------------------------------------------------------------------------//
//Criação de Entidadades
void Fase::criaPlataforma(Vector2f pos) {
    //Obstaculo_Plataforma* obstaculo;
    //obstaculo = new Obstaculo();
    //obstaculo->inicializa(pos);
    //listaEntidades->incluir(static_cast<Entidade*>(obstaculo));
}

void Fase::posicionaJogador(Vector2f pos){
    pJ1->setPosition(pos);
    if(pJ2){
        Vector2f pos2(pos.x+2, pos.y);
        pJ2->setPosition(pos2);
    }
}

void Fase::criaSpike(Vector2f pos){
    //Obstaculo_Spike* obstaculo;
    //obstaculo = new Obstaculo_Spike;
    //obstaculo->inicializa(pos);
    //listaEntidades->incluir(static_cast<Entidade*>(obstaculo));
}
void Fase::criaProjetil(Vector2f pos){
    //Projetil* projetil;
    //projetil = new Projetil;
    //projetil->inicializa(pos);
    //listaEntidades->incluir(static_cast<Entidade*>(projetil));
    //criaInimigoB(pos,projetil);
}

void Fase::criaInimigoB(Vector2f pos, Projetil* projetil){
    //Inimigo_B* inimigo;
    //inimigo = new Inimigo_B;
    //inimigo->inicializa(pos);
    //listaEntidades->incluir(static_cast<Entidade*>(inimigo));
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

void Fase::destroiMatriz(){
    for(int row =0; row < FASE_WIDTH ; row++){
        delete matrizFase[row];
    }
    delete matrizFase;
    matrizFase = nullptr;
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
