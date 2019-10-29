
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 26/10/19.
#pragma once
#include "Entidade.h"

//--------------------------------------------------------------------------------------------------------------------//
//Classe Entidade//

//--------------------------------------------------------------------------------------------------------------------//
//contrutora/Destrutora//

Entidade::Entidade(float posX, float posY) {
    posicao = Vector2f(posX,posY);
}

Entidade::Entidade(Vector2f posicao) {
    this->posicao = posicao;
}


Entidade::~Entidade() {

}

//--------------------------------------------------------------------------------------------------------------------//
//Metodos de loop//

void Entidade::update() {

}

void Entidade::draw() {

}


