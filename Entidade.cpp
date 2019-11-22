
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 26/10/19.
#pragma once
#include "Entidade.h"

//--------------------------------------------------------------------------------------------------------------------//
//Classe Entidade//
GerenciadorGrafico* Entidade::gerenciadorGrafico = GerenciadorGrafico::getGerGrafico();


//--------------------------------------------------------------------------------------------------------------------//
//CONSTRUÇÃO

Entidade::Entidade() {
    ativar();
}


Entidade::~Entidade() {

}

//--------------------------------------------------------------------------------------------------------------------//
//Metodo de Ativação//
void Entidade::ativar() {
    _active = true;
}

void Entidade::desativar() {
    _active = false;
}



