
//--------------------------------------------------------------------------------------------------------------------//
// Created by simao on 11/11/2019.

#include "Fase_B.h"

//TODO: Avaliar a possibilidade de mudar o tamanho de faseB para diferenciar

//--------------------------------------------------------------------------------------------------------------------//
//Constantes//

const String Fase_B::FASE_FILE = "Fase_B.txt";
const int Fase_B::FASE_WIDTH = 16;
const int Fase_B::FASE_HEIGHT = 12;
//fase agora tem o a dimensão da view, a ideia é expandir tanto vertical, quanto horizontalmente, percorrendo a view,
//ou deixando a view menor, fazendo à caminhar pela fase, seguindo o jogador

//--------------------------------------------------------------------------------------------------------------------//
//Construtoras//

Fase_B::Fase_B( Jogador_1* jogador1, Jogador_2* jogador2) : Fase( jogador1, jogador2) {
    inicializa();
}

Fase_B::~Fase_B() {
    //verifica se os jogadores foram derrotados ou passaram de fase ( talvez deva ser implementado em outro lugar)
    if(pJ1->isActive()){

    }

    delete arqFase;
    destroiMatriz();
}

void Fase_B::inicializa(){
	//terá implementação semelhante à de FaseA
}
//--------------------------------------------------------------------------------------------------------------------//
//Entidades

void Fase_B::criaEntidade(char aux, Vector2f pos){
	//implementar switch
}

void Fase_B::criaInimigoBoss(Vector2f pos){

}


