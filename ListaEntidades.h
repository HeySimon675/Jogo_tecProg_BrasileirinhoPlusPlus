
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
    Lista<Entidade>::Iterator i;
    Elemento<Entidade>* aux;

public:
    ListaEntidades();
    ~ListaEntidades();
    Lista<Entidade>* getLista();
//--------------------------------------------------------------------------------------------------------------------//
//Metodos de loop//
private:
    void draw();
    void update();  //atualmente em desuso
public:
    void drawEntidades();
    void incluir(Entidade* entidade);
};

