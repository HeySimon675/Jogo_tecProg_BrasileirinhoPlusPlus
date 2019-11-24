
//--------------------------------------------------------------------------------------------------------------------//
// Created by simao on 11/11/2019.

#include "Fase_A.h"

//--------------------------------------------------------------------------------------------------------------------//
//Construção
Fase_A::Fase_A(Jogador_1* jogador1, Jogador_2* jogador2) : Fase(jogador1, jogador2) {
    background.setTexture(gerenciadorGrafico->getTexture(getID()));
    inicializa();
    setFinalPosition();
}

Fase_A::~Fase_A() {}
//--------------------------------------------------------------------------------------------------------------------//

void Fase_A::criaInimigoA(Vector2f pos) {
    if(numInimigos){
        Inimigo_A *nA;
        nA = new Inimigo_A;
        nA->inicializar(pos);
        listaEntidades.incluir(static_cast<Entidade*>(nA));
        gerenciadorDeColisoes.incluiInimigoNaLista(static_cast<Inimigo*>(nA));
        numInimigos--;
    }

}

void Fase_A::criaEntidade(char aux, Vector2f pos) {

    switch (aux){
        case 'J' :
            armazenaPosicao(pos);
            break;
        case 'A':   //Inimigo_A
            criaInimigoA(pos);
            break;
        case 'B':
            criaProjetil_InimigoB(pos);
            break;
        case 'P':
            criaPlataforma(pos);
            break;
        case 'E':
            criaEspinho(pos);
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

const String Fase_A::FASE_FILE = FASES_DIR + "FaseTest.txt";
const int Fase_A::FASE_WIDTH = 16;
const int Fase_A::FASE_HEIGHT = 12;
//fase agora tem o a dimensão da view, a ideia é expandir tanto vertical, quanto horizontalmente, percorrendo a view,
//ou deixando a view menor, fazendo à caminhar pela fase, seguindo o jogador
const int Fase_A::id = 7;
const float Fase_A::FIM = 18;