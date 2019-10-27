
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

public:
    ListaEntidades();
    ~ListaEntidades();
    Lista<Entidade>* getLista();
    void draw();
    void update();

};

