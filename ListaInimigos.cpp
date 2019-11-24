
//--------------------------------------------------------------------------------------------------------------------//
// Created by simao on 14/11/2019.
//

#include "ListaInimigos.h"

ListaInimigos::ListaInimigos() {
    contador = 0;
}

ListaInimigos::~ListaInimigos() {

}

void ListaInimigos::incluir(Inimigo *inimigo) {
    vetorInimigo.push_back(inimigo);
    contador++;
}

void ListaInimigos::desativar() {
    vector<Inimigo*>::iterator iterator = vetorInimigo.begin();
    while(iterator != vetorInimigo.end()){
        (*iterator)->desativar();
    }
}


