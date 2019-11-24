
//--------------------------------------------------------------------------------------------------------------------//
#pragma once

//--------------------------------------------------------------------------------------------------------------------//
//Header//
#include "Lista.h"
#include "Projetil.h"
#include <vector>
#include <iterator>
using namespace std;

//--------------------------------------------------------------------------------------------------------------------//
//Lista especializada para Projetil//

class ListaProjetil{
private:
    vector<Projetil*> vetorProjetil;
    int contador;
public:
    ListaProjetil();
    ~ListaProjetil();
    void incluir(Projetil* Projetil);
    int getContador() {return contador;}
    Projetil* getProjetil(int i) {return vetorProjetil[i];}
    void desativar();
};

