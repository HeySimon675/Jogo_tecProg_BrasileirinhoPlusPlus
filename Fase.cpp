
//--------------------------------------------------------------------------------------------------------------------//

#include "Fase.h"

//--------------------------------------------------------------------------------------------------------------------//
/*PREFIXO DO SISTEMA//
    "../"      -> LINUX
    ""         -> WINDOWS
*/
const String Fase::SYSTEM_PREFIX = "../";

//--------------------------------------------------------------------------------------------------------------------//
//Constantes//

const String Fase::FASES_DIR = SYSTEM_PREFIX + "Fases/";
const int Fase::FASE_HEIGHT = 12;
const int Fase::FASE_WIDTH = 18;

Fase::Fase(Jogador_1* jogador1, Jogador_2* jogador2) : Entidade() {
    pJ1 = jogador1;
    pJ2 = jogador2;
    srand(time(NULL));
    randomizaEntidades();
    background.setSize(Vector2f(800,600));
    background.setPosition(50,0);
    isDoisPlayer = false;
}

Fase::~Fase() {
    //verifica se os jogadores foram derrotados ou passaram de fase ( talvez deva ser implementado em outro lugar)
    if(pJ1->isActive() && pJ2){
        pJ2->ativar();
    }
    destroiMatriz();
    pJ1 = nullptr;
    pJ2 = nullptr;
    arqFase = nullptr;

}

void Fase::setJogadores(Jogador_1 *jogador1, Jogador_2 *jogador2) {
    pJ1 = jogador1;
    posicionaJogador(posicaoPlayer);
    if(jogador2){
        pJ2 = jogador2;
        isDoisPlayer = true;
    }
}

//--------------------------------------------------------------------------------------------------------------------//
//Criação de Entidadades
void Fase::criaPlataforma(Vector2f pos) {
    Obstaculo_Plataforma* obstaculo;
    obstaculo = new Obstaculo_Plataforma;
    obstaculo->setPosition(pos);
    listaEntidades.incluir(static_cast<Entidade*>(obstaculo));
    gerenciadorDeColisoes.incluiObstaculoNalista(static_cast<Obstaculo*>(obstaculo));
}

void Fase::posicionaJogador(Vector2f pos){
    pJ1->inicializar(pos);
    //listaEntidades.incluir(static_cast<Entidade*>(pJ1));
    gerenciadorDeColisoes.getPonteiroPlayer(pJ1);
    if(pJ2){
        Vector2f pos2(pos.x, pos.y);
        pJ2->setPosition(pos2);
        gerenciadorDeColisoes.getPonteiroPlayer2(pJ2);
        //listaEntidades.incluir(static_cast<Entidade*>(pJ2));
        //incluir no gerenciador de colisoes o player 2
    }
}

void Fase::criaEspinho(Vector2f pos){
    if(numEspinhos){
        Obstaculo_Espinho* obstaculo;
        obstaculo = new Obstaculo_Espinho;
        obstaculo->setPosition(pos);
        listaEntidades.incluir(static_cast<Entidade*>(obstaculo));
        gerenciadorDeColisoes.incluiObstaculoNalista(static_cast<Obstaculo*>(obstaculo));
        numEspinhos--;
    }

}
void Fase::criaProjetil_InimigoB(Vector2f pos){
    if(numInimigos){
        Projetil* projetil;
        projetil = new Projetil;
        listaEntidades.incluir(static_cast<Entidade*>(projetil));
        gerenciadorDeColisoes.incluiProjetilNaLista(projetil);
        criaInimigoB(pos,projetil);
        numInimigos--;
    }

}

void Fase::criaInimigoB(Vector2f pos, Projetil* projetil){
    Inimigo_B* inimigo;
    inimigo = new Inimigo_B;
    inimigo->inicializar(pos,projetil);
    listaEntidades.incluir(static_cast<Entidade*>(inimigo));
    gerenciadorDeColisoes.incluiInimigoNaLista(static_cast<Inimigo*>(inimigo));
}
//--------------------------------------------------------------------------------------------------------------------//
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
    delete matrizFase[0];
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
    arqFase->close();
}

void Fase::criaEntidade(char aux, Vector2f pos) {}
//--------------------------------------------------------------------------------------------------------------------//

void Fase::update(float deltaTime) {
    listaEntidades.percorrer(deltaTime);
    if(pJ1->isActive()){
        pJ1->draw();
        pJ1->update(deltaTime);
        gerenciadorDeColisoes.executar();
    }
    else{
        this->desativar();
    }

    if(isDoisPlayer){
        if(pJ2->isActive()){
            pJ2->draw();
            pJ2->update(deltaTime);
            gerenciadorDeColisoes.executar();
        }
    }
    if(checkFim()){
        this->desativar();
    }

}
//--------------------------------------------------------------------------------------------------------------------//

void Fase::inicializa() {}

void Fase::randomizaEntidades() {
    numCaixas = rand() % 3 + 2;
    numEspinhos = rand() % 3 + 3;
    numInimigos = rand() % 5 + 5;
}

bool Fase::checkFim() {
    if(pJ1->isActive()) {
        if (pJ1->getPosition().x > finalPosition) {
            return true;
        }
    }
    if(pJ2){
        if (pJ2->isActive() && pJ2->getPosition().x > finalPosition){
            return true;
        }
    }
    return false;
}
