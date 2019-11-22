
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 27/10/19.


//--------------------------------------------------------------------------------------------------------------------//
//Header//
#include "ListaEntidades.h"

//--------------------------------------------------------------------------------------------------------------------//
//Contrutora/Destrutora//
ListaEntidades::ListaEntidades() {
    aux = nullptr;
}

ListaEntidades::~ListaEntidades() {
    aux = nullptr;

}

//--------------------------------------------------------------------------------------------------------------------//
//Sets/Gets//
Lista<Entidade> *ListaEntidades::getLista() {
    return &lista;
}

//--------------------------------------------------------------------------------------------------------------------//
//metodos de loop//
void ListaEntidades::draw() {
    //TESTAR USAR OPERADOR * DA LISTA PARA ACESSAR INFO
    aux->getInfo()->draw();
    
}
//--------------------------------------------------------------------------------------------------------------------//
//TODO: TESTAR
void ListaEntidades::update(float deltaTime) {
    //TESTAR USAR OPERADOR * DA LISTA PARA ACESSAR INFO
    aux->getInfo()->update(deltaTime);
    
    
}
//TESTAR
void ListaEntidades::executar(float deltaTime){
    //testar operador *
    if(aux->getInfo()->isActive()){
        update(deltaTime);
        draw();
    }
}
//--------------------------------------------------------------------------------------------------------------------//
//LOOP//

//testar e se funcional, migrar para a função para 'Percorrer'
void ListaEntidades::drawEntidades() {
    if(!lista.vazia()){
        aux = lista.inicio();
        while (aux != lista.fim()){
            executar();
            aux = aux->getProx();
            //aux = aux++;    //testar metodo, se possivel trocar por um iterator, assim incrementando somente o iterator
        }
        executar();
        aux = nullptr;
    }
}

//função principal de loop
void ListaEntidades::percorrer(float deltaTime){
    if(!lista.vazia()){
        aux = lista.inicio();
        while (aux != lista.fim()){
            executar(deltaTime);
            aux = aux->getProx();
            //aux = aux++;    //testar metodo, se possivel trocar por um iterator, assim incrementando somente o iterator
        }
        executar(deltaTime);
        aux = nullptr;
    }
}


//--------------------------------------------------------------------------------------------------------------------//
//Inclui entidades na lista//
void ListaEntidades::incluir(Entidade* entidade) {
    lista=(entidade);
}
