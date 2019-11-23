
//--------------------------------------------------------------------------------------------------------------------//
//Implemetado por:
    //Coradassi - 95%
    //Simão     - 5%

//todo Classe ainda não otimizada para o projeto

#pragma once

#include <SFML/Graphics.hpp>
#include "Obstaculo_Plataforma.h"
#include "Obstaculo_Espinho.h"
#include "Obstaculo_Movel.h"
#include "Personagem.h"
#include "Jogador_1.h"
#include "Jogador_2.h"
#include "ListaInimigos.h"
#include "ListaObstaculos.h"
#include "ListaProjetil.h"
#pragma once
class GerenciadorDeColisoes {
private:
    Jogador_1* j1;
    Jogador_2* j2;
    ListaInimigos li;
    ListaObstaculos lo;
    ListaProjetil lp;

public:
    GerenciadorDeColisoes();
    ~GerenciadorDeColisoes();

    // void move (float dx, float dy){body.move(dx,dy);}

    // void setBody(sf::RectangleShape& body);
    void executar();
    void getPonteiroPlayer(Jogador_1* j1) {this->j1 = j1;}
    void incluiObstaculoNalista(Obstaculo* obstaculo) {lo.incluir(obstaculo);}
    void incluiInimigoNaLista(Inimigo* inimigo) {li.incluir(inimigo);}
    void incluiProjetilNaLista(Projetil* projetil) {lp.incluir(projetil);}
    bool checkCollision(Projetil* parada, Jogador* movimentavel);
    bool checkCollision(Obstaculo* parada, Personagem* movimentavel,sf::Vector2f& direction, float push);
    // bool checkCollision(Obstaculo_Espinho* parada, Jogador* movimentavel, sf::Vector2f& direction, float push);
    //  bool checkCollision(Obstaculo_Movel* parada, Jogador* movimentavel, sf::Vector2f& direction, float push);
    bool checkCollision(Inimigo* parada, Jogador* movimentavel);
};
