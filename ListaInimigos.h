
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 14/11/19.
#pragma once

//--------------------------------------------------------------------------------------------------------------------//
//Header//
#include "Lista.h"
#include "Inimigo.h"

//--------------------------------------------------------------------------------------------------------------------//
//Lista especializada para Inimigos//

class ListaInimigos{
private:
    Lista<Inimigo> lista;
    Elemento<Inimigo>* aux;
public:
    ListaInimigos();
    ~ListaInimigos();
    void incluir(Inimigo& inimigo);

//Metodo para teste//
    Lista<Inimigo>* getLista();
//fim teste//

//--------------------------------------------------------------------------------------------------------------------//
//Verifica colisões
private:
    void checkColisao();
};

