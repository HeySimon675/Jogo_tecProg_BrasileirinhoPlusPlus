#pragma once
#include "Menu.h"

class MenuPause : public Menu
{
public:
    MenuPause();
    ~MenuPause();
    int executar();
    void update();
    void desPause();
    void sair();
    void inicializaTextos();

private:
    sf::Text DesPause;
    sf::Text Sair;
    int naoDuplica;
};
