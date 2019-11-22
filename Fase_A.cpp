
//--------------------------------------------------------------------------------------------------------------------//
// Created by simao on 11/11/2019.

#include "Fase_A.h"

//--------------------------------------------------------------------------------------------------------------------//
//Construção
Fase_A::Fase_A(ListaEntidades* lista, Jogador_1* jogador1, Jogador_2* jogador2) : Fase(lista, jogador1, jogador2) {
    inicializa();
}

Fase_A::~Fase_A() {
    //verifica se os jogadores foram derrotados ou passaram de fase ( talvez deva ser implementado em outro lugar)
    if(pJ1->isActive()){

    }

    delete arqFase;
    destroiMatriz();
}
//--------------------------------------------------------------------------------------------------------------------//

void Fase_A::criaInimigoA(Vector2f pos) {
    Inimigo_A *nA;
    nA = new Inimigo_A;
    nA->inicializar(pos);
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
        case 'B':
            criaProjetil(pos);
            break;
        case 'P':
            criaPlataforma(pos);
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
const int Fase_A::FASE_WIDTH = 16;
const int Fase_A::FASE_HEIGHT = 12;
//fase agora tem o a dimensão da view, a ideia é expandir tanto vertical, quanto horizontalmente, percorrendo a view,
//ou deixando a view menor, fazendo à caminhar pela fase, seguindo o jogador
