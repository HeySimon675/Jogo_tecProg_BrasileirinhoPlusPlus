
//--------------------------------------------------------------------------------------------------------------------//
//Implementado por:
    //Coradassi - 100%
#pragma once

//--------------------------------------------------------------------------------------------------------------------//
//Header//
#include "Lista.h"
#include "Inimigo.h"
#include <vector>
#include <iterator>
using namespace std;

//--------------------------------------------------------------------------------------------------------------------//
//Lista especializada para Inimigos//

class ListaInimigos{
private:
    vector<Inimigo*> vetorInimigo;
    int contador;
public:
    ListaInimigos();
    ~ListaInimigos();
    void incluir(Inimigo* inimigo);
    int getContador() {return contador;}
    Inimigo* getInimigo(int i) {return vetorInimigo[i];}
    void desativar();

//Metodo para teste//
//fim teste//

//--------------------------------------------------------------------------------------------------------------------//
//Verifica colisões
private:
};

