
//--------------------------------------------------------------------------------------------------------------------//

#include "Fase_B.h"

//--------------------------------------------------------------------------------------------------------------------//
//Constantes//

const String Fase_B::FASE_FILE = FASES_DIR + "Fase_B.txt";
const int Fase_B::FASE_WIDTH = 18;
const int Fase_B::FASE_HEIGHT = 12;
//fase agora tem o a dimensão da view, a ideia é expandir tanto vertical, quanto horizontalmente, percorrendo a view,
//ou deixando a view menor, fazendo à caminhar pela fase, seguindo o jogador
const int Fase_B::id = 8;
const float Fase_B::FIM = 17;

//--------------------------------------------------------------------------------------------------------------------//
//Construtoras//

Fase_B::Fase_B( Jogador_1* jogador1, Jogador_2* jogador2) : Fase( jogador1, jogador2) {
    background.setTexture(gerenciadorGrafico->getTexture(getID()));
    inicializa();
    setFinalPosition();
    numBoss= 1;
}

Fase_B::~Fase_B() {}
//--------------------------------------------------------------------------------------------------------------------//

void Fase_B::inicializa(){
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
//Entidades

void Fase_B::criaEntidade(char aux, Vector2f pos){
    switch (aux){
        case 'J' :
            armazenaPosicao(pos);
            break;
        case 'Z':   //Inimigo_Boss
            criaInimigoBoss(pos);
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
        case 'C':   //caixa
            criaCaixa(pos);
            break;
        default:
            break;
    }
}

void Fase_B::criaInimigoBoss(Vector2f pos){
    if(numBoss){
        Inimigo_Boss *inimigo;
        inimigo = new Inimigo_Boss;
        inimigo->inicializarBoss(pos);
        listaEntidades.incluir(static_cast<Entidade*>(inimigo));
        gerenciadorDeColisoes.incluiInimigoNaLista(static_cast<Inimigo*>(inimigo));
        numBoss--;
    }
}

void Fase_B::criaCaixa(Vector2f pos) {
    if(numCaixas){
        Obstaculo_Movel *obstaculo;
        obstaculo = new Obstaculo_Movel;
        obstaculo->setPosition(pos);
        listaEntidades.incluir(static_cast<Entidade*>(obstaculo));
        gerenciadorDeColisoes.incluiObstaculoNalista(static_cast<Obstaculo*>(obstaculo));
        numCaixas--;
    }
}
//--------------------------------------------------------------------------------------------------------------------//


