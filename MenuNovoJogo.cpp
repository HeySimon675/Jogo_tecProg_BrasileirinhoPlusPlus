#include "MenuNovoJogo.h"

MenuNovoJogo::MenuNovoJogo()
{
    contador = 0;
    naoDuplica = 0;
}

MenuNovoJogo::~MenuNovoJogo()
{
    //dtor
}

int MenuNovoJogo::executar()
{
    inicializaTextos();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && contador <1 && naoDuplica > 7)
    {
        contador++;
        naoDuplica = 0;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && contador > 0 && naoDuplica > 7)
    {
        contador--;
        naoDuplica = 0;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && naoDuplica > 7)
    {
        naoDuplica = 0;
        return contador;
    }

    switch (contador)
    {
        case 0:
            Player1.setColor(sf::Color::Red);
            Player2.setColor(sf::Color::White);
            break;

        case 1:
            Player2.setColor(sf::Color::Red);
            Player1.setColor(sf::Color::White);
            break;
    }

    if(naoDuplica < 100)
    {
        naoDuplica++;
    }
}

void MenuNovoJogo::update()
{
    int op = -1;
    op = executar();

    switch (op)
    {
        case 0:
            set1Player();
            break;

        case 1:
            set2Player();
            break;
    }
}

void MenuNovoJogo::inicializaTextos()
{
    sf::Font font;
    font.loadFromFile("Textures/arial.ttf");

    Player1.setString("Player1");
    Player2.setString("Player2");

    Player1.setFont(font);
    Player2.setFont(font);

    Player1.setPosition(0.0f, 0.0f);
    Player2.setPosition(0.0f, 30.0f);

    draw(Player1);
    draw(Player2);
}

void MenuNovoJogo::set1Player()
{

}

void MenuNovoJogo::set2Player()
{

}
