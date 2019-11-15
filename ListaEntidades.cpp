
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 27/10/19.


//--------------------------------------------------------------------------------------------------------------------//
//Header//
#include "ListaEntidades.h"

//--------------------------------------------------------------------------------------------------------------------//
//Contrutora/Destrutora//
ListaEntidades::ListaEntidades() {

}

ListaEntidades::~ListaEntidades() {

}

//--------------------------------------------------------------------------------------------------------------------//
//Sets/Gets//
Lista<Entidade> *ListaEntidades::getLista() {
    return &lista;
}

//--------------------------------------------------------------------------------------------------------------------//
//metodos de loop//
void ListaEntidades::draw() {
    //chamará o metodo draw do elemento apontado por i
    aux->getInfo()->draw();
}

void ListaEntidades::update() {
    //chamará o metodo update do elemento apontado por i
    aux->getInfo()->update();
}

void ListaEntidades::percorrer() {
    aux = lista.getPrim();
while (aux != lista.getAt()){
        draw();
        update();
        aux = aux->getProx();
    }
    aux = NULL;
}

//--------------------------------------------------------------------------------------------------------------------//
//Inclui entidades na lista//
void ListaEntidades::incluir(Entidade* entidade) {
    lista=(entidade);
}
