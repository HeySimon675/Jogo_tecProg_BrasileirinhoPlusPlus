#pragma once
#include "Menu.h"

class MenuNovoJogo : public Menu
{
public:
    MenuNovoJogo();
    ~MenuNovoJogo();
    void set1Player();
    void set2Player();
    int executar();
    void update();
    void inicializaTextos();

private:
    sf::Text Player1;
    sf::Text Player2;
    int naoDuplica;
};

