#pragma once
#include "Entidade.h"

class Menu : public Entidade
{
public:
    Menu();
    virtual ~Menu();
    void update();
    void draw(sf::Text text);
    virtual int executar() = 0;
    virtual void inicializaTextos() = 0;
    sf::Font getFont();

protected:
    sf::RectangleShape fundo;
    sf::Font font;
    int contador;
    bool keyRepeat;
};

