
//--------------------------------------------------------------------------------------------------------------------//


#include "ListaProjetil.h"

ListaProjetil::ListaProjetil() {
    contador = 0;
}

ListaProjetil::~ListaProjetil() {

}

void ListaProjetil::incluir(Projetil *Projetil) {
    vetorProjetil.push_back(Projetil);
    contador++;
}

void ListaProjetil::desativar() {
    vector<Projetil*>::iterator iterator = vetorProjetil.begin();
    while(iterator != vetorProjetil.end()){
        (*iterator)->desativar();
    }
}


