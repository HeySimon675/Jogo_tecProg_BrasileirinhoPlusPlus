
//--------------------------------------------------------------------------------------------------------------------//
// Created by simao on 27/10/2019//
#include "Jogo.h"

//--------------------------------------------------------------------------------------------------------------------//
//Inicializações de Variaveis
Jogo* Jogo::_instance = nullptr;



//--------------------------------------------------------------------------------------------------------------------//
//Metodo Singleton//
Jogo *Jogo::getJogo() {
    if(!_instance){
        _instance = new Jogo;
    }
    return _instance;
}

//--------------------------------------------------------------------------------------------------------------------//
//construtora Privada//
Jogo::Jogo() {
    inicializa();
}   //end Construtora

//--------------------------------------------------------------------------------------------------------------------//
//destrutora//

Jogo::~Jogo() {

}   //end Destrutora

//--------------------------------------------------------------------------------------------------------------------//
//inicializadores//
void Jogo::inicializa() {
    g = GerenciadorGrafico::getGerGrafico();
}
//--------------------------------------------------------------------------------------------------------------------//
//metodos principais//
void Jogo::executar() {
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    //FIM TESTE//
    while (g->isOpen())
    {
        g->executar();
        // teste//

        g->draw(shape);
        g->display();

    }

}


//--------------------------------------------------------------------------------------------------------------------//
//Nesse momento do desenvolvimento, esses metodos se tornaram obsoletos//
void Jogo::update() {
    //ira atualizar as posições das Entidades dependendo de seu State
}

void Jogo::draw() {
}
//--------------------------------------------------------------------------------------------------------------------//