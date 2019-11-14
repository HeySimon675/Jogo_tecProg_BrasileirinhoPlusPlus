
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 14/11/19.
#pragma once

//--------------------------------------------------------------------------------------------------------------------//
//Header//
#include "Lista.h"
#include "Obstaculo.h"

//--------------------------------------------------------------------------------------------------------------------//
//Lista especializada para obstaculos//

class ListaObstaculos{
private:
    Lista<Obstaculo> lista;
    Elemento<Obstaculo>* aux;
public:
    ListaObstaculos();
    ~ListaObstaculos();
    void incluir(Obstaculo& obstaculo);

//Metodo para teste//
    Lista<Obstaculo>* getLista();
//fim teste//

//--------------------------------------------------------------------------------------------------------------------//
//Verifica colisões
private:
    void checkColisao();
};
