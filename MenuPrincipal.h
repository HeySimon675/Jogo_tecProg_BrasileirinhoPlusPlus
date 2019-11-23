#pragma once
#include "Menu.h"

class MenuPrincipal : public Menu
{
public:
    MenuPrincipal();
    ~MenuPrincipal();
    int executar();
    void update();
    void novoJogo();
    void ranking();
    void sair();
    void inicializaTextos();

private:
    sf::Text NovoJogo;
    sf::Text Ranking;
    sf::Text Sair;
    int naoDuplica;
};

