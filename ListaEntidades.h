
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 27/10/19.
#pragma once

//--------------------------------------------------------------------------------------------------------------------//
//Header//
#include "Lista.h"
#include "Entidade.h"

//--------------------------------------------------------------------------------------------------------------------//
//Lista especializada para Entidades//

class ListaEntidades {
private:
    Lista<Entidade> lista;
    //Lista<Entidade>::Iterator i;
    Elemento<Entidade>* aux;

public:
    ListaEntidades();
    ~ListaEntidades();
    Lista<Entidade>* getLista();
//--------------------------------------------------------------------------------------------------------------------//
//Metodos de loop//
private:
    void draw();
    void update(float deltaTime);
    void executar(float deltaTime = 0.0f);  //paramentro default somente para teste
    void drawEntidades(); //função em desuso
public:

    void percorrer(float deltaTime);    //testar em jogo
    void incluir(Entidade* entidade);
};

