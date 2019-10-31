
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 26/10/19.
#pragma once
#include "Entidade.h"

//--------------------------------------------------------------------------------------------------------------------//
//Classe Entidade//

//--------------------------------------------------------------------------------------------------------------------//
//contrutora/Destrutora//

Entidade::Entidade(float posX, float posY,bool active) {
    posicao = Vector2f(posX,posY);
    gerenciadorGrafico = GerenciadorGrafico::getGerGrafico();
}

Entidade::Entidade(Vector2f posicao) {
    this->posicao = posicao;
}


Entidade::~Entidade() {

}

//--------------------------------------------------------------------------------------------------------------------//
//Metodo de Ativação//
void Entidade::ativarEntidade() {
    _active = true;
}

void Entidade::desativarEntidade() {

}

//--------------------------------------------------------------------------------------------------------------------//
//Metodos de loop//

void Entidade::update() {

}

void Entidade::draw() {

}


