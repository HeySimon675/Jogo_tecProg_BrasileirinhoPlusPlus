
//--------------------------------------------------------------------------------------------------------------------//
//Created by simao on 26/10/19.
//Update on 30/10 - 21hrs
#pragma once
#include "Entidade.h"

//--------------------------------------------------------------------------------------------------------------------//
//Classe Entidade//
GerenciadorGrafico* Entidade::gerenciadorGrafico = GerenciadorGrafico::getGerGrafico();

//--------------------------------------------------------------------------------------------------------------------//
//contrutora/Destrutora//

Entidade::Entidade(float posX, float posY,bool active) {
    posicao = Vector2f(posX,posY);
    _active = active;
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
    //tera sua implementação em subclasses, a ideia é passar o body da Entidade especifica pro gerenciador grafico
}


