
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
    vector<Obstaculo*> vetorObstaculo;
    int contador;

public:
    ListaObstaculos();
    ~ListaObstaculos();
    void incluir(Obstaculo* Obstaculo);
    Obstaculo* getObstaculo(int i) {return vetorObstaculo[i];}
    int getContador(){return contador;}
    void desativar();

//Metodo para teste//
//fim teste//

//--------------------------------------------------------------------------------------------------------------------//
};

